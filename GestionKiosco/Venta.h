#ifndef VENTA_H
#define VENTA_H
#include "Venta.h"
#include "Productos.h"

struct Detalle{
	Producto p;
	int cantidad, fecha;
};

struct Fiado{
	Detalle d;
	string cliente;
	bool pagado=false;
};

class Venta {
public:
	Venta();
	int VerCantidad(int codigo);
	void AgregarVenta(int codigo, int cantidad);
	void EliminarVenta(int indice);
	float CalcularTotal();
	void Pagar(Productos &p); // tambien actualiza stock en vector de productos
	void Fiar(string cliente, string nombre_archivo);
	void GuardarVenta(string nombre_archivo); //binario
private:
	vector<Producto> _prods;
	vector<int> _cantidades;
};

#endif

