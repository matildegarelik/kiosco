#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "Producto.h"

class Producto {
private:
	char _nombre[30], _marca[50], _tipo[30];
	int _codigo, _stock;
	float _precio;
public:
	Producto();
	char* VerNombre();
	char* VerMarca();
	char* VerTipo();	
	int VerCodigo();
	void CambiarStock(int A);
	int VerStock();
	float VerPrecio();
	void ActualizarPrecio(int A);
};

#endif

