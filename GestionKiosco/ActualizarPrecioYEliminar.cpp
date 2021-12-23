#include "ActualizarPrecioYEliminar.h"
#include "WxFunciones.cpp"
ActualizarPrecioYEliminar::ActualizarPrecioYEliminar(wxWindow *parent, Productos *prods, int codigo) : ActualizarPrecio_Eliminar(parent) {
	this->prods = prods;
	m_codigo = codigo;
	Producto p = this->prods->BuscarProducto(m_codigo);
	m_precio_nuevo->SetValue(to_string(p._precio));
}

void ActualizarPrecioYEliminar::OnButtonClickActualizarPrecio( wxCommandEvent& event )  {
	
	float nuevo_precio = stof(wx_to_std(m_precio_nuevo->GetValue()));
	prods->ActualizarPrecio(m_codigo,nuevo_precio);
	prods->GuardarCambios("productos.dat");
	EndModal(1);
}

void ActualizarPrecioYEliminar::OnButtonClickEliminarProducto( wxCommandEvent& event )  {
	
	prods->EliminarProducto(m_codigo);
	EndModal(1);
}

ActualizarPrecioYEliminar::~ActualizarPrecioYEliminar() {
	
}

