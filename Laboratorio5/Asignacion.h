/*
 * Asignacion.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef ASIGNACION_H_
#define ASIGNACION_H_

#include <string>

//#include "Asignatura.h"
#include "Docente.h"
#include "Monitoreo.h"
#include "Practico.h"
#include "Teorico.h"

using namespace std;

class Asignatura;
//class Docente;

class Asignacion {
private:

	int id;
	//string id;//puede ser el mismo codigo de asignatura? Yo diria que si

	Asignatura* asignatura;
	TipoClase tClase;
	Docente* docente;
public:
	Asignacion(int, TipoClase);
	int getid();
	Asignatura* getasignatura();
	TipoClase gettClase();
	Docente* getusuario();
	//DtDocente* getDocente();
	string getEmailDocente();
	//void setusuario(Usuario*);

	Docente* getdocente();
	//DtDocente* getdocente();
	void setdocente(Docente*);
	void setasignatura(Asignatura*);
	~Asignacion();
};
//#include "Asignatura.h"
//#include "Docente.h"

#endif /* ASIGNACION_H_ */
