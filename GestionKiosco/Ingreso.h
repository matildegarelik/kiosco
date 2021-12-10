#ifndef INGRESO_H
#define INGRESO_H
#include "Venta.h"
#include <iostream>
using namespace std;

class Ingreso {
public:
	Ingreso(int cod_prod, const Productos &prods, int cant, Fecha f);
	void GuardarCambios(string archivo_ingresos, string archivo_productos, Productos &prods);
private:
	Producto _producto;
	int _cantidad;
	Fecha _fecha;
};

#endif

