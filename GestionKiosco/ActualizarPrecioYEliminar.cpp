#include "ActualizarPrecioYEliminar.h"
#include "ActualizarPrecioProducto.h"

ActualizarPrecioYEliminar::ActualizarPrecioYEliminar(wxWindow *parent) : ActualizarPrecio_Eliminar(parent) {
	
}

void ActualizarPrecioYEliminar::OnButtonClickActualizarPrecio( wxCommandEvent& event )  {
	ActualizarPrecioProducto *win= new ActualizarPrecioProducto(this);
	win->Show();
}

void ActualizarPrecioYEliminar::OnButtonClickEliminarProducto( wxCommandEvent& event )  {
	event.Skip();
}

ActualizarPrecioYEliminar::~ActualizarPrecioYEliminar() {
	
}

