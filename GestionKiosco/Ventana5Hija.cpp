#include "Ventana6Hija.h"
#include "Ventana4HIja.h"
#include "wxfb_project.h"
#include "Ventana5Hija.h"
#include "WxFunciones.cpp"

Ventana5Hija::Ventana5Hija(wxWindow *parent, Productos *prods) : Ventana5(parent) {
	_prods=prods;
	vector<Compra> fiados = v.CargarFiados();
	for(Compra &c: fiados){
		m_tabla_fiados->AppendRows(1);
		m_tabla_fiados->SetCellValue(m_tabla_fiados->GetNumberRows()-1,0,std_to_wx(c.cliente));
		m_tabla_fiados->SetCellValue(m_tabla_fiados->GetNumberRows()-1,1,std_to_wx(to_string(c.f.dia)+'/'+to_string(c.f.mes)+'/'+to_string(c.f.anio)));
		m_tabla_fiados->SetCellValue(m_tabla_fiados->GetNumberRows()-1,2,std_to_wx(to_string(c.total)));
		m_tabla_fiados->SetCellValue(m_tabla_fiados->GetNumberRows()-1,3,std_to_wx("X"));
	}
	
}

Ventana5Hija::~Ventana5Hija() {
	
}

void Ventana5Hija::to_stock( wxCommandEvent& event )  {
	Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL,_prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana5Hija::to_consultas( wxCommandEvent& event )  {
	Ventana6Hija *Ventana_Nueva = new Ventana6Hija(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana5Hija::m_tabla_fiadosOnGridCellLeftClick( wxGridEvent& event )  {
	if(event.GetCol()==3){
		//Compra c ;
		//strcpy(c.cliente, wx_to_std(m_tabla_fiados->GetCellValue(event.GetRow(),0)).c_str());
		//c.f={19,12,2021};
		//c.total=stof(wx_to_std(m_tabla_fiados->GetCellValue(event.GetRow(),2)));
		//v.MarcarPagado(c);
		v.MarcarPagado(event.GetRow());
		m_tabla_fiados->DeleteRows(event.GetRow());
	}
	event.Skip();
}

