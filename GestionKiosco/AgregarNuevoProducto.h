#ifndef AGREGARNUEVOPRODUCTO_H
#define AGREGARNUEVOPRODUCTO_H
#include "wxfb_project.h"
#include "Productos.h"

class AgregarNuevoProducto : public AgregarProducto {
	
private:
	Productos *_prods;
protected:
	void OnButonClickAgregarProducto( wxCommandEvent& event )  override;
	
public:
	AgregarNuevoProducto(wxWindow *parent=NULL, Productos *prods=NULL);
	~AgregarNuevoProducto();
};

#endif

