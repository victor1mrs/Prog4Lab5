/*
 * Clase.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "Clase.h"

Clase::Clase(string n, int i, DtFecha fI, DtFecha fF, DtHora hI, DtHora hF, string u, string cod, string nomAsig) {

	nombre = n;
	id = i;
	fInicio = fI;
	fFin = fF;
	hInicio = hI;
	hFin = hF;
	url = u;
	map<int, Mensaje*> men;
	map<string, Docente*> doc;
	set<InfoVisita*> info;

	infosVisita = info;
	docentes = doc;
	mensajes = men;

	codigoAsignatura = cod;
	nombreAsignatura = nomAsig;
}


void Clase::setNombre(string n){
	this->nombre=n;}

void Clase::setId(int id){
	this->id=id;}

void Clase::setfInicio(DtFecha fI){
	this->fInicio=fI;}

void Clase::setfFin(DtFecha fF){
	this->fFin=fF;}

void Clase::sethInicio(DtHora hI){
	this->hInicio=hI;}

void Clase::sethFin(DtHora hF){
	this->hFin=hF;	}

void Clase::setUrl(string url){
	this->url=url;}


void Clase::agregarDocente(Docente* d){
	//docentes[d->getEmail()]= d;
    map<string, Docente*>::iterator it = docentes.end();
    docentes.insert(it, std::pair<string, Docente*>(d->getEmail(), d));
}
void Clase::agregarInfoVisita(InfoVisita* i){
    set<InfoVisita*>::iterator it = infosVisita.end();
    infosVisita.insert(it, i);
};

string Clase::getCodigoAsignatura(){
    return codigoAsignatura;
};

string Clase::getNombre(){
	return this->nombre;
}
string Clase::getNombreAsignatura(){
	return this->nombreAsignatura;
}


int Clase::getId(){
	return this->id;
}

DtFecha Clase::getfInicio(){
	return this->fInicio;}

DtFecha Clase::getfFin(){
	return this->fFin;}

DtHora Clase::gethInicio(){
	return this->hInicio;}

DtHora Clase::gethFin(){
	return this->hFin;	}

string Clase::getUrl(){
	return this->url;	}

map<int, Mensaje*> Clase::listarMensajes(){
    return this->mensajes;
}

map<string, Docente*> Clase::listarDocentes(){
    map<string, Docente*> docs= this->docentes;
    return docs;
}

set<InfoVisita*> Clase::listarInfosVisita(){
    return this->infosVisita;
}


DtNombreClase* Clase::getNombreClase(){
    DtNombreClase* dtnc = new DtNombreClase(this->getNombre(), this->getId());
    return dtnc;
};

// No sera DtClase* ???
DtClase Clase::getDtClase(string nomAsig, string codAsig){//No parece coherente tener que pasarle esos datos por parametro, ademas no se si son necesarios
    //map<string, Docente*> docentes;
    set<DtDocente> d;//ARREGLAR
    //for (int i)


    DtClase dtc = DtClase(nombre, nomAsig, codAsig, id, fInicio, fFin, hInicio, hFin, url, d);
    return dtc;
};
void Clase::setClase(DtFecha ff, DtHora hf, string u){
    fFin = ff;
    hFin = hf;
    url = u;
};

/*bool Clase::aplica_notif(Usuario*){//HACER?
};*/

void Clase::finalizarInfos(){
	for (set<InfoVisita*>::iterator it = infosVisita.begin(); it!= infosVisita.end(); it++){
		(*it)->terminarVisitas();
	}
};


