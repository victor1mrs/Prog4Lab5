/*
 * Usuario.h
 *
 *  Created on: 2 jun. 2020
 *      Author: Santi
 */


#ifndef USUARIO_H_
#define USUARIO_H_

#include <map>
#include <typeinfo>
#include <string>
#include <set>
#include "InfoVisita.h"
#include "DtNotificacion.h"
#include "DtUsuario.h"
#include "DtNombreClase.h"
#include "DtClase.h"
#include "DtClase2.h"
#include "DtMensaje.h"
#include "IObserver.h"
//#include "Suscripcion.h"
#include "Respuesta.h"
#include "TipoClase.h"
//#include "TipoSuscripcion.h"

using namespace std;
//class Respuesta;
class Mensaje;
//class Clase;
class Usuario: public IObserver {

private:
    Suscripcion* modoSuscripcion;//strategy
	string nombre;
	string email;
	string imagen;
	string pass;
	map<int, InfoVisita*> infovisitas;
	set<DtNotificacion*> notificaciones;
	tipoDataUsuario tipo;
public:
	Usuario(string, string, string, string, tipoDataUsuario);

	Usuario();
	virtual ~Usuario();
	string getnombre();
	string getEmail();
	string getimagen();
	string getpass();
	map<int, InfoVisita*> getinfovisitas();
	set<DtNotificacion*> getnotificaciones();
	void setnombre(string);
	void setemail(string);
	void setimagen(string);
	void setpass(string);
	void setTipo(tipoDataUsuario tipo);
	const tipoDataUsuario getTipo() const;
	void agregarinfovisita(InfoVisita*);
	void removerinfovisita(InfoVisita*);

	//CASO DE USO ENVIO DE MENSAJE
	//virtual map<Clase*> getMapClases();//para guardarme la clase seleccionada en ver mensajes
	virtual set<DtClase*> listarClases()=0;//CAMBIAR
	virtual set<DtMensaje*> verMensajes(int)=0;
	void notificar(DtNotificacion*);
	bool aplicaNotif(Mensaje* m, bool es_respuesta);
	//virtual TipoClase getRol(Asignatura*)=0;
    //virtual void agregarmonitoreo(Monitoreo*) = 0;


    //ASISTENCIA A CLASE EN VIVO
    virtual set<DtNombreClase*> listarClasesEnVivo(string)=0;
    virtual Clase* seleccionarClaseVivo(int, string) = 0;
    set<DtNotificacion*> getNotificaciones();
    void eliminarNotificaciones();


    //SUSCRIPCION
   Suscripcion* crearSuscripcion (string);
    //STRATEGY
    void setModoSuscripcion(Suscripcion*);

};





#endif /* USUARIO_H_ */



