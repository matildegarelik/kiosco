#ifndef AGREGARNUEVOPRODUCTO_H
#define AGREGARNUEVOPRODUCTO_H
#include "wxfb_project.h"

class AgregarNuevoProducto : public AgregarProducto {
	
private:
	
protected:
	void OnButonClickAgregarProducto( wxCommandEvent& event )  override;
	
public:
	AgregarNuevoProducto(wxWindow *parent=NULL);
	~AgregarNuevoProducto();
};

#endif

