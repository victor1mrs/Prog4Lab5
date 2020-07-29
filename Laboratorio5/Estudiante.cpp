#include "Estudiante.h"


//Estudiante::Estudiante(string c, string n, string e, string i, string p, tipoDataUsuario TIPOESTUDIANTE):Usuario(n, e,i,p, TIPOESTUDIANTE) {

Estudiante::Estudiante(string n, string e, string i, string p, string c, tipoDataUsuario td):Usuario(n, e,i,p, td) {
	ci = c;
}

string Estudiante::getci(){
    return ci;
};
map<int, Monitoreo*> Estudiante::getmonitoreos(){
    return monitoreos;
};
map<string, Asignatura*> Estudiante::getasignaturas(){
    return asignaturas;
};
void Estudiante::setci(string c){
    ci = c;
};
void Estudiante::agregarmonitoreo(Monitoreo* c){
    map<int,Monitoreo*> ::iterator it = monitoreos.end();
    monitoreos.insert(it, std::pair<int, Monitoreo*>(c->getId(), c));
};
void Estudiante::agregarasignatura(Asignatura* as){
    map<string,Asignatura*> ::iterator it = asignaturas.end();
    asignaturas.insert(it, std::pair<string, Asignatura*>(as->getCodigo(), as));
};

DtEstudiante* Estudiante::getInfo(){
    DtEstudiante* dt = new DtEstudiante(this->getnombre(), this->getEmail(), this->getimagen(), this->getpass(), this->getci());
	return dt;
};


//ENVIO DE MENSAJE
set<DtClase*> Estudiante::listarClases(){
    set<DtClase*> a_retornar;
    set<DtClase*>::iterator fin;
    map<int, InfoVisita*>::iterator it;
    Clase* c;
    if (this->getinfovisitas().empty())
    	throw std::invalid_argument {"No asiste a esta clase."};
    unsigned int i=0;
    for(it = this->getinfovisitas().begin();i!= this->getinfovisitas().size(); it++){
        c = it->second->getClaseAsociada();
        fin = a_retornar.end();
        a_retornar.insert(fin, c->getInfo());
        i++;
    }
    return a_retornar;
}


set<DtMensaje*> Estudiante::verMensajes(int idClase){//ACA
    set<DtMensaje*> a_retornar;
    if(!this->getinfovisitas().empty()){
        map<int, InfoVisita*>::iterator it = this->getinfovisitas().find(idClase);//el id clase == id infovisita. Se hace en asistencia

        Clase* c = it->second->getClaseAsociada();

        set<DtMensaje*>::iterator fin;
        map<int, Mensaje*>::iterator itm;
        map<int, Mensaje*> lstmsjs = c->listarMensajes();
        for(itm=lstmsjs.begin(); itm!=lstmsjs.end(); itm++){
            fin = a_retornar.end();
            a_retornar.insert(fin, itm->second->getMensaje());
        }
    }
    else
        cout<<"Nunca ha asistido a esa clase."<<endl;

    return a_retornar;

};


//ASISTENCIA A CLASE EN VIVO
set<DtNombreClase*> Estudiante::listarClasesEnVivo(string cod){
    HandlerAsignatura* HA = HandlerAsignatura::getInstancia();
    Asignatura* asig = HA->find(cod);
    map<int, Clase*> lstclases = asig->getClases();
    map<int, Clase*>::iterator it;
    Clase* c;
    set<DtNombreClase*> a_retornar;
    set<DtNombreClase*>::iterator fin;
    for(it=lstclases.begin(); it!=lstclases.end(); it++){
        c = it->second;
        if (c->gethFin().gethora()==-1){
            fin = a_retornar.end();
            a_retornar.insert(fin, c->getNombreClase());
        }
    }
    return a_retornar;
}

Clase* Estudiante::seleccionarClaseVivo(int id, string cod){
    HandlerAsignatura* HA = HandlerAsignatura::getInstancia();
    Asignatura* asig = HA->find(cod);
    map<int, Clase*> lstclases = asig->getClases();
    map<int, Clase*>::iterator it = lstclases.find(id);
    Clase* c = it->second;
    return c;
}


//ELIMINACION DE ASIGNATURA
Estudiante::~Estudiante() {
    map<string, Asignatura*>::iterator it;
    for (it=asignaturas.begin(); 0!=asignaturas.size();it=asignaturas.begin()){
        asignaturas.erase(it->first);//lo saca de estudiante
    }

    map<int,Monitoreo*>::iterator it1;
    for (it1=monitoreos.begin(); 0!=monitoreos.size();it1=monitoreos.begin()){
        monitoreos.erase(it1->first);//lo saca de estudiante
    }
}

void Estudiante::removerMonitoreo(Monitoreo* m){
    monitoreos.erase(m->getId());//lo saca o lo borra?
};

void Estudiante::removerAsignatura(Asignatura* a){
    asignaturas.erase(a->getCodigo());//lo saca o lo borra?

};
