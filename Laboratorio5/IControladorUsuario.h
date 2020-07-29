/*
 * ICtrlUsuario.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef ICONTROLADORUSUARIO_H_
#define ICONTROLADORUSUARIO_H_

#include <string>
#include <set>
#include "DtAsignatura.h"
#include "DtNotificacion.h"

using namespace std;

class IControladorUsuario {// interface

public:
	//virtual void nombreOperacion()=0;
	//IControladorUsuario();
	virtual ~IControladorUsuario(){};
	virtual void agregarDocente(string, string, string, string, string)=0;
	virtual void agregarEstudiante(string, string, string, string, string)=0;
	virtual void confirmarAltaUsuario()=0;
	virtual void cancelarAltaUsuario()=0;
	virtual void logIn(string)=0;
	virtual void logOut()=0;


	virtual set<DtAsignatura*> asignaturasDisponibles()=0;
    virtual void seleccionarAsignatura(string)=0;
    virtual void confirmarInscripcion()=0;
    virtual void cancelarInscripcion()=0;

    virtual set<DtNotificacion*> getNotificaciones()=0;
    virtual void eliminarNotificaciones()=0;
    virtual void suscribirse(string )=0;
};

#endif /* ICONTROLADORUSUARIO_H_ */
