#include "Productos.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
bool OrdenarPorNombre(Producto &x1, Producto &x2){
	return strcmp(x1._nombre,x2._nombre)<0;
}
bool OrdenarPorCodigo(Producto &x1, Producto &x2){
	return (x1._codigo<x2._codigo);
}
bool OrdenarPorTipo(Producto &x1, Producto &x2){
	return strcmp(x1._tipo,x2._tipo)<0;
}
bool OrdenarPorMarca(Producto &x1, Producto &x2){
	return strcmp(x1._marca,x2._marca)<0;
}
bool OrdenarPorStock(Producto &x1, Producto &x2){
	return (x1._stock<x2._stock);
}
bool OrdenarPorPrecio(Producto &x1, Producto &x2){
	return (x1._precio<x2._precio);
}
	
ostream &operator<<(ostream &o, Producto n){
	o<<n._nombre<<"  "<<n._stock<<"  "<<n._precio<<endl;
	return o;
}
bool operator==(Producto a, Producto b){
	return a._codigo == b._codigo;
}

	
Productos::Productos() :
	repo_productos("productos.dat"){
	VectorProductos = repo_productos.buscarTodos();
}

Producto Productos::BuscarProducto(int codigo) const{
	Producto aux={"ERROR\0","ERROR\0","ERRoR\0",0,0,0};
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i]._codigo==codigo){
			//VectorProductos[i]=aux;
			aux = VectorProductos[i];
			return aux;
		}
		cout<<VectorProductos.size()<<endl;
	}
	return aux;
}
char*Productos::VerNombre (int x){return VectorProductos[x]._nombre;}
char*Productos::VerMarca (int x){return VectorProductos[x]._marca;}
char*Productos::VerTipo (int x){return VectorProductos[x]._tipo;}
int Productos::VerCodigo(int x){return VectorProductos[x]._codigo; }
int Productos::VerStock(int x){return VectorProductos[x]._stock;}
float Productos::VerPrecio(int x){return VectorProductos[x]._precio;}
int Productos::BuscarIndice(int codigo){
	for(int i=0; i<VectorProductos.size(); ++i){
		int aux;
		for(int i=0; i<VectorProductos.size(); ++i){
			if(VectorProductos[i]._codigo==codigo) aux=i;
		}
		return aux;
	}
}
void Productos::GuardarCambios(string NombreArchivo){
	fstream archi(NombreArchivo, ios::binary|ios::out|ios::trunc);
	for(int i=0; i<VectorProductos.size(); ++i){
		archi.write(reinterpret_cast<char*>(&VectorProductos[i]),sizeof(Producto));
	}
	archi.close();
}
int Productos::DevolverTamanio(){
	return VectorProductos.size();
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
	fstream archi(NombreArchivo, ios::binary|ios::in);
	int aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i]._codigo==codigo){
			VectorProductos[i]._stock=cantidad;
			i=aux;
			break;
		}
	}
	archi.seekg(aux*sizeof(Producto));
	archi.write(reinterpret_cast<char*>(&VectorProductos[aux]),sizeof(Producto)); //Escribe el vector actualizado
}
void Productos::AgregarProducto(Producto aux){
	VectorProductos.push_back(aux);
	repo_productos.guardarNuevo(aux);
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
	if(Parametro=="PRODUCTO")sort(VectorProductos.begin(), VectorProductos.end(), OrdenarPorNombre);
	if(Parametro=="CODIGO")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorCodigo );
	if(Parametro=="TIPO")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorTipo );
	if(Parametro=="MARCA")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorMarca );
	if(Parametro=="PRECIO")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorPrecio );
}
vector<Producto>Productos::Filtrar(string tipo){ 
	//Se modificó la función para que le llegue una string determinando el tipo a Filtrar		int D;
	
	vector<Producto> aux;
	cout<<VectorProductos.size()<<endl;
	for(int i=0; i<VectorProductos.size(); ++i){
		string S=VectorProductos[i]._tipo;
		if(S==tipo){
			aux.push_back(VectorProductos[i]);
		}
	}
	return aux;
}
void Productos::ActualizarPrecio(string NombreArchivo, int codigo, int precio){ //ué el parametro precio porque no estaba
	//fstream archi(NombreArchivo, ios::binary|ios::in);							
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

string Productos :: obtenerIdentificador(Producto auxiliar){
	return to_string(auxiliar._codigo);
}

bool Productos :: existe(int codigo){
	bool retorno = false;
	for(int i=0;i<VectorProductos.size();i++) { 
		if(VectorProductos[i]._codigo == codigo){
			retorno = true;
		}
	}
	return retorno;
}
	
