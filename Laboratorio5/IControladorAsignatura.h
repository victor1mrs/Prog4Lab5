/*
 * IControladorAsignatura.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef ICONTROLADORASIGNATURA_H_
#define ICONTROLADORASIGNATURA_H_
#include"DtAsignatura.h"
#include"DtDocente.h"
#include"TipoClase.h"
#include"DtTiempoAsignatura.h"
#include"DtPromedioClase.h"


class IControladorAsignatura {
public:
	//IControladorAsignatura(){};
	virtual ~IControladorAsignatura(){};
	virtual void altaAsig(string, string)=0;
	virtual void altaAsig(string, string, bool, bool, bool )=0;

	virtual set<DtAsignatura*> listarAsignaturas()=0;
	virtual void seleccionarAsignatura(string)=0;
	virtual set<DtDocente*> verDocentesQNoDictan(string)=0;

	virtual void indicarInstancias(bool, bool, bool)=0;
    virtual void confirmarAltaAsig()=0;
    virtual void cancelarAltaAsig()=0;


    virtual void seleccionarDocente(string, TipoClase)=0;
	virtual DtAsignatura mostrarDatosAsig()=0;
	virtual void confirmarAsignacion()=0;
	virtual void cancelarAsignacion()=0;
    virtual void logOut()=0;

	virtual void confirmarEliminacion() = 0;
	virtual void cancelarEliminacion() = 0;
	virtual void seleccionarAsig(string)=0;


	virtual set<DtTiempoAsignatura*> obtenerTiempo() = 0;

	virtual set<DtPromedioClase*> mostrarPromedios() = 0;
	virtual void logIn(string)=0;
	virtual set<DtAsignatura*> listarAsigDictadas()=0;

};

#endif /* ICONTROLADORASIGNATURA_H_ */
