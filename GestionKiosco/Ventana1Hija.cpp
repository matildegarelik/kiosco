#include "Ventana1Hija.h"
#include "Ventana2HIja.h"
#include "Ventana6Hija.h"
#include "WxFunciones.cpp"
#include "AgregarNuevoProducto.h"
#include "Ventana4HIja.h"
#include "Ventana5Hija.h"
#include "Ventana3Hija.h"
Ventana1Hija::Ventana1Hija(wxWindow *parent, Productos *prods) : Ventana1(parent) {
	this->prods=prods;
	this->Actualizar();
}

void Ventana1Hija::to_ventas( wxCommandEvent& event )  {
	Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL, prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}
void Ventana1Hija::Actualizar(){
	//Producto aux;                                      
	m_grilla->DeleteRows(0,prods->DevolverTamanio());
	for(int i=0; i<prods->DevolverTamanio(); ++i){
		m_grilla->AppendRows(1);
		//m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,to_string(prods->VerCodigo(i)));
		//m_codigo->SetValue("");
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(prods->VerNombre(i)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,c_to_wx(prods->VerMarca(i)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,c_to_wx(prods->VerTipo(i)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,4,to_string(prods->VerStock(i)));
		//m_cantidad->SetValue("");
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,5,std_to_wx(to_string(prods->VerPrecio(i))));
		//m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,5,std_to_wx("-"));
	}
}

Ventana1Hija::~Ventana1Hija() {
	
}

void Ventana1Hija::to_consultas( wxCommandEvent& event )  {
	Ventana6Hija *Ventana_Nueva = new Ventana6Hija(NULL,prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana1Hija::AgregarStockBoton( wxCommandEvent& event )  {
	Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL,prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana1Hija::HacerPedidoBoton( wxCommandEvent& event )  {
	Ventana3Hija *Ventana_Nueva = new Ventana3Hija(NULL,prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}


void Ventana1Hija::DobleClickCellLeft( wxGridEvent& event )  {
	ActualizarPrecio_Eliminar *win=new ActualizarPrecio_Eliminar(this/*, prods, event.getrow()*/);
	win->ShowModal();
	event.Skip();
}

void Ventana1Hija::AgregarProductoBoton( wxCommandEvent& event )  {
	AgregarNuevoProducto win(this,prods);
	win.ShowModal();
	Actualizar();
	//event.Skip();
}

void Ventana1Hija::FiadosBoton( wxCommandEvent& event )  {
	Ventana5Hija *Ventana_Nueva = new Ventana5Hija(NULL,prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

