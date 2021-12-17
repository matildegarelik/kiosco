#include "Ventana3Hija.h"
#include "Ventana5Hija.h"
#include "Ventana4HIja.h"

Ventana4HIja::Ventana4HIja(wxWindow *parent) : Ventana4(parent) {
	
}

Ventana4HIja::~Ventana4HIja() {
	
}

void Ventana4HIja::to_pedido( wxCommandEvent& event )  {
	Ventana3Hija *Ventana_Nueva = new Ventana3Hija(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana4HIja::to_fiados( wxCommandEvent& event )  {
	Ventana5Hija *Ventana_Nueva = new Ventana5Hija(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

