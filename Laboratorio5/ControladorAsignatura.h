/*
    ControladorAsignatura.h
    Controlador SINGLETON
 */

#ifndef CONTROLADORASIGNATURA_H_
#define CONTROLADORASIGNATURA_H_

#include <map>
#include <string>
#include <set>
#include "Asignatura.h"
#include "Docente.h"
#include "IControladorAsignatura.h"
#include "HandlerAsignatura.h"
#include "HandlerUsuario.h"


using namespace std;

class ControladorAsignatura: public IControladorAsignatura {

private:

	static ControladorAsignatura * instance;
	ControladorAsignatura();

	Asignatura* asignatura;
	Docente* docente;
	Usuario* usuarioLogueado;

	string codigo;
	string nombre;
	bool teorico;
	bool practico;
	bool monitoreo;

	set<DtDocente*> dqnd;
	TipoClase tc;

public:

	static ControladorAsignatura * getInstancia();

	void altaAsig(string codigo, string nombre, bool t, bool p, bool m );
	void altaAsig(string codigo, string nombre);
	void indicarInstancias(bool teorico, bool practico, bool monitoreo);
	DtAsignatura mostrarDatosAsig();
	void cancelarAltaAsig();
	void confirmarAltaAsig();
	~ControladorAsignatura(){};



	// CASO DE USO ASIGNACION DE DOCENTES A UNA ASIGNATURA
	set<DtAsignatura*> listarAsignaturas();
	void seleccionarAsignatura(string);//recuerda la asignatura seleccionada
	set<DtDocente*> verDocentesQNoDictan(string);
	void seleccionarDocente(string, TipoClase);

	void cancelarAsignacion();
	void confirmarAsignacion();
	void logOut();



	//ELIMINACION DE ASIGNATURA
	void cancelarEliminacion();
    void confirmarEliminacion();
    void seleccionarAsig(string);

    //Tiempo de dictado de calses
    set<DtTiempoAsignatura*> obtenerTiempo();

    //Tiempo de Asistencia a clase

    set<DtPromedioClase*> mostrarPromedios();
    set<DtAsignatura*>listarAsigDictadas();
    void logIn(string);


};

#endif /* CONTROLADORASIGNATURA_H_ */
