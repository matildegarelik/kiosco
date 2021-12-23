#ifndef INGRESO_H
#define INGRESO_H
#include "Venta.h"
#include <iostream>
#include "HistoricoVentas.h"
using namespace std;

class Ingreso {
public:
	Ingreso(int cod_prod, const Productos &prods, int cant, Fecha f);
	void GuardarCambios(Productos &prods);
private:
	Producto m_producto;
	int m_cantidad;
	Fecha m_fecha;
	Repositorio<DetalleYFecha> repo_ingresos;
};

#endif

