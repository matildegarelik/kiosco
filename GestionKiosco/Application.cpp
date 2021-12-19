#include <wx/image.h>
#include "Application.h"
#include "Ventana1Hija.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	Ventana1Hija *win = new Ventana1Hija(NULL, &prods);
	win->Show();
	return true;
}


