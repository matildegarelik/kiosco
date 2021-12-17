#include "Ventana6Hija.h"
#include "Ventana4HIja.h"
#include "wxfb_project.h"
#include "Ventana5Hija.h"

Ventana5Hija::Ventana5Hija(wxWindow *parent) : Ventana5(parent) {
	
}

Ventana5Hija::~Ventana5Hija() {
	
}

void Ventana5Hija::to_stock( wxCommandEvent& event )  {
	Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana5Hija::to_consultas( wxCommandEvent& event )  {
	Ventana6Hija *Ventana_Nueva = new Ventana6Hija(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

