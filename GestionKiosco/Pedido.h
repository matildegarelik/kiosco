#ifndef PEDIDO_H
#define PEDIDO_H
#include <vector>
#include <string>
#include  <ctime>
#include "Productos.h"
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


class Pedido {
public:
	Pedido();
	void agregarProducto(int cod, int cant, Productos &prod);
	void eliminarProducto(int cod,Productos &prod);
	
	void armarArchivoTexto(vector<int> cantidades);
	
	
private:
	vector<Producto> lista_pedido;
	string nombre_archivo;
};

#endif

