#include "Productos.h"
#include "Venta.h"
#include "Repositorio.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	Repositorio<Producto> repo_produtos("productos.dat");
//	Venta v1;
//	v1.repo_ventas.cargarDatosDePruebaProducto
//	Repositorio<Compra> repo_ventas2("ventas.dat");
//
//	repo_produtos.cargarDatosDePruebaProducto();
	vector<Producto> v = repo_produtos.buscarTodos();
//
	repo_produtos.verTodos();
	cout<<endl;
//	
	Producto nuevo = {"barra frutal", "arcor", "alimento", 006, 4, 100};
	repo_produtos.guardarNuevo(nuevo);
//	
	repo_produtos.verTodos();
	cout<<endl;
//	
//
	repo_produtos.eliminarPermanente(nuevo);
	repo_produtos.verTodos();
//	repo_ventas.cargarDatosDePruebaVenta();
//	Compra nueva = {"cccc", 3,10,2020,300}:
//	repo_ventas.guardarNuevo(nueva);
//	repo_ventas.eliminarPermanente(nueva);
	
	
	
	int x;
	cin>>x;
	return 0;
	
}
