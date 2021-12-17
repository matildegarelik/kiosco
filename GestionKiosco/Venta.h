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

ostream &operator<<(ostream &o, Fecha &f) {
	o << f.dia <<'/'<< f.mes<<'/'<<f.anio;
	return o;
}

bool operator==(Fecha f1, Fecha f2) {
	return f1.dia==f2.dia and f1.mes==f2.mes and f1.anio==f2.anio;
}

bool operator==(Compra c1, Compra c2) {
	return c1.cliente==c2.cliente and c1.f==c2.f and c1.total==c2.total;
}
bool operator==(Detalle d1, Detalle d2) {
	return d1.cantidad ==d2.cantidad;
}
bool operator==(DetalleYFecha d1, DetalleYFecha d2) {
	return d1.d==d2.d and d1.f==d2.f;
}

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
	
	
	vector<Compra> CargarFiados(string archivo_fiados); //archivo binario
	void MarcarPagado(Compra c); //guarda vector y archivos
	void Ordenar();
	
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

