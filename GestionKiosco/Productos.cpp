#include "Productos.h"
#include <vector>
#include <fstream>
using namespace std;
Productos::Productos() {
	
}
char*Productos::VerNombre (int x){return VectorProductos[x]._nombre;}
char*Productos::VerMarca (int x){return VectorProductos[x]._marca;}
char*Productos::VerTipo (int x){return VectorProductos[x]._tipo;}
int Productos::VerCodigo(int x){return VectorProductos[x]._codigo; }
int Productos::VerStock(int x){return VectorProductos[x]._stock;}
float Productos::VerPrecio(float x){return VectorProductos[x]._precio;}
Producto Productos::BuscarProducto(int codigo){
	Producto aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i]._codigo==codigo){
			VectorProductos[i]=aux;
			return aux;
		}
	}
}
int Productos::BuscarIndice(int codigo){
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i]._codigo==codigo) return i;
	}
}
void Productos::GuardarCambios(string NombreArchivo){
	fstream archi(NombreArchivo, ios::binary|ios::in|ios::trunc|ios::app);
	for(int i=0; i<VectorProductos.size(); ++i){
		archi.write(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto));
	}
}
void Productos::Lectura(string NombreArchivo){
	fstream archi(NombreArchivo, ios::binary|ios::out|ios::app); //Lectura del binario y se lo pasa a vector
	Producto aux;												//Revisar 
	int n=archi.tellg();
	int cant=n/sizeof(Producto);
	VectorProductos.resize(cant);
	archi.seekg(0);
	for(int i=0; i<VectorProductos.size(); ++i){
		archi.read(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto));
	}
}
void Productos::ActualizarStock(string NombreArchivo, int codigo, int cantidad){
	fstream archi(NombreArchivo, ios::binary|ios::in);
	int aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos._codigo==codigo){
			VectorProductos[i]._stock-=cantidad;
			i=aux;
			break;
		}
	}
	archi.seekg(aux*sizeof(Producto));
	archi.write(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto)); //Escribe el vector actualizado
}
void Productos::AgregarProducto(string NombreArchivo, Producto aux){
	fstream archi()
}
void Productos::EliminarProducto(string NombreArchivo, int codigo){}
void Productos::Ordenar(string Parametro){}
void Productos::Buscar(string Parametro){}
void Productos::ActualizarPrecio(string NombreArchivo, int codigo){}
void Productos::GuardarCambios(string NombreArchivo, int indice){}
