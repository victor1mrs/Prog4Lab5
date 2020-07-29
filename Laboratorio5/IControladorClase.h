/*
 * IControladorClase.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef ICONTROLADORCLASE_H_
#define ICONTROLADORCLASE_H_
#include "DtAsignatura.h"
#include "DtEstudiante.h"
#include "DtClase.h"
#include "DtMensaje.h"
#include "DtFecha.h"
#include "DtHora.h"
#include "Reloj.h"
#include "DtNombreClase.h"
#include "DtClase2.h"
#include <set>
#include <string>
using namespace std;

class IControladorClase {
public:
	virtual ~IControladorClase(){};
	virtual void logIn(string)=0;
	//INICIO DE CLASE
	virtual set<DtAsignatura*> listarAsignaturasDictadas()=0;
	virtual void seleccionarAsignatura(string)=0;
	virtual void ingresarDatosClase(string, DtFecha, DtHora)=0;
	virtual set<DtEstudiante*> listarInscriptos()=0;
	virtual void agregarEstudiante(string)=0;
	virtual DtClase* mostrarInfoClase()=0;
	virtual void confirmarInicio()=0;
    virtual	void cancelarInicio()=0;
    virtual void finalizarClase(DtHora)=0;
    virtual void finalizarClaseDDP(DtFecha fFin, DtHora hFin)=0;

    //Envio de mensaje
    virtual void confirmarEnvio()=0;
    virtual void cancelarEnvio()=0;
    virtual void enviarMensaje(string)=0;
    virtual void responder(int, string)=0;
    virtual set<DtMensaje*> verMensajes(int)=0;
    virtual set<DtClase*> listarClases()=0;
    virtual void fijarClase(int)=0;
    //Finalizacion de clase
    virtual set<DtNombreClase*> listarClasesEnVivo()=0;
	virtual void seleccionarClaseVivo(int)=0;
	virtual DtClase2* mostrarDatos()=0;
    virtual void cancelarFinalizacion()=0;
    virtual void confirmarFinalizacion()=0;
    //ASISTENCIA A CLASE EN VIVO
    virtual set<DtAsignatura*> listarAsigCursadas()=0;
    virtual void confirmarAsistencia()=0;
    virtual void cancelarAsistencia()=0;
    //FINALIZACION DE ASISTENCIA A CLASE EN VIVO
    virtual set<DtClase*> listarClasesAsistiendo()=0;
    virtual void seleccionarClaseAsistiendo(int)=0;
    virtual void confirmarFinAsistencia()=0;
    virtual void cancelarFinAsistencia()=0;
};



#endif /* ICONTROLADORCLASE_H_ */
