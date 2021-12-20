#ifndef HIJAFIAR_H
#define HIJAFIAR_H
#include "wxfb_project.h"
#include "Venta.h"
#include "Productos.h"

class HijaFiar : public BaseFiar {
	
private:
	Venta *_venta;
	Productos *_prods;
protected:
	void MarcarFIado( wxCommandEvent& event )  override;
	
public:
	HijaFiar(wxWindow *parent=NULL, Venta *venta=NULL, Productos *prods=NULL);
	~HijaFiar();
};

#endif

