#include "Productos.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
bool ordP(Producto &x1, Producto &x2){
	return (x1._nombre<x2._nombre);
}
bool ordC(Producto &x1, Producto &x2){
	return (x1._codigo<x2._codigo);
}
bool ordT(Producto &x1, Producto &x2){
	return (x1._tipo<x2._tipo);
}
bool ordM(Producto &x1, Producto &x2){
	return (x1._marca<x2._marca);
}
bool ordS(Producto &x1, Producto &x2){
	return (x1._stock<x2._stock);
}
bool ordPr(Producto &x1, Producto &x2){
	return (x1._precio<x2._precio);
}
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
		if(VectorProductos[i]._codigo==codigo){
			VectorProductos[i]._stock-=cantidad;
			i=aux;
			break;
		}
	}
	archi.seekg(aux*sizeof(Producto));
	archi.write(reinterpret_cast<char*>(&VectorProductos[aux]),sizeof(Producto)); //Escribe el vector actualizado
}
void Productos::AgregarProducto(string NombreArchivo, Producto aux){
	fstream archi(NombreArchivo, ios::binary|ios::in);
	VectorProductos.push_back(aux);
	for(int i=0; i<VectorProductos.size(); ++i){
		archi.write(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto));
	}
}
void Productos::EliminarProducto(string NombreArchivo, int codigo){
	fstream archi(NombreArchivo, ios::binary);
	int aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i]._codigo==codigo){
			VectorProductos.erase(VectorProductos.begin()+i);
			aux=i;
			break;
		}
	}
	for(int i=aux; i<VectorProductos.size(); ++i){
		archi.write(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto));
	}
}
void Productos::Ordenar(string Parametro){
	if(Parametro=="PRODUCTO")sort(VectorProductos.begin(), VectorProductos.end(),ordP );
	if(Parametro=="CODIGO")sort(VectorProductos.begin(), VectorProductos.end(),ordC );
	if(Parametro=="TIPO")sort(VectorProductos.begin(), VectorProductos.end(),ordT );
	if(Parametro=="MARCA")sort(VectorProductos.begin(), VectorProductos.end(),ordM );
	if(Parametro=="STOCK")sort(VectorProductos.begin(), VectorProductos.end(),ordS );
	if(Parametro=="PRECIO")sort(VectorProductos.begin(), VectorProductos.end(),ordPr );
	
}
void Productos::Buscar(string Parametro){
}
void Productos::ActualizarPrecio(string NombreArchivo, int codigo, int precio){ //Agregué el parametro precio porque no estaba
	fstream archi(NombreArchivo, ios::binary|ios::in);							
	for(int i=0; i<VectorProductos.size();++i){
		if(VectorProductos[i]._codigo==codigo){
			VectorProductos[i]._precio=precio;
		}
	}
}
void Productos::GuardarCambios(string NombreArchivo, int indice){
	fstream archi(NombreArchivo, ios::binary|ios::in);
	archi.seekg(indice*sizeof(Producto));
	archi.write(reinterpret_cast<char*>(&VectorProductos[indice]),sizeof(Producto));
}
