/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2015 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 2009-2016 Wayne Stambaugh <stambaughw@verizon.net>
 * Copyright (C) 2004-2016 KiCad Developers, see change_log.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/**
 * @file eeschema/block.cpp
 */

#include <fctsys.h>
#include <pgm_base.h>
#include <gr_basic.h>
#include <class_drawpanel.h>
#include <confirm.h>
#include <sch_edit_frame.h>

#include <general.h>
#include <class_library.h>
#include <lib_pin.h>
#include <list_operations.h>
#include <sch_bus_entry.h>
#include <sch_marker.h>
#include <sch_junction.h>
#include <sch_line.h>
#include <sch_no_connect.h>
#include <sch_text.h>
#include <sch_component.h>
#include <sch_sheet.h>
#include <sch_sheet_path.h>
#include <list_operations.h>

static void DrawMovingBlockOutlines( EDA_DRAW_PANEL* aPanel, wxDC* aDC,
                                     const wxPoint& aPosition, bool aErase );

int SCH_EDIT_FRAME::BlockCommand( EDA_KEY key )
{
    int cmd = BLOCK_IDLE;

    switch( key )
    {
    default:
        cmd = key & 0xFF;
        break;

    case 0:
        cmd = BLOCK_MOVE;
        break;

    case GR_KB_SHIFT:
        cmd = BLOCK_DUPLICATE;
        break;

    case GR_KB_ALT:
        cmd = BLOCK_ROTATE;
        break;

    case GR_KB_CTRL:
        cmd = BLOCK_DRAG;
        break;

    case GR_KB_SHIFTCTRL:
        cmd = BLOCK_DELETE;
        break;

    case MOUSE_MIDDLE:
        cmd = BLOCK_ZOOM;
        break;
    }

    return cmd;
}


void SCH_EDIT_FRAME::InitBlockPasteInfos()
{
    BLOCK_SELECTOR* block = &GetScreen()->m_BlockLocate;

    block->GetItems().CopyList( m_blockItems.GetItems() );
    m_canvas->SetMouseCaptureCallback( DrawMovingBlockOutlines );
}


void SCH_EDIT_FRAME::HandleBlockPlace( wxDC* DC )
{
    BLOCK_SELECTOR* block = &GetScreen()->m_BlockLocate;

    if( !m_canvas->IsMouseCaptured() )
    {
        DisplayError( this, wxT( "HandleBlockPLace() : m_mouseCaptureCallback = NULL" ) );
    }

    if( block->GetCount() == 0 )
    {
        wxString msg;
        msg.Printf( wxT( "HandleBlockPLace() error : no items to place (cmd %d, state %d)" ),
                    block->GetCommand(), block->GetState() );
        DisplayError( this, msg );
    }

    block->SetState( STATE_BLOCK_STOP );

    switch( block->GetCommand() )
    {
    case BLOCK_DRAG:        // Drag from mouse
    case BLOCK_DRAG_ITEM:   // Drag from a component selection and drag command
    case BLOCK_MOVE:
        if( m_canvas->IsMouseCaptured() )
            m_canvas->CallMouseCapture( DC, wxDefaultPosition, false );

        // If the block wasn't changed, don't update the schematic
        if( block->GetMoveVector() == wxPoint( 0, 0 ) )
        {
            // This calls the block-abort command routine on cleanup
            m_canvas->EndMouseCapture( GetToolId(), m_canvas->GetCurrentCursor() );
            return;
        }

        SaveCopyInUndoList( block->GetItems(), UR_CHANGED, false, block->GetMoveVector() );
        MoveItemsInList( block->GetItems(), block->GetMoveVector() );
        break;

    case BLOCK_DUPLICATE:           /* Duplicate */
    case BLOCK_PRESELECT_MOVE:      /* Move with preselection list*/
        if( m_canvas->IsMouseCaptured() )
            m_canvas->CallMouseCapture( DC, wxDefaultPosition, false );

        DuplicateItemsInList( GetScreen(), block->GetItems(), block->GetMoveVector() );

        SaveCopyInUndoList( block->GetItems(),
                            ( block->GetCommand() == BLOCK_PRESELECT_MOVE ) ? UR_CHANGED : UR_NEW );
        break;

    case BLOCK_PASTE:
        if( m_canvas->IsMouseCaptured() )
            m_canvas->CallMouseCapture( DC, wxDefaultPosition, false );

        PasteListOfItems( DC );
        break;

    default:        // others are handled by HandleBlockEnd()
       break;
    }

    CheckListConnections( block->GetItems(), true );
    block->ClearItemsList();
    SchematicCleanUp( true );
    OnModify();

    // clear dome flags and pointers
    GetScreen()->ClearDrawingState();
    GetScreen()->ClearBlockCommand();
    GetScreen()->SetCurItem( NULL );
    GetScreen()->TestDanglingEnds();

    if( block->GetCount() )
    {
        DisplayError( this, wxT( "HandleBlockPLace() error: some items left in buffer" ) );
        block->ClearItemsList();
    }

    m_canvas->EndMouseCapture( GetToolId(), m_canvas->GetCurrentCursor(), wxEmptyString, false );
    m_canvas->Refresh();
}


