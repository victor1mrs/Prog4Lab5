#include "Respuesta.h"

Respuesta::Respuesta():Suscripcion(){
}

Respuesta::~Respuesta()
{
    //dtor
}

bool Respuesta::aplicaNotif(Mensaje* m, string emailCandidato, bool es_respuesta){
    if (es_respuesta){
        HandlerMensaje* hm = HandlerMensaje::getInstancia();
        Mensaje* padre = hm->find(m->getmsjPadre());
        return m->aplicaNotif(emailCandidato, padre);
        //if (padre==NULL)
    }
    else return false;
};
