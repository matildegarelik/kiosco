#ifndef VENTANAVALIDARHIJA_H
#define VENTANAVALIDARHIJA_H
#include "wxfb_project.h"
#include <string>
using namespace std;

class VentanaValidarHija : public VetanaValidar {
	
private:
	string descripcion_error;
protected:
	void PasarPestania( wxCommandEvent& event )  override;
	void MantenersePestania( wxCommandEvent& event )  override;
	
public:
	VentanaValidarHija(wxWindow *parent=NULL);
	~VentanaValidarHija();
};

#endif

