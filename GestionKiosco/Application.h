#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Productos.h"

class Application : public wxApp {
	Productos prods;
public:
	virtual bool OnInit();
};

#endif
