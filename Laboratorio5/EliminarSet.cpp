#include "EliminarSet.h"

EliminarSet::EliminarSet()
{
    //ctor
}


void EliminarSet::eliminarlstDtAsignatura(set<DtAsignatura*> lst){
    set<DtAsignatura*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtAsignatura();
        delete  (*it);
    }
};


void EliminarSet::eliminarlstDtDocente(set<DtDocente*> lst){
    set<DtDocente*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtDocente();
        delete (*it);
    }
};



void EliminarSet::eliminarlstDtEstudiante(set<DtEstudiante*> lst){
    set<DtEstudiante*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtEstudiante();
        delete (*it);
    }
};
void EliminarSet::eliminarlstDtNombreClase(set<DtNombreClase*> lst){
    set<DtNombreClase*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtNombreClase();
        delete (*it);
    }
};
void EliminarSet::eliminarlstDtClase(set<DtClase*> lst){
    set<DtClase*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtClase();
        //delete (*it);
    }
};
void EliminarSet::eliminarlstDtTiempoAsig(set<DtTiempoAsignatura*> lst){
    set<DtTiempoAsignatura*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtTiempoAsignatura();
        delete (*it);
    }
};
void EliminarSet::eliminarlstDtPromedioClase(set<DtPromedioClase*> lst){
    set<DtPromedioClase*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtPromedioClase();
        delete (*it);
    }
};
/*
void EliminarSet::eliminarNotificaciones(set<DtNotificacion*> lst){
    set<DtNotificacion*>::iterator it;
    cout << "Notificaciones: " << endl;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << (**it) << endl;
       // delete (*it);
    }
};*/



void EliminarSet::eliminarlstDtMensaje(set<DtMensaje*> lst){
    set<DtMensaje*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        (*it)->~DtMensaje();
        delete(*it);
    }
};


EliminarSet::~EliminarSet()
{
    //dtor
}
