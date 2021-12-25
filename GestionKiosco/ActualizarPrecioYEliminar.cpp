#include "ActualizarPrecioYEliminar.h"
#include "WxFunciones.h"
ActualizarPrecioYEliminar::ActualizarPrecioYEliminar(wxWindow *parent, Productos *prods, int codigo) : ActualizarPrecio_Eliminar(parent) {
	this->prods = prods;
	m_codigo = codigo;
	Producto p = this->prods->BuscarProducto(m_codigo);
	m_precio_nuevo->SetValue(to_string(p.precio));
	m_stock_nuevo->SetValue(to_string(p.stock));
}

void ActualizarPrecioYEliminar::OnButtonClickActualizarPrecio( wxCommandEvent& event )  {
	float nuevo_precio = stof(wx_to_std(m_precio_nuevo->GetValue()));
	prods->ActualizarPrecio(m_codigo,nuevo_precio);
	prods->GuardarCambios(prods->BuscarIndice(m_codigo));
	EndModal(1);
}

void ActualizarPrecioYEliminar::OnButtonClickEliminarProducto( wxCommandEvent& event )  {
	prods->EliminarProducto(m_codigo);
	EndModal(1);
}

ActualizarPrecioYEliminar::~ActualizarPrecioYEliminar() {
	
}

void ActualizarPrecioYEliminar::ActualizarStock( wxCommandEvent& event )  {
	int nuevo_stock = stoi(wx_to_std(m_stock_nuevo->GetValue()));
	prods->CambiarStock(m_codigo,nuevo_stock);
	EndModal(1);
	event.Skip();
}

