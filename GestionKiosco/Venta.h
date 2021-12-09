#ifndef VENTA_H
#define VENTA_H
#include "Venta.h"
#include "Productos.h"

struct Detalle{
	Producto p;
	int cantidad;
};

class Venta {
public:
	Venta();
	int VerCantidad(int codigo);
	void AgregarDetalle(int codigo, int cantidad);
	void EliminarDetalle(int indice);
	float CalcularTotal();
	void Pagar(Productos &p); // tambien actualiza stock en vector de productos
	void Fiar(string cliente, string nombre_archivo);
	void GuardarVenta(string archivo_ventas, string archivo_fiados); //binario
	
	void CargarFiados(string archivo_fiados); //archivo binario
	void MarcarPagado(int indice); //guarda vector y archivos
	void Ordenar();
	
private:
	vector<Detalle> _detalles;
	char _cliente[50];
	bool _pagado;
	int _fecha;
};

#endif

