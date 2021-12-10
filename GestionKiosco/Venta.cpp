#include "Venta.h"
#include <vector>
#include <cstring>
using namespace std;

Venta::Venta() {
	
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
	for(Detalle d: &_detalles) total+=d.cantidad*d.p.VerPrecio();
}
void Venta::Pagar(Productos &prods){
	// actualiza stock en vector de productos
	for(Detalle d: &_detalles){
		prods.ActualizarStock("productos.dat",d.p.VerCodigo(),d.cantidad);
		prods.GuardarCambios("productos.dat",prods.BuscarIndice(d.p.VerCodigo()))
	}
	string arch;
	// Guardar en archivo_ventas si se pago, sino en fiados
	if(this->_pagado)arch ="ventas.dat";
	else arch="fiados.dat";
	GuardarVenta(arch);
	
}

void Venta::GuardarVenta(string nombre_archivo){
	//binario
	Compra c = {_cliente,_fecha,CalcularTotal()};
	ofstream f(archivo_ventas,ios::binary|ios::app);
	f.write(reinterpret_cast<char*>(&c), sizeof(Compra));
	f.close();
}

// FIADOS
vector<Compra> Venta::CargarFiados(string archivo_fiados){
	vector<Compra> fiados;
	ifstream f(archivo_fiados,ios::binary|ios::ate);
	int size = f.tellg()/sizeof(Compra);
	f.seekg(0,ios::beg);
	for(int i =0; i<size; ++i){
		Compra c;
		f.read(reinterpret_cast<char*>(&c), sizeof(c));
		fiados.push_back(c);
	}
	return fiados;
}
void Venta::MarcarPagado(string archivo_ventas, string archivo_fiados, int indice){
	//borra registro compra de fiados y agrega a ventas ese registro
	Compra pagada;
	vector<Compra> fiados;
	ifstream f(archivo_fiados,ios::binary|ios::ate);
	int size = f.tellg()/sizeof(Compra);
	f.seekg(indice*sizeof(Compra));
	f.read(reinterpret_cast<char*>(&pagada),sizeof(pagada));
	f.seekg(0,ios::beg);
	for(int i =0; i<size; ++i){
		Compra c;
		f.read(reinterpret_cast<char*>(&c), sizeof(c));
		fiados.push_back(c);
	}
	f.close();
	if(indice!=fiados.size()-1){
		for(int i=indice; i<fiados.size(); ++i)	fiados[i] = fiados[i+1];
	fiados.pop_back();
	
	ofstream fout(archivo_fiados,ios::binary|ios::trunc);
	for(Compra c: fiados) fout.write(reinterpret_cast<char*>(&c), sizeof(c));
	fout.close();
	
	ofstream fout_ventas(archivo_ventas,ios::binary|ios::app);
	fout_ventas.write(reinterpret_cast<char*>(&pagada),sizeof(pagada));
	fout_ventas.close();
	
}
void Venta::Ordenar(){
	
}

