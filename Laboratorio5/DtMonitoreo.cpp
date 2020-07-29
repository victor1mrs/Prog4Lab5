#include "DtMonitoreo.h"

DtMonitoreo::DtMonitoreo(set<DtEstudiante> estudiantes, string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes):DtClase(nombre, nombreAsig, idAsig, id, fInicio,
                fFin, hInicio, hFin, url, docentes){
    this->estudiantes = estudiantes;
}

set<DtEstudiante> DtMonitoreo::getEstudiantes() const{
    return estudiantes;
};

ostream& operator<<(ostream& os,DtMonitoreo dtc){
    /*os << "-   Id clase: " << dtc.getId() << endl;
	os << "-   Nombre: " << dtc.getNombre() << endl;
	os << "-   Fecha de inicio: " << dtc.getfInicio() << endl;
	os << "-   Fecha de fin: " << dtc.getfFin() << endl;
	os << "-   Hora de inicio: " << dtc.gethInicio() << endl;
	os << "-   Hora de fin: " << dtc.gethFin() << endl;
	os << "-   Url: " << dtc.getUrl() << endl;*/
	//os << "-   Inscriptos: " << dtc.getEstudiantes()<<endl;//ARREGLAR
	//Imprimir i = Imprimir();
    //i->imprimirlstDtEstudiante(dtc.getEstudiantes());
	return os;
};


DtMonitoreo::~DtMonitoreo()
{
    //dtor
}
