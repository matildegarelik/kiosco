#include "Pedido.h"
#include "Productos.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


int getFechaActualEntero(){
	int fecha_actual;
	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	
	fecha_actual = year*10000 + month*100 + day;
	return fecha_actual;
};
	//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
string getFechaActualString(){
		time_t now = time(0);
		tm *ltm = localtime(&now);
		string year = to_string( 1900 + ltm->tm_year );
		string month = to_string( 1 + ltm->tm_mon );
		string day = to_string( ltm->tm_mday );
		string time = to_string(5+ltm->tm_hour) + ":" + to_string( 30+ltm->tm_min) + ":" ;
		
		return year + "-" + month + "-" + day + "  " + time;
	}
		

Pedido::Pedido() {
	string fe = getFechaActualString();
	string a = fe.substr(0,fe.find(':',0)-1);
	this->nombre_archivo = "PedidoArchivo  "+ a + ".txt";
}


void Pedido :: agregarProducto(int cod, int cant, Productos &prod ){

	if(prod.existe(cod)){
		Producto aux;
		aux = prod.BuscarProducto(cod);
		lista_pedido.push_back(aux);
		cantidades.push_back(cant);
	}

}

void Pedido :: vaciarVectores(){
	cantidades.clear();
	lista_pedido.clear();
}

void Pedido :: armarArchivoTexto(){
 
	ofstream arch(nombre_archivo,ios::trunc);
	
	string texto1 = "Buenos días, quisiera solicitar los siguientes productos:";
	string texto2 = "Muchas gracias por su atención, saludos.";
	
	arch<<getFechaActualString()<<endl <<texto1<<endl;
	for(int i=0;i<lista_pedido.size();i++) { 
		arch<<lista_pedido[i]._nombre<<"  "<<cantidades[i]<<endl;
	}
	arch<<texto2;
	
	arch.close();
}

void Pedido :: eliminarProducto(int cod, Productos &prod){
	
	if(prod.existe(cod)){
		for(int i=0;i<lista_pedido.size();i++) { 
			if(lista_pedido[i]._codigo == cod){
				lista_pedido.erase(lista_pedido.begin()+i);
			}
		}
	}
	
}

int Pedido :: getTamanio(){
	return cantidades.size();
}
