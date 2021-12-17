#ifndef VENTANA4HIJA_H
#define VENTANA4HIJA_H
#include "wxfb_project.h"

class Ventana4HIja : public Ventana4 {
	
private:
	
protected:
	void to_pedido( wxCommandEvent& event )  override;
	void to_fiados( wxCommandEvent& event )  override;
	
public:
	Ventana4HIja(wxWindow *parent=NULL);
	~Ventana4HIja();
};

#endif

