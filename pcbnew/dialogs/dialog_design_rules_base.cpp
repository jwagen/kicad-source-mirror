///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan  2 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialog_design_rules_aux_helper_class.h"

#include "dialog_design_rules_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_DESIGN_RULES_BASE::DIALOG_DESIGN_RULES_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_DRnotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP );
	m_panelNetClassesEditor = new wxPanel( m_DRnotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bpanelNetClassesSizer;
	bpanelNetClassesSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizerUpper;
	sbSizerUpper = new wxStaticBoxSizer( new wxStaticBox( m_panelNetClassesEditor, wxID_ANY, _("Net Classes") ), wxVERTICAL );
	
	m_grid = new wxGrid( m_panelNetClassesEditor, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxSUNKEN_BORDER|wxTAB_TRAVERSAL|wxVSCROLL );
	
	// Grid
	m_grid->CreateGrid( 1, 8 );
	m_grid->EnableEditing( true );
	m_grid->EnableGridLines( true );
	m_grid->EnableDragGridSize( false );
	m_grid->SetMargins( 0, 0 );
	
	// Columns
	m_grid->SetColSize( 0, 100 );
	m_grid->SetColSize( 1, 120 );
	m_grid->SetColSize( 2, 84 );
	m_grid->SetColSize( 3, 85 );
	m_grid->SetColSize( 4, 81 );
	m_grid->SetColSize( 5, 90 );
	m_grid->EnableDragColMove( false );
	m_grid->EnableDragColSize( true );
	m_grid->SetColLabelSize( 40 );
	m_grid->SetColLabelValue( 0, _("Clearance") );
	m_grid->SetColLabelValue( 1, _("Track Width") );
	m_grid->SetColLabelValue( 2, _("Via Dia") );
	m_grid->SetColLabelValue( 3, _("Via Drill") );
	m_grid->SetColLabelValue( 4, _("uVia Dia") );
	m_grid->SetColLabelValue( 5, _("uVia Drill") );
	m_grid->SetColLabelValue( 6, _("Diff Pair Width") );
	m_grid->SetColLabelValue( 7, _("Diff Pair Gap") );
	m_grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid->EnableDragRowSize( false );
	m_grid->SetRowLabelSize( 120 );
	m_grid->SetRowLabelValue( 0, _("Default") );
	m_grid->SetRowLabelAlignment( wxALIGN_LEFT, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_grid->SetToolTip( _("Net Class parameters") );
	
	sbSizerUpper->Add( m_grid, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* buttonBoxSizer;
	buttonBoxSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_addButton = new wxButton( m_panelNetClassesEditor, wxID_ADD_NETCLASS, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	m_addButton->SetToolTip( _("Add another Net Class") );
	
	buttonBoxSizer->Add( m_addButton, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_removeButton = new wxButton( m_panelNetClassesEditor, wxID_REMOVE_NETCLASS, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	m_removeButton->SetToolTip( _("Remove the currently select Net Class\nThe default Net Class cannot be removed") );
	
	buttonBoxSizer->Add( m_removeButton, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	m_moveUpButton = new wxButton( m_panelNetClassesEditor, wxID_ANY, _("Move Up"), wxDefaultPosition, wxDefaultSize, 0 );
	m_moveUpButton->SetToolTip( _("Move the currently selected Net Class up one row") );
	
	buttonBoxSizer->Add( m_moveUpButton, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );
	
	
	sbSizerUpper->Add( buttonBoxSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	bpanelNetClassesSizer->Add( sbSizerUpper, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	wxStaticBoxSizer* sbSizerNetSelectMain;
	sbSizerNetSelectMain = new wxStaticBoxSizer( new wxStaticBox( m_panelNetClassesEditor, wxID_ANY, _("Net Class Membership") ), wxHORIZONTAL );
	
	wxBoxSizer* leftNetSelectBoxSizer;
	leftNetSelectBoxSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_leftClassChoice = new wxComboBox( m_panelNetClassesEditor, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	bSizer10->Add( m_leftClassChoice, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticline21 = new wxStaticLine( m_panelNetClassesEditor, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer10->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );
	
	m_buttonLeftSelAll = new wxButton( m_panelNetClassesEditor, wxID_ANY, _("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonLeftSelAll->SetToolTip( _("Select all nets in the left list") );
	
	bSizer10->Add( m_buttonLeftSelAll, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	leftNetSelectBoxSizer->Add( bSizer10, 0, wxEXPAND, 5 );
	
	m_leftListCtrl = new NETS_LIST_CTRL( m_panelNetClassesEditor, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES|wxSUNKEN_BORDER );
	leftNetSelectBoxSizer->Add( m_leftListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizerNetSelectMain->Add( leftNetSelectBoxSizer, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bmiddleSizerNetSelect;
	bmiddleSizerNetSelect = new wxBoxSizer( wxVERTICAL );
	
	m_buttonRightToLeft = new wxButton( m_panelNetClassesEditor, ID_LEFT_TO_RIGHT_COPY, _("<<<"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonRightToLeft->SetToolTip( _("Move the selected nets in the right list to the left list") );
	
	bmiddleSizerNetSelect->Add( m_buttonRightToLeft, 0, wxALL, 5 );
	
	m_buttonLeftToRight = new wxButton( m_panelNetClassesEditor, ID_RIGHT_TO_LEFT_COPY, _(">>>"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonLeftToRight->SetToolTip( _("Move the selected nets in the left list to the right list") );
	
	bmiddleSizerNetSelect->Add( m_buttonLeftToRight, 0, wxALL, 5 );
	
	
	sbSizerNetSelectMain->Add( bmiddleSizerNetSelect, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* rghtNetSelectBoxSizer;
	rghtNetSelectBoxSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rightClassChoice = new wxComboBox( m_panelNetClassesEditor, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	bSizer11->Add( m_rightClassChoice, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticline3 = new wxStaticLine( m_panelNetClassesEditor, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer11->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	m_buttonRightSelAll = new wxButton( m_panelNetClassesEditor, wxID_ANY, _("Select All"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonRightSelAll->SetToolTip( _("Select all nets in the right list") );
	
	bSizer11->Add( m_buttonRightSelAll, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	rghtNetSelectBoxSizer->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_rightListCtrl = new NETS_LIST_CTRL( m_panelNetClassesEditor, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VIRTUAL|wxLC_VRULES|wxSUNKEN_BORDER );
	rghtNetSelectBoxSizer->Add( m_rightListCtrl, 1, wxALL|wxEXPAND, 5 );
	
	
	sbSizerNetSelectMain->Add( rghtNetSelectBoxSizer, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	
	bpanelNetClassesSizer->Add( sbSizerNetSelectMain, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panelNetClassesEditor->SetSizer( bpanelNetClassesSizer );
	m_panelNetClassesEditor->Layout();
	bpanelNetClassesSizer->Fit( m_panelNetClassesEditor );
	m_DRnotebook->AddPage( m_panelNetClassesEditor, _("Net Classes Editor"), true );
	m_panelGolbalDesignRules = new wxPanel( m_DRnotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bpanelGlobRulesSizer;
	bpanelGlobRulesSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bDesignRulesUpperSizer;
	bDesignRulesUpperSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbViasOptionSizer;
	sbViasOptionSizer = new wxStaticBoxSizer( new wxStaticBox( m_panelGolbalDesignRules, wxID_ANY, _("Routing Options") ), wxVERTICAL );
	
	wxFlexGridSizer* fgViaOptionsSize;
	fgViaOptionsSize = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgViaOptionsSize->AddGrowableCol( 1 );
	fgViaOptionsSize->SetFlexibleDirection( wxBOTH );
	fgViaOptionsSize->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_TrackMinWidthTitle = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("Minimum track width"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_TrackMinWidthTitle->Wrap( -1 );
	fgViaOptionsSize->Add( m_TrackMinWidthTitle, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SetTrackMinWidthCtrl = new wxTextCtrl( m_panelGolbalDesignRules, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgViaOptionsSize->Add( m_SetTrackMinWidthCtrl, 0, wxALIGN_LEFT|wxALIGN_TOP|wxALL|wxEXPAND, 5 );
	
	m_TrackMinWidthUnits = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_TrackMinWidthUnits->Wrap( -1 );
	fgViaOptionsSize->Add( m_TrackMinWidthUnits, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );
	
	m_ViaMinTitle = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("Minimum via diameter"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_ViaMinTitle->Wrap( -1 );
	fgViaOptionsSize->Add( m_ViaMinTitle, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SetViasMinSizeCtrl = new wxTextCtrl( m_panelGolbalDesignRules, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgViaOptionsSize->Add( m_SetViasMinSizeCtrl, 0, wxALL|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_ViaMinUnits = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_ViaMinUnits->Wrap( -1 );
	fgViaOptionsSize->Add( m_ViaMinUnits, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );
	
	m_ViaMinDrillTitle = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("Minimum via drill"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_ViaMinDrillTitle->Wrap( -1 );
	fgViaOptionsSize->Add( m_ViaMinDrillTitle, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SetViasMinDrillCtrl = new wxTextCtrl( m_panelGolbalDesignRules, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgViaOptionsSize->Add( m_SetViasMinDrillCtrl, 0, wxALL|wxEXPAND, 5 );
	
	m_ViaMinDrillUnits = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_ViaMinDrillUnits->Wrap( -1 );
	fgViaOptionsSize->Add( m_ViaMinDrillUnits, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );
	
	
	fgViaOptionsSize->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_OptAllowBlindBuriedVias = new wxCheckBox( m_panelGolbalDesignRules, wxID_ANY, _("Allow blind/buried vias"), wxDefaultPosition, wxDefaultSize, 0 );
	fgViaOptionsSize->Add( m_OptAllowBlindBuriedVias, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	fgViaOptionsSize->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgViaOptionsSize->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_OptAllowMicroVias = new wxCheckBox( m_panelGolbalDesignRules, wxID_ANY, _("Allow micro vias (uVias)"), wxDefaultPosition, wxDefaultSize, 0 );
	fgViaOptionsSize->Add( m_OptAllowMicroVias, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	fgViaOptionsSize->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_MicroViaMinSizeTitle = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("Minimum uVia diameter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MicroViaMinSizeTitle->Wrap( -1 );
	fgViaOptionsSize->Add( m_MicroViaMinSizeTitle, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_SetMicroViasMinSizeCtrl = new wxTextCtrl( m_panelGolbalDesignRules, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_SetMicroViasMinSizeCtrl->Enable( false );
	
	fgViaOptionsSize->Add( m_SetMicroViasMinSizeCtrl, 0, wxALL|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	m_MicroViaMinSizeUnits = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_MicroViaMinSizeUnits->Wrap( -1 );
	fgViaOptionsSize->Add( m_MicroViaMinSizeUnits, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );
	
	m_MicroViaMinDrillTitle = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("Minimum uVia drill"), wxDefaultPosition, wxDefaultSize, 0 );
	m_MicroViaMinDrillTitle->Wrap( -1 );
	fgViaOptionsSize->Add( m_MicroViaMinDrillTitle, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SetMicroViasMinDrillCtrl = new wxTextCtrl( m_panelGolbalDesignRules, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_SetMicroViasMinDrillCtrl->Enable( false );
	
	fgViaOptionsSize->Add( m_SetMicroViasMinDrillCtrl, 0, wxEXPAND|wxALL, 5 );
	
	m_MicroViaMinDrillUnits = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("mm"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_MicroViaMinDrillUnits->Wrap( -1 );
	fgViaOptionsSize->Add( m_MicroViaMinDrillUnits, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );
	
	
	sbViasOptionSizer->Add( fgViaOptionsSize, 1, wxEXPAND, 5 );
	
	
	bDesignRulesUpperSizer->Add( sbViasOptionSizer, 1, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	bpanelGlobRulesSizer->Add( bDesignRulesUpperSizer, 0, wxEXPAND, 5 );
	
	m_staticTextInfo = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("Specific via diameters and track widths, which can be used to replace default Netclass values on demand,\nfor arbitrary vias or track segments."), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticTextInfo->Wrap( -1 );
	bpanelGlobRulesSizer->Add( m_staticTextInfo, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bDesignRulesLowerSizer;
	bDesignRulesLowerSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sViaSizeBox;
	sViaSizeBox = new wxStaticBoxSizer( new wxStaticBox( m_panelGolbalDesignRules, wxID_ANY, _("Custom Via Sizes") ), wxVERTICAL );
	
	m_staticText7 = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, _("Drill value: a blank or 0 => default Netclass value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	sViaSizeBox->Add( m_staticText7, 0, wxALL, 5 );
	
	m_gridViaSizeList = new wxGrid( m_panelGolbalDesignRules, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridViaSizeList->CreateGrid( 8, 2 );
	m_gridViaSizeList->EnableEditing( true );
	m_gridViaSizeList->EnableGridLines( true );
	m_gridViaSizeList->EnableDragGridSize( false );
	m_gridViaSizeList->SetMargins( 0, 0 );
	
	// Columns
	m_gridViaSizeList->EnableDragColMove( false );
	m_gridViaSizeList->EnableDragColSize( true );
	m_gridViaSizeList->SetColLabelSize( 30 );
	m_gridViaSizeList->SetColLabelValue( 0, _("Diameter") );
	m_gridViaSizeList->SetColLabelValue( 1, _("Drill") );
	m_gridViaSizeList->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridViaSizeList->EnableDragRowSize( true );
	m_gridViaSizeList->SetRowLabelSize( 80 );
	m_gridViaSizeList->SetRowLabelValue( 0, _("Via 1") );
	m_gridViaSizeList->SetRowLabelValue( 1, _("Via 2") );
	m_gridViaSizeList->SetRowLabelValue( 2, _("Via 3") );
	m_gridViaSizeList->SetRowLabelValue( 3, _("Via 4") );
	m_gridViaSizeList->SetRowLabelValue( 4, _("Via 5") );
	m_gridViaSizeList->SetRowLabelValue( 5, _("Via 6") );
	m_gridViaSizeList->SetRowLabelValue( 6, _("Via 7") );
	m_gridViaSizeList->SetRowLabelValue( 7, _("Via 8") );
	m_gridViaSizeList->SetRowLabelValue( 8, _("Via 9") );
	m_gridViaSizeList->SetRowLabelValue( 9, _("Via 10") );
	m_gridViaSizeList->SetRowLabelValue( 10, _("Via 11") );
	m_gridViaSizeList->SetRowLabelValue( 11, _("Via 12") );
	m_gridViaSizeList->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridViaSizeList->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sViaSizeBox->Add( m_gridViaSizeList, 1, wxALL|wxEXPAND, 5 );
	
	
	bDesignRulesLowerSizer->Add( sViaSizeBox, 1, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbTracksListSizer;
	sbTracksListSizer = new wxStaticBoxSizer( new wxStaticBox( m_panelGolbalDesignRules, wxID_ANY, _("Custom Track Widths") ), wxVERTICAL );
	
	m_staticText8 = new wxStaticText( m_panelGolbalDesignRules, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	sbTracksListSizer->Add( m_staticText8, 0, wxALL, 5 );
	
	m_gridTrackWidthList = new wxGrid( m_panelGolbalDesignRules, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gridTrackWidthList->CreateGrid( 8, 1 );
	m_gridTrackWidthList->EnableEditing( true );
	m_gridTrackWidthList->EnableGridLines( true );
	m_gridTrackWidthList->EnableDragGridSize( false );
	m_gridTrackWidthList->SetMargins( 0, 0 );
	
	// Columns
	m_gridTrackWidthList->EnableDragColMove( false );
	m_gridTrackWidthList->EnableDragColSize( true );
	m_gridTrackWidthList->SetColLabelSize( 30 );
	m_gridTrackWidthList->SetColLabelValue( 0, _("Width") );
	m_gridTrackWidthList->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gridTrackWidthList->EnableDragRowSize( true );
	m_gridTrackWidthList->SetRowLabelSize( 80 );
	m_gridTrackWidthList->SetRowLabelValue( 0, _("Track 1") );
	m_gridTrackWidthList->SetRowLabelValue( 1, _("Track 2") );
	m_gridTrackWidthList->SetRowLabelValue( 2, _("Track 3") );
	m_gridTrackWidthList->SetRowLabelValue( 3, _("Track 4") );
	m_gridTrackWidthList->SetRowLabelValue( 4, _("Track 5") );
	m_gridTrackWidthList->SetRowLabelValue( 5, _("Track 6") );
	m_gridTrackWidthList->SetRowLabelValue( 6, _("Track 7") );
	m_gridTrackWidthList->SetRowLabelValue( 7, _("Track 8") );
	m_gridTrackWidthList->SetRowLabelValue( 8, _("Track 9") );
	m_gridTrackWidthList->SetRowLabelValue( 9, _("Track 10") );
	m_gridTrackWidthList->SetRowLabelValue( 10, _("Track 11") );
	m_gridTrackWidthList->SetRowLabelValue( 11, _("Track 12") );
	m_gridTrackWidthList->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gridTrackWidthList->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sbTracksListSizer->Add( m_gridTrackWidthList, 1, wxALL|wxEXPAND, 5 );
	
	
	bDesignRulesLowerSizer->Add( sbTracksListSizer, 1, wxALL|wxEXPAND, 5 );
	
	
	bpanelGlobRulesSizer->Add( bDesignRulesLowerSizer, 0, wxEXPAND, 5 );
	
	
	m_panelGolbalDesignRules->SetSizer( bpanelGlobRulesSizer );
	m_panelGolbalDesignRules->Layout();
	bpanelGlobRulesSizer->Fit( m_panelGolbalDesignRules );
	m_DRnotebook->AddPage( m_panelGolbalDesignRules, _("Global Design Rules"), false );
	
	bMainSizer->Add( m_DRnotebook, 1, wxALL|wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bMainSizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	
	bMainSizer->Add( m_sdbSizer1, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bMainSizer );
	this->Layout();
	bMainSizer->Fit( this );
	
	// Connect Events
	m_DRnotebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( DIALOG_DESIGN_RULES_BASE::OnNotebookPageChanged ), NULL, this );
	m_grid->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( DIALOG_DESIGN_RULES_BASE::OnNetClassesNameLeftClick ), NULL, this );
	m_grid->Connect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( DIALOG_DESIGN_RULES_BASE::OnNetClassesNameRightClick ), NULL, this );
	m_addButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnAddNetclassClick ), NULL, this );
	m_removeButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRemoveNetclassClick ), NULL, this );
	m_moveUpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnMoveUpSelectedNetClass ), NULL, this );
	m_leftClassChoice->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnLeftCBSelection ), NULL, this );
	m_buttonLeftSelAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnLeftSelectAllButton ), NULL, this );
	m_buttonRightToLeft->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRightToLeftCopyButton ), NULL, this );
	m_buttonLeftToRight->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnLeftToRightCopyButton ), NULL, this );
	m_rightClassChoice->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRightCBSelection ), NULL, this );
	m_buttonRightSelAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRightSelectAllButton ), NULL, this );
	m_OptAllowMicroVias->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnAllowMicroVias ), NULL, this );
}

DIALOG_DESIGN_RULES_BASE::~DIALOG_DESIGN_RULES_BASE()
{
	// Disconnect Events
	m_DRnotebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( DIALOG_DESIGN_RULES_BASE::OnNotebookPageChanged ), NULL, this );
	m_grid->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( DIALOG_DESIGN_RULES_BASE::OnNetClassesNameLeftClick ), NULL, this );
	m_grid->Disconnect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( DIALOG_DESIGN_RULES_BASE::OnNetClassesNameRightClick ), NULL, this );
	m_addButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnAddNetclassClick ), NULL, this );
	m_removeButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRemoveNetclassClick ), NULL, this );
	m_moveUpButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnMoveUpSelectedNetClass ), NULL, this );
	m_leftClassChoice->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnLeftCBSelection ), NULL, this );
	m_buttonLeftSelAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnLeftSelectAllButton ), NULL, this );
	m_buttonRightToLeft->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRightToLeftCopyButton ), NULL, this );
	m_buttonLeftToRight->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnLeftToRightCopyButton ), NULL, this );
	m_rightClassChoice->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRightCBSelection ), NULL, this );
	m_buttonRightSelAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnRightSelectAllButton ), NULL, this );
	m_OptAllowMicroVias->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_DESIGN_RULES_BASE::OnAllowMicroVias ), NULL, this );
	
}
