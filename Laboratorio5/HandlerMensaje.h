#ifndef HANDLERMensaje_H_
#define HANDLERMensaje_H_

#include <map>
#include <string>
#include<stdlib.h>
#include "DtNotificacion.h"
#include "Mensaje.h"
//#include "Clase.h"
//#include "Asignatura.h"
#include "IObserver.h"

using namespace std;
//class IObserver;
//class Asignatura;
//class Clase;
//class Mensaje;//forwardDeclaration

class HandlerMensaje {//Singleton

private:
    int cantMensajes;
    map<string, IObserver*> observers;
	map<int, Mensaje*> mensajes;
	static HandlerMensaje* instancia;
	HandlerMensaje();
public:
	static HandlerMensaje* getInstancia();
	map<int, Mensaje*> listarMensajes();
	virtual ~HandlerMensaje();
	void add(Mensaje*);
	void removerMensaje(Mensaje*);
	//map<string,Mensaje*>::iterator find(string);
	map<int,Mensaje*>::iterator end();
	map<int,Mensaje*>::iterator begin();
	Mensaje* find(int id);
	map<string, IObserver*> getobservers();
	int getcantMensajes();
	//void aumentarCantMensajes();


	//ENVIO DE MENSAJE
	void agregarMensaje(Mensaje* m, string nomUsuario, string codAsig,string nomAsig, int idClase, string nomClase, bool es_respuesta);
	void agregarObserver(IObserver*);
	void removerObserver(IObserver*);
};

#endif /* HANDLERMensaje_H_ */
