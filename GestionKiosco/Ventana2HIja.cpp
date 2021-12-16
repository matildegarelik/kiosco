#include "Ventana2HIja.h"
#include "HijaFiar.h"

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

