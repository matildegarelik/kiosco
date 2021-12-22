#include "AgregarNuevoProducto.h"
#include "Productos.h"
#include "WxFunciones.cpp"

AgregarNuevoProducto::AgregarNuevoProducto(wxWindow *parent, Productos *prods) : AgregarProducto(parent) {
	_prods=prods;
}

void AgregarNuevoProducto::OnButonClickAgregarProducto( wxCommandEvent& event )  {
	Producto aux;
	strcpy(aux._nombre,(wx_to_std(m_txt_nombre->GetValue()).c_str()));
	strcpy(aux._marca,(wx_to_std(m_txt_marca->GetValue()).c_str()));
	aux._codigo=stoi(wx_to_std(m_txt_codigo->GetValue()));
	strcpy(aux._tipo,(wx_to_std(m_txt_tipo->GetValue()).c_str()));
	aux._stock=stoi(wx_to_std(m_txt_sock->GetValue()));
	aux._precio=stoi(wx_to_std(m_txt_precio->GetValue()));
	_prods->AgregarProducto(aux);
	EndModal(1);
	//event.Skip();
}

AgregarNuevoProducto::~AgregarNuevoProducto() {
	
}

