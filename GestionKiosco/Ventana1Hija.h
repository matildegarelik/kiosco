#ifndef VENTANA1HIJA_H
#define VENTANA1HIJA_H
#include "wxfb_project.h"

class Ventana1Hija : public Ventana1 {
	
private:
	
protected:
	void to_consultas( wxCommandEvent& event )  override;
	void to_ventas( wxCommandEvent& event )  override;
	
public:
	Ventana1Hija(wxWindow *parent=NULL);
	~Ventana1Hija();
};

#endif

