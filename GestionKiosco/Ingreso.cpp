#include "Ingreso.h"
#include <fstream>
#include "Venta.h"
using namespace std;

Ingreso::Ingreso(int cod_prod,const Productos &prods, int cant, Fecha f): repo_ingresos("ingresos.dat") {
	Producto p = prods.BuscarProducto(cod_prod);
	_producto = p;
	_cantidad=cant;
	_fecha=f;
}

void Ingreso::GuardarCambios(Productos &prods){
	// Guardar en archivo de texto
	/*ofstream fout(archivo_ingresos, ios::app);
	string nombre(_producto._nombre);
	fout<<"- "<<nombre;
	fout<<" (Cod: "<<_producto._codigo<<")";
	fout<<" - Cantidad: "<<_cantidad;
	fout<<"- Fecha: "<<_fecha.dia<<"/"<<_fecha.mes<<"/"<<_fecha.anio<<endl;*/
	Detalle d = {_producto,_cantidad};
	DetalleYFecha df = {d,_fecha}; 
	repo_ingresos.guardarNuevo(df);
	//Actualizar vector productos y binario con stock
	prods.ActualizarStock("productos.dat",_producto._codigo,-_cantidad);// negativo para q la sume
	prods.GuardarCambios("productos.dat",prods.BuscarIndice(_producto._codigo));
	
}

