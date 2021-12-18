#include "Ingreso.h"
#include <fstream>
#include "Venta.h"
using namespace std;

Ingreso::Ingreso(int cod_prod,const Productos &prods, int cant, Fecha f) {
	Producto p = prods.BuscarProducto(cod_prod);
	_producto = p;
	_cantidad=cant;
	_fecha=f;
}

void Ingreso::GuardarCambios(string archivo_ingresos, string archivo_productos, Productos &prods){
	// Guardar en archivo de texto
	ofstream fout(archivo_ingresos, ios::app);
	string nombre(_producto._nombre);
	fout<<"- "<<nombre;
	fout<<" (Cod: "<<_producto._codigo<<")";
	fout<<" - Cantidad: "<<_cantidad;
	fout<<"- Fecha: "<<_fecha.dia<<"/"<<_fecha.mes<<"/"<<_fecha.anio<<endl;
	
	//Actualizar vector productos y binario con stock
	prods.ActualizarStock("productos.dat",_producto._codigo,-_cantidad);// negativo para q la sume
	prods.GuardarCambios("productos.dat",prods.BuscarIndice(_producto._codigo));
	
}

