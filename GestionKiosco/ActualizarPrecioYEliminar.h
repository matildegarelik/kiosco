#ifndef ACTUALIZARPRECIOYELIMINAR_H
#define ACTUALIZARPRECIOYELIMINAR_H
#include "wxfb_project.h"
#include "Productos.h"

class ActualizarPrecioYEliminar : public ActualizarPrecio_Eliminar {
	
private:
	Productos *prods;
	int m_codigo;
protected:
	void ActualizarStock( wxCommandEvent& event )  override;
	void OnButtonClickActualizarPrecio( wxCommandEvent& event )  override;
	void OnButtonClickEliminarProducto( wxCommandEvent& event )  override;
	
public:
	ActualizarPrecioYEliminar(wxWindow *parent=NULL ,Productos *prods = NULL,int m_codigo=0);
	~ActualizarPrecioYEliminar();
};

#endif

