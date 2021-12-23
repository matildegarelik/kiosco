#ifndef HIJAFIAR_H
#define HIJAFIAR_H
#include "wxfb_project.h"
#include "Venta.h"
#include "Productos.h"
#include "HistoricoVentas.h"

class HijaFiar : public BaseFiar {
	
private:
	Venta *m_venta;
	Productos *m_prods;
	HistoricoVentas hist;
protected:
	void MarcarFIado( wxCommandEvent& event )  override;
	
public:
	HijaFiar(wxWindow *parent=NULL, Venta *venta=NULL, Productos *prods=NULL);
	~HijaFiar();
};

#endif

