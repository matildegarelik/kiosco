#ifndef VENTANA5HIJA_H
#define VENTANA5HIJA_H
#include "wxfb_project.h"
#include "Productos.h"
#include "Venta.h"
#include "HistoricoVentas.h"

class Ventana5Hija : public Ventana5 {
	
private:
	Productos *m_prods;
	Venta v;
	HistoricoVentas hist;
protected:
	void m_tabla_fiadosOnGridCellLeftClick( wxGridEvent& event )  override;
	void to_stock( wxCommandEvent& event )  override;
	void to_consultas( wxCommandEvent& event )  override;
	
public:
	Ventana5Hija(wxWindow *parent=NULL, Productos *prods=NULL);
	~Ventana5Hija();
};

#endif