Clase::~Clase() {
	map<int, Mensaje*>::iterator itm;
	set<InfoVisita*>::iterator iti;
	map<string, Docente*>::iterator itd;

    HandlerMensaje* HM = HandlerMensaje::getInstancia();
    if (!mensajes.empty()){
        Mensaje* m;
        for (itm = mensajes.begin(); 0 != mensajes.size(); itm = mensajes.begin()){
            m = itm->second;
            mensajes.erase(itm);
            HM->removerMensaje(m);
            //m->~Mensaje();
            //delete(m);
            //m=NULL;
        }
    }

    if (!infosVisita.empty()){
        InfoVisita* i;
        Usuario* usr;
        HandlerUsuario* HU=HandlerUsuario::getInstancia();
        for (iti = infosVisita.begin(); 0 != infosVisita.size(); iti = infosVisita.begin()){
            i = *iti;
            usr=HU->find(i->getUsuarioAsociado());
            usr->removerinfovisita(i);
            infosVisita.erase(iti);//VA SIN PUNTERO
            i->~InfoVisita();//BORRO COSAS DEL INFOVISITA
           // delete(*iti);//BORRO EL INFOVISITA
        }
    }
    if (!docentes.empty()){
        for (itd = docentes.begin(); 0 != docentes.size(); itd = docentes.begin()){
            itd->second->removerClase(this);
            docentes.erase(itd);
        }
    }
};

DtClase2* Clase::getInfo2(){
    DtClase2* dtc = new DtClase2(nombre, id, fInicio, fFin, hInicio, hFin, url);
    return dtc;
};


//ENVIO DE MENSAJES
DtClase* Clase::getInfo(){
    DtClase* dtc = new DtClase(nombre, id, fInicio, hInicio, url);
    return dtc;
};

set<DtMensaje*> Clase::listarDtMensajes(){
    map<int, Mensaje*>::iterator itm;
    set<DtMensaje*> a_retornar;
    set<DtMensaje*>::iterator fin;
    for (itm = mensajes.begin(); itm != mensajes.end(); itm++){
        fin = a_retornar.end();
        a_retornar.insert(fin, itm->second->getMensaje());
    }
    return a_retornar;
};

Mensaje* Clase::crearMensaje(Usuario* usr, string contenido, DtFecha fecha, DtHora hora){
    HandlerMensaje* HM =HandlerMensaje::getInstancia();
    int cant = HM->getcantMensajes();
    int idMsj = cant+1;
    Mensaje* m = new Mensaje(idMsj, contenido, fecha, hora, usr);
    HM->add(m);
    return m;
};




void Clase::respuesta(int idmsjPadre, Mensaje* m){
    map<int, Mensaje*>::iterator it = mensajes.find(idmsjPadre);
    Mensaje* padre = it->second;
    padre->agregarMsj(m);
    this->mensajes.insert(std::pair<int, Mensaje*>(m->getid(), m));
};
void Clase::agregarMensaje(Mensaje* m){
    this->mensajes.insert(pair<int, Mensaje*>(m->getid(), m));
}

//TIEMPO DICTADO DE CLASE
float Clase::tiempoClase(){

    int segundosFin = this->hFin.getsegundo();
    int segundosIni = this->hInicio.getsegundo();
    int segundosRes;
    if (segundosIni > segundosFin) segundosRes = 60 - segundosIni + segundosFin;
    else segundosRes = segundosFin - segundosIni;

    int minutosFin = this->hFin.getminuto();
    int minutosIni = this->hInicio.getminuto();
    int minutosRes;
    if (minutosIni > minutosFin && segundosIni > segundosFin) minutosRes = 60 - minutosIni + minutosFin -1;
        else if (minutosIni > minutosFin && segundosIni < segundosFin) minutosRes = 60 - minutosIni + minutosFin;
            else if (segundosIni > segundosFin) minutosRes = minutosFin - minutosIni - 1;
                     else minutosRes = minutosFin - minutosIni;
                minutosRes = 60*(minutosRes);

    int horasFin = this->hFin.gethora();
    int horasIni = this->hInicio.gethora();
    int horasRes;
    if (horasIni > horasFin && minutosIni > minutosFin) horasRes = 24 - horasIni + horasFin -1;
        else if (horasIni > horasFin && minutosIni < minutosFin) horasRes = 24 - horasIni + horasFin;
            else if (minutosIni > minutosFin) horasRes = horasFin - horasIni - 1;
                     else horasRes = horasFin - horasIni;
            horasRes = 60*60*(horasRes);

    float tiempoRes = (segundosRes + minutosRes + horasRes);

    return tiempoRes;

}
