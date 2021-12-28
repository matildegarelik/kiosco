#include "Ventana3Hija.h"
#include "Ventana2HIja.h"
#include "Ventana4HIja.h"
#include "WxFunciones.h"
#include <wx/msgdlg.h>
#include "VentanaValidarHija.h"
#include <string>
#include <wx/wx.h>
#include "Productos.h"
#include <wx/string.h>
#include <wx/arrstr.h>
using namespace std;


bool Ventana3Hija::EsNumero(const string& str){
	for (char const &c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}

Ventana3Hija::Ventana3Hija(wxWindow *parent, Productos *prods) : Ventana3(parent) {
	_prods=prods;
	
	vector<Producto>::iterator A, B;
	tie(A, B)=_prods->iteradores();
	sort(A,B,OrdenarPorNombre);
	wxArrayString lista_string;
	for(int i=0;i<_prods->DevolverTamanio();i++) { 
		lista_string.Add(std_to_wx(_prods->VerNombre(i)));
//		m_lista_productos->Append(std_to_wx(_prods->VerNombre(i)));
	}
	m_lista_productos->Append(lista_string);
}

void Ventana3Hija::to_venta( wxCommandEvent& event )  {

//	Ventana2HIja *win = new Ventana2HIja(NULL, _prods);
//	bool paso;
//	paso = Validar(,event,_prods,_pedido);
//	if (paso){ Close();}
	
	VentanaValidarHija Ventana_val(this);
	
	if(m_pedido.getTamanio() == 0){
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

	if(m_pedido.getTamanio() == 0){
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
	int codigo;
	int cantidad;
	int seleccion = m_lista_productos->GetSelection()-1;
	string cod_string = wx_to_std(m_codigo->GetValue());
	string cant_string = wx_to_std(m_cantidad->GetValue());
	
	Producto agregado;
	
	if((EsNumero(cod_string)) and !(m_codigo->IsEmpty())){
		codigo = stoi(cod_string);	
	}else{
		if(!m_codigo->IsEmpty()){
			codigo = -1;
			wxMessageBox("Intentó ingresar un codigo no numérico","Error");
		};
		codigo = -1;
	}

	if((EsNumero(cant_string)) and !(m_cantidad->IsEmpty())){
		cantidad = stoi(cant_string);	
	}else{
		if(!m_cantidad->IsEmpty()){
			codigo = -1;
			wxMessageBox("Intentó ingresar una cantidad no numérica","Error");
		};
		cantidad = -1;
	}
	if((m_lista_productos->GetSelection() == 0 ) and ( _prods->existe(codigo)) and (cantidad != -1)){
	
		agregado = _prods->BuscarProducto(codigo);
		m_pedido.agregarProducto(stoi(wx_to_std(m_codigo->GetValue())),stoi(wx_to_std(m_cantidad->GetValue())), *_prods);
		
		m_grilla->AppendRows(1);
		//m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,m_codigo->GetValue());
		m_codigo->SetValue("");
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(agregado.nombre));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,c_to_wx(agregado.marca));
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
		m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,4,"X");
		m_cantidad->SetValue("");
			
	}else{
		if( (m_lista_productos->GetSelection() > 0) and (codigo == -1) and (cantidad != -1) ) {
			int pos = m_lista_productos->GetSelection()-1;
			
			agregado = _prods->BuscarProducto(_prods->VerCodigo(pos));
			//			cout<<agregado;
			m_pedido.agregarProducto(_prods->VerCodigo(pos),stoi(wx_to_std(m_cantidad->GetValue())), *_prods);
			
			m_grilla->AppendRows(1);
			
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,0,std_to_wx((to_string(agregado.codigo))));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,1,c_to_wx(agregado.nombre));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,2,c_to_wx(agregado.marca));
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,3,m_cantidad->GetValue());
			m_grilla->SetCellValue(m_grilla->GetNumberRows()-1,4,"X");
			m_cantidad->SetValue("");
			m_lista_productos->SetSelection(0);
		}else{
			if((codigo == -1) and (m_lista_productos->GetSelection() <= 0)){
				wxMessageBox("Debe seleccionar un producto o ingresar el codigo del producto que busque","Error");
			}else{
				wxMessageBox("El código ingresado es erroneo o ha intentado ingresar un producto diferente al del código","Error");
			}
		}
	}

	event.Skip();
}

void Ventana3Hija::GuardarArchivo( wxCommandEvent& event )  {
	m_pedido.armarArchivoTexto();
	wxMessageBox("Muy Bien");
	
	m_grilla->DeleteRows(0,m_pedido.getTamanio());
	m_pedido.vaciarVectores();
	event.Skip();
}


void Ventana3Hija::ClickDerechoProducto( wxGridEvent& event )  {
	event.Skip();
}

void Ventana3Hija::Eliminar( wxGridEvent& event )  {
	if(event.GetCol()==4){
		m_pedido.eliminarProducto(event.GetRow());
		m_grilla->DeleteRows(event.GetRow());
	}
	event.Skip();
}

