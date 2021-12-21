#include "VentanaValidarHija.h"

VentanaValidarHija::VentanaValidarHija(wxWindow *parent) : VetanaValidar(parent) {
	
}

void VentanaValidarHija::PasarPestania( wxCommandEvent& event )  {
	event.Skip();
}

void VentanaValidarHija::MantenersePestania( wxCommandEvent& event )  {
	event.Skip();
}

VentanaValidarHija::~VentanaValidarHija() {
	
}

