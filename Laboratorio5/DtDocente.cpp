#include "DtDocente.h"

DtDocente::DtDocente(string nombre, string email, string imagen, string pass, string instituto, tipoDataUsuario td):DtUsuario(nombre, email, imagen, pass, td){
    this->instituto = instituto;
}


DtDocente::DtDocente(string nombre, string email, string imagen, string instituto, tipoDataUsuario td): DtUsuario(nombre, email, imagen, td){
	this->instituto= instituto;
}

DtDocente::DtDocente(string nombre, string email, string img): DtUsuario(nombre, email, img){

}


string DtDocente::getInstituto() const{
    return instituto;
}

ostream& operator<<(ostream& os,DtDocente dtc){
    os << "-   Instituto: " << dtc.getInstituto() << endl;
	return os;
};


DtDocente::~DtDocente(){
    //dtor
}
