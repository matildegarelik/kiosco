#ifndef VENTANA5HIJA_H
#define VENTANA5HIJA_H
#include "wxfb_project.h"

class Ventana5Hija : public Ventana5 {
	
private:
	
protected:
	void to_stock( wxCommandEvent& event )  override;
	void to_consultas( wxCommandEvent& event )  override;
	
public:
	Ventana5Hija(wxWindow *parent=NULL);
	~Ventana5Hija();
};

#endif

