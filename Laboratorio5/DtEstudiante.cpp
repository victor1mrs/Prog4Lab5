#include "DtEstudiante.h"

DtEstudiante::DtEstudiante(string nombre, string email, string imagen, string pass, string ci):DtUsuario(nombre, email, imagen, pass, TIPOESTUDIANTE){
    this->ci=ci;
}

string DtEstudiante::getCi() const{
    return ci;
}


ostream& operator<<(ostream& os,DtEstudiante dtc){
	//os << "-   CI: " << dtc.getCi() << endl;
	os << "-   Email: " << dtc.getEmail() << endl;
	return os;
};



DtEstudiante::~DtEstudiante(){
    //dtor
}
