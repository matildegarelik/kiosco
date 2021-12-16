///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Ventana2::Ventana2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Codigo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer6->Add( m_staticText4, 0, wxALL, 5 );

	m_codigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_codigo, 0, wxALL, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Cantidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer6->Add( m_staticText5, 0, wxALL, 5 );

	m_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_cantidad, 0, wxALL, 5 );

	m_btn_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_btn_agregar, 0, wxALL, 5 );


	bSizer5->Add( bSizer6, 0, 0, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 6 );
	m_grilla->EnableEditing( false );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 80 );
	m_grilla->SetColSize( 1, 80 );
	m_grilla->SetColSize( 2, 80 );
	m_grilla->SetColSize( 3, 80 );
	m_grilla->SetColSize( 4, 93 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Codigo") );
	m_grilla->SetColLabelValue( 1, wxT("Nombre") );
	m_grilla->SetColLabelValue( 2, wxT("Marca") );
	m_grilla->SetColLabelValue( 3, wxT("Cantidad") );
	m_grilla->SetColLabelValue( 4, wxT("Precio x Unidad") );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( 0 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer5->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("TOTAL: $"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer8->Add( m_staticText7, 0, wxALL, 5 );

	m_total = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_total, 0, wxALL, 5 );


	bSizer5->Add( bSizer8, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_fiar = new wxButton( this, wxID_ANY, wxT("Fiar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_btn_fiar, 0, wxALL, 5 );

	m_btn_pagar = new wxButton( this, wxID_ANY, wxT("Pagar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_btn_pagar, 0, wxALL, 5 );


	bSizer5->Add( bSizer7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_btn_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickAgregar ), NULL, this );
	m_btn_fiar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickVerFiar ), NULL, this );
}

Ventana2::~Ventana2()
{
	// Disconnect Events
	m_btn_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickAgregar ), NULL, this );
	m_btn_fiar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickVerFiar ), NULL, this );

}

BaseFiar::BaseFiar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Total: $"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer10->Add( m_staticText9, 0, wxALL, 5 );

	m_total = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_total, 0, wxALL, 5 );


	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Cliente: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer11->Add( m_staticText10, 0, wxALL, 5 );

	m_cliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_cliente, 0, wxALL, 5 );


	bSizer9->Add( bSizer11, 1, wxEXPAND, 5 );

	m_button8 = new wxButton( this, wxID_ANY, wxT("Fiar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();
	bSizer9->Fit( this );

	this->Centre( wxBOTH );
}

BaseFiar::~BaseFiar()
{
}

Ventana5::Ventana5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("FIADOS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer8->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_tabla_fiados = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_tabla_fiados->CreateGrid( 0, 4 );
	m_tabla_fiados->EnableEditing( false );
	m_tabla_fiados->EnableGridLines( true );
	m_tabla_fiados->EnableDragGridSize( false );
	m_tabla_fiados->SetMargins( 0, 0 );

	// Columns
	m_tabla_fiados->EnableDragColMove( false );
	m_tabla_fiados->EnableDragColSize( true );
	m_tabla_fiados->SetColLabelValue( 0, wxT("Cliente") );
	m_tabla_fiados->SetColLabelValue( 1, wxT("Fecha") );
	m_tabla_fiados->SetColLabelValue( 2, wxT("Total") );
	m_tabla_fiados->SetColLabelValue( 3, wxT("Pago?") );
	m_tabla_fiados->SetColLabelValue( 4, wxEmptyString );
	m_tabla_fiados->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_tabla_fiados->EnableDragRowSize( true );
	m_tabla_fiados->SetRowLabelSize( 0 );
	m_tabla_fiados->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_tabla_fiados->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer8->Add( m_tabla_fiados, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );
}

Ventana5::~Ventana5()
{
}

Ventana4::Ventana4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Ingreso stock"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer9->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Codigo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer10->Add( m_staticText8, 0, wxALL, 5 );

	m_textCtrl6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_textCtrl6, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Cantidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer10->Add( m_staticText9, 0, wxALL, 5 );

	m_textCtrl7 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_textCtrl7, 0, wxALL, 5 );

	m_button5 = new wxButton( this, wxID_ANY, wxT("Finalizar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_button5, 0, wxALL, 5 );


	bSizer9->Add( bSizer10, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Ultimos ingresos:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer9->Add( m_staticText10, 0, wxALL, 5 );

	m_grid4 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid4->CreateGrid( 0, 5 );
	m_grid4->EnableEditing( false );
	m_grid4->EnableGridLines( true );
	m_grid4->EnableDragGridSize( false );
	m_grid4->SetMargins( 0, 0 );

	// Columns
	m_grid4->SetColSize( 0, 80 );
	m_grid4->SetColSize( 1, 115 );
	m_grid4->SetColSize( 2, 114 );
	m_grid4->SetColSize( 3, 107 );
	m_grid4->SetColSize( 4, 64 );
	m_grid4->EnableDragColMove( false );
	m_grid4->EnableDragColSize( true );
	m_grid4->SetColLabelValue( 0, wxT("Fecha") );
	m_grid4->SetColLabelValue( 1, wxT("Producto") );
	m_grid4->SetColLabelValue( 2, wxT("Marca") );
	m_grid4->SetColLabelValue( 3, wxT("Codigo") );
	m_grid4->SetColLabelValue( 4, wxT("Cantidad") );
	m_grid4->SetColLabelValue( 5, wxEmptyString );
	m_grid4->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid4->EnableDragRowSize( true );
	m_grid4->SetRowLabelSize( 0 );
	m_grid4->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid4->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer9->Add( m_grid4, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();

	this->Centre( wxBOTH );
}

Ventana4::~Ventana4()
{
}

Ventana6::Ventana6( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Consultas Historial"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer11->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("Productos mas vendidos\nVentas por cliente\nVentas por producto\nVentas en (fecha)"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer12->Add( m_comboBox1, 0, wxALL, 5 );

	m_textCtrl8 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_textCtrl8, 0, wxALL, 5 );

	m_button10 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_button10, 0, wxALL, 5 );


	bSizer11->Add( bSizer12, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Resultados:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer11->Add( m_staticText12, 0, wxALL, 5 );

	m_grid5 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid5->CreateGrid( 0, 5 );
	m_grid5->EnableEditing( true );
	m_grid5->EnableGridLines( true );
	m_grid5->EnableDragGridSize( false );
	m_grid5->SetMargins( 0, 0 );

	// Columns
	m_grid5->EnableDragColMove( false );
	m_grid5->EnableDragColSize( true );
	m_grid5->SetColLabelSize( 0 );
	m_grid5->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid5->EnableDragRowSize( true );
	m_grid5->SetRowLabelSize( 00 );
	m_grid5->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid5->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_grid5, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer11 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::ConsultarHistorial ), NULL, this );
}

Ventana6::~Ventana6()
{
	// Disconnect Events
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::ConsultarHistorial ), NULL, this );

}
