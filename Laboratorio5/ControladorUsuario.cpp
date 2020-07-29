/*
 * ControladorUsuario.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario() {
	this->ciU="";
	this->emailU="";
	this->imagenU="";
	this->institutoU="";
	this->nombreU="";
	this->passU="";
	//this->usuario=NULL;
}

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
}


void ControladorUsuario::agregarDocente(string nombre, string email, string pass , string img, string instituto){
	this->emailU=email;
	this->nombreU=nombre;
	this->passU=pass;
	this->imagenU=img;
	this->institutoU=instituto;



	/*Docente* nuevoUsuario = new Docente(nombre, email, pass, img, instituto);
	HandlerUsuario* HU= HandlerUsuario::getInstancia();
	HU->add(nuevoUsuario);*/
}

void ControladorUsuario::agregarEstudiante(string nombre, string email, string pass , string img, string ci){
	this->emailU=email;
	this->nombreU=nombre;
	this->passU=pass;
	this->imagenU=img;
	this->ciU=ci;

	/*Estudiante* nuevoUsuario = new Estudiante(nombre, email, pass, img, ci);
	HandlerUsuario* HU= HandlerUsuario::getInstancia();
	HU->add(nuevoUsuario);*/
}



void ControladorUsuario::confirmarAltaUsuario(){
	if (this->institutoU == ""){
		Estudiante* nuevoUsuario = new Estudiante(this->nombreU, this->emailU, this->passU, this->imagenU, this->ciU, TIPOESTUDIANTE);
		HandlerUsuario* HU= HandlerUsuario::getInstancia();
		HU->add(nuevoUsuario);
		}
	else{
		Docente* nuevoUsuario = new Docente(this->nombreU, this->emailU, this->passU, this->imagenU,this->institutoU, TIPODOCENTE);
		HandlerUsuario* HU= HandlerUsuario::getInstancia();
		HU->add(nuevoUsuario);
	}

	this->ciU="";
	this->emailU="";
	this->imagenU="";
	this->institutoU="";
};

void ControladorUsuario::cancelarAltaUsuario(){
	this->ciU="";
	this->emailU="";
	this->imagenU="";
	this->institutoU="";
}

void ControladorUsuario::logIn(string e){
	HandlerUsuario* HU = HandlerUsuario::getInstancia();
    Usuario* u = HU->find(e);
    //chequeo que este en el sistema
	if (u == NULL) {
        throw std::invalid_argument ("El usuario no se encuentra registrado.");
    }
	this->usuarioLogueado=u;
	/*if (u->getTipo()==TIPOESTUDIANTE)
		this->estudianteLogueado=u;*/
	this->emailU=u->getEmail();
}

void ControladorUsuario::logOut(){
	this->ciU="";
	this->usuarioLogueado=NULL;
	this->estudianteLogueado=NULL;
}


set<DtAsignatura*> ControladorUsuario::asignaturasDisponibles(){

    HandlerAsignatura* HA= HandlerAsignatura::getInstancia();
    set<DtAsignatura*> dts =  HA->asignaturasQNC(this->emailU);
	return dts;
}


void ControladorUsuario::seleccionarAsignatura(string codAsig){
	this->codigoAsig= codAsig;
}

void ControladorUsuario::confirmarInscripcion(){

	Estudiante* e= dynamic_cast<Estudiante*>(usuarioLogueado);
	HandlerAsignatura* HA= HandlerAsignatura::getInstancia();
	Asignatura* asig= HA->seleccionarAsignatura(this->codigoAsig);
	e->agregarasignatura(asig);
	asig->agregarEstudiante(e);
}


void ControladorUsuario::cancelarInscripcion(){
	this->codigoAsig="";
}


set<DtNotificacion*> ControladorUsuario::getNotificaciones(){
	set<DtNotificacion*> res;
	res= this->usuarioLogueado->getNotificaciones();
	return res;
}


void ControladorUsuario::eliminarNotificaciones(){
	this->usuarioLogueado->eliminarNotificaciones();
}


//SUSCRIPCION A NOTIFICACIONES
void ControladorUsuario::suscribirse(string modo ){
	Suscripcion* s= this->usuarioLogueado->crearSuscripcion(modo);

	this->usuarioLogueado->setModoSuscripcion(s);
	HandlerMensaje* HM= HandlerMensaje::getInstancia();
	HM->agregarObserver(this->usuarioLogueado);
}




ControladorUsuario::~ControladorUsuario(){
};

