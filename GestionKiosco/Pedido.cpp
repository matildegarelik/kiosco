#include "Pedido.h"
#include "Productos.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


Pedido::Pedido() {
	this->nombre_archivo = "Pedido " + getFechaActualString();
}


void Pedido :: agregarProducto(int cod, int cant, const Productos &prod ){

	if(prod.existe(cod)){
		Producto aux;
		aux = prod.BuscarProducto(cod);
		lista_pedido.push_back(aux);		
	}

}


void Pedido :: armarArchivoTexto(vector<int> cantidades){
 
	ofstream arch(nombre_archivo);
	
	string texto1 = "Buenos días, quisiera solicitar los siguientes productos:";
	string texto2 = "Muchas gracias por su atención, saludos.";
	
	arch<<getFechaActualString()<<endl <<texto1<<endl;
	for(int i=0;i<lista_pedido.size();i++) { 
		arch<<lista_pedido[i]._nombre<<"  "<<cantidades[i]<<endl;
	}
	arch<<texto2;
	
	arch.close();
}

void Pedido :: eliminarProducto(int cod){
	
	if(prod.existe(cod)){
		for(int i=0;i<lista_pedido.size();i++) { 
			if(lista_pedido[i]._codigo == cod){
				lista_pedido.erase(lista_pedido.begin()+i);
			}
		}
	}
	
}

