#ifndef ACTUALIZARPRECIOPRODUCTO_H
#define ACTUALIZARPRECIOPRODUCTO_H
#include "wxfb_project.h"

class ActualizarPrecioProducto : public ActualizarPrecio {
	
private:
	
protected:
	void OnButtonClickActualizarPrecio( wxCommandEvent& event );  //override;
	void OnButtonClickEliminarProducto( wxCommandEvent& event );// override;
	void OnButtonClickNuevoPrecio( wxCommandEvent& event )  override;
	
public:
	ActualizarPrecioProducto(wxWindow *parent=NULL);
	~ActualizarPrecioProducto();
};

#endif

