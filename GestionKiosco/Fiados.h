#ifndef FIADOS_H
#define FIADOS_H

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

