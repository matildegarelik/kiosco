#include "Ventana2HIja.h"
#include "HijaFiar.h"
#include "Ventana1Hija.h"
#include "Ventana3Hija.h"
#include "BasePagarHija.h"

/// para convertir un c-string, o una constante, a wxString
inline wxString c_to_wx(const char *c_str) {
	return wxString::From8BitData(c_str);
}
/// para convertir un std::string a wxString
inline wxString std_to_wx(const std::string &std_str) {
	return wxString::From8BitData(std_str.c_str());
}
/// para convertir wxString a std::string
inline std::string wx_to_std(const wxString &wx_str) {
	return static_cast<const char*>(wx_str.To8BitData());
}


Ventana2HIja::Ventana2HIja(wxWindow *parent, Productos *prods) : Ventana2(parent) {
	this->prods = prods;
}

void Ventana2HIja::OnClickAgregar( wxCommandEvent& event )  {
	
	_venta.AgregarDetalle(stoi( wx_to_std(m_codigo->GetValue())),stoi(wx_to_std(m_cantidad->GetValue())), *prods);
	
	m_grilla->AppendRows(1);
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
	m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,m_codigo->GetValue());
	m_codigo->SetValue("");
	m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
	m_cantidad->SetValue("");
	
	//m_grilla->SetCellValue(
	
	m_total->SetValue(to_string(_venta.CalcularTotal()));
}

void Ventana2HIja::OnClickVerFiar( wxCommandEvent& event )  {
	HijaFiar hf(this, &_venta, prods);
	hf.ShowModal();
}

Ventana2HIja::~Ventana2HIja() {
	
}

void Ventana2HIja::to_productos( wxCommandEvent& event )  {
	Ventana1Hija *Ventana_Nueva = new Ventana1Hija(NULL, prods);
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
	BasePagarHija ph(this, &_venta, prods);
	ph.ShowModal();
	event.Skip();
}

