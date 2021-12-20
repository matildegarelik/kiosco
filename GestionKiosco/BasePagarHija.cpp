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

BasePagarHija::BasePagarHija(wxWindow *parent,Venta *venta, Productos *prods) : BasePagar(parent) {
	_venta= venta;
	_prods=prods;
	m_total->SetValue(to_string(_venta->CalcularTotal()));
}

BasePagarHija::~BasePagarHija() {
	
}

void BasePagarHija::MarcarPagado( wxCommandEvent& event )  {
	_venta->SetCliente(wx_to_std(m_cliente->GetValue()));
	_venta->SetFecha(18,12,2021);
	_venta->SetPago(true);
	
	_venta->Pagar(*_prods);
	
	event.Skip();
	this->Close();
}

