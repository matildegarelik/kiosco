#include "Productos.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
bool OrdenarPorNombre(Producto &x1, Producto &x2){
	return (x1.VerNombre()<x2.VerNombre());
}
bool OrdenarPorCodigo(Producto &x1, Producto &x2){
	return (x1.VerCodigo()<x2.VerCodigo());
}
bool OrdenarPorTipo(Producto &x1, Producto &x2){
	return (x1.VerTipo()<x2.VerTipo());
}
bool OrdenarPorMarca(Producto &x1, Producto &x2){
	return (x1.VerMarca()<x2.VerMarca());
}
bool OrdenarPorStock(Producto &x1, Producto &x2){
	return (x1.VerStock()<x2.VerStock());
}
bool OrdenarPorPrecio(Producto &x1, Producto &x2){
	return (x1.VerPrecio()<x2.VerPrecio());
}
Productos::Productos() {
	
}
/*char*Productos::VerNombre (int x){return VectorProductos[x]._nombre;}
char*Productos::VerMarca (int x){return VectorProductos[x]._marca;}
char*Productos::VerTipo (int x){return VectorProductos[x]._tipo;}
int Productos::VerCodigo(int x){return VectorProductos[x]._codigo; }
int Productos::VerStock(int x){return VectorProductos[x]._stock;}
float Productos::VerPrecio(float x){return VectorProductos[x]._precio;}*/
Producto Productos::BuscarProducto(int codigo){
	Producto aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i].VerCodigo()==codigo){
			VectorProductos[i]=aux;
			return aux;
		}
	}
}
int Productos::BuscarIndice(int codigo){
	for(int i=0; i<VectorProductos.size(); ++i){
		if(VectorProductos[i].VerCodigo()==codigo) return i;
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
		if(VectorProductos[i].VerCodigo()==codigo){
			VectorProductos[i].CambiarStock(cantidad);
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
		if(VectorProductos[i].VerCodigo()==codigo){
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
	if(Parametro=="PRODUCTO")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorNombre );
	if(Parametro=="CODIGO")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorCodigo );
	if(Parametro=="TIPO")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorTipo );
	if(Parametro=="MARCA")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorMarca );
	if(Parametro=="STOCK")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorStock );
	if(Parametro=="PRECIO")sort(VectorProductos.begin(), VectorProductos.end(),OrdenarPorPrecio );
	
}
vector<Producto> Productos::Filtrar(string Parametro){
	int D;
	vector<Producto>aux;
	for(int i=0; i<VectorProductos.size(); ++i){
		string S1=VectorProductos[i].VerNombre();
		D=S1.find(Parametro, i);
		if(D!=string::npos) aux.push_back(VectorProductos[i]);
	}
	return aux;
}
void Productos::ActualizarPrecio(string NombreArchivo, int codigo, int precio){ //Agregué el parametro precio porque no estaba
	fstream archi(NombreArchivo, ios::binary|ios::in);							
	for(int i=0; i<VectorProductos.size();++i){
		if(VectorProductos[i].VerCodigo()==codigo){
			VectorProductos[i].ActualizarPrecio(precio);
		}
	}
}
void Productos::GuardarCambios(string NombreArchivo, int indice){
	fstream archi(NombreArchivo, ios::binary|ios::in);
	archi.seekg(indice*sizeof(Producto));
	archi.write(reinterpret_cast<char*>(&VectorProductos[indice]),sizeof(Producto));
}
