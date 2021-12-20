///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Ventana1::Ventana1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_to_consultas = new wxButton( this, wxID_ANY, wxT("<<Consultas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_btn_to_consultas, 0, wxALL, 5 );


	bSizer15->Add( 0, 0, 1, 0, 5 );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Productos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer15->Add( 0, 0, 1, wxEXPAND, 5 );

	m_btn_to_ventas = new wxButton( this, wxID_ANY, wxT("Ventas>>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_btn_to_ventas, 0, wxALL, 5 );


	bSizer14->Add( bSizer15, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_agregarstock = new wxButton( this, wxID_ANY, wxT("Agregar Stock"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_btn_agregarstock, 0, wxALL, 5 );

	m_btn_hacerpedido = new wxButton( this, wxID_ANY, wxT("Hacer Pedido"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_btn_hacerpedido, 0, wxALL, 5 );

	m_btn_nuevaventa = new wxButton( this, wxID_ANY, wxT("Nueva Venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_btn_nuevaventa, 0, wxALL, 5 );

	m_ordenarpor = new wxComboBox( this, wxID_ANY, wxT("Ordenar Por:"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer26->Add( m_ordenarpor, 0, wxALL, 5 );

	m_buscar = new wxTextCtrl( this, wxID_ANY, wxT("Buscar:"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_buscar, 0, wxALL, 5 );


	bSizer14->Add( bSizer26, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_grid6 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grid6->CreateGrid( 0, 6 );
	m_grid6->EnableEditing( true );
	m_grid6->EnableGridLines( true );
	m_grid6->EnableDragGridSize( false );
	m_grid6->SetMargins( 0, 0 );

	// Columns
	m_grid6->EnableDragColMove( false );
	m_grid6->EnableDragColSize( true );
	m_grid6->SetColLabelValue( 0, wxT("PRODUCTO") );
	m_grid6->SetColLabelValue( 1, wxT("CÓDIGO") );
	m_grid6->SetColLabelValue( 2, wxT("TIPO") );
	m_grid6->SetColLabelValue( 3, wxT("MARCA") );
	m_grid6->SetColLabelValue( 4, wxT("STOCK") );
	m_grid6->SetColLabelValue( 5, wxT("PRECIO") );
	m_grid6->SetColLabelValue( 6, wxEmptyString );
	m_grid6->SetColLabelValue( 7, wxEmptyString );
	m_grid6->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid6->EnableDragRowSize( true );
	m_grid6->SetRowLabelSize( 0 );
	m_grid6->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid6->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer14->Add( m_grid6, 1, wxALL|wxEXPAND, 5 );

	m_btn_agregarproducto = new wxButton( this, wxID_ANY, wxT("Agregar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_btn_agregarproducto, 0, wxALIGN_RIGHT|wxALL, 5 );


	this->SetSizer( bSizer14 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_btn_to_consultas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana1::to_consultas ), NULL, this );
	m_btn_to_ventas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana1::to_ventas ), NULL, this );
}

Ventana1::~Ventana1()
{
	// Disconnect Events
	m_btn_to_consultas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana1::to_consultas ), NULL, this );
	m_btn_to_ventas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana1::to_ventas ), NULL, this );

}

Ventana2::Ventana2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_to_productos = new wxButton( this, wxID_ANY, wxT("<<Productos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_btn_to_productos, 0, wxALL, 5 );


	bSizer13->Add( 130, 0, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer13->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer13->Add( 50, 0, 1, wxEXPAND, 5 );

	m_btn_to_pedido = new wxButton( this, wxID_ANY, wxT("Pedido>>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_btn_to_pedido, 0, wxALL, 5 );


	bSizer5->Add( bSizer13, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

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


	bSizer5->Add( bSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

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
	m_grilla->SetColSize( 5, 88 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Codigo") );
	m_grilla->SetColLabelValue( 1, wxT("Nombre") );
	m_grilla->SetColLabelValue( 2, wxT("Marca") );
	m_grilla->SetColLabelValue( 3, wxT("Cantidad") );
	m_grilla->SetColLabelValue( 4, wxT("Precio x Unidad") );
	m_grilla->SetColLabelValue( 5, wxT("ELIMINAR") );
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

	m_total = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
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
	m_btn_to_productos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::to_productos ), NULL, this );
	m_btn_to_pedido->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::to_pedidos ), NULL, this );
	m_btn_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickAgregar ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Ventana2::m_grillaOnGridCellLeftClick ), NULL, this );
	m_btn_fiar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickVerFiar ), NULL, this );
	m_btn_pagar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::VerPagar ), NULL, this );
}

Ventana2::~Ventana2()
{
	// Disconnect Events
	m_btn_to_productos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::to_productos ), NULL, this );
	m_btn_to_pedido->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::to_pedidos ), NULL, this );
	m_btn_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickAgregar ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Ventana2::m_grillaOnGridCellLeftClick ), NULL, this );
	m_btn_fiar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::OnClickVerFiar ), NULL, this );
	m_btn_pagar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana2::VerPagar ), NULL, this );

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

	m_total = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
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

	m_btn_fiar = new wxButton( this, wxID_ANY, wxT("Fiar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_btn_fiar, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();
	bSizer9->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_btn_fiar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFiar::MarcarFIado ), NULL, this );
}

