#include "Venta.h"
#include <vector>
#include <cstring>
using namespace std;

Venta::Venta():
	repo_ventas("ventas.dat"),
	repo_fiados("fiados.dat"),
	repo_detalles("detalles.dat"){
}

int Venta::VerCantidad(int indice){
	return _detalles[indice].cantidad;
}

void Venta::SetCliente(string cliente){
	strcpy(_cliente, cliente.c_str());
}
void Venta::SetFecha(int dia, int mes, int anio){
	_fecha = Fecha{dia,mes,anio};
}
void Venta::SetPago(bool pago){
	_pagado=pago;
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

void Venta::Pagar(Productos &prods){
	// actualiza stock en vector de productos
	for(Detalle &d: _detalles){
		prods.ActualizarStock("productos.dat",d.p._codigo,d.cantidad);
		prods.GuardarCambios("productos.dat",prods.BuscarIndice(d.p._codigo));
		
		DetalleYFecha d_y_f = {d,_fecha};
		repo_detalles.guardarNuevo(d_y_f);
		
	}
	string arch;
	// Guardar en archivo_ventas si se pago, sino en fiados
	Compra c;
	strcpy(c.cliente,_cliente);
	c.f=_fecha;
	c.total=CalcularTotal();
	if(this->_pagado)repo_ventas.guardarNuevo(c);
	else repo_fiados.guardarNuevo(c);
}


// FIADOS
vector<Compra> Venta::CargarFiados(){
	vector<Compra> fiados;
	fiados = repo_fiados.buscarTodos();
	return fiados;
}
void Venta::MarcarPagado(Compra c){
	//borra registro compra de fiados y agrega a ventas ese registro
	repo_fiados.eliminarPermanente(c);
	repo_ventas.guardarNuevo(c);	
}

void Venta::Ordenar(){
	
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

ostream &operator<<(ostream &o, Fecha &f) {
	o << f.dia <<'/'<< f.mes<<'/'<<f.anio;
	return o;
}

