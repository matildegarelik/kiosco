#include "HijaFiar.h"
#include "Venta.h"
#include "WxFunciones.h"
#include <wx/msgdlg.h>
#include "Ventana2HIja.h"



HijaFiar::HijaFiar(wxWindow *parent, Venta *venta, Productos *prods) : BaseFiar(parent) {
	m_venta= venta;
	m_prods=prods;
	m_total->SetValue(to_string(m_venta->CalcularTotal()));
}

HijaFiar::~HijaFiar() {
	
}

void HijaFiar::MarcarFIado( wxCommandEvent& event )  {
	if(m_cliente->IsEmpty()){
		wxMessageBox("Ingresar nombre cliente","Aviso");
	}else{
		m_venta->SetCliente(wx_to_std(m_cliente->GetValue()));
		
		m_venta->SetFecha(m_venta->getFechaActual());
		m_venta->SetPago(false);
		
		m_venta->Pagar(*m_prods);
		hist.Agregar(*m_venta);
		GetParent()->Close();
		Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL, m_prods);
		Ventana_Nueva->Show();
		EndModal(1);
	}
	event.Skip();
}

