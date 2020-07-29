#include "DtClase2.h"

DtClase2::DtClase2(string nombre, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url){
    this->nombre=nombre;
    this->id=id;
    this->fInicio=fInicio;
    this->fFin=fFin;
    this->hInicio=hInicio;
    this->hFin= hFin;
    this->url = url;
};


string DtClase2::getNombre() const{
    return nombre;
};


int DtClase2::getId() const{
    return id;
};

DtFecha DtClase2::getFInicio() const{
    return fInicio;
};

DtFecha DtClase2::getFFin() const{
    return fFin;
};


DtHora DtClase2::getHInicio() const{
    return hInicio;
};

DtHora DtClase2::getHFin() const{
    return hFin;
};

string DtClase2::getUrl() const{
    return url;
};


ostream& operator<<(ostream& os,DtClase2 dtc){
    os << "-   Id clase: " << dtc.getId() << endl;
	os << "-   Nombre clase: " << dtc.getNombre() << endl;
	os << "-   Fecha de inicio: " << dtc.getFInicio() << endl;
	if (dtc.getFFin().getdia()!=-1)
        os << "-   Fecha de fin: " << dtc.getFFin() << endl;
	os << "-   Hora de inicio: " << dtc.getHInicio() << endl;
	if (dtc.getHFin().gethora()!=-1)
        os << "-   Hora de fin: " << dtc.getHFin() << endl;
	os << "-   Url: " << dtc.getUrl() << endl;
	return os;
};


DtClase2::~DtClase2()
{
    //dtor
}
