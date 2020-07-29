/*
 * ControladorUsuario.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef CONTROLADORUSUARIO_H_
#define CONTROLADORUSUARIO_H_



#include "IControladorUsuario.h"
#include "HandlerUsuario.h"
#include "Docente.h"
#include "Estudiante.h"




using namespace std;

class ControladorUsuario:public IControladorUsuario {
private:
	static ControladorUsuario* instancia;
	ControladorUsuario();
	//Usuario* usuario;
	string nombreU;
	string emailU;
	string imagenU;
	string passU;
	string ciU="";
	string institutoU;
	Usuario* usuarioLogueado;
	string codigoAsig;
	Estudiante* estudianteLogueado;

public:
	static ControladorUsuario* getInstancia();
	virtual ~ControladorUsuario();



	//Caso de uso Alta Usuario
	void agregarDocente(string, string, string, string, string);
	void agregarEstudiante(string, string, string, string, string);
    void confirmarAltaUsuario();
    void cancelarAltaUsuario();


	//Log In
	void logIn(string email);
	void logOut();


	//Caso de uso Inscripcion a Asignatura
	set<DtAsignatura*> asignaturasDisponibles();
	void seleccionarAsignatura(string);
	void confirmarInscripcion();
	void cancelarInscripcion();

	set<DtNotificacion*> getNotificaciones();
    void eliminarNotificaciones();

    void suscribirse(string );
};

#endif /* CONTROLADORUSUARIO_H_ */




