#include "Venta.h"
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;

Venta::Venta(){
}

int Venta::VerCantidad(int indice){
	return m_detalles[indice].cantidad;
}

void Venta::SetCliente(string cliente){
	strcpy(m_cliente, cliente.c_str());
}
void Venta::SetFecha(int dia, int mes, int anio){
	m_fecha.dia=dia;
	m_fecha.mes=mes;
	m_fecha.anio=anio;
}

void Venta::SetFecha(Fecha f){
	m_fecha=f;
}

void Venta::SetPago(bool pago){
	m_pagado=pago;
}

char* Venta::GetCliente(){
	return m_cliente;
}
Fecha Venta::GetFecha() const{
	return m_fecha;
}
bool Venta::GetPago() const{
	return m_pagado;
}
vector<Detalle> Venta::GetDetalles() const{
	return m_detalles;
}

void Venta::AgregarDetalle(int codigo, int cantidad, const Productos &prods){
	Producto p = prods.BuscarProducto(codigo);
	Detalle d = {p,cantidad};
	m_detalles.push_back(d);
}
void Venta::EliminarDetalle(int indice){
	m_detalles.erase(m_detalles.begin()+indice);
}
float Venta::CalcularTotal(){
	float total=0;
	for(Detalle &d: m_detalles) total+=d.cantidad*d.p.precio;
	return total;
}


Venta Venta::Pagar(Productos &prods){
	// actualiza stock en vector de productos
	for(Detalle &d: m_detalles){
		prods.ActualizarStock("productos.dat",d.p.codigo,d.cantidad);
		prods.GuardarCambios("productos.dat",prods.BuscarIndice(d.p.codigo));
	}
	
	// Guardar en archivo_ventas si se pago, sino en fiados
	return *this;
}

Fecha Venta::getFechaActual(){
	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	
	Fecha fecha_actual = {day,month,year};
	return fecha_actual;
};


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
