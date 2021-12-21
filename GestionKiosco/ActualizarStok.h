#ifndef ACTUALIZARSTOK_H
#define ACTUALIZARSTOK_H
#include "wxfb_project.h"

class ActualizarStok : public BaseAgregarStock {
	
private:
	
protected:
	void OnButtonClickAgregarStock( wxCommandEvent& event )  override;
	
public:
	ActualizarStok(wxWindow *parent=NULL);
	~ActualizarStok();
};

#endif

