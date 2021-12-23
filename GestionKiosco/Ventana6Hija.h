#ifndef VENTANA6HIJA_H
#define VENTANA6HIJA_H
#include "wxfb_project.h"
#include "Productos.h"
#include "Venta.h"
#include "HistoricoVentas.h"

class Ventana6Hija : public Ventana6 {
	
private:
	Productos *_prods;
	Venta _venta;
	HistoricoVentas hist;
protected:
	void CambioOpcion( wxCommandEvent& event )  override;
	void to_fiados( wxCommandEvent& event )  override;
	void to_productos( wxCommandEvent& event )  override;
	void ConsultarHistorial( wxCommandEvent& event )  override;
	
public:
	Ventana6Hija(wxWindow *parent=NULL, Productos *prods=NULL);
	~Ventana6Hija();
};

#endif