BaseFiar::~BaseFiar()
{
	// Disconnect Events
	m_btn_fiar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseFiar::MarcarFIado ), NULL, this );

}

BasePagar::BasePagar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Total: $"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer22->Add( m_staticText17, 0, wxALL, 5 );

	m_total = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer22->Add( m_total, 0, wxALL, 5 );


	bSizer21->Add( bSizer22, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Cliente: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer23->Add( m_staticText18, 0, wxALL, 5 );

	m_cliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_cliente, 0, wxALL, 5 );


	bSizer21->Add( bSizer23, 1, wxEXPAND, 5 );

	m_btn_pagar = new wxButton( this, wxID_ANY, wxT("Pagar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_btn_pagar, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer21 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_btn_pagar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePagar::MarcarPagado ), NULL, this );
}

BasePagar::~BasePagar()
{
	// Disconnect Events
	m_btn_pagar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePagar::MarcarPagado ), NULL, this );

}

Ventana3::Ventana3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_to_venta = new wxButton( this, wxID_ANY, wxT("<<Venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_btn_to_venta, 0, wxALL, 5 );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Hacer Pedido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	m_staticText15->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer17->Add( m_staticText15, 0, wxALL, 5 );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_btn_to_stock = new wxButton( this, wxID_ANY, wxT("Stock>>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_btn_to_stock, 0, wxALL, 5 );


	bSizer16->Add( bSizer17, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Codigo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer10->Add( m_staticText8, 0, wxALL, 5 );

	m_codigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_codigo, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Cantidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer10->Add( m_staticText9, 0, wxALL, 5 );

	m_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_cantidad, 0, wxALL, 5 );

	m_botonAgregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_botonAgregar, 0, wxALL, 5 );


	bSizer16->Add( bSizer10, 0, wxEXPAND, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Ultimos ingresos:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer16->Add( m_staticText10, 0, wxALL, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 5 );
	m_grilla->EnableEditing( false );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 80 );
	m_grilla->SetColSize( 1, 115 );
	m_grilla->SetColSize( 2, 114 );
	m_grilla->SetColSize( 3, 107 );
	m_grilla->SetColSize( 4, 64 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Fecha") );
	m_grilla->SetColLabelValue( 1, wxT("Producto") );
	m_grilla->SetColLabelValue( 2, wxT("Marca") );
	m_grilla->SetColLabelValue( 3, wxT("Codigo") );
	m_grilla->SetColLabelValue( 4, wxT("Cantidad") );
	m_grilla->SetColLabelValue( 5, wxEmptyString );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( 0 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer16->Add( m_grilla, 1, wxALL, 5 );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_botonCerrar = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_botonCerrar, 0, wxALL, 5 );

	m_botonGuardar = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_botonGuardar, 0, wxALL, 5 );


	bSizer16->Add( bSizer29, 0, wxBOTTOM|wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer16 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_btn_to_venta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::to_venta ), NULL, this );
	m_btn_to_stock->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::to_stock ), NULL, this );
	m_botonAgregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::AgregarProductoLista ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( Ventana3::ClickDerechoProducto ), NULL, this );
	m_botonCerrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::CerrarVentana ), NULL, this );
	m_botonGuardar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::GuardarArchivo ), NULL, this );
}

Ventana3::~Ventana3()
{
	// Disconnect Events
	m_btn_to_venta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::to_venta ), NULL, this );
	m_btn_to_stock->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::to_stock ), NULL, this );
	m_botonAgregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::AgregarProductoLista ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_LABEL_RIGHT_CLICK, wxGridEventHandler( Ventana3::ClickDerechoProducto ), NULL, this );
	m_botonCerrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::CerrarVentana ), NULL, this );
	m_botonGuardar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana3::GuardarArchivo ), NULL, this );

}

