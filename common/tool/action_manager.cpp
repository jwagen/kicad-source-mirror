/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2013 CERN
 * @author Maciej Suminski <maciej.suminski@cern.ch>
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

#include <tool/action_manager.h>
#include <tool/tool_manager.h>
#include <tool/tool_action.h>
#include <draw_frame.h>

#include <hotkeys_basic.h>
#include <cctype>
#include <cassert>
#include <vector>

ACTION_MANAGER::ACTION_MANAGER( TOOL_MANAGER* aToolManager ) :
    m_toolMgr( aToolManager )
{
    // Register known actions
    std::list<TOOL_ACTION*>& actionList = GetActionList();

    for( TOOL_ACTION* action : actionList )
    {
        if( action->m_id == -1 )
            action->m_id = MakeActionId( action->m_name );

        RegisterAction( new TOOL_ACTION( *action ) );
    }
}


ACTION_MANAGER::~ACTION_MANAGER()
{
    while( !m_actionNameIndex.empty() )
    {
        TOOL_ACTION* action = m_actionNameIndex.begin()->second;
        UnregisterAction( action );
        delete action;
    }
}


void ACTION_MANAGER::RegisterAction( TOOL_ACTION* aAction )
{
    // TOOL_ACTIONs are supposed to be named [appName.]toolName.actionName (with dots between)
    // action name without specifying at least toolName is not valid
    assert( aAction->GetName().find( '.', 0 ) != std::string::npos );

    // TOOL_ACTIONs must have unique names & ids
    assert( m_actionNameIndex.find( aAction->m_name ) == m_actionNameIndex.end() );

    m_actionNameIndex[aAction->m_name] = aAction;
}


void ACTION_MANAGER::UnregisterAction( TOOL_ACTION* aAction )
{
    m_actionNameIndex.erase( aAction->m_name );
    std::vector<int> hotkey = GetHotKey( *aAction );

    if( hotkey.size() > 0 && hotkey[0] )
    {
        std::list<TOOL_ACTION*>& actions = m_actionHotKeys[hotkey];
        std::list<TOOL_ACTION*>::iterator action = std::find( actions.begin(), actions.end(), aAction );

        if( action != actions.end() )
            actions.erase( action );
        else
            assert( false );
    }
}


int ACTION_MANAGER::MakeActionId( const std::string& aActionName )
{
    static int currentActionId = 1;

    return currentActionId++;
}


TOOL_ACTION* ACTION_MANAGER::FindAction( const std::string& aActionName ) const
{
    std::map<std::string, TOOL_ACTION*>::const_iterator it = m_actionNameIndex.find( aActionName );

    if( it != m_actionNameIndex.end() )
        return it->second;

    return NULL;
}


bool ACTION_MANAGER::RunHotKey( int aHotKey ) const
{
    //Do stuff to match sequences
    int key = aHotKey & ~MD_MODIFIER_MASK;
    int mod = aHotKey & MD_MODIFIER_MASK;

    int hotKeysMatched = 1;

    if( key >= 'a' && key <= 'z' )
        key = std::toupper( key );

    HOTKEY_LIST::const_iterator it = m_actionHotKeys.find( {key | mod });
    //HOTKEY_LIST matchedHotKeysbb

    // If no luck, try without Shift, to handle keys that require it
    // e.g. to get ? you need to press Shift+/ without US keyboard layout
    // Hardcoding ? as Shift+/ is a bad idea, as on another layout you may need to press a
    // different combination
    if( it == m_actionHotKeys.end() )
    {
        it = m_actionHotKeys.find( {key | ( mod & ~MD_SHIFT )} );

        if( it == m_actionHotKeys.end() )
            return false; // no appropriate action found for the hotkey
    }







    //Only one unique hotkey sequence found, may be related to multple actions depending of context
    if( hotKeysMatched == 1 )
    {

        const std::list<TOOL_ACTION*>& actions = it->second;

        // Choose the action that has the highest priority on the active tools stack
        // If there is none, run the global action associated with the hot key
        int highestPriority = -1, priority = -1;
        const TOOL_ACTION* context = NULL;  // pointer to context action of the highest priority tool
        const TOOL_ACTION* global = NULL;   // pointer to global action, if there is no context action

        for( const TOOL_ACTION* action : actions )
        {
            if( action->GetScope() == AS_GLOBAL )
            {
                // Store the global action for the hot key in case there was no possible
                // context actions to run
                assert( global == NULL );       // there should be only one global action per hot key
                global = action;
                continue;
            }

            TOOL_BASE* tool = m_toolMgr->FindTool( action->GetToolName() );

            if( tool )
            {
                // Choose the action that goes to the tool with highest priority
                // (i.e. is on the top of active tools stack)
                priority = m_toolMgr->GetPriority( tool->GetId() );

                if( priority >= 0 && priority > highestPriority )
                {
                    highestPriority = priority;
                    context = action;
                }
            }
        }

        if( context )
        {
            m_toolMgr->RunAction( *context, true );
            return true;
        }
        else if( global )
        {
            m_toolMgr->RunAction( *global, true );
            return true;
        }
    }
    //Clear hotkey sequence if no matches is found
    else if( hotKeysMatched == 0 )
    {
        m_collectedHotKeySequence.clear();
        return false;
    }

    //Partial match
    return true;

}


