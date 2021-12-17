#ifndef VENTANA2HIJA_H
#define VENTANA2HIJA_H
#include "wxfb_project.h"

class Ventana2HIja : public Ventana2 {
	
private:
	
protected:
	void to_productos( wxCommandEvent& event )  override;
	void to_pedidos( wxCommandEvent& event )  override;
	void VerPagar( wxCommandEvent& event )  override;
	void OnClickAgregar( wxCommandEvent& event )  override;
	void OnClickVerFiar( wxCommandEvent& event )  override;
	
public:
	Ventana2HIja(wxWindow *parent=NULL);
	~Ventana2HIja();
};

#endif

