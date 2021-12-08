#include <vector>
#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include <string>
using namespace std;

struct Producto{
	char _nombre[30], _marca[50], _tipo[30];
	int _codigo, _stock;
	float _precio;
};

class Productos {
public:
	Productos();
	char* VerNombre(int x);
	char* VerMarca(int x);
	char* VerTipo(int x);	
	int VerCodigo(int x);
	int VerStock(int x);
	float VerPrecio(float x);
	Producto BuscarProducto(int codigo);
	int BuscarIndice(int codigo);
	void GuardarCambios(string NombreArchivo);
	void Lectura(string NombreArchivo);
	void ActualizarStock(string NombreArchivo, int codigo, int cantidad);
	void AgregarProducto(string NombreArchivo, Producto aux);
	void EliminarProducto(string NombreArchivo, int codigo);
	void Ordenar(string Parametro);
	void Buscar(string Parametro);
	void ActualizarPrecio(string NombreArchivo, int codigo);
	void GuardarCambios(string NombreArchivo, int indice);
	
	
private:
	vector<Producto>VectorProductos;
};

#endif

