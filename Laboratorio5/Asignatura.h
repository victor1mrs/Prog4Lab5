#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

#include <map>
#include <string>
#include <set>

#include "DtEstudiante.h"
#include "DtAsignatura.h"
#include "HandlerUsuario.h"
#include "DtMensaje.h"
//#include "Asignacion.h"
#include "TipoClase.h"
//#include "Clase.h"
#include "Estudiante.h"
#include "DtTiempoAsignatura.h"

using namespace std;
//class Estudiante;
class Clase;
class Asignacion;

class Asignatura {

private:
	string codigo;
	string nombre;
	bool tiene_monitoreo;
	bool tiene_practico;
	bool tiene_teorico;

    map<int, Clase*> clases;
	map<string, Estudiante*> estudiantes;
	map<int, Asignacion*> asignaciones;

public:
	Asignatura();
	Asignatura(string codigo, string nombre, bool teorico, bool pratico, bool monitoreo );
	~Asignatura();
    string getCodigo();
    string getNombre();
    bool getMonitoreo();
    bool getPractico();
    bool getTeorico();
    map<int, Clase*> getClases();
    map<int, Asignacion*> getAsignaciones();


    void setCodigo(string);
    void setNombre(string);
    void setMonitoreo(bool);
    void setPractico(bool);
    void setTeorico(bool);

    DtAsignatura* getInfo();
    //set<DtDocente*> listarDocentes();
    set<DtEstudiante*> listarInscriptos();
    //DtClase getClase(string id);
    //set<DtClase> listarEnDif(DtFecha, DtHora);
    //set<DtClase> mostrarInfoClases();


    //set<DtClase> verMensajes(string idClase);

    bool dictaAsignatura(string nombreDocente);

    void crearClase (string nombreClase,DtFecha fComienzo,DtHora hComienzo,int id, TipoClase rol,set<string> inscriptos, string);

    //ENVIO DE MENSAJES
    set<DtClase*> listarClases();
    set<DtMensaje*> verMensajes(int idClase);

    //INSCRIPCION A ASIGNATURA
    bool cursa(string mail);
    void agregarEstudiante(Estudiante* e);

    //asginacion de docente a una asignatura
    void agregarAsignacion(Asignacion*);

    Clase* getClase(int);


    //Tiempo de dictado de clases
    DtTiempoAsignatura* getTiemposClases();

};
//#include "Asignacion.h"
//#include "Estudiante.h"
#include "Asignacion.h"

#endif /* ASIGNATURA_H_ */
