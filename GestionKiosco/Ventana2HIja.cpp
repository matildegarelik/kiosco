#include "Ventana2HIja.h"
#include "HijaFiar.h"
#include "Ventana1Hija.h"
#include "Ventana3Hija.h"
#include "BasePagarHija.h"
#include "WxFunciones.cpp"
#include <wx/msgdlg.h>


Ventana2HIja::Ventana2HIja(wxWindow *parent, Productos *prods) : Ventana2(parent) {
	this->prods = prods;
}

void Ventana2HIja::OnClickAgregar( wxCommandEvent& event )  {
	if(m_codigo->IsEmpty()){
		wxMessageBox("Ingresar codigo producto","Aviso");
	}else{
		if(prods->existe(stoi( wx_to_std(m_codigo->GetValue())))){
			if(m_cantidad->IsEmpty()){
				wxMessageBox("Ingresar cantidad","Aviso");
			}else{
				Producto p = prods->BuscarProducto(stoi( wx_to_std(m_codigo->GetValue())));
				if(p._stock<stoi( wx_to_std(m_cantidad->GetValue()))){
					wxMessageBox("No hay suficiente stock","Aviso");
				}else{
					_venta.AgregarDetalle(stoi( wx_to_std(m_codigo->GetValue())),stoi(wx_to_std(m_cantidad->GetValue())), *prods);
					
					Producto agregado = prods->BuscarProducto(stoi( wx_to_std(m_codigo->GetValue())));
					
					m_grilla->AppendRows(1);
					//m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
					m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,m_codigo->GetValue());
					m_codigo->SetValue("");
					m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(agregado._nombre));
					m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,c_to_wx(agregado._marca));
					m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
					m_cantidad->SetValue("");
					m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,4,std_to_wx(to_string(agregado._precio)));
					m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,5,std_to_wx("-"));
					
					m_total->SetValue(to_string(_venta.CalcularTotal()));
				}
				
			}
		}else{
			wxMessageBox("No existe un producto con ese codigo","Aviso");
		}
	}
	
	
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
	Ventana3Hija *Ventana_Nueva = new Ventana3Hija(NULL, prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana2HIja::VerPagar( wxCommandEvent& event )  {
	BasePagarHija ph(this, &_venta, prods);
	ph.ShowModal();
	event.Skip();
}

void Ventana2HIja::m_grillaOnGridCellLeftClick( wxGridEvent& event )  {
	if(event.GetCol()==5){
		m_grilla->DeleteRows(event.GetRow());
		_venta.EliminarDetalle(event.GetRow());
		m_total->SetValue(to_string(_venta.CalcularTotal()));
	}
	event.Skip();
}

