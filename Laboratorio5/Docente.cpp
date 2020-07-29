/*
 * Docente.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "Docente.h"


Docente::Docente():Usuario(){}

Docente::Docente(string n, string e, string i, string p,string ins,  tipoDataUsuario TIPODOCENTE):Usuario(n, e,i,p, TIPODOCENTE) {
    this->instituto = ins;
    tipoRecordado = otro;
}


void Docente::setTipo(TipoClase tc){
	this->tipoRecordado= tc;
}

/*Docente::Docente(string n, string e, string i, string p, string ins):Usuario(n, e,i,p, TIPODOCENTE) {
    instituto = ins;
}*/

string Docente::getinstituto(){
    return instituto;
}

void Docente::setinstituto(string i){
    instituto = i;
}

map<int,Asignacion*> Docente::getasignaciones(){
    return asignaciones;
};

void Docente::agregarasignacion(Asignacion* as){
	//this->asignaciones[as->getid()]= as;
	map<int,Asignacion*> ::iterator it = asignaciones.end();
    asignaciones.insert(it, std::pair<int, Asignacion*>(as->getid(), as));
};



DtDocente* Docente::getInfo(){
	DtDocente* dt= new DtDocente(this->getinstituto(),this->getnombre(), this->getEmail(), this->getimagen(), this->getTipo());
	return dt;
}

map<int, Clase*> Docente::getclases(){
    return clases;
};

void Docente::setclase(Clase* c){
    map<int,Clase*>::iterator it = clases.end();
    clases.insert(it,std::pair<int, Clase*>(c->getId(),c));
};

void Docente::confirmarAsignacion(Docente* d, TipoClase tc, Asignatura* a){
	HandlerAsignatura* HA = HandlerAsignatura::getInstancia();

	int cantAsignaciones= HA->getCantAsignaciones();
	HA->aumentarCantAsignaciones();
	Asignacion* asignacion = new Asignacion(cantAsignaciones+1, tc);
	//this->asignaciones[asignacion->getid()]= asignacion;//NO ANDA
	/*HandlerAsignatura* ha = HandlerAsignatura::getInstancia();
	Asignatura* ASIG = ha->find(a->getCodigo());
    HandlerUsuario* hu = HandlerUsuario::getInstancia();
	Usuario* DOC1 = hu->find(d->getEmail());
	Docente* DOC = dynamic_cast<Docente*>(DOC1);*/
	asignacion->setdocente(d);
	asignacion->setasignatura(a);
	a->agregarAsignacion(asignacion);
	map<int,Asignacion*>::iterator it = asignaciones.end();
    asignaciones.insert(it, std::pair<int, Asignacion*>(asignacion->getid(), asignacion));
}

//INICIO DE CLASE
TipoClase Docente::getRol(Asignatura* asig){
    map<int,Asignacion*>::iterator it;
    for(it=asignaciones.begin(); it!=asignaciones.end(); it++){
        if(asig->getCodigo() == it->second->getasignatura()->getCodigo()){
            return it->second->gettClase();
        }
    }
    return otro;
};

//FINALIZACION DE CLASE
set<DtNombreClase*> Docente::listarClasesEnVivo(string cod){
    map<int, Clase*>::iterator itm;
    set<DtNombreClase*> a_retornar;
    set<DtNombreClase*>::iterator fin;
    for (itm = clases.begin(); itm != clases.end(); itm++){
        fin = a_retornar.end();
        Clase* aux = itm->second;
        if(aux->gethFin().gethora() == -1){
            //crear DtNombreClase con nombre e id
             DtNombreClase* nc = aux->getNombreClase();
            a_retornar.insert(fin,nc);
        }
    }
    return a_retornar;
};

Clase* Docente::seleccionarClaseVivo(int id,string cod){
    map<int, Clase*>::iterator it = clases.find(id);
    if(it==clases.end()){
        return NULL;
    }
    return it->second;
}


//ENVIO DE MENSAJE
set<DtClase*> Docente::listarClases(){
    map<int, Clase*>::iterator it;
    set<DtClase*> a_retornar;
    set<DtClase*>::iterator fin;
    for(it=clases.begin(); it!=clases.end(); it++){
        fin = a_retornar.end();
        if (it->second!=NULL)
            a_retornar.insert(fin, it->second->getInfo());
    }
    return a_retornar;
};

set<DtMensaje*> Docente::verMensajes(int idClase){
    map<int, Clase*>::iterator it = clases.find(idClase);
    set<DtMensaje*> a_retornar;
    set<DtMensaje*>::iterator fin;
    map<int, Mensaje*>::iterator itm;
    map<int, Mensaje*> lstmsjs = it->second->listarMensajes();
    for(itm=lstmsjs.begin(); itm!=lstmsjs.end(); itm++){
        fin = a_retornar.end();
        a_retornar.insert(fin, itm->second->getMensaje());
    }
    return a_retornar;
};


//ELIMINACION DE ASIGNATURA
void Docente::removerAsignacion(Asignacion* a){
    asignaciones.erase(a->getid());
};
void Docente::removerClase(Clase* c){
    clases.erase(c->getId());
};


Docente::~Docente() {

    if(!asignaciones.empty()){
        map<int, Asignacion*>::iterator it;
        for (it=asignaciones.begin(); 0!=asignaciones.size();it=asignaciones.begin()){
            asignaciones.erase(it->first);//lo saca del docente
        }
    }

    if(!clases.empty()){
        map<int, Clase*>::iterator itc;
        for (itc=clases.begin(); 0!=clases.size();itc=clases.begin()){
            clases.erase(itc->first);//lo saca o lo borra?
        }
    }
}
