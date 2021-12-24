#include <vector>
#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include <string>
#include "Repositorio.h"
#include <fstream>
using namespace std;

struct Producto{
	char nombre[30], marca[50], tipo[30];
	int codigo, stock;
	float precio;
};

bool OrdenarPorCodigo(Producto &x1, Producto &x2);
bool OrdenarPorNombre(Producto &x1, Producto &x2);
bool OrdenarPorTipo(Producto &x1, Producto &x2);
bool OrdenarPorMarca(Producto &x1, Producto &x2);
bool OrdenarPorStock(Producto &x1, Producto &x2);
bool OrdenarPorPrecio(Producto &x1, Producto &x2);

ostream &operator<<(ostream &o, Producto n);
bool operator==(Producto a, Producto b);

class Productos {
public:
	Productos();
	char* VerNombre(int x);
	char* VerMarca(int x);
	char* VerTipo(int x);	
	int VerCodigo(int x);
	int VerStock(int x);
	float VerPrecio(int x);	
	
	void CambiarStock(int A);
	void ActualizarPrecio(int A);
	
	Producto BuscarProducto(int codigo) const;
	int BuscarIndice(int codigo);
	
	void GuardarCambios(string NombreArchivo);
	void Lectura(string NombreArchivo);
	void ActualizarStock(string NombreArchivo, int codigo, int cantidad);
	
	tuple<vector<Producto>::iterator,vector<Producto>::iterator> iteradores();
	int DevolverTamanio();
	void AgregarProducto(Producto aux);
	void EliminarProducto( int codigo);
	vector<Producto> Filtrar(string tipo); //Busca por tipo o Producto
	Producto FiltrarPorCodigo(int codigo);
	Producto FiltrarPorNombre(string nombre);
	vector<Producto>FiltrarPorTipo(string tipo);
	void ActualizarPrecio(int codigo, float precio);
	void GuardarCambios(string NombreArchivo, int indice);
	
	string obtenerIdentificador(Producto entidad);
	bool existe(int codigo);
private:
	vector<Producto>VectorProductos; //Me parece que hay que sacar este vector (Lucas)
	Repositorio<Producto> repo_productos;
};

#endif

