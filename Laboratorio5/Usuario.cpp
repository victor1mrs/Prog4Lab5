/*
 * Usuario.cpp
 *
 *  Created on: 2 jun. 2020
 *      Author: Santi
 */

#include "Usuario.h"

Usuario::Usuario(string n, string e, string i, string p, tipoDataUsuario tipo) {
	map<int, InfoVisita*>info;
	set<DtNotificacion*> noti;
    nombre = n;
    email = e;
    imagen = i;
    pass = p;
    infovisitas = info;
    notificaciones = noti;
    this->tipo=tipo;
    modoSuscripcion = NULL;
}

Usuario::Usuario() {
    map<int, InfoVisita*> info;
    infovisitas = info;
    set<DtNotificacion*> noti;
    notificaciones = noti;
    modoSuscripcion = NULL;
}



string Usuario::getnombre(){
    return nombre;
}
string Usuario::getEmail(){
    return email;
}
string Usuario::getimagen(){
    return imagen;
}
string Usuario::getpass(){
    return pass;
}
map<int, InfoVisita*> Usuario::getinfovisitas(){
    return infovisitas;
}


void Usuario::setnombre(string n){
    nombre = n;
}
void Usuario::setemail(string e){
    email = e;
}
void Usuario::setimagen(string i){
    imagen = i;
}
void Usuario::setpass(string p){
    pass = p;
}

void Usuario::setTipo(tipoDataUsuario tipo){
	this->tipo=tipo;
}

const tipoDataUsuario Usuario::getTipo() const{
	return tipo;
}


void Usuario::agregarinfovisita(InfoVisita* info){
    infovisitas.insert(std::pair<int, InfoVisita*>(info->getId(), info));
}
//para eliminar asignatura
void Usuario::removerinfovisita(InfoVisita* i){
    infovisitas.erase(i->getId());
    //delete (i);
};


//ENVIO DE MENSAJES
void Usuario::notificar(DtNotificacion* n){
    set<DtNotificacion*>::iterator it;
    it = notificaciones.end();
    notificaciones.insert(it, n);
};

bool Usuario::aplicaNotif(Mensaje* m, bool es_respuesta){
    if(typeid(Respuesta).name() == typeid(*modoSuscripcion).name()){
        return modoSuscripcion->aplicaNotif(m, email, es_respuesta);
    }
    return false;
}

void Usuario::setModoSuscripcion(Suscripcion* r){
    modoSuscripcion = r;
};



Suscripcion* Usuario::crearSuscripcion (string modo){
    Respuesta* r;
	if (modo=="Respuesta"){
		r= new Respuesta();
		this->setModoSuscripcion(r);
	}
	//Suscripcion* r= new Suscripcion();
	return r;
}



set<DtNotificacion*> Usuario::getNotificaciones(){
	return this->notificaciones;
}

void Usuario::eliminarNotificaciones(){
	set<DtNotificacion*>::iterator it;
	for (it= notificaciones.begin(); 0!=notificaciones.size(); it= notificaciones.begin()){
		notificaciones.erase(it);
		//delete (*it);
	}
}



Usuario::~Usuario() {
    if (!infovisitas.empty()){
        map<int, InfoVisita*>::iterator it;
        for (it=infovisitas.begin(); 0!=infovisitas.size();it=infovisitas.begin()){
            infovisitas.erase(it->first);//lo saca de usuario
            //delete(it->second);
        }
    }

    if (!notificaciones.empty()){
        set<DtNotificacion*>::iterator it1;
        for (it1=notificaciones.begin(); 0!=notificaciones.size();it1=notificaciones.begin()){
            notificaciones.erase(*it1);//lo saca de usuario
            //delete(*it1);
        }
    }
}

