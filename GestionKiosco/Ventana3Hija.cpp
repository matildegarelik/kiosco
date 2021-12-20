#include "Ventana3Hija.h"
#include "Ventana2HIja.h"
#include "Ventana4HIja.h"

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
	event.Skip();
}

void Ventana3Hija::GuardarArchivo( wxCommandEvent& event )  {
	event.Skip();
}

void Ventana3Hija::CerrarVentana( wxCommandEvent& event )  {
	event.Skip();
}

void Ventana3Hija::ClickDerechoProducto( wxGridEvent& event )  {
	event.Skip();
}

