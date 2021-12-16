#include <wx/image.h>
#include "Application.h"
#include "Ventana2HIja.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	Ventana2HIja *win = new Ventana2HIja(NULL);
	win->Show();
	return true;
}


