#ifndef CONTROLADORCLASE_H_
#define CONTROLADORCLASE_H_

#include <map>
#include <string>
#include <set>

//#include "HandlerAsignatura.h"
#include "HandlerUsuario.h"
//#include "HandlerMensaje.h"
#include "IControladorClase.h"
#include "Clase.h"
#include "Usuario.h"
#include "Docente.h"//nuevo
#include "Estudiante.h"//nuevo
#include "Asignatura.h"
#include "DtFecha.h"
#include "DtHora.h"
#include "HandlerAsignatura.h"
using namespace std;

//class HandlerAsignatura;

class ControladorClase: public IControladorClase {

private:

	static ControladorClase* instancia;
	ControladorClase();
	Clase* clase;
	Usuario* usuario;
	Asignatura* asignatura;
	Usuario* usuarioLogueado;

	//envio de msj
	int idmsjPadre;
	bool es_respuesta;
	string contenido;

	//otros
    string email;
    Asignatura* asigRecordada;//asignatura de seleccionarAsignatura(string codigo)
	string nombreClase;
	DtFecha fComienzo;
	DtHora hComienzo;
	DtHora hFin;
	set<string> inscriptos;//estudiante de agregarEstudiante(string email)

public:
    static ControladorClase* getInstancia();
	virtual ~ControladorClase();
	void logIn(string email);

	//inicio de clase
	set<DtAsignatura*> listarAsignaturasDictadas();
	void seleccionarAsignatura(string codigo);
	void ingresarDatosClase(string, DtFecha, DtHora);
	set<DtEstudiante*> listarInscriptos();
	void agregarEstudiante(string);
	DtClase* mostrarInfoClase();
	void confirmarInicio();
	void cancelarInicio();

	//finalizacion de clase
	set<DtNombreClase*> listarClasesEnVivo();
	//void seleccionarClase(int);
	void finalizarClase(DtHora);
	DtClase2* mostrarDatos();
    void cancelarFinalizacion();
    void confirmarFinalizacion();
    void finalizarClaseDDP(DtFecha fFin, DtHora hFin);



	//Envio de mensaje
    void confirmarEnvio();
    void cancelarEnvio();
    void enviarMensaje(string);
    void responder(int, string);
    set<DtMensaje*> verMensajes(int);
    set<DtClase*> listarClases();
    void fijarClase(int id);

    //ASISTENCIA A CLASE EN VIVO
    set<DtAsignatura*> listarAsigCursadas();
    void seleccionarClaseVivo(int id);
    string mostrarCodAsig();
    int mostrarIdClase();
    void confirmarAsistencia();
    void cancelarAsistencia();

    //finalizacion de asistencia a clase en vivo
    set<DtClase*> listarClasesAsistiendo();
    void seleccionarClaseAsistiendo(int);
    void confirmarFinAsistencia();
    void cancelarFinAsistencia();
};
//#include "HandlerAsignatura.h"

#endif /* CONTROLADORCLASE_H_ */

