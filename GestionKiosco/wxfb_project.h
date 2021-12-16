///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/combobox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Ventana2
///////////////////////////////////////////////////////////////////////////////
class Ventana2 : public wxFrame
{
	private:

	protected:
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
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickVerFiar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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
		wxButton* m_button8;

	public:

		BaseFiar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~BaseFiar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana5
///////////////////////////////////////////////////////////////////////////////
class Ventana5 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText6;
		wxGrid* m_tabla_fiados;

	public:

		Ventana5( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana5();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana4
///////////////////////////////////////////////////////////////////////////////
class Ventana4 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_textCtrl6;
		wxStaticText* m_staticText9;
		wxTextCtrl* m_textCtrl7;
		wxButton* m_button5;
		wxStaticText* m_staticText10;
		wxGrid* m_grid4;

	public:

		Ventana4( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana4();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana6
///////////////////////////////////////////////////////////////////////////////
class Ventana6 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText11;
		wxComboBox* m_comboBox1;
		wxTextCtrl* m_textCtrl8;
		wxButton* m_button10;
		wxStaticText* m_staticText12;
		wxGrid* m_grid5;

		// Virtual event handlers, override them in your derived class
		virtual void ConsultarHistorial( wxCommandEvent& event ) { event.Skip(); }


	public:

		Ventana6( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Ventana6();

};

