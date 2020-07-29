#include "DtPractico.h"

DtPractico::DtPractico(string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes):DtClase(nombre, nombreAsig, idAsig, id, fInicio,
                fFin, hInicio, hFin, url, docentes)
{
    //ctor
}
/*
ostream& operator<<(ostream& os,DtPractico dtc){
   os << "-   Id clase: " << dtc.getId() << endl;
	os << "-   Nombre: " << dtc.getNombre() << endl;
	os << "-   Fecha de inicio: " << dtc.getfInicio() << endl;
	os << "-   Fecha de fin: " << dtc.getfFin() << endl;
	os << "-   Hora de inicio: " << dtc.gethInicio() << endl;
	os << "-   Hora de fin: " << dtc.gethFin() << endl;
	os << "-   Url: " << dtc.getUrl() << endl;
	return os;
};*/


DtPractico::~DtPractico()
{
    //dtor
}
