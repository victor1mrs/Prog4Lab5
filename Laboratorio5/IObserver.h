/*
 * IObserver.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef IObserver_H_
#define IObserver_H_
#include "DtNotificacion.h"
class HandlerAsignatura;
class Usuario;
class Mensaje;
class IObserver {
public:
	//IObserver(){};
	virtual ~IObserver(){};
	virtual void notificar(DtNotificacion*)=0;
	virtual bool aplicaNotif(Mensaje* m, bool es_respuesta)=0;
	virtual string getEmail()=0;

};

#endif /* IObserver_H_ */
