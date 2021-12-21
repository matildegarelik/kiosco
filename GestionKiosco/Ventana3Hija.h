#ifndef VENTANA3HIJA_H
#define VENTANA3HIJA_H
#include "wxfb_project.h"
#include "Productos.h"
#include "Pedido.h"

class Ventana3Hija : public Ventana3 {
	
private:
	Productos *_prods;
	Pedido _pedido;
protected:
	void ClickDerechoProducto( wxGridEvent& event )  override;
	void AgregarProductoLista( wxCommandEvent& event )  override;
	void GuardarArchivo( wxCommandEvent& event )  override;
	void to_venta( wxCommandEvent& event )  override;
	void to_stock( wxCommandEvent& event )  override;
	
public:
	Ventana3Hija(wxWindow *parent=NULL, Productos *prods=NULL);
	~Ventana3Hija();
};

#endif

