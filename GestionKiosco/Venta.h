#ifndef VENTA_H
#define VENTA_H
#include "Venta.h"
#include "Productos.h"
#include <iostream>
#include "Repositorio.h"

using namespace std;

struct Detalle{
	Producto p;
	int cantidad;
};
struct Fecha{
	int dia, mes, anio;
};

struct DetalleYFecha{
	Detalle d;
	Fecha f;
};

struct Compra{
	char cliente[50];
	Fecha f;
	float total;
};

bool operator==(Fecha f1, Fecha f2);
bool operator==(Compra c1, Compra c2);
bool operator==(Detalle d1, Detalle d2);
bool operator==(DetalleYFecha d1, DetalleYFecha d2);
bool operator<(Fecha f1, Fecha f2);
ostream &operator<<(ostream &o, Fecha &f);



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
	void Pagar(Productos &prods); // tambien actualiza stock en vector de productos y archivo de detalles
	void Pagar();
	
	vector<Compra> CargarFiados(); //archivo binario
	void MarcarPagado(Compra c); //guarda vector y archivos
	void MarcarPagado(int indice); //guarda vector y archivos
	void Ordenar();
	
	vector<Detalle> prods_mas_vendidos();
	vector<Compra> ultimas_ventas();
	vector<DetalleYFecha> ventas_por_producto(int codigo);
	vector<Compra> ventas_por_cliente(string nombre);
	
private:
	vector<Detalle> _detalles;
	char _cliente[50];
	bool _pagado;
	Fecha _fecha;
	
	Repositorio<Compra> repo_ventas;
	Repositorio<Compra> repo_fiados;
	Repositorio<DetalleYFecha> repo_detalles;
};

#endif

