/*
 * InfoVisita.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "InfoVisita.h"

InfoVisita::InfoVisita(int i, Clase* c){
    id = i;
    claseAsociada = c;
};
int InfoVisita::getId(){
    return id;
};
set<DtInfo*> InfoVisita::getInfo(){
    return info;
};
void InfoVisita::agregarDtInfo(DtInfo* i){
    set<DtInfo*>::iterator it = info.end();
    info.insert(it, i);
};
Clase* InfoVisita::getClaseAsociada(){
    return claseAsociada;
};
/*
Usuario* InfoVisita::getUsuarioAsociado(){
    return usuario;
};
void InfoVisita::setUsuarioAsociado(Usuario* u){
    usuario = u;
};*/

string InfoVisita::getUsuarioAsociado(){
    return usuario;
};
void InfoVisita::setUsuarioAsociado(string u){
    usuario = u;
};



//para eliminacion
InfoVisita::~InfoVisita(){
    set<DtInfo*>::iterator iti;
    //DtInfo* dti;
    for (iti = info.begin(); 0 != info.size(); iti = info.begin()){
        //dti = *iti;
        info.erase(iti);
        //dti->~DtInfo();//no hace nada porque es un datatype
        //delete(dti);
    }
//usuario->removerinfovisita(this);
    //usuario = NULL;
    claseAsociada = NULL;
};

//Fin de asistenica a clase en vivo
void InfoVisita::terminarVisitas(){
	Reloj* r= Reloj::getInstancia();
	DtFecha nuevaFecha = r->getfecha();
	DtHora nuevaHora = r->gethora();
	for (set<DtInfo*>::iterator it = info.begin(); it != info.end(); it++){
		if((*it)->gethFin().gethora()== -1)
            (*it)->setFechaYHoraFinales(nuevaFecha, nuevaHora);
    }
}



//Tiempo de Asistencia a clase
float InfoVisita::TiempoInfoVisita(){

    set<DtInfo*>::iterator iti;
    float suma = 0;
    int cant = 0;
    for (iti = info.begin(); iti != info.end(); iti++){
        cant++;
        suma = suma + (*iti)->calculoTiempoDtInfo();
    }
    float res = suma / cant;
    return res;
}