std::vector<int> ACTION_MANAGER::GetHotKey( const TOOL_ACTION& aAction ) const
{
    std::map<int, std::vector<int>>::const_iterator it = m_hotkeys.find( aAction.GetId() );

    if( it == m_hotkeys.end() )
        return {};

    return it->second;
}


void ACTION_MANAGER::UpdateHotKeys()
{
    m_actionHotKeys.clear();
    m_hotkeys.clear();

    for( const auto& actionName : m_actionNameIndex )
    {
        TOOL_ACTION* action = actionName.second;
        std::vector<int> hotkey = processHotKey( action );

        if( hotkey.size() > 0 && hotkey[0] )
        {
            m_actionHotKeys[hotkey].push_back( action );
            m_hotkeys[action->GetId()] = hotkey;
        }
    }

#ifdef DEBUG
    // Check if there are two global actions assigned to the same hotkey
    for( const auto& action_list : m_actionHotKeys )
    {
        int global_actions_cnt = 0;

        for( const TOOL_ACTION* action : action_list.second )
        {
            if( action->GetScope() == AS_GLOBAL )
                ++global_actions_cnt;
        }

        assert( global_actions_cnt <= 1 );
    }
#endif /* not NDEBUG */
}


std::vector<int> ACTION_MANAGER::processHotKey( TOOL_ACTION* aAction )
{
    std::vector<int> hotkey = aAction->getDefaultHotKey();

    if( hotkey.size() == 1 && ( hotkey[0] & TOOL_ACTION::LEGACY_HK ))
    {
        hotkey[0] = hotkey[0] & ~TOOL_ACTION::LEGACY_HK;  // it leaves only HK_xxx identifier

        auto frame = dynamic_cast<EDA_DRAW_FRAME*>( m_toolMgr->GetEditFrame() );
        EDA_HOTKEY* hk_desc = nullptr;

        if( frame )
            hk_desc = frame->GetHotKeyDescription( hotkey[0] );

        if( hk_desc )
        {
            hotkey[0] = hk_desc->m_KeyCode;

            // Convert modifiers to the ones used by the Tool Framework
            if( hotkey[0] & GR_KB_CTRL )
            {
                hotkey[0] &= ~GR_KB_CTRL;
                hotkey[0] |= MD_CTRL;
            }

            if( hotkey[0] & GR_KB_ALT )
            {
                hotkey[0] &= ~GR_KB_ALT;
                hotkey[0] |= MD_ALT;
            }

            if( hotkey[0] & GR_KB_SHIFT )
            {
                hotkey[0] &= ~GR_KB_SHIFT;
                hotkey[0] |= MD_SHIFT;
            }
        }
        else
        {
            hotkey = {};
        }
    }

    return hotkey;
}
