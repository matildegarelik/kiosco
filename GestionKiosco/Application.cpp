#include <wx/image.h>
#include "Application.h"
#include "Ventana1Hija.h"
#include "Venta.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	//Producto p = {"chocolate negro\0","milka\0","golosinas\0",1211,10,34.99};
	//Producto p2 = {"chocolate blanco\0","milka\0","golosinas\0",1210,15,39.99};
	//prods.AgregarProducto("productos.dat",p);
	//prods.AgregarProducto("productos.dat",p2);
	//11prods.GuardarCambios("productos.dat");
	//Venta v;
	//v.SetCliente("matilde");
	//v.SetFecha(19,12,2021);
	//v.SetPago(false);
	//v.Pagar(prods);
	wxInitAllImageHandlers();
	Ventana1Hija *win = new Ventana1Hija(NULL, &prods);
	win->Show();
	return true;
}


