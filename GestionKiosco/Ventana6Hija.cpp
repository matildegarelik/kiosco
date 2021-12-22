#include "Ventana6Hija.h"
#include "Ventana1Hija.h"
#include "Ventana5Hija.h"
#include <wx/msgdlg.h>
#include "WxFunciones.cpp"
#include <wx/grid.h>



Ventana6Hija::Ventana6Hija(wxWindow *parent, Productos *prods) : Ventana6(parent) {
	_prods=prods;
	m_param->Disable();
	m_grilla->AppendRows(1);
	m_grilla->SetCellBackgroundColour(0,0,*wxLIGHT_GREY);
	m_grilla->SetCellBackgroundColour(0,1,*wxLIGHT_GREY);
	m_grilla->SetCellBackgroundColour(0,2,*wxLIGHT_GREY);
	m_grilla->SetCellBackgroundColour(0,3,*wxLIGHT_GREY);
	m_grilla->SetCellValue(0,0,wx_to_std("Codigo"));
	m_grilla->SetCellValue(0,1,wx_to_std("Nombre"));
	m_grilla->SetCellValue(0,2,wx_to_std("Cantidad de ventas"));
	//m_grilla->SetRowAttr(0, 
	vector<Detalle> dets=_venta.prods_mas_vendidos();
	for(Detalle &d: dets){
		m_grilla->AppendRows(1);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx(to_string(d.p._codigo)));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(d.p._nombre));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,std_to_wx(to_string(d.cantidad)));
	}
}

void Ventana6Hija::ConsultarHistorial( wxCommandEvent& event )  {
	int opcion = m_dropdown->GetSelection();
	if(m_grilla->GetNumberRows()!=0)
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	
	switch(opcion){
	case 0:// Productos mas vendidos
	{
		m_param->Disable();
		m_grilla->AppendRows(1);
		m_grilla->SetCellBackgroundColour(0,0,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,1,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,2,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,3,*wxLIGHT_GREY);
		m_grilla->SetCellValue(0,0,wx_to_std("Codigo"));
		m_grilla->SetCellValue(0,1,wx_to_std("Nombre"));
		m_grilla->SetCellValue(0,2,wx_to_std("Cantidad de ventas"));
		vector<Detalle> dets=_venta.prods_mas_vendidos();
		for(Detalle &d: dets){
			m_grilla->AppendRows(1);
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx(to_string(d.p._codigo)));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(d.p._nombre));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,std_to_wx(to_string(d.cantidad)));
		}
	}
	break;
	case 1: //Ultimas ventas
	{
		m_param->Disable();
		m_grilla->AppendRows(1);
		m_grilla->SetCellValue(0,0,wx_to_std("Fecha"));
		m_grilla->SetCellValue(0,1,wx_to_std("Cliente"));
		m_grilla->SetCellValue(0,2,wx_to_std("Total"));
		m_grilla->SetCellBackgroundColour(0,0,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,1,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,2,*wxLIGHT_GREY);
		//Compra v={"matilde\0",Fecha{21,12,2021},100};
		vector<Compra> ult_ventas =_venta.ultimas_ventas();
		//ult_ventas.push_back(v);
		for(Compra &c: ult_ventas){
			m_grilla->AppendRows(1);
			string fecha = to_string(c.f.dia)+'/'+to_string(c.f.mes)+'/'+to_string(c.f.anio);
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx(fecha));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(c.cliente));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,std_to_wx(to_string(c.total)));
		}
	}
	break;
	case 2: // Ventas por producto
	{
		m_param->Enable();
		m_grilla->AppendRows(1);
		m_grilla->SetCellBackgroundColour(0,0,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,1,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,2,*wxLIGHT_GREY);
		m_grilla->SetCellValue(0,0,wx_to_std("Fecha"));
		m_grilla->SetCellValue(0,1,wx_to_std("Producto"));
		m_grilla->SetCellValue(0,2,wx_to_std("Cantidad"));
		//m_grilla->SetCellValue(0,3,wx_to_std("Total"));
		if(_prods->existe(stoi(wx_to_std(m_param->GetValue())))){
			vector<DetalleYFecha> dets = _venta.ventas_por_producto(stoi(wx_to_std(m_param->GetValue())));
			for(DetalleYFecha &d: dets){
				m_grilla->AppendRows(1);
				string fecha = to_string(d.f.dia)+'/'+to_string(d.f.mes)+'/'+to_string(d.f.anio);
				m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx(fecha));
				m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(d.d.p._nombre));
				m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,std_to_wx(to_string(d.d.cantidad)));
				//m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,std_to_wx(to_string(d.d.cantidad*d.d.p._precio)));
				
			}
		}else{
			wxMessageBox("No existe un producto con ese codigo","Aviso");
		}
		
	}
		break;
	case 3: //Ventas por cliente
	{
		m_param->Enable();
		m_grilla->AppendRows(1);
		m_grilla->SetCellBackgroundColour(0,0,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,1,*wxLIGHT_GREY);
		m_grilla->SetCellBackgroundColour(0,2,*wxLIGHT_GREY);
		m_grilla->SetCellValue(0,0,wx_to_std("Cliente"));
		m_grilla->SetCellValue(0,1,wx_to_std("Total"));
		m_grilla->SetCellValue(0,2,wx_to_std("Fecha"));
		vector<Compra> dets = _venta.ventas_por_cliente(wx_to_std(m_param->GetValue()));
		for(Compra &c: dets){
			m_grilla->AppendRows(1);
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,c_to_wx(c.cliente));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,std_to_wx(to_string(c.total)));
			string fecha = to_string(c.f.dia)+'/'+to_string(c.f.mes)+'/'+to_string(c.f.anio);
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,std_to_wx(fecha));
			
		}
	}
	break;
	}
	event.Skip();
}

Ventana6Hija::~Ventana6Hija() {
	
}

void Ventana6Hija::to_fiados( wxCommandEvent& event )  {
	Ventana5Hija *Ventana_Nueva = new Ventana5Hija(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana6Hija::to_productos( wxCommandEvent& event )  {
	Ventana1Hija *Ventana_Nueva = new Ventana1Hija(NULL, _prods);
	Close();
	Ventana_Nueva->Show();
	event.Skip();
}

void Ventana6Hija::CambioOpcion( wxCommandEvent& event )  {
	int opcion = m_dropdown->GetSelection();
	switch(opcion){
	case 0:// Productos mas vendidos
		m_param->Disable();
		break;
	case 1: //Ultimas ventas
		m_param->Disable();
		break;
	case 2: // Ventas por producto
		m_param->Enable();
		break;
	case 3: //Ventas por cliente
		m_param->Enable();
		break;
	}
	event.Skip();
}

