#ifndef REPOSITORIO_H
#define REPOSITORIO_H
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Venta.h"
#include "Productos.h"
#include <iostream>

using namespace std;


/* Prototipos de repositorio así los pueden usar sin leer el codigo --> No estan separados pq por ser templatizados tienen que estar adentro
	Repositorio(string nombre_archivo);
	vector<T> buscarTodos();
	vector<T> buscarNoEliminados();
	bool existe(T entidad);
	void verTodos();
	T buscarPorIdentificador(string Identificador);
	void guardarNuevo(T entidad);
	void eliminar(T entidad);
	void eliminarPermanente(T entidad);
	vector<T> eliminarMultiple( vector<int> posiciones);
	void actualizar(vector<T> registros);*/


template<typename T>
class Repositorio {
private:
	string nombre_archivo;
	vector<T> m_registros;
public:
	
	Repositorio(string nombre_archivo){
		T auxiliar;
		
		this->nombre_archivo = nombre_archivo;
		
		ifstream fin(nombre_archivo,ios::binary|ios::in|ios::ate);
		
		int cant_datos = fin.tellg()/sizeof(T);
		fin.seekg(0);
		
		for(int i=0;i<cant_datos;i++) { 
			fin.read(reinterpret_cast<char *> (&auxiliar), sizeof(auxiliar));	
			m_registros.push_back(auxiliar);
		}
		
		fin.close();
	}
	
	
	vector<T> buscarTodos(){ //Devolver los elementos no eliminados 		
		return m_registros;
	}
	
	
	void verTodos(){
		cout<<"Archivo:"<<nombre_archivo<<endl; //esto dsp hay que pasarlo a la ventana grafica
		ifstream fin(nombre_archivo,ios::binary|ios::ate);
		int cant_datos = fin.tellg()/sizeof(T);
		fin.seekg(0);
		T aux;
		for(int i=0;i<cant_datos;i++) { 
			fin.read(reinterpret_cast<char *> (&aux), sizeof (aux));
			cout<<aux<<endl;
		}
		cout<<endl;
		fin.close();
	}
		
	vector<T> buscarNoEliminados(){
		vector<T> registros_no_eliminados; 
		T auxiliar;
		for(int i=0;i<m_registros.size();i++) { 
			if(auxiliar.eliminado = true){
				registros_no_eliminados.push_back(auxiliar);}			
		}
		return registros_no_eliminados;
	}
	
	
	//Buscar por codigo o factura.... La funcion obtenerIdentificador deberia estar tanto en la clase productos y ventas para que retorne el identificador que corresponde
	T buscarPorIdentificador(string Identificador){
		T auxiliar, entidad_retorno;
		
		fstream f(nombre_archivo,ios::binary|ios::in|ios::ate);
		
		int cant_datos = f.tellg()/sizeof(T);
		f.seekg(0);
		
		for(int i=0;i<cant_datos;i++) { 
			f.read(reinterpret_cast<char *> (&auxiliar), sizeof(auxiliar));	
			if(Identificador == this->obtenerIdentificador( auxiliar)){
				entidad_retorno = auxiliar;
				break;
			}
		}
		
		f.close();
		
		return entidad_retorno;
	}
	
	bool existe(T entidad){
		bool retorno = false;
		auto it = find(m_registros.begin(),m_registros.end(),entidad);
		if(it != m_registros.end()){
			retorno = true;
		}
		return retorno;
	}
	
	
	//La opcion empleada es pasandole el vector, pero esta comentada la version buscando en el archivo y verificando si existe
	void guardarNuevo(T entidad){ 
		ofstream fout(nombre_archivo,ios::binary|ios::out|ios::app);
		
		auto it = find(m_registros.begin(),m_registros.end(),entidad);
		if(it != m_registros.end()){
			fout.write(reinterpret_cast<char *> (&entidad), sizeof(entidad));
			m_registros.push_back(entidad);
		}
		fout.close();
		//		
		//		fstream f(nombre_archivo,ios::binary|ios::in|ios::out|ios::ate);
		//		int cant_datos = f.tellg()/sizeof(T);
		//		f.seekg(0);
		//		bool existe = false;
		//		for(int i=0;i<cant_datos;i++) { 
		//			f.read(reinterpret_cast<char *> (&auxiliar), sizeof(auxiliar));	
		//			if(auxiliar == entidad){
		//				existe = true;
		//				break;
		//				}
		//		if(existe) f.write(reinterpret_cast<char *> (&entidad), sizeof(entidad));	
		//		f.close();
	}
	
	
	