bool SCH_EDIT_FRAME::HandleBlockEnd( wxDC* aDC )
{
    bool            nextcmd = false;
    bool            zoom_command = false;
    bool            append = false;
    BLOCK_SELECTOR* block = &GetScreen()->m_BlockLocate;

    if( block->GetCount() )
    {
        BLOCK_STATE_T   state   = block->GetState();
        BLOCK_COMMAND_T command = block->GetCommand();

        m_canvas->CallEndMouseCapture( aDC );

        block->SetState( state );
        block->SetCommand( command );
        m_canvas->SetMouseCapture( DrawAndSizingBlockOutlines, AbortBlockCurrentCommand );
        SetCrossHairPosition( block->GetEnd() );

        if( block->GetCommand() != BLOCK_ABORT )
            m_canvas->MoveCursorToCrossHair();
    }

    if( m_canvas->IsMouseCaptured() )
    {
        switch( block->GetCommand() )
        {
        case BLOCK_IDLE:
            DisplayError( this, wxT( "Error in HandleBlockPLace()" ) );
            break;

        case BLOCK_ROTATE:
            GetScreen()->UpdatePickList();
            DrawAndSizingBlockOutlines( m_canvas, aDC, wxDefaultPosition, false );

            if( block->GetCount() )
            {
                // Compute the rotation center and put it on grid:
                wxPoint rotationPoint = block->Centre();
                rotationPoint = GetNearestGridPosition( rotationPoint );
                SetCrossHairPosition( rotationPoint );
                SaveCopyInUndoList( block->GetItems(), UR_ROTATED, false, rotationPoint );
                RotateListOfItems( block->GetItems(), rotationPoint );
                CheckListConnections( block->GetItems(), true );
                SchematicCleanUp( true );
                OnModify();
            }

            block->ClearItemsList();
            GetScreen()->TestDanglingEnds();
            m_canvas->Refresh();
            break;

        case BLOCK_DRAG:
        case BLOCK_DRAG_ITEM:   // Drag from a drag command
        case BLOCK_MOVE:
        case BLOCK_DUPLICATE:
            if( block->GetCommand() == BLOCK_DRAG_ITEM &&
                GetScreen()->GetCurItem() != NULL )
            {
                // This is a drag command, not a mouse block command
                // Only this item is put in list
                ITEM_PICKER picker;
                picker.SetItem( GetScreen()->GetCurItem() );
                block->PushItem( picker );
            }
            else
            {
                // Collect all items in the locate block
                GetScreen()->UpdatePickList();
            }
            // fall through

        case BLOCK_PRESELECT_MOVE: /* Move with preselection list*/
            if( block->GetCount() )
            {
                nextcmd = true;
                GetScreen()->SelectBlockItems();
                if( block->GetCommand() != BLOCK_DUPLICATE )
                    block->SetFlags( IS_MOVED );

                m_canvas->CallMouseCapture( aDC, wxDefaultPosition, false );
                m_canvas->SetMouseCaptureCallback( DrawMovingBlockOutlines );
                m_canvas->CallMouseCapture( aDC, wxDefaultPosition, false );
                block->SetState( STATE_BLOCK_MOVE );
            }
            else
            {
                m_canvas->CallMouseCapture( aDC, wxDefaultPosition, false );
                m_canvas->SetMouseCapture( NULL, NULL );
            }
            break;

        case BLOCK_CUT:
        case BLOCK_DELETE:
            GetScreen()->UpdatePickList();
            DrawAndSizingBlockOutlines( m_canvas, aDC, wxDefaultPosition, false );

            // The CUT variant needs to copy the items from their originial position
            if( ( block->GetCommand() == BLOCK_CUT ) && block->GetCount() )
            {
                wxPoint move_vector = -GetScreen()->m_BlockLocate.GetLastCursorPosition();
                copyBlockItems( block->GetItems() );
                MoveItemsInList( m_blockItems.GetItems(), move_vector );
            }

            // We set this in a while loop to catch any newly created items
            // as a result of the delete (e.g. merged wires)
            while( block->GetCount() )
            {
                DeleteItemsInList( block->GetItems(), append );
                SchematicCleanUp( true );
                OnModify();
                block->ClearItemsList();
                GetScreen()->UpdatePickList();
                append = true;
            }

            GetScreen()->TestDanglingEnds();
            m_canvas->Refresh();
            break;

        case BLOCK_COPY:    // Save a copy of items in paste buffer
            GetScreen()->UpdatePickList();
            DrawAndSizingBlockOutlines( m_canvas, aDC, wxDefaultPosition, false );

            if( block->GetCount() )
            {
                wxPoint move_vector = -GetScreen()->m_BlockLocate.GetLastCursorPosition();
                copyBlockItems( block->GetItems() );
                MoveItemsInList( m_blockItems.GetItems(), move_vector );
            }

            block->ClearItemsList();
            break;

        case BLOCK_PASTE:
            block->SetState( STATE_BLOCK_MOVE );
            break;

        case BLOCK_ZOOM:
            zoom_command = true;
            break;

        case BLOCK_MIRROR_X:
            GetScreen()->UpdatePickList();
            DrawAndSizingBlockOutlines( m_canvas, aDC, wxDefaultPosition, false );

            if( block->GetCount() )
            {
                // Compute the mirror center and put it on grid.
                wxPoint mirrorPoint = block->Centre();
                mirrorPoint = GetNearestGridPosition( mirrorPoint );
                SetCrossHairPosition( mirrorPoint );
                SaveCopyInUndoList( block->GetItems(), UR_MIRRORED_X, false, mirrorPoint );
                MirrorX( block->GetItems(), mirrorPoint );
                SchematicCleanUp( true );
                OnModify();
            }

            block->ClearItemsList();
            GetScreen()->TestDanglingEnds();
            m_canvas->Refresh();
            break;

        case BLOCK_MIRROR_Y:
            GetScreen()->UpdatePickList();
            DrawAndSizingBlockOutlines( m_canvas, aDC, wxDefaultPosition, false );

            if( block->GetCount() )
            {
                // Compute the mirror center and put it on grid.
                wxPoint mirrorPoint = block->Centre();
                mirrorPoint = GetNearestGridPosition( mirrorPoint );
                SetCrossHairPosition( mirrorPoint );
                SaveCopyInUndoList( block->GetItems(), UR_MIRRORED_Y, false, mirrorPoint );
                MirrorY( block->GetItems(), mirrorPoint );
                SchematicCleanUp( true );
                OnModify();
            }

            block->ClearItemsList();
            GetScreen()->TestDanglingEnds();
            m_canvas->Refresh();
            break;

        default:
            break;
        }
    }

    if( block->GetCommand() == BLOCK_ABORT )
    {
        GetScreen()->ClearDrawingState();
        m_canvas->Refresh();
    }

    if( ! nextcmd )
    {
        block->SetState( STATE_NO_BLOCK );
        block->SetCommand( BLOCK_IDLE );
        GetScreen()->SetCurItem( NULL );
        m_canvas->EndMouseCapture( GetToolId(), m_canvas->GetCurrentCursor(), wxEmptyString,
                                   false );
    }

    if( zoom_command )
        Window_Zoom( GetScreen()->m_BlockLocate );

    return nextcmd;
}


