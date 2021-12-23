#include "HistoricoVentas.h"
#include <cstring>
using namespace std;

bool cmp_cantidad(Detalle d1, Detalle d2){
	return d1.cantidad<d2.cantidad;
}
bool operator==(Compra c1, Compra c2) {
	return c1.cliente==c2.cliente and c1.f==c2.f and c1.total==c2.total;
}

bool operator==(DetalleYFecha d1, DetalleYFecha d2) {
	return d1.d==d2.d and d1.f==d2.f;
}
bool cmp_fecha(Compra c1, Compra c2){
	return c1.f<c2.f;
}

HistoricoVentas::HistoricoVentas():
	repo_ventas("ventas.dat"),
	repo_fiados("fiados.dat"),
	repo_detalles("detalles.dat") {
	
}

void HistoricoVentas::Agregar(Venta v){
	int codigo_factura = generar_codigo();
	Compra c;
	strcpy(c.cliente,v.GetCliente());
	c.f=v.GetFecha();
	c.total=v.CalcularTotal();
	c.cod_factura= codigo_factura;
	if(v.GetPago())repo_ventas.guardarNuevo(c);
	else repo_fiados.guardarNuevo(c);
	
	for(Detalle &d: v.GetDetalles()) {
		DetalleYFecha d_y_f = {d,v.GetFecha(),codigo_factura};
		repo_detalles.guardarNuevo(d_y_f);
	}
	
}


// FIADOS
vector<Compra> HistoricoVentas::CargarFiados(){
	vector<Compra> fiados;
	fiados = repo_fiados.buscarTodos();
	return fiados;
}
void HistoricoVentas::MarcarPagado(Compra c){
	//borra registro compra de fiados y agrega a ventas ese registro
	repo_fiados.eliminarPermanente(c);
	repo_ventas.guardarNuevo(c);	
}

void HistoricoVentas::MarcarPagado(int indice){
	//borra registro compra de fiados y agrega a ventas ese registro
	Compra c = repo_fiados.eliminarPermanente(indice);
	repo_ventas.guardarNuevo(c);	
}


vector<Detalle> HistoricoVentas::prods_mas_vendidos(){
	vector<DetalleYFecha> detalles = repo_detalles.buscarTodos();
	vector<Producto> ps;
	vector<Detalle> det;
	
	for(DetalleYFecha &d: detalles){
		if(find(ps.begin(),ps.end(),d.d.p)==ps.end()){
			ps.push_back(d.d.p);
			det.push_back(d.d);
		}else{
			auto it = find(ps.begin(),ps.end(),d.d.p);
			
			auto it2 = det.begin()+(it-ps.begin());
			//cout<<(*det.begin()).cantidad<<endl;
			(*it2).cantidad+=d.d.cantidad;
		}
	}
	sort(det.begin(),det.end(),cmp_cantidad);
	reverse(det.begin(),det.end());
	return det;
}

vector<Compra> HistoricoVentas::ultimas_ventas(){
	vector<Compra> ventas = repo_ventas.buscarTodos();
	cout<<ventas.size()<<endl;
	vector<Compra> fiados = repo_fiados.buscarTodos();
	ventas.insert(ventas.end(),fiados.begin(),fiados.end());
	sort(ventas.begin(),ventas.end(),cmp_fecha);
	
	if(ventas.size()>10){
		vector<Compra> ult_ventas;
		for(size_t i =0; i<10;++i) ult_ventas.push_back(ventas[i]);
		return ult_ventas;
	}else{
		return ventas;
	}
}
vector<DetalleYFecha> HistoricoVentas::ventas_por_producto(int codigo){
	vector<DetalleYFecha> todos = repo_detalles.buscarTodos();
	vector<DetalleYFecha> det_prod;
	for(DetalleYFecha &d: todos){
		if(d.d.p._codigo==codigo) det_prod.push_back(d);
	}
	return det_prod;
}
vector<Compra> HistoricoVentas::ventas_por_cliente(string nombre){
	vector<Compra> todos = repo_ventas.buscarTodos();
	vector<Compra> det_cliente;
	for(Compra &c: todos){
		string cliente = c.cliente;
		if(cliente==nombre){
			det_cliente.push_back(c);
		}
	}
	return det_cliente;
}
int HistoricoVentas::generar_codigo(){
	int codigo;
	vector<Compra> ventas = repo_ventas.buscarTodos();
	vector<Compra> fiados = repo_fiados.buscarTodos();
	bool aparece = true;
	while(aparece){
		codigo=rand();
		aparece=false;
		for(Compra &c: ventas){
			if(c.cod_factura==codigo) aparece= true;
		}
		for(Compra &c: fiados){
			if(c.cod_factura==codigo) aparece=true;
		}
	}
	return codigo;
	
}

vector<DetalleYFecha> HistoricoVentas::armar_factura(int codigo_factura){
	vector<DetalleYFecha> todos = repo_detalles.buscarTodos();
	vector<DetalleYFecha> det_fac;
	for(DetalleYFecha &d: todos){
		if(d.cod_factura==codigo_factura) det_fac.push_back(d);
	}
	return det_fac;
}
