#include "HijaFiar.h"
#include "Venta.h"
#include "WxFunciones.cpp"
#include <wx/msgdlg.h>
#include "Ventana2HIja.h"

HijaFiar::HijaFiar(wxWindow *parent, Venta *venta, Productos *prods) : BaseFiar(parent) {
	_venta= venta;
	_prods=prods;
	m_total->SetValue(to_string(_venta->CalcularTotal()));
}

HijaFiar::~HijaFiar() {
	
}

void HijaFiar::MarcarFIado( wxCommandEvent& event )  {
	if(m_cliente->IsEmpty()){
		wxMessageBox("Ingresar nombre cliente","Aviso");
	}else{
		_venta->SetCliente(wx_to_std(m_cliente->GetValue()));
		_venta->SetFecha(18,12,2021);
		_venta->SetPago(false);
		
		_venta->Pagar(*_prods);
		hist.Agregar(*_venta);
		GetParent()->Close();
		Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL, _prods);
		Ventana_Nueva->Show();
		EndModal(1);
	}
	event.Skip();
}

