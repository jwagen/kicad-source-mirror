///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Aug  4 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "pcb_layer_box_selector.h"
#include "widgets/text_ctrl_eval.h"

#include "dialog_graphic_item_properties_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bUpperSizer;
	bUpperSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_fgUpperLeftGridSizer = new wxFlexGridSizer( 4, 3, 0, 0 );
	m_fgUpperLeftGridSizer->AddGrowableCol( 1 );
	m_fgUpperLeftGridSizer->SetFlexibleDirection( wxBOTH );
	m_fgUpperLeftGridSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_StartPointXLabel = new wxStaticText( this, wxID_ANY, _("Start point X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StartPointXLabel->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_StartPointXLabel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_Center_StartXCtrl = new TEXT_CTRL_EVAL( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_fgUpperLeftGridSizer->Add( m_Center_StartXCtrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	m_StartPointXUnit = new wxStaticText( this, wxID_ANY, _("Unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StartPointXUnit->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_StartPointXUnit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_StartPointYLabel = new wxStaticText( this, wxID_ANY, _("Start point Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StartPointYLabel->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_StartPointYLabel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_Center_StartYCtrl = new TEXT_CTRL_EVAL( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_fgUpperLeftGridSizer->Add( m_Center_StartYCtrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	m_StartPointYUnit = new wxStaticText( this, wxID_ANY, _("Unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StartPointYUnit->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_StartPointYUnit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_EndPointXLabel = new wxStaticText( this, wxID_ANY, _("End point X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_EndPointXLabel->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_EndPointXLabel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_EndX_Radius_Ctrl = new TEXT_CTRL_EVAL( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_fgUpperLeftGridSizer->Add( m_EndX_Radius_Ctrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	m_EndPointXUnit = new wxStaticText( this, wxID_ANY, _("Unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_EndPointXUnit->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_EndPointXUnit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_EndPointYLabel = new wxStaticText( this, wxID_ANY, _("End point Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_EndPointYLabel->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_EndPointYLabel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_EndY_Ctrl = new TEXT_CTRL_EVAL( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_fgUpperLeftGridSizer->Add( m_EndY_Ctrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	m_EndPointYUnit = new wxStaticText( this, wxID_ANY, _("Unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_EndPointYUnit->Wrap( -1 );
	m_fgUpperLeftGridSizer->Add( m_EndPointYUnit, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxRIGHT|wxTOP, 5 );
	
	
	bUpperSizer->Add( m_fgUpperLeftGridSizer, 0, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bUpperSizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bUpperRightSizer;
	bUpperRightSizer = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgUpperRightGridSizer;
	fgUpperRightGridSizer = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgUpperRightGridSizer->AddGrowableCol( 1 );
	fgUpperRightGridSizer->SetFlexibleDirection( wxBOTH );
	fgUpperRightGridSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_AngleText = new wxStaticText( this, wxID_ANY, _("Arc angle:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AngleText->Wrap( -1 );
	fgUpperRightGridSizer->Add( m_AngleText, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_AngleCtrl = new TEXT_CTRL_EVAL( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgUpperRightGridSizer->Add( m_AngleCtrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	m_AngleUnit = new wxStaticText( this, wxID_ANY, _("degrees"), wxDefaultPosition, wxDefaultSize, 0 );
	m_AngleUnit->Wrap( -1 );
	fgUpperRightGridSizer->Add( m_AngleUnit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_ThicknessLabel = new wxStaticText( this, wxID_ANY, _("Item thickness:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ThicknessLabel->Wrap( -1 );
	fgUpperRightGridSizer->Add( m_ThicknessLabel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_ThicknessCtrl = new TEXT_CTRL_EVAL( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgUpperRightGridSizer->Add( m_ThicknessCtrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	m_ThicknessTextUnit = new wxStaticText( this, wxID_ANY, _("Unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ThicknessTextUnit->Wrap( -1 );
	fgUpperRightGridSizer->Add( m_ThicknessTextUnit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_DefaultThicknessLabel = new wxStaticText( this, wxID_ANY, _("Default thickness:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DefaultThicknessLabel->Wrap( -1 );
	fgUpperRightGridSizer->Add( m_DefaultThicknessLabel, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	m_DefaultThicknessCtrl = new TEXT_CTRL_EVAL( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgUpperRightGridSizer->Add( m_DefaultThicknessCtrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	m_DefaulThicknessTextUnit = new wxStaticText( this, wxID_ANY, _("Unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_DefaulThicknessTextUnit->Wrap( -1 );
	fgUpperRightGridSizer->Add( m_DefaulThicknessTextUnit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_LayerLabel = new wxStaticText( this, wxID_ANY, _("Layer:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerLabel->Wrap( -1 );
	fgUpperRightGridSizer->Add( m_LayerLabel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_LayerSelectionCtrl = new PCB_LAYER_BOX_SELECTOR( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgUpperRightGridSizer->Add( m_LayerSelectionCtrl, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	
	fgUpperRightGridSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bUpperRightSizer->Add( fgUpperRightGridSizer, 0, wxEXPAND, 5 );
	
	
	bUpperSizer->Add( bUpperRightSizer, 0, wxEXPAND, 5 );
	
	
	bMainSizer->Add( bUpperSizer, 1, wxALL|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bMainSizer->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_StandardButtonsSizer = new wxStdDialogButtonSizer();
	m_StandardButtonsSizerOK = new wxButton( this, wxID_OK );
	m_StandardButtonsSizer->AddButton( m_StandardButtonsSizerOK );
	m_StandardButtonsSizerCancel = new wxButton( this, wxID_CANCEL );
	m_StandardButtonsSizer->AddButton( m_StandardButtonsSizerCancel );
	m_StandardButtonsSizer->Realize();
	
	bMainSizer->Add( m_StandardButtonsSizer, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	this->SetSizer( bMainSizer );
	this->Layout();
	bMainSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnInitDlg ) );
}

DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::~DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnInitDlg ) );
	
}
