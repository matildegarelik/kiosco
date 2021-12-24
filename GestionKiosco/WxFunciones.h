//#include "WxFunciones.h"
#include <wx/string.h>
#include <string>
#include "Productos.h"
#include "VentanaValidarHija.h"
using namespace std;


/// para convertir un c-string, o una constante, a wxString
inline wxString c_to_wx(const char *c_str) {
	return wxString::From8BitData(c_str);
}
/// para convertir un std::string a wxString
inline wxString std_to_wx(const std::string &std_str) {
	return wxString::From8BitData(std_str.c_str());
}
/// para convertir wxString a std::string
inline std::string wx_to_std(const wxString &wx_str) {
	return static_cast<const char*>(wx_str.To8BitData());
}
template<typename T, typename T2>
bool Validar(wxWindow *parent, wxCommandEvent& event ,Productos *prods, T2 entidad){
	bool paso = false;
	VentanaValidarHija Ventana_val(parent);
	
	if(entidad.getTamanio() == 0){
		T *Ventana_Nueva = new T(NULL, prods);
		Ventana_Nueva->Show();
		paso = true;
	}else{
		if(Ventana_val.ShowModal()==1){
			T *Ventana_Nueva = new T(NULL, prods);
			Ventana_Nueva->Show();
			paso = true;
		}
	}
	return paso;
}
