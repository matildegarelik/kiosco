#ifndef VENTANA6HIJA_H
#define VENTANA6HIJA_H
#include "wxfb_project.h"

class Ventana6Hija : public Ventana6 {
	
private:
	
protected:
	void to_fiados( wxCommandEvent& event )  override;
	void to_productos( wxCommandEvent& event )  override;
	void ConsultarHistorial( wxCommandEvent& event )  override;
	
public:
	Ventana6Hija(wxWindow *parent=NULL);
	~Ventana6Hija();
};

#endif