/* Traces the outline of the search block structures
 * The entire block follows the cursor
 */
static void DrawMovingBlockOutlines( EDA_DRAW_PANEL* aPanel, wxDC* aDC, const wxPoint& aPosition,
                                     bool aErase )
{
    BASE_SCREEN*    screen = aPanel->GetScreen();
    BLOCK_SELECTOR* block = &screen->m_BlockLocate;
    SCH_ITEM*       schitem;

    /* Erase old block contents. */
    if( aErase )
    {
        block->Draw( aPanel, aDC, block->GetMoveVector(), g_XorMode, block->GetColor() );

        for( unsigned ii = 0; ii < block->GetCount(); ii++ )
        {
            schitem = (SCH_ITEM*) block->GetItem( ii );

            if( schitem->Type() == SCH_COMPONENT_T )
                ((SCH_COMPONENT*)schitem)->Draw( aPanel, aDC, block->GetMoveVector(),
                                                 g_XorMode, g_GhostColor, false );
            else
                schitem->Draw( aPanel, aDC, block->GetMoveVector(), g_XorMode, g_GhostColor );
        }
    }

    /* Repaint new view. */
    block->SetMoveVector( aPanel->GetParent()->GetCrossHairPosition() - block->GetLastCursorPosition() );
    block->Draw( aPanel, aDC, block->GetMoveVector(), g_XorMode, block->GetColor() );

    for( unsigned ii = 0; ii < block->GetCount(); ii++ )
    {
        schitem = (SCH_ITEM*) block->GetItem( ii );

            if( schitem->Type() == SCH_COMPONENT_T )
                ((SCH_COMPONENT*)schitem)->Draw( aPanel, aDC, block->GetMoveVector(),
                                                 g_XorMode, g_GhostColor, false );
            else
                schitem->Draw( aPanel, aDC, block->GetMoveVector(), g_XorMode, g_GhostColor );
    }
}


