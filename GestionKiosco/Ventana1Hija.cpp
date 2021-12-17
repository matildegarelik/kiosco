#include "Ventana1Hija.h"
#include "Ventana2HIja.h"
#include "Ventana6Hija.h"

Ventana1Hija::Ventana1Hija(wxWindow *parent) : Ventana1(parent) {
	
}

void Ventana1Hija::to_ventas( wxCommandEvent& event )  {
	Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

Ventana1Hija::~Ventana1Hija() {
	
}

void Ventana1Hija::to_consultas( wxCommandEvent& event )  {
	Ventana6Hija *Ventana_Nueva = new Ventana6Hija(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

