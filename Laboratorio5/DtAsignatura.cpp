#include "DtAsignatura.h"



DtAsignatura::DtAsignatura(){}

DtAsignatura::DtAsignatura(string codigo, string nombre, bool teorico, bool practico, bool monitoreo ){
    this->codigo = codigo;
    this->nombre = nombre;
    this->teorico = teorico;
    this->practico = practico;
    this->monitoreo = monitoreo;
}

string DtAsignatura::getCodigo() const{
    return this->codigo;
}

string DtAsignatura::getNombre() const{
    return this->nombre;
}

bool DtAsignatura::getTeorico() const{
    return this->teorico;
}

bool DtAsignatura::getPractico() const{
    return this->practico;
}

bool DtAsignatura::getMonitoreo() const{
    return this->monitoreo;
}


ostream& operator<<(ostream& os, DtAsignatura dtc){
    os << "-   Codigo: " << dtc.getCodigo() << endl;
	os << "-   Nombre: " << dtc.getNombre() << endl;

	if(dtc.getTeorico()){
        os << "-    Tiene teóricos."<<endl;
    }
    if(dtc.getPractico()){
        os << "-    Tiene practicos."<<endl;
    }
    if(dtc.getMonitoreo()){
        os << "-    Tiene monitoreos."<<endl;
    }


	return os;
}



DtAsignatura::~DtAsignatura()
{
    //dtor
}
