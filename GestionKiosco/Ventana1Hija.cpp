#include "Ventana1Hija.h"
#include "Ventana2HIja.h"
#include "Ventana6Hija.h"
#include "WxFunciones.h"
#include "AgregarNuevoProducto.h"
#include "Ventana4HIja.h"
#include "Ventana5Hija.h"
#include "Ventana3Hija.h"
#include "Productos.h"
#include "wxfb_project.h"
#include "ActualizarPrecioYEliminar.h"
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
	if(m_grilla->GetNumberRows()>0)	m_grilla->DeleteRows(0,m_grilla->GetColSize(0));
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
	
	int indice = m_grilla->GetGridCursorRow();
	int codigo = prods->VerCodigo(indice);
	
	ActualizarPrecioYEliminar *win = new ActualizarPrecioYEliminar(NULL, prods, codigo);/*, prods, event.getrow()*/
	if(win->ShowModal() == 1){
		Actualizar();
	}
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

void Ventana1Hija::ComboBoxOrdenarPor( wxCommandEvent& event )  {
	
	vector<Producto>::iterator A, B;
	tie(A, B)=prods->iteradores();
	int t=m_grilla->GetNumberRows();
	if(m_ordenarpor>=0){
		if(m_ordenarpor->GetSelection()==0) sort(A,B,OrdenarPorNombre);
		if(m_ordenarpor->GetSelection()==1) sort(A,B,OrdenarPorCodigo);
		if(m_ordenarpor->GetSelection()==2) sort(A,B,OrdenarPorTipo);
		if(m_ordenarpor->GetSelection()==3) sort(A,B,OrdenarPorMarca);
		if(m_ordenarpor->GetSelection()==4) sort(A,B,OrdenarPorStock);
		if(m_ordenarpor->GetSelection()==5) sort(A,B,OrdenarPorPrecio);
	}
	Actualizar();
	
}

