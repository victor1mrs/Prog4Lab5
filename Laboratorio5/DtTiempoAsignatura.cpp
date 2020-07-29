#include "DtTiempoAsignatura.h"

DtTiempoAsignatura::DtTiempoAsignatura(string i, string n, int t){
    id =i;
    nombre = n;
    tiempo = t;
};
string DtTiempoAsignatura::getid(){
    return id;
};
string DtTiempoAsignatura::getnombre(){
    return nombre;
};
int DtTiempoAsignatura::gettiempo(){
    return tiempo;
};

ostream& operator<<(ostream& os,DtTiempoAsignatura dtc){
	os << "-   Nombre de asignatura: " << dtc.getnombre() << endl;
	os << "-   Codigo de asignatura: " << dtc.getid() << endl;
	os << "-   Tiempo de dictado de clases: ";
	int segTotal = dtc.gettiempo();
    int horas = segTotal/3600;
    int minutos = (segTotal - horas* 3600)/60;
    int segundos = segTotal - (horas*3600 + minutos*60);

    os<<horas<<" horas, "<< minutos << " minutos, " << segundos<<" segundos." <<endl;
	return os;
};

DtTiempoAsignatura::DtTiempoAsignatura(string i, string n){
	id =i;
	nombre = n;

}

void DtTiempoAsignatura::setTiempo(int t){
	this->tiempo =t;

}


DtTiempoAsignatura::~DtTiempoAsignatura(){
};
