#include "DtTeorico.h"

DtTeorico::DtTeorico(int cantAsistentes, string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes):DtClase(nombre, nombreAsig, idAsig, id, fInicio,
                fFin, hInicio, hFin, url, docentes){
    this->cantAsistentes = cantAsistentes;
}

int DtTeorico::getCantAsistentes() const{
    return cantAsistentes;
};


ostream& operator<<(ostream& os,DtTeorico dtc){
    /*os << "-   Id clase: " << dtc.getId() << endl;
	os << "-   Nombre: " << dtc.getNombre() << endl;
	os << "-   Fecha de inicio: " << dtc.getfInicio() << endl;
	os << "-   Fecha de fin: " << dtc.getfFin() << endl;
	os << "-   Hora de inicio: " << dtc.gethInicio() << endl;
	os << "-   Hora de fin: " << dtc.gethFin() << endl;
	os << "-   Url: " << dtc.getUrl() << endl;*/
	os << "-   Cantidad de asistentes: " << dtc.getCantAsistentes() << endl;
	return os;
};

DtTeorico::~DtTeorico()
{
    //dtor
}
