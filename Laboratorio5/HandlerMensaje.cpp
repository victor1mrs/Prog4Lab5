/*
 * HandlerMensaje.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "HandlerMensaje.h"

HandlerMensaje* HandlerMensaje::instancia=NULL;


HandlerMensaje::HandlerMensaje() {
    cantMensajes = 0;
    map<int, Mensaje*> u;
	this->mensajes=u;
	map<string, IObserver*> o;
	observers=o;
}

HandlerMensaje* HandlerMensaje::getInstancia(){
	if (instancia==NULL)
		instancia= new HandlerMensaje();
	return instancia;
}

void HandlerMensaje::add(Mensaje* u) {
    //map<int,Mensaje*>::iterator it = mensajes.end();
    mensajes.insert(std::pair<int, Mensaje*>(u->getid(), u));
    cantMensajes++;
};

Mensaje* HandlerMensaje::find(int e){
	map<int,Mensaje*>::iterator it = mensajes.find(e);
	if (it==mensajes.end())
        return NULL;
    else
        return it->second;
};

/*map<int,Mensaje*>::iterator HandlerMensaje::find(int e) {
   return Mensajes.find(e);
};*/

map<int,Mensaje*>::iterator HandlerMensaje::begin() {
   return mensajes.begin();
};
map<int,Mensaje*>::iterator HandlerMensaje::end() {
   return mensajes.end();
};

map<int, Mensaje*> HandlerMensaje::listarMensajes(){
	return mensajes;
};

map<string, IObserver*> HandlerMensaje::getobservers(){
    return observers;
};


//ENVIO DE MENSAJE
void HandlerMensaje::agregarMensaje(Mensaje* m, string nomUsuario, string codAsig, string nomAsig, int idClase, string nomClase, bool es_respuesta){
    //crear dtnotificacion
    DtNotificacion* dtn = new DtNotificacion(m->gethMen(), nomUsuario, m->getmsj(), nomClase, codAsig, idClase, nomAsig);
    //recorrer IObserver
    map<string, IObserver*>::iterator it;
    bool apl = false;
    for(it=observers.begin(); it!=observers.end(); it++){
        apl = it->second->aplicaNotif(m, es_respuesta);
        if (apl==true){
            it->second->notificar(dtn);
        }
    }
};
/*
void HandlerMensaje::aumentarCantMensajes(){
    cantMensajes=cantMensajes+1;
};*/

int HandlerMensaje::getcantMensajes(){
    return cantMensajes;
};


//SUSCRIPCION
void HandlerMensaje::agregarObserver(IObserver* i){
    observers.insert(std::pair<string, IObserver*>(i->getEmail(), i));
};
void HandlerMensaje::removerObserver(IObserver* i){
    map<string,IObserver*>::iterator it = observers.find(i->getEmail());
    IObserver* o = it->second;
    observers.erase(it);
    o->~IObserver();
    //delete it->second;
};
HandlerMensaje::~HandlerMensaje() {
    if (!observers.empty()){
        map<string, IObserver*>::iterator ito;
        IObserver* io;
        for(ito= observers.begin(); ito!=observers.end();ito++){
            io = ito->second;
            observers.erase(ito->first);//SACO AL IOBSERVER DEL HANDLER
            delete (io);//BORRO EL IOBSERVER
        }
    }
    if (!mensajes.empty()){
        map<int, Mensaje*>::iterator itm;
        Mensaje* m;
        for(itm= mensajes.begin(); itm!=mensajes.end();itm++){
            m = itm->second;
            mensajes.erase(itm->first);//SACO EL MENSAJE DEL HANDLER
            m->~Mensaje();//BORRO LAS COSAS DEL MENSAJE
            delete (m);//BORRO EL MENSAJE
        }
    }
}


void HandlerMensaje::removerMensaje(Mensaje* m){
    mensajes.erase(m->getid());
    //m->~Mensaje();
    //delete m;
};
