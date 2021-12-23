#ifndef BASEPAGARHIJA_H
#define BASEPAGARHIJA_H
#include "wxfb_project.h"
#include "Venta.h"
#include "Productos.h"
#include "HistoricoVentas.h"

class BasePagarHija : public BasePagar {
	
private:
	Venta *m_venta;
	Productos *m_prods;
	HistoricoVentas hist;
protected:
	void MarcarPagado( wxCommandEvent& event )  override;
	
public:
	BasePagarHija(wxWindow *parent=NULL, Venta *venta=NULL, Productos *prods=NULL);
	~BasePagarHija();
};

#endif

