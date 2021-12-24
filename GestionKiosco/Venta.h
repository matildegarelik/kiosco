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


bool operator==(Fecha f1, Fecha f2);
bool operator==(Detalle d1, Detalle d2);

bool operator<(Fecha f1, Fecha f2);
ostream &operator<<(ostream &o, Fecha &f);

class Venta {
public:
	Venta();
	int VerCantidad(int indice);
	Fecha getFechaActual();
	
	void SetCliente(string cliente);
	void SetFecha(int dia, int mes, int anio);
	void SetFecha(Fecha f);
	void SetPago(bool pago);
	
	char* GetCliente();
	Fecha GetFecha() const;
	bool GetPago() const;
	vector<Detalle> GetDetalles() const;
	
	void AgregarDetalle(int codigo, int cantidad, const Productos &prods);
	void EliminarDetalle(int indice);
	float CalcularTotal();
	Venta Pagar(Productos &prods); // tambien actualiza stock en vector de productos y archivo de detalles
	int getTamanio();
private:
	vector<Detalle> m_detalles;
	char m_cliente[50];
	bool m_pagado;
	Fecha m_fecha;
};

#endif

