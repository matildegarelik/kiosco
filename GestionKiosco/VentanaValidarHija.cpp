#include "VentanaValidarHija.h"
#include <string>
#include "WxFunciones.h"

using namespace std;

VentanaValidarHija::VentanaValidarHija(wxWindow *parent) : VetanaValidar(parent) {
	descripcion_error = "Esta por pasar a otra ventana, si sale de la misma se borrara lo cargado\n";
	m_texto->SetLabel(std_to_wx(descripcion_error));
}

void VentanaValidarHija::PasarPestania( wxCommandEvent& event )  {
	
	EndModal(1);
}

void VentanaValidarHija::MantenersePestania( wxCommandEvent& event )  {
	EndModal(0);
}

VentanaValidarHija::~VentanaValidarHija() {
	
}

