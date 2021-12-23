#ifndef HISTORICOVENTAS_H
#define HISTORICOVENTAS_H
#include "Venta.h"

struct DetalleYFecha{
	Detalle d;
	Fecha f;
	int cod_factura;
};

struct Compra{
	char cliente[50];
	Fecha f;
	float total;
	int cod_factura;
};

bool operator==(Compra c1, Compra c2);
bool operator==(DetalleYFecha d1, DetalleYFecha d2);

class HistoricoVentas {
public:
	HistoricoVentas();
	int generar_codigo();
	
	void Agregar(Venta v);
	
	vector<Compra> CargarFiados(); //archivo binario
	void MarcarPagado(Compra c); //guarda vector y archivos
	void MarcarPagado(int indice); //guarda vector y archivos
	
	vector<Detalle> prods_mas_vendidos();
	vector<Compra> ultimas_ventas();
	vector<DetalleYFecha> ventas_por_producto(int codigo);
	vector<Compra> ventas_por_cliente(string nombre);
	vector<DetalleYFecha> armar_factura(int codigo_factura);
	Compra buscar_compra(int codigo_factura);
private:
	Repositorio<Compra> repo_ventas;
	Repositorio<Compra> repo_fiados;
	Repositorio<DetalleYFecha> repo_detalles;
};

#endif

