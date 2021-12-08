#include "Productos.h"
#include <vector>
Productos::Productos() {
	
}
char*Productos::VerNombre (int x){return VectorProductos[x]._nombre;}
char*Productos::VerMarca (int x){return VectorProductos[x]._marca;}
char*Productos::VerTipo (int x){return VectorProductos[x]._tipo;}
int VerCodigo(int x){}
int VerStock(int x){}
float VerPrecio(float x){}
Producto BuscarProducto(int codigo){}
int BuscarIndice(int codigo){}
void GuardarCambios(string NombreArchivo){}
void Lectura(string NombreArchivo){}
void ActualizarStock(string NombreArchivo, int codigo, int cantidad){}
void AgregarProducto(string NombreArchivo, Producto aux){}
void EliminarProducto(string NombreArchivo, int codigo){}
void Ordenar(string Parametro){}
void Buscar(string Parametro){}
void ActualizarPrecio(string NombreArchivo, int codigo){}
void GuardarCambios(string NombreArchivo, int indice){}
