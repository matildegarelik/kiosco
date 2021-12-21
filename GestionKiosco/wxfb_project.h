///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/statbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Ventana1
///////////////////////////////////////////////////////////////////////////////
class Ventana1 : public wxFrame
{
	private:

	protected:
		wxButton* m_btn_to_consultas;
		wxStaticText* m_staticText14;
		wxButton* m_btn_to_ventas;
		wxButton* m_btn_agregarstock;
		wxButton* m_btn_hacerpedido;
		wxButton* m_btn_nuevaventa;
		wxComboBox* m_ordenarpor;
		wxTextCtrl* m_buscar;
		wxGrid* m_grid6;
		wxButton* m_btn_agregarproducto;

		// Virtual event handlers, override them in your derived class
		virtual void to_consultas( wxCommandEvent& event ) { event.Skip(); }
		virtual void to_ventas( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana1();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana2
///////////////////////////////////////////////////////////////////////////////
class Ventana2 : public wxFrame
{
	private:

	protected:
		wxButton* m_btn_to_productos;
		wxStaticText* m_staticText13;
		wxButton* m_btn_to_pedido;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_codigo;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_cantidad;
		wxButton* m_btn_agregar;
		wxGrid* m_grilla;
		wxStaticText* m_staticText7;
		wxTextCtrl* m_total;
		wxButton* m_btn_fiar;
		wxButton* m_btn_pagar;

		// Virtual event handlers, override them in your derived class
		virtual void to_productos( wxCommandEvent& event ) { event.Skip(); }
		virtual void to_pedidos( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_grillaOnGridCellLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickVerFiar( wxCommandEvent& event ) { event.Skip(); }
		virtual void VerPagar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 521,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana2();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseFiar
///////////////////////////////////////////////////////////////////////////////
class BaseFiar : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText9;
		wxTextCtrl* m_total;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_cliente;
		wxButton* m_btn_fiar;

		// Virtual event handlers, override them in your derived class
		virtual void MarcarFIado( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseFiar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~BaseFiar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BasePagar
///////////////////////////////////////////////////////////////////////////////
class BasePagar : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText17;
		wxTextCtrl* m_total;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_cliente;
		wxButton* m_btn_pagar;

		// Virtual event handlers, override them in your derived class
		virtual void MarcarPagado( wxCommandEvent& event ) { event.Skip(); }


	public:

		BasePagar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 184,125 ), long style = wxDEFAULT_DIALOG_STYLE );

		~BasePagar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana3
///////////////////////////////////////////////////////////////////////////////
class Ventana3 : public wxFrame
{
	private:

	protected:
		wxButton* m_btn_to_venta;
		wxStaticText* m_staticText15;
		wxButton* m_btn_to_stock;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_codigo;
		wxStaticText* m_staticText9;
		wxTextCtrl* m_cantidad;
		wxButton* m_botonAgregar;
		wxStaticText* m_staticText10;
		wxGrid* m_grilla;
		wxButton* m_botonGuardar;

		// Virtual event handlers, override them in your derived class
		virtual void to_venta( wxCommandEvent& event ) { event.Skip(); }
		virtual void to_stock( wxCommandEvent& event ) { event.Skip(); }
		virtual void AgregarProductoLista( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickDerechoProducto( wxGridEvent& event ) { event.Skip(); }
		virtual void GuardarArchivo( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana3();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana4
///////////////////////////////////////////////////////////////////////////////
class Ventana4 : public wxFrame
{
	private:

	protected:
		wxButton* m_btn_to_pedido;
		wxStaticText* m_staticText7;
		wxButton* m_btn_to_fiados;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_codigo;
		wxStaticText* m_staticText9;
		wxTextCtrl* m_cantidad;
		wxButton* m_btn_ingreso;
		wxStaticText* m_staticText10;
		wxGrid* m_grilla;

		// Virtual event handlers, override them in your derived class
		virtual void to_pedido( wxCommandEvent& event ) { event.Skip(); }
		virtual void to_fiados( wxCommandEvent& event ) { event.Skip(); }
		virtual void Ingresar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana4( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana4();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana5
///////////////////////////////////////////////////////////////////////////////
class Ventana5 : public wxFrame
{
	private:

	protected:
		wxButton* m_btn_to_stock;
		wxStaticText* m_staticText6;
		wxButton* m_btn_to_consultas;
		wxGrid* m_tabla_fiados;

		// Virtual event handlers, override them in your derived class
		virtual void to_stock( wxCommandEvent& event ) { event.Skip(); }
		virtual void to_consultas( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_tabla_fiadosOnGridCellLeftClick( wxGridEvent& event ) { event.Skip(); }


	public:

		Ventana5( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana5();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana6
///////////////////////////////////////////////////////////////////////////////
class Ventana6 : public wxFrame
{
	private:

	protected:
		wxButton* m_btn_to_fiados;
		wxStaticText* m_staticText11;
		wxButton* m_btn_to_productos;
		wxComboBox* m_comboBox1;
		wxTextCtrl* m_textCtrl8;
		wxButton* m_button10;
		wxStaticText* m_staticText12;
		wxGrid* m_grid5;

		// Virtual event handlers, override them in your derived class
		virtual void to_fiados( wxCommandEvent& event ) { event.Skip(); }
		virtual void to_productos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ConsultarHistorial( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana6( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana6();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VetanaError
///////////////////////////////////////////////////////////////////////////////
class VetanaError : public wxDialog
{
	private:

	protected:
		wxStaticText* m_texto;
		wxButton* m_botonCerrar;

		// Virtual event handlers, override them in your derived class
		virtual void CerrarVentana( wxCommandEvent& event ) { event.Skip(); }


	public:

		VetanaError( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 364,199 ), long style = wxDEFAULT_DIALOG_STYLE );

		~VetanaError();

};