	//La version comentada lo elimina permanentemente mientras que la activa lo elimina logicamente
	void eliminar(T entidad){
		//		auto it_remove = remove(m_registros.begin(),m_registros.end(),entidad);
		//		if(it_remove != m_registros.end()){
		//			m_registros.erase(it_remove);
		//			
		//			ofstream fout(nombre_archivo,ios::binary|ios::trunc);
		//			for(int i=0;i<registros.size();i++) { 
		//				fout.write(reinterpret_cast<char *> (&registros[i]), sizeof(registros[i]));
		//			}
		//			fout.close();		
		//		}
		T auxiliar;
		fstream f(nombre_archivo,ios::binary|ios::in|ios::out|ios::ate);
		
		for(int i=0;i<m_registros.size();i++) {
			f.read(reinterpret_cast<char *> (&auxiliar), sizeof(auxiliar));	
			
			if(entidad == auxiliar){
				m_registros[i].eliminado = true;
				f.write(reinterpret_cast<char *> (&auxiliar), sizeof(auxiliar));
			}
			f.close();		
		}
	}
		
	void eliminarPermanente(T entidad){
		auto it_remove = remove(m_registros.begin(),m_registros.end(),entidad);
		if(it_remove != m_registros.end()){
			m_registros.erase(it_remove);
			
			ofstream fout(nombre_archivo,ios::binary|ios::trunc);
			for(int i=0;i<m_registros.size();i++) { 
				fout.write(reinterpret_cast<char *> (&m_registros[i]), sizeof(m_registros[i]));
			}
			fout.close();		
		}
	}
	
	
	//La version comentada lo elimina permanentemente mientras que la activa lo elimina logicamente
	vector<T> eliminarMultiple( vector<int> posiciones){
		
		//		for(int i=0;i<posiciones.size();i++) { 
		//			m_registros.erase(posiciones[i]);
		//		}
		//		ofstream fout(nombre_archivo,ios::binary|ios::trunc);
		//		
		//		for(int i=0;i<registros.size();i++) { 
		//			fout.write(reinterpret_cast<char *> (&m_registros[i]), sizeof(m_registros[i]));
		//		}
		//		fout.close();
		//		
		//		return m_registros;
		//	}
		
		T auxiliar;
		fstream f(nombre_archivo,ios::binary|ios::in|ios::out);
		
		for(int i=0;i<posiciones.size();i++) {
			f.seekg(sizeof(T)*posiciones[i]);
			f.read(reinterpret_cast<char *> (&auxiliar), sizeof(auxiliar));	
			
			f.seekp(sizeof(T)*posiciones[i]);
			f.write(reinterpret_cast<char *> (&auxiliar), sizeof(auxiliar));
			
			m_registros[posiciones[i]].eliminado = true;
		}
		f.close();					
	}

	void cargarDatosDePruebaProducto(){
		ofstream fout(nombre_archivo,ios::binary|ios::trunc);

		Producto p1 = {"barra chocolate", "arcor", "alimento", 1, 4, 100};
		Producto p2 = {"chocolate", "arcor", "alimento", 2, 10, 200};
		Producto p3 = {"caramelo", "sugus", "alimento", 3, 20, 5};
		Producto p4 = {"desodorante", "rexona", "higiene", 4, 0, 160};
		Producto p5 = {"desodorante", "nivea", "higiene", 5, 0, 15};
		
		fout.write(reinterpret_cast<char*> (&p1), sizeof(Producto));
		fout.write(reinterpret_cast<char*> (&p2), sizeof(Producto));
		fout.write(reinterpret_cast<char*> (&p3), sizeof(Producto));
		fout.write(reinterpret_cast<char*> (&p4), sizeof(Producto));
		fout.write(reinterpret_cast<char*> (&p5), sizeof(Producto));
	}
	void cargarDatosDePruebaVenta(){
		ofstream fout(nombre_archivo,ios::binary|ios::trunc);
//		Fecha f1 = {2,10,2021};
//		Compra c1 = {"lucas",f1 ,450};
//		Compra c2 = {"Mati", f1,500};
//		Compra c3 = {"Brian",f1,300};
//		Compra c4 = {"aaaa", f1,800};
//		Compra c5 = {"bbbb", f1,300};
//	
//		fout.write(reinterpret_cast<char*> (&c1), sizeof(Compra));
//		fout.write(reinterpret_cast<char*> (&c2), sizeof(Compra));
//		fout.write(reinterpret_cast<char*> (&c3), sizeof(Compra));
//		fout.write(reinterpret_cast<char*> (&c4), sizeof(Compra));
//		fout.write(reinterpret_cast<char*> (&c5), sizeof(Compra));
	}
		
};




#endif

