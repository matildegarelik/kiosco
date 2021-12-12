#ifndef REPOSITORIO_H
#define REPOSITORIO_H
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


/* Prototipos de repositorio así los pueden usar sin leer el codigo --> No estan separados pq por ser templatizados tienen que estar adentro
	Repositorio(string nombre_archivo);
	vector<T> buscarTodos();
	vector<T> buscarNoEliminados();	
	T buscarPorIdentificador(string Identificador);
	void guardarNuevo(T entidad);
	void eliminar(T entidad);
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
	
	
	
	vector<T> buscarNoEliminados(){
		vector<T> registros_no_eliminados; 
		if(auxiliar.eliminado = true){
			registros_no_eliminados.push_back(auxiliar);}
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

};




#endif

