#include "Venta.h"
#include <vector>
#include <cstring>
using namespace std;

Venta::Venta(){
}

int Venta::VerCantidad(int indice){
	return _detalles[indice].cantidad;
}

void Venta::SetCliente(string cliente){
	strcpy(_cliente, cliente.c_str());
}
void Venta::SetFecha(int dia, int mes, int anio){
	_fecha.dia=dia;
	_fecha.mes=mes;
	_fecha.anio=anio;
}
void Venta::SetPago(bool pago){
	_pagado=pago;
}

char* Venta::GetCliente(){
	return _cliente;
}
Fecha Venta::GetFecha() const{
	return _fecha;
}
bool Venta::GetPago() const{
	return _pagado;
}
vector<Detalle> Venta::GetDetalles() const{
	return _detalles;
}

void Venta::AgregarDetalle(int codigo, int cantidad, const Productos &prods){
	Producto p = prods.BuscarProducto(codigo);
	Detalle d = {p,cantidad};
	_detalles.push_back(d);
}
void Venta::EliminarDetalle(int indice){
	_detalles.erase(_detalles.begin()+indice);
}
float Venta::CalcularTotal(){
	float total=0;
	for(Detalle &d: _detalles) total+=d.cantidad*d.p._precio;
	return total;
}


Venta Venta::Pagar(Productos &prods){
	// actualiza stock en vector de productos
	for(Detalle &d: _detalles){
		prods.ActualizarStock("productos.dat",d.p._codigo,d.cantidad);
		prods.GuardarCambios("productos.dat",prods.BuscarIndice(d.p._codigo));
	}
	
	// Guardar en archivo_ventas si se pago, sino en fiados
	return *this;
}




bool operator==(Fecha f1, Fecha f2) {
	return f1.dia==f2.dia and f1.mes==f2.mes and f1.anio==f2.anio;
}

bool operator==(Detalle d1, Detalle d2) {
	return d1.cantidad ==d2.cantidad;
}

ostream &operator<<(ostream &o, Fecha &f) {
	o << f.dia <<'/'<< f.mes<<'/'<<f.anio;
	return o;
}
bool operator<(Fecha f1, Fecha f2){
	return f1.anio*10000+f1.mes*100+f1.dia<f2.anio*10000+f2.mes*100+f2.dia;
}
