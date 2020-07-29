/*
 * Asignacion.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "Asignacion.h"

Asignacion::Asignacion(int i, TipoClase t){
    id =i;
    tClase = t;
};
int Asignacion::getid(){
    return id;
};
Asignatura* Asignacion::getasignatura(){
    return asignatura;
};
TipoClase Asignacion::gettClase(){
    return tClase;
};
Docente* Asignacion::getdocente(){
    return docente;
};

void Asignacion::setdocente(Docente* u){
    docente = u;
};
void Asignacion::setasignatura(Asignatura* a){
    asignatura = a;
};

//DtDocente* Asignacion::getDocente(){
	//DtDocente* dt= this->docente.getInfo();
//};

string Asignacion::getEmailDocente(){
	Docente* docente= this->getdocente();
	string e= docente->getEmail();
	return e;
}

Asignacion::~Asignacion() {
    asignatura = NULL;
    docente->removerAsignacion(this);
    docente = NULL;
    tClase = otro;
}
