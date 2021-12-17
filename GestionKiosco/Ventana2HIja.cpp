#include "Ventana2HIja.h"
#include "HijaFiar.h"
#include "Ventana1Hija.h"
#include "Ventana3Hija.h"
#include "BasePagarHija.h"

Ventana2HIja::Ventana2HIja(wxWindow *parent) : Ventana2(parent) {
	
}

void Ventana2HIja::OnClickAgregar( wxCommandEvent& event )  {
	m_grilla->AppendRows(1);
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
	m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,m_codigo->GetValue());
	m_codigo->SetValue("");
	m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
	m_cantidad->SetValue("");
}

void Ventana2HIja::OnClickVerFiar( wxCommandEvent& event )  {
	HijaFiar hf(this);
	hf.ShowModal();
}

Ventana2HIja::~Ventana2HIja() {
	
}

void Ventana2HIja::to_productos( wxCommandEvent& event )  {
	Ventana1Hija *Ventana_Nueva = new Ventana1Hija(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana2HIja::to_pedidos( wxCommandEvent& event )  {
	Ventana3Hija *Ventana_Nueva = new Ventana3Hija(NULL);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana2HIja::VerPagar( wxCommandEvent& event )  {
	BasePagarHija ph(this);
	ph.ShowModal();
	event.Skip();
}

