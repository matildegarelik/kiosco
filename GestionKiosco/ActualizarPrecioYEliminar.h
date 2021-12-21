#ifndef ACTUALIZARPRECIOYELIMINAR_H
#define ACTUALIZARPRECIOYELIMINAR_H
#include "wxfb_project.h"

class ActualizarPrecioYEliminar : public ActualizarPrecio_Eliminar {
	
private:
	
protected:
	void OnButtonClickActualizarPrecio( wxCommandEvent& event )  override;
	void OnButtonClickEliminarProducto( wxCommandEvent& event )  override;
	
public:
	ActualizarPrecioYEliminar(wxWindow *parent=NULL);
	~ActualizarPrecioYEliminar();
};

#endif

