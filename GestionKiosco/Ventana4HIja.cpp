#include "Ventana3Hija.h"
#include "Ventana5Hija.h"
#include "Ventana4HIja.h"
#include "Venta.h"
#include "Ingreso.h"
#include "WxFunciones.cpp"
#include <wx/msgdlg.h>

string to_string(Fecha f){
	return to_string(f.dia)+'/'+to_string(f.mes)+'/'+to_string(f.anio);
}
	

Ventana4HIja::Ventana4HIja(wxWindow *parent, Productos *prods) : Ventana4(parent), repo_ingresos("ingresos.dat") {
	_prods=prods;
	vector<DetalleYFecha> ult_ingresos = repo_ingresos.buscarTodos();
	reverse(ult_ingresos.begin(),ult_ingresos.end());
	for(DetalleYFecha &d: ult_ingresos){
		m_grilla->AppendRows(1);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx(to_string(d.f)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,d.d.p._nombre);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,d.d.p._marca);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,std_to_wx(to_string(d.d.p._codigo)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,4,std_to_wx(to_string(d.d.cantidad)));
	}
	
}

Ventana4HIja::~Ventana4HIja() {
	
}

void Ventana4HIja::to_pedido( wxCommandEvent& event )  {
	Ventana3Hija *Ventana_Nueva = new Ventana3Hija(NULL,_prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana4HIja::to_fiados( wxCommandEvent& event )  {
	Ventana5Hija *Ventana_Nueva = new Ventana5Hija(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana4HIja::Ingresar( wxCommandEvent& event )  {
	if(m_codigo->IsEmpty()){
		wxMessageBox("Ingresar codigo producto","Aviso");
	}else{
		if(_prods->existe(stoi( wx_to_std(m_codigo->GetValue())))){
			if(m_cantidad->IsEmpty()){
				wxMessageBox("Ingresar cantidad","Aviso");
			}else{
				Fecha f = {19,12,2021};
				Ingreso nuevo(stoi(wx_to_std(m_codigo->GetValue())), *_prods,stoi(wx_to_std(m_cantidad->GetValue())),f);
				nuevo.GuardarCambios(*_prods);
			}
		}else{
			wxMessageBox("No existe un producto con ese codigo","Error");
		}
	}
	/*vector<DetalleYFecha> ult_ingresos = repo_ingresos.buscarTodos();
	DetalleYFecha u = ult_ingresos[ult_ingresos.size()-1];
	
		m_grilla->AppendRows(1);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx(to_string(d.f)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,d.d.p._nombre);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,d.d.p._marca);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,std_to_wx(to_string(d.d.p._codigo)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,4,std_to_wx(to_string(d.d.cantidad)));
	*/
	Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

