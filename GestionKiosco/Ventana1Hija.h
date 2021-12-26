#ifndef VENTANA1HIJA_H
#define VENTANA1HIJA_H
#include "wxfb_project.h"
#include "Productos.h"

class Ventana1Hija : public Ventana1 {
	
private:
	Productos *prods;
protected:
	//void OnComboBuscarPor( wxCommandEvent& event )  override;
	void OnEnterBuscarPor( wxCommandEvent& event )  override;
	void ComboBoxOrdenarPor( wxCommandEvent& event )  override;
	void FiadosBoton( wxCommandEvent& event )  override;
	void AgregarProductoBoton( wxCommandEvent& event )  override;
	void DobleClickCellLeft( wxGridEvent& event )  override;
	void AgregarStockBoton( wxCommandEvent& event )  override;
	void HacerPedidoBoton( wxCommandEvent& event )  override;
	void to_consultas( wxCommandEvent& event )  override;
	void to_ventas( wxCommandEvent& event )  override;
	void Actualizar();
	void Ver(Producto aux);
	
public:
	Ventana1Hija(wxWindow *parent=NULL, Productos *prods=NULL);
	~Ventana1Hija();
};

#endif