void SCH_EDIT_FRAME::copyBlockItems( PICKED_ITEMS_LIST& aItemsList )
{
    m_blockItems.ClearListAndDeleteItems();   // delete previous saved list, if exists

    for( unsigned ii = 0; ii < aItemsList.GetCount(); ii++ )
    {
        // Clear m_Flag member of selected items:
        aItemsList.GetPickedItem( ii )->ClearFlags();

        /* Make a copy of the original picked item. */
        SCH_ITEM* copy = DuplicateStruct( (SCH_ITEM*) aItemsList.GetPickedItem( ii ) );
        copy->SetParent( NULL );
        copy->SetFlags( copy->GetFlags() | UR_TRANSIENT );
        ITEM_PICKER item( copy, UR_NEW );

        m_blockItems.PushItem( item );
    }
}


void SCH_EDIT_FRAME::PasteListOfItems( wxDC* DC )
{
    unsigned       i;
    SCH_ITEM*      item;
    SCH_SHEET_LIST hierarchy( g_RootSheet );    // This is the entire schematic hierarcy.

    if( m_blockItems.GetCount() == 0 )
    {
        DisplayError( this, _( "No item to paste." ) );
        return;
    }

    wxFileName destFn = m_CurrentSheet->Last()->GetFileName();

    if( destFn.IsRelative() )
        destFn.MakeAbsolute( Prj().GetProjectPath() );

    // Make sure any sheets in the block to be pasted will not cause recursion in
    // the destination sheet.
    for( i = 0; i < m_blockItems.GetCount(); i++ )
    {
        item = (SCH_ITEM*) m_blockItems.GetItem( i );

        if( item->Type() == SCH_SHEET_T )
        {
            SCH_SHEET* sheet = (SCH_SHEET*)item;
            wxFileName srcFn = sheet->GetFileName();

            if( srcFn.IsRelative() )
                srcFn.MakeAbsolute( Prj().GetProjectPath() );

            SCH_SHEET_LIST sheetHierarchy( sheet );

            if( hierarchy.TestForRecursion( sheetHierarchy,
                                            destFn.GetFullPath( wxPATH_UNIX ) ) )
            {
                wxString msg;

                msg.Printf( _( "The sheet changes cannot be made because the destination "
                               "sheet already has the sheet \"%s\" or one of it's subsheets "
                               "as a parent somewhere in the schematic hierarchy." ),
                            GetChars( sheet->GetFileName() ) );
                DisplayError( this, msg );
                return;
            }

            // Duplicate sheet names and sheet time stamps are not valid.  Use a time stamp
            // based sheet name and update the time stamp for each sheet in the block.
            timestamp_t timeStamp = GetNewTimeStamp();

            sheet->SetName( wxString::Format( wxT( "sheet%8.8lX" ), (unsigned long)timeStamp ) );
            sheet->SetTimeStamp( timeStamp );
        }
    }

    PICKED_ITEMS_LIST picklist;

    for( i = 0; i < m_blockItems.GetCount(); i++ )
    {
        item = DuplicateStruct( (SCH_ITEM*) m_blockItems.GetItem( i ) );

        // Creates data, and push it as new data in undo item list buffer
        ITEM_PICKER picker( item, UR_NEW );
        picklist.PushItem( picker );

        // Clear annotation and init new time stamp for the new components and sheets:
        if( item->Type() == SCH_COMPONENT_T )
        {
            ( (SCH_COMPONENT*) item )->SetTimeStamp( GetNewTimeStamp() );
            ( (SCH_COMPONENT*) item )->ClearAnnotation( NULL );
        }
        else if( item->Type() == SCH_SHEET_T )
        {
            ( (SCH_SHEET*) item )->SetTimeStamp( GetNewTimeStamp() );
        }

        SetSchItemParent( item, GetScreen() );
        item->Draw( m_canvas, DC, wxPoint( 0, 0 ), GR_DEFAULT_DRAWMODE );
        GetScreen()->Append( item );
    }

    SaveCopyInUndoList( picklist, UR_NEW );

    MoveItemsInList( picklist, GetScreen()->m_BlockLocate.GetMoveVector() );

    // Clear flags for all items.
    GetScreen()->ClearDrawingState();

    OnModify();

    return;
}
