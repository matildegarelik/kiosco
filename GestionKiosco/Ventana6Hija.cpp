#include "Ventana6Hija.h"
#include "Ventana1Hija.h"
#include "Ventana5Hija.h"

Ventana6Hija::Ventana6Hija(wxWindow *parent, Productos *prods) : Ventana6(parent) {
	_prods=prods;
}

void Ventana6Hija::ConsultarHistorial( wxCommandEvent& event )  {
	event.Skip();
}

Ventana6Hija::~Ventana6Hija() {
	
}

void Ventana6Hija::to_fiados( wxCommandEvent& event )  {
	Ventana5Hija *Ventana_Nueva = new Ventana5Hija(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana6Hija::to_productos( wxCommandEvent& event )  {
	Ventana1Hija *Ventana_Nueva = new Ventana1Hija(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

