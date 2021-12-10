#include "Producto.h"

Producto::Producto() {
	Producto();
}
char* Producto::VerNombre(){return _nombre;}
char* Producto::VerMarca(){return _marca;}
char* Producto::VerTipo(){return _tipo;}	
int Producto::VerCodigo(){return _codigo;}
int Producto::VerStock(){return _stock;}
void Producto::CambiarStock(int A){ _stock-=A;}
float Producto::VerPrecio(){return _precio;}
void Producto::ActualizarPrecio(int A){_precio=A;}

