#include "AgregarNuevoProducto.h"
#include "Productos.h"
#include "WxFunciones.h"

AgregarNuevoProducto::AgregarNuevoProducto(wxWindow *parent, Productos *prods) : AgregarProducto(parent) {
	_prods=prods;
}

void AgregarNuevoProducto::OnButonClickAgregarProducto( wxCommandEvent& event )  {
	Producto aux;
	strcpy(aux.nombre,(wx_to_std(m_txt_nombre->GetValue()).c_str()));
	strcpy(aux.marca,(wx_to_std(m_txt_marca->GetValue()).c_str()));
	aux.codigo=stoi(wx_to_std(m_txt_codigo->GetValue()));
	strcpy(aux.tipo,(wx_to_std(m_txt_tipo->GetValue()).c_str()));
	aux.stock=stoi(wx_to_std(m_txt_sock->GetValue()));
	aux.precio=stoi(wx_to_std(m_txt_precio->GetValue()));
	_prods->AgregarProducto(aux);
	EndModal(1);
	//event.Skip();
}

AgregarNuevoProducto::~AgregarNuevoProducto() {
	
}

