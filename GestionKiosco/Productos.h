#include <vector>
#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include <string>
#include "Producto.h"
using namespace std;

class Productos {
public:
	Productos();
	Producto BuscarProducto(int codigo);
	int BuscarIndice(int codigo);
	void GuardarCambios(string NombreArchivo);
	void Lectura(string NombreArchivo);
	void ActualizarStock(string NombreArchivo, int codigo, int cantidad);
	void AgregarProducto(string NombreArchivo, Producto aux);
	void EliminarProducto(string NombreArchivo, int codigo);
	void Ordenar(string Parametro);
	vector<Producto> Filtrar(string Parametro); //Busca por tipo o Producto 
	void ActualizarPrecio(string NombreArchivo, int codigo, int precio);
	void GuardarCambios(string NombreArchivo, int indice);
	
private:
	vector<Producto>VectorProductos;
};

#endif

