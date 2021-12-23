#include "Ingreso.h"
#include <fstream>
#include "Venta.h"
using namespace std;

Ingreso::Ingreso(int cod_prod,const Productos &prods, int cant, Fecha f): repo_ingresos("ingresos.dat") {
	Producto p = prods.BuscarProducto(cod_prod);
	m_producto = p;
	m_cantidad=cant;
	m_fecha=f;
}

void Ingreso::GuardarCambios(Productos &prods){
	// Guardar en archivo de texto
	/*ofstream fout(archivo_ingresos, ios::app);
	string nombre(_producto._nombre);
	fout<<"- "<<nombre;
	fout<<" (Cod: "<<_producto._codigo<<")";
	fout<<" - Cantidad: "<<_cantidad;
	fout<<"- Fecha: "<<_fecha.dia<<"/"<<_fecha.mes<<"/"<<_fecha.anio<<endl;*/
	Detalle d = {m_producto,m_cantidad};
	DetalleYFecha df = {d,m_fecha}; 
	repo_ingresos.guardarNuevo(df);
	
	//Actualizar vector productos y binario con stock
	prods.ActualizarStock("productos.dat",m_producto.codigo,-m_cantidad);// negativo para q la sume
	prods.GuardarCambios("productos.dat",prods.BuscarIndice(m_producto.codigo));
	
}



