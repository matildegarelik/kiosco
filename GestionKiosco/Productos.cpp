#include "Productos.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <tuple>
#include <cctype>
using namespace std;


bool OrdenarPorNombre(Producto &x1, Producto &x2){
	return strcmp(x1.nombre,x2.nombre)<0;
}
bool OrdenarPorCodigo(Producto &x1, Producto &x2){
	return (x1.codigo<x2.codigo);
}
bool OrdenarPorTipo(Producto &x1, Producto &x2){
	return strcmp(x1.tipo,x2.tipo)<0;
	}
bool OrdenarPorMarca(Producto &x1, Producto &x2){
	return strcmp(x1.marca,x2.marca)<0;
	}
bool OrdenarPorStock(Producto &x1, Producto &x2){
	return (x1.stock<x2.stock);
}
bool OrdenarPorPrecio(Producto &x1, Producto &x2){
	return (x1.precio<x2.precio);
}


ostream &operator<<(ostream &o, Producto n){
	o<<n.nombre<<"  "<<n.stock<<"  "<<n.precio<<endl;
	return o;
}
bool operator==(Producto a, Producto b){
	return a.codigo == b.codigo;
}

	
Productos::Productos() :
	repo_productos("productos.dat"){
	VectorProductos = repo_productos.buscarTodos();
}

Producto Productos::BuscarProducto(int codigo) const{
	Producto aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i].codigo==codigo){
			aux = VectorProductos[i];
			return aux;
		}
	}
	return aux;
}
char*Productos::VerNombre (int x){return VectorProductos[x].nombre;}
char*Productos::VerMarca (int x){return VectorProductos[x].marca;}
char*Productos::VerTipo (int x){return VectorProductos[x].tipo;}
int Productos::VerCodigo(int x){return VectorProductos[x].codigo; }
int Productos::VerStock(int x){return VectorProductos[x].stock;}
float Productos::VerPrecio(int x){return VectorProductos[x].precio;}
int Productos::BuscarIndice(int codigo){
	for(int i=0; i<VectorProductos.size(); ++i){
		int aux;
		for(int i=0; i<VectorProductos.size(); ++i){
			if(VectorProductos[i].codigo==codigo) aux=i;
		}
		return aux;
	}
}

void Productos::GuardarCambios(){
	for(int i=0; i<VectorProductos.size(); ++i){
		repo_productos.actualizarParametro(VectorProductos[i],i);
	}
}



void Productos::ActualizarStock(int codigo, int cantidad){
	int aux;
	for(size_t i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i].codigo==codigo){
			VectorProductos[i].stock-=cantidad;
			aux=i;
			break;
		}
	}
	repo_productos.actualizarParametro(VectorProductos[aux],aux);
	
}

void Productos::AgregarProducto(Producto aux){
	aux.nombre[0]=toupper(aux.nombre[0]);
	aux.tipo[0]=toupper(aux.tipo[0]);
	aux.marca[0]=toupper(aux.marca[0]);
	for(int i=1; i<strlen(aux.nombre); ++i) aux.nombre[i]=tolower(aux.nombre[i]);
	for(int i=1; i<strlen(aux.tipo); ++i) aux.tipo[i]=tolower(aux.tipo[i]);
	for(int i=1; i<strlen(aux.marca); ++i) aux.marca[i]=tolower(aux.marca[i]);
	VectorProductos.push_back(aux);
	repo_productos.guardarNuevo(aux);
}
void Productos::EliminarProducto(int codigo){
	Producto p = BuscarProducto(codigo);
	auto it = remove(VectorProductos.begin(), VectorProductos.end(),p);
	VectorProductos.erase(it);
	repo_productos.eliminarPermanente(p);
}
tuple<vector<Producto>::iterator,vector<Producto>::iterator> Productos::iteradores(){
		vector<Producto>::iterator A, B;
		A=VectorProductos.begin();
		B=VectorProductos.end();
		return make_tuple(A, B);
	}

Producto Productos::FiltrarPorCodigo(int codigo){ 
	Producto aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		int A=VectorProductos[i].codigo;
		if(A==codigo){
			aux=VectorProductos[i];
			break;
		}
	}
	return aux;
}
bool Productos::VerificarNombre(string nombre){	
	bool A=0;
	for(int i=0; i<VectorProductos.size(); ++i){
		if(nombre==VectorProductos[i].nombre){
			return A=1;
		}
	}
	return A;
}


Producto Productos::FiltrarPorNombre(string nombre){ 	
	Producto aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		string A=VectorProductos[i].nombre;
		if(A==nombre){
			aux=VectorProductos[i];
			break;
		}
	}
	return aux;
}
vector<Producto>Productos::FiltrarPorTipo(string tipo){
	vector<Producto> aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		string A=VectorProductos[i].tipo;
		if(A==tipo){
			aux.push_back(VectorProductos[i]);
		}
	}
	return aux;
}

void Productos::ActualizarPrecio( int codigo, float precio){ 
	int pos;
	Producto p;
	for(int i=0; i<VectorProductos.size();++i){
		if(VectorProductos[i].codigo==codigo){
			VectorProductos[i].precio=precio;
			p = VectorProductos[i];
			pos = i;
		}
	}
	repo_productos.actualizarParametro(p,pos);
}
void Productos::GuardarCambios(int indice){
	repo_productos.actualizarParametro(VectorProductos[indice],indice);
}

string Productos :: obtenerIdentificador(Producto auxiliar){
	return to_string(auxiliar.codigo);
}
bool Productos :: existe(int codigo){
	bool retorno = false;
	for(int i=0;i<VectorProductos.size();i++) { 
		if(VectorProductos[i].codigo == codigo){
			retorno = true;
			break;
		}
	}
	return retorno;
}
int Productos::DevolverTamanio(){
	return VectorProductos.size();
}
void Productos::CambiarStock(int codigo, int nuevo){
	int i = BuscarIndice(codigo);
	VectorProductos[i].stock = nuevo;
	repo_productos.actualizarParametro(VectorProductos[i],i);
}

/// VIEJO
/*void Productos::GuardarCambios(string NombreArchivo){
	fstream archi(NombreArchivo, ios::binary|ios::out|ios::trunc);
	for(int i=0; i<VectorProductos.size(); ++i){
		archi.write(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto));
	}
	archi.close();
}
void Productos::Lectura(string NombreArchivo){
	fstream archi(NombreArchivo, ios::binary|ios::in|ios::app); //Lectura del binario y se lo pasa a vector
	Producto aux;
	VectorProductos.clear();//Revisar 
	int n=archi.tellg();
	int cant=n/sizeof(Producto);
	VectorProductos.resize(cant);
	archi.seekg(0);
	archi.seekp(0);
	for(int i=0; i<VectorProductos.size(); ++i){
		archi.read(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto));
	}
	archi.close();
}

void Productos::ActualizarStock(string NombreArchivo, int codigo, int cantidad){
	fstream archi(NombreArchivo, ios::binary|ios::in|ios::out);
	int aux;
	for(size_t i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i].codigo==codigo){
			VectorProductos[i].stock-=cantidad;
			aux=i;
			break;
		}
	}
	archi.seekg(aux*sizeof(Producto));
	archi.write(reinterpret_cast<char*>(&VectorProductos[aux]),sizeof(Producto)); //Escribe el vector actualizado
}
	
void Productos::GuardarCambios(string NombreArchivo, int indice){
	fstream archi(NombreArchivo, ios::binary|ios::in);
	archi.seekg(indice*sizeof(Producto));
	archi.write(reinterpret_cast<char*>(&VectorProductos[indice]),sizeof(Producto));
}
*/