Ventana4::Ventana4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_to_pedido = new wxButton( this, wxID_ANY, wxT("<<Pedido"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_btn_to_pedido, 0, wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Ingreso stock"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	m_staticText7->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer18->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_btn_to_fiados = new wxButton( this, wxID_ANY, wxT("Fiados>>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_btn_to_fiados, 0, wxALL, 5 );


	bSizer9->Add( bSizer18, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Codigo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer10->Add( m_staticText8, 0, wxALL, 5 );

	m_codigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_codigo, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Cantidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer10->Add( m_staticText9, 0, wxALL, 5 );

	m_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_cantidad, 0, wxALL, 5 );

	m_btn_ingreso = new wxButton( this, wxID_ANY, wxT("Finalizar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_btn_ingreso, 0, wxALL, 5 );


	bSizer9->Add( bSizer10, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Ultimos ingresos:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer9->Add( m_staticText10, 0, wxALL, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 5 );
	m_grilla->EnableEditing( false );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 80 );
	m_grilla->SetColSize( 1, 115 );
	m_grilla->SetColSize( 2, 114 );
	m_grilla->SetColSize( 3, 107 );
	m_grilla->SetColSize( 4, 64 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Fecha") );
	m_grilla->SetColLabelValue( 1, wxT("Producto") );
	m_grilla->SetColLabelValue( 2, wxT("Marca") );
	m_grilla->SetColLabelValue( 3, wxT("Codigo") );
	m_grilla->SetColLabelValue( 4, wxT("Cantidad") );
	m_grilla->SetColLabelValue( 5, wxEmptyString );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( 0 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer9->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_btn_to_pedido->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana4::to_pedido ), NULL, this );
	m_btn_to_fiados->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana4::to_fiados ), NULL, this );
	m_btn_ingreso->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana4::Ingresar ), NULL, this );
}

Ventana4::~Ventana4()
{
	// Disconnect Events
	m_btn_to_pedido->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana4::to_pedido ), NULL, this );
	m_btn_to_fiados->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana4::to_fiados ), NULL, this );
	m_btn_ingreso->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana4::Ingresar ), NULL, this );

}

Ventana5::Ventana5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_to_stock = new wxButton( this, wxID_ANY, wxT("<<Stock"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_btn_to_stock, 0, wxALL, 5 );


	bSizer19->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("FIADOS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer19->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer19->Add( 0, 0, 1, wxEXPAND, 5 );

	m_btn_to_consultas = new wxButton( this, wxID_ANY, wxT("Consultas>>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_btn_to_consultas, 0, wxALL, 5 );


	bSizer8->Add( bSizer19, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_tabla_fiados = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_tabla_fiados->CreateGrid( 0, 4 );
	m_tabla_fiados->EnableEditing( false );
	m_tabla_fiados->EnableGridLines( true );
	m_tabla_fiados->EnableDragGridSize( false );
	m_tabla_fiados->SetMargins( 0, 0 );

	// Columns
	m_tabla_fiados->SetColSize( 0, 80 );
	m_tabla_fiados->SetColSize( 1, 79 );
	m_tabla_fiados->SetColSize( 2, 80 );
	m_tabla_fiados->SetColSize( 3, 80 );
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

	// Connect Events
	m_btn_to_stock->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana5::to_stock ), NULL, this );
	m_btn_to_consultas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana5::to_consultas ), NULL, this );
	m_tabla_fiados->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Ventana5::m_tabla_fiadosOnGridCellLeftClick ), NULL, this );
}

Ventana5::~Ventana5()
{
	// Disconnect Events
	m_btn_to_stock->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana5::to_stock ), NULL, this );
	m_btn_to_consultas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana5::to_consultas ), NULL, this );
	m_tabla_fiados->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Ventana5::m_tabla_fiadosOnGridCellLeftClick ), NULL, this );

}

Ventana6::Ventana6( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_btn_to_fiados = new wxButton( this, wxID_ANY, wxT("<<Fiados"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_btn_to_fiados, 0, wxALL, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Consultas Historial"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	m_staticText11->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer20->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	m_btn_to_productos = new wxButton( this, wxID_ANY, wxT("Productos>>"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_btn_to_productos, 0, wxALL, 5 );


	bSizer11->Add( bSizer20, 0, wxEXPAND, 5 );

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
	m_btn_to_fiados->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::to_fiados ), NULL, this );
	m_btn_to_productos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::to_productos ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::ConsultarHistorial ), NULL, this );
}

Ventana6::~Ventana6()
{
	// Disconnect Events
	m_btn_to_fiados->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::to_fiados ), NULL, this );
	m_btn_to_productos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::to_productos ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Ventana6::ConsultarHistorial ), NULL, this );

}
