#ifndef PEDIDO_H
#define PEDIDO_H
#include <vector>
#include <string>
#include  <ctime>
#include "Productos.h"
using namespace std;

int getFechaActualEntero();
string getFechaActualString();

class Pedido {
public:
	Pedido();
	void agregarProducto(int cod, int cant, Productos &prod);
	void eliminarProducto(int cod,Productos &prod);
	void eliminarProducto(int pos);
	void vaciarVectores();
	int getTamanio();
	void armarArchivoTexto();
	
	
private:
	vector<Producto> lista_pedido;
	vector<int> cantidades;
	string nombre_archivo;
};

#endif

