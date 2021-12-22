#include "ActualizarPrecioYEliminar.h"
#include "ActualizarPrecioProducto.h"
#include "WxFunciones.cpp"
ActualizarPrecioYEliminar::ActualizarPrecioYEliminar(wxWindow *parent) : ActualizarPrecio_Eliminar(parent) {
	
}

void ActualizarPrecioYEliminar::OnButtonClickActualizarPrecio( wxCommandEvent& event )  {
	ActualizarPrecioProducto *win= new ActualizarPrecioProducto(this);
	win->Show();
	float nuevo_precio = stoi(wx_to_std(m_actualizarPrecio));
	
	EndModal(1);
}

void ActualizarPrecioYEliminar::OnButtonClickEliminarProducto( wxCommandEvent& event )  {
	event.Skip();
}

ActualizarPrecioYEliminar::~ActualizarPrecioYEliminar() {
	
}

