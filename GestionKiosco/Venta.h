#ifndef VENTA_H
#define VENTA_H
#include "Venta.h"
#include "Productos.h"

struct Detalle{
	Producto p;
	int cantidad;
};
struct Fecha{
	int dia, mes, anio;
};
struct Compra{
	char cliente[50];
	Fecha f;
	float total;
};

class Venta {
public:
	Venta();
	int VerCantidad(int indice);
	
	void SetCliente(string cliente);
	void SetFecha(int dia, int mes, int anio);
	void SetPago(bool pago);
	
	void AgregarDetalle(int codigo, int cantidad, const Productos &prods);
	void EliminarDetalle(int indice);
	float CalcularTotal();
	void Pagar(Productos &prods); // tambien actualiza stock en vector de productos
	
	void GuardarVenta(string nombre_archivo); //binario
	
	vector<Compra> CargarFiados(string archivo_fiados); //archivo binario
	void MarcarPagado(string archivo_ventas, string archivo_fiados, int indice); //guarda vector y archivos
	void Ordenar();
	
private:
	vector<Detalle> _detalles;
	char _cliente[50];
	bool _pagado;
	Fecha _fecha;
};

#endif

