
#include "Monitoreo.h"

Monitoreo::Monitoreo(string n, int i, DtFecha fI, DtFecha fF, DtHora hI, DtHora hF, string u, string cod, string nomA):Clase(n, i, fI, fF, hI, hF, u, cod, nomA) {
    map<string, Estudiante*> est;
    estudiantes = est;
}

map<string, Estudiante*> Monitoreo::getEstudiantes(){
    return estudiantes;
};
void Monitoreo::agregarEstudiante(Estudiante* e){
    if (estudiantes.size()<15){//mymap.insert (it, std::pair<char,int>('b',300))

    	//estudiantes[e->getEmail()]=e;
    	map<string, Estudiante*>::iterator it = estudiantes.end();
        estudiantes.insert(it, std::pair<string, Estudiante*>(e->getEmail(), e));

    }else cout<<"No se puede agregar porque el monitoreo está lleno."<<endl;
    //throw std::invalid_argument ("No se puede agregar porque el monitoreo esta lleno.\n"); //poner cout
};

Monitoreo::~Monitoreo(){
    map<string, Estudiante*>::iterator it;
    for (it=estudiantes.begin(); 0!=estudiantes.size();it=estudiantes.begin()){
        estudiantes.erase(it);//SACO AL ESTUDIANTE DEL MONITOREO
    }
}
