#ifndef VALIDARFIAR_H
#define VALIDARFIAR_H
#include "wxfb_project.h"
#include "Productos.h"
#include "HistoricoVentas.h"

class ValidarFiar : public BaseValidarFiar {
	
private:
	Productos *m_prods;
	int m_i;
	HistoricoVentas hist;
protected:
	void Pagar( wxCommandEvent& event )  override;
	void Cerrar( wxCommandEvent& event )  override;
	
public:
	ValidarFiar(wxWindow *parent=NULL,int indice=0, Productos *prods=NULL);
	~ValidarFiar();
};

#endif

