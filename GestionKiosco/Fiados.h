#ifndef FIADOS_H
#define FIADOS_H
#include <string>
#include <vector>
#include "Venta.h"
using namespace std;

class Fiados {
public:
	Fiados();
	void CargarFiados(string nombre_archivo); //archivo binario
	void MarcarPagado(int indice); //guarda vector y archivo
	void Ordenar();
private:
	vector<Fiado> v;
};

#endif

