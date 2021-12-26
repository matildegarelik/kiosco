#ifndef VENTANA1ACEPTARHIJA_H
#define VENTANA1ACEPTARHIJA_H
#include "wxfb_project.h"

class Ventana1Aceptarhija : public MyDialog7 {
	
private:
	
protected:
	void OnButtonAceptar( wxCommandEvent& event )  override;
	
public:
	Ventana1Aceptarhija(wxWindow *parent=NULL);
	~Ventana1Aceptarhija();
};

#endif

