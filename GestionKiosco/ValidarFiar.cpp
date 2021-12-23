#include "ValidarFiar.h"
#include "Ventana5Hija.h"

ValidarFiar::ValidarFiar(wxWindow *parent,int indice, Productos *prods) : BaseValidarFiar(parent) {
	m_i=indice;
	m_prods=prods;
}

ValidarFiar::~ValidarFiar() {
	
}

void ValidarFiar::Pagar( wxCommandEvent& event )  {
	hist.MarcarPagado(m_i);
	GetParent()->Close();
	Ventana5Hija *Ventana_Nueva = new Ventana5Hija(NULL, m_prods);
	Ventana_Nueva->Show();
	EndModal(1);
	event.Skip();
}

void ValidarFiar::Cerrar( wxCommandEvent& event )  {
	EndModal(1);
	event.Skip();
}

