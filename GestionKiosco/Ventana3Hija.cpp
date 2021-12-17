#include "Ventana3Hija.h"
#include "Ventana2HIja.h"
#include "Ventana4HIja.h"

Ventana3Hija::Ventana3Hija(wxWindow *parent) : Ventana3(parent) {
	
}

void Ventana3Hija::to_venta( wxCommandEvent& event )  {
	Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana3Hija::to_stock( wxCommandEvent& event )  {
	Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

Ventana3Hija::~Ventana3Hija() {
	
}

