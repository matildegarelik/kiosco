#include "Ventana3Hija.h"
#include "Ventana2HIja.h"
#include "Ventana4HIja.h"
#include "WxFunciones.h"
#include <wx/msgdlg.h>
#include "VentanaValidarHija.h"
#include <string>
#include <wx/wx.h>
using namespace std;

Ventana3Hija::Ventana3Hija(wxWindow *parent, Productos *prods) : Ventana3(parent) {
	_prods=prods;
	
	vector<Producto>::iterator A, B;
	tie(A, B)=_prods->iteradores();
	sort(A,B,OrdenarPorNombre);
	for(int i=0;i<_prods->DevolverTamanio();i++) { 
		m_lista_productos->Append(std_to_wx(_prods->VerNombre(i)));
	}

}

void Ventana3Hija::to_venta( wxCommandEvent& event )  {

//	Ventana2HIja *win = new Ventana2HIja(NULL, _prods);
//	bool paso;
//	paso = Validar(,event,_prods,_pedido);
//	if (paso){ Close();}
	
	VentanaValidarHija Ventana_val(this);
	
	if(_pedido.getTamanio() == 0){
		Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL, _prods);
		Close();
		Ventana_Nueva->Show();
		event.Skip();
	}else{
		if(Ventana_val.ShowModal()==1){
			Ventana2HIja *Ventana_Nueva = new Ventana2HIja(NULL, _prods);
			Close();
			Ventana_Nueva->Show();
			event.Skip();
		}
	}
}

void Ventana3Hija::to_stock( wxCommandEvent& event )  {

//	bool paso = Validar<Ventana4HIja> (event, _prods);
//	if (paso){ Close();}
	
	VentanaValidarHija Ventana_val(this);

	if(_pedido.getTamanio() == 0){
		Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL, _prods);
		Close();
		Ventana_Nueva->Show();
		event.Skip();
	}else{
		if(Ventana_val.ShowModal()==1){
			Ventana4HIja *Ventana_Nueva = new Ventana4HIja(NULL, _prods);
			Close();
			Ventana_Nueva->Show();
			event.Skip();
		}
	}
	
}

Ventana3Hija::~Ventana3Hija() {
	
}


void Ventana3Hija::AgregarProductoLista( wxCommandEvent& event )  {
	int codigo = stoi(wx_to_std(m_codigo->GetValue()));	
	Producto agregado;
	
	if((m_lista_productos->GetSelection() == wxNOT_FOUND ) and ( _prods->existe(codigo))){
		
		agregado = _prods->BuscarProducto(codigo);
		_pedido.agregarProducto(stoi(wx_to_std(m_codigo->GetValue())),stoi(wx_to_std(m_cantidad->GetValue())), *_prods);
		
		m_grilla->AppendRows(1);
		//m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,m_codigo->GetValue());
		m_codigo->SetValue("");
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(agregado.nombre));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,c_to_wx(agregado.marca));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
		m_cantidad->SetValue("");
		
	}else{
		if( (m_lista_productos->GetSelection() != wxNOT_FOUND) and (m_codigo->IsEmpty()) ) {
			int pos = m_lista_productos->GetSelection();
			
			agregado = _prods->BuscarProducto(_prods->VerCodigo(pos));
			_pedido.agregarProducto(_prods->VerCodigo(pos),stoi(wx_to_std(m_cantidad->GetValue())), *_prods);
			
			m_grilla->AppendRows(1);
			
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx((to_string(agregado.codigo))));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(agregado.nombre));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,c_to_wx(agregado.marca));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
			m_cantidad->SetValue("");
		}else{
			if((m_codigo->IsEmpty()) and (m_lista_productos->GetSelection() == wxNOT_FOUND)){
				wxMessageBox("Debe seleccionar un producto o ingresar el codigo del producto que busque","Error");
			}else{
				wxMessageBox("El codigo ingresado es erroneo o ah intentado ingresar un producto diferente al del codigo","Error");
			}
		}
	}
	
	event.Skip();
}

void Ventana3Hija::GuardarArchivo( wxCommandEvent& event )  {
	_pedido.armarArchivoTexto();
	wxMessageBox("muy bien");
	
	m_grilla->DeleteRows(0,_pedido.getTamanio());
	_pedido.vaciarVectores();
	event.Skip();
}


void Ventana3Hija::ClickDerechoProducto( wxGridEvent& event )  {
	event.Skip();
}

