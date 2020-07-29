/*
 * Mensaje.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "Mensaje.h"
Mensaje::Mensaje(int i, string contenido, DtFecha fecha, DtHora hora, Usuario* usr){
    id = i;
    msj = contenido;
    fMen = fecha;
    hMen = hora;
    usuario = usr;
    msjPadre = -1;
    map<int, Mensaje*> r;
    respuestas = r;
};
set<DtMensaje*> Mensaje::getListaDtRespuesta(){
    map<int,Mensaje*>::iterator it = respuestas.begin();
    set<DtMensaje*> ret;
    set<DtMensaje*>::iterator fin;
    if (!(respuestas.empty())){
        while(it != respuestas.end()){
            fin = ret.end();
            ret.insert(fin, it->second->getMensaje());
            it++;
        }
    }
    return ret;

};
int Mensaje::getid(){
    return id;
};
string Mensaje::getmsj(){
    return msj;
};
DtFecha Mensaje::getfMen(){
    return fMen;
};
DtHora Mensaje::gethMen(){
    return hMen;
};
Usuario* Mensaje::getusuario(){
    return usuario;
};
map<int, Mensaje*> Mensaje::getrespuestas(){
    return respuestas;
};
int Mensaje::getmsjPadre(){
    return msjPadre;
};

void Mensaje::setmsjPadre(int idmsj){
    msjPadre = idmsj;
};

void Mensaje::agregarMsj(Mensaje* m){
    int i = m->getid();
    this->respuestas.insert(std::pair<int, Mensaje*>(i, m));
};
Mensaje::~Mensaje(){
    if (!respuestas.empty()){
        map<int, Mensaje*>::iterator it;
        Mensaje* m;
        for (it = respuestas.begin(); it!=respuestas.end();it++){
            m=it->second;
            respuestas.erase(it);//lo saca nomas, no?
            m->~Mensaje();
        }
    }
    usuario = NULL;
};

//ENVIO DE MENSAJE
DtMensaje* Mensaje::getMensaje(){
    return new DtMensaje(id, msj, fMen, hMen, usuario->getEmail(), usuario->getnombre(), this->getListaDtRespuesta());
};

bool Mensaje::aplicaNotif(string emailCandidato, Mensaje* pa){
    return pa->checkearUsuario(emailCandidato);
};

bool Mensaje::checkearUsuario(string candidato){
    string emailPadre = this->usuario->getEmail();
    return (candidato == emailPadre);
};
