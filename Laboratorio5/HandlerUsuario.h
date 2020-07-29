/*
 * HandlerUsuario.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef HANDLERUSUARIO_H_
#define HANDLERUSUARIO_H_

#include <map>
#include <string>
#include <iterator>
#include "Usuario.h"
#include "DtDocente.h"
//#include "Asignatura.h"
//#include "HandlerAsignatura.h"
using namespace std;
//class Usuario;
//class HandlerAsignatura;
class Asignatura;
class HandlerUsuario {//Singleton

private:
	map<string, Usuario*> usuarios;
	static HandlerUsuario* instancia;
	HandlerUsuario();
public:
	static HandlerUsuario* getInstancia();
	map<string, Usuario*> listarUsuarios();
	virtual ~HandlerUsuario();
	void add(Usuario* u);
	//map<string,Usuario*>::iterator find(string);
	map<string,Usuario*>::iterator end();
	map<string,Usuario*>::iterator begin();
	Usuario* find(string email);
	//Docente* find(string email);

	set<DtDocente*> docentesQND(Asignatura*);//le paso el nombre de la asignatura
};
#include "Asignatura.h"

#endif /* HANDLERUSUARIO_H_ */
