#include "DtClase.h"

DtClase::DtClase(string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes){
    this->nombre=nombre;
    this->nombreAsig=nombreAsig;
    this->idAsig=idAsig;
    this->id=id;
    this->fInicio=fInicio;
    this->fFin=fFin;
    this->hInicio=hInicio;
    this->hFin= hFin;
    this->url = url;
    this->docentes = docentes;
};
DtClase::DtClase(string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url){
    this->nombre=nombre;
    this->nombreAsig=nombreAsig;
    this->idAsig=idAsig;
    this->id=id;
    this->fInicio=fInicio;
    this->fFin=fFin;
    this->hInicio=hInicio;
    this->hFin= hFin;
    this->url = url;
};




DtClase::DtClase(string nombre, int id, DtFecha fInicio, DtHora hInicio, string url){
    this->nombre=nombre;
    this->id=id;
    this->hInicio=hInicio;
    this->fInicio= fInicio;
    this->url = url;
};



string DtClase::getidAsig() const{
    return idAsig;
};

string DtClase::getNombre() const{
    return nombre;
};

string DtClase::getNombreAsig() const{
    return nombreAsig;
};

int DtClase::getId() const{
    return id;
};

DtFecha DtClase::getFInicio() const{
    return fInicio;
};

DtFecha DtClase::getFFin() const{
    return fFin;
};


DtHora DtClase::getHInicio() const{
    return hInicio;
};

DtHora DtClase::getHFin() const{
    return hFin;
};

string DtClase::getUrl() const{
    return url;
};

set<DtDocente> DtClase::getDocentes() const{
    return docentes;
};

ostream& operator<<(ostream& os,DtClase dtc){
    //os << "-   Codigo asignatura: " << dtc.getidAsig() << endl;
    //os << "-   Nombre asignatura: " << dtc.getNombreAsig() << endl;
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


DtClase::~DtClase()
{
    //dtor
}
