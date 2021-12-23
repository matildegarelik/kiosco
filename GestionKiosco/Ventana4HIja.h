#ifndef VENTANA4HIJA_H
#define VENTANA4HIJA_H
#include "wxfb_project.h"
#include "Productos.h"
#include "Repositorio.h"
#include "Venta.h"
#include "HistoricoVentas.h"

class Ventana4HIja : public Ventana4 {
	
private:
	Productos *m_prods;
	Repositorio<DetalleYFecha> repo_ingresos;
protected:
	void Ingresar( wxCommandEvent& event )  override;
	void to_pedido( wxCommandEvent& event )  override;
	void to_fiados( wxCommandEvent& event )  override;
	
public:
	Ventana4HIja(wxWindow *parent=NULL, Productos *prods=NULL);
	~Ventana4HIja();
};

#endif

