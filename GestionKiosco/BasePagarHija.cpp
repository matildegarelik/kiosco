#include "BasePagarHija.h"
#include "WxFunciones.cpp"

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
	
	_venta->Pagar(/*_prods*/);
	
	EndModal(1);
	
	event.Skip();
	//this->Close();
}

