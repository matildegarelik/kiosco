#include "Ventana3Hija.h"
#include "Ventana2HIja.h"
#include "Ventana4HIja.h"
#include "WxFunciones.cpp"
#include <wx/msgdlg.h>

Ventana3Hija::Ventana3Hija(wxWindow *parent, Productos *prods) : Ventana3(parent) {
	_prods=prods;
}

void Ventana3Hija::to_venta( wxCommandEvent& event )  {
	Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana3Hija::to_stock( wxCommandEvent& event )  {
	Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

Ventana3Hija::~Ventana3Hija() {
	
}


void Ventana3Hija::AgregarProductoLista( wxCommandEvent& event )  {
	
	Producto agregado;
	if(_prods->existe(stoi(wx_to_std(m_codigo->GetValue())))){
		agregado = _prods->BuscarProducto(stoi(wx_to_std(m_codigo->GetValue())));
		_pedido.agregarProducto(stoi(wx_to_std(m_codigo->GetValue())),stoi(wx_to_std(m_cantidad->GetValue())), *_prods);
		
		m_grilla->AppendRows(1);
		//m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,m_codigo->GetValue());
		m_codigo->SetValue("");
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(agregado._nombre));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,c_to_wx(agregado._marca));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
		m_cantidad->SetValue("");
	}else{
		wxMessageBox("Estaba mal el codigo","Error");
//		VentanaErrorHija *Ventana_Nueva = new VentanaErrorHija(NULL, " estaba mal el codigo ");
//		Ventana_Nueva->Show();
//		event.Skip();
	}
	
	event.Skip();
}

void Ventana3Hija::GuardarArchivo( wxCommandEvent& event )  {
	_pedido.armarArchivoTexto();
	wxMessageBox("muy bien");
	
	m_grilla->DeleteRows(0,_pedido.getTamanio());
	_pedido.vaciarVectores();
	event.Skip();
}


void Ventana3Hija::ClickDerechoProducto( wxGridEvent& event )  {
	event.Skip();
}

