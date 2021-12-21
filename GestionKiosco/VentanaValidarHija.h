#ifndef VENTANAVALIDARHIJA_H
#define VENTANAVALIDARHIJA_H
#include "wxfb_project.h"

class VentanaValidarHija : public VetanaValidar {
	
private:
	
protected:
	void PasarPestania( wxCommandEvent& event )  override;
	void MantenersePestania( wxCommandEvent& event )  override;
	
public:
	VentanaValidarHija(wxWindow *parent=NULL);
	~VentanaValidarHija();
};

#endif

