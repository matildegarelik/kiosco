#include "HijaFiar.h"
#include "Venta.h"


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

HijaFiar::HijaFiar(wxWindow *parent, Venta *venta, Productos *prods) : BaseFiar(parent) {
	_venta= venta;
	_prods=prods;
	m_total->SetValue(to_string(_venta->CalcularTotal()));
}

HijaFiar::~HijaFiar() {
	
}

void HijaFiar::MarcarFIado( wxCommandEvent& event )  {
	_venta->SetCliente(wx_to_std(m_cliente->GetValue()));
	_venta->SetFecha(18,12,2021);
	_venta->SetPago(false);
	
	_venta->Pagar(*_prods);
	
	event.Skip();
}

