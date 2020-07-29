#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_
using namespace std;
#include <map>
#include <string>

#include "DtClase.h"

#include "Usuario.h"
#include "DtEstudiante.h"


class Monitoreo;
class Asignatura;
class Estudiante: public Usuario {

private:
	string ci;
	map<int, Monitoreo*> monitoreos;
	map<string, Asignatura*> asignaturas;

public:

	//Estudiante(string c, string n, string e, string i, string p, tipoDataUsuario);

	Estudiante(string n, string e, string i, string p, string c, tipoDataUsuario);

	string getci();
	map<int, Monitoreo*> getmonitoreos();
	map<string, Asignatura*> getasignaturas();
	void setci(string);
	void agregarmonitoreo(Monitoreo*);
	void agregarasignatura(Asignatura*);
	DtEstudiante* getInfo();

	//CASO DE USO ENVIO DE MENSAJE
	set<DtClase*> listarClases();//IMPLEMENTAR BIEN
    set<DtMensaje*> verMensajes(int);
    set<DtNombreClase*> listarClasesEnVivo(string);


    //ASISTENCIA DE CLASE EN VIVO
    Clase* seleccionarClaseVivo(int, string);

    //ELIMINACION DE ASIGNATURA
    ~Estudiante();
    void removerMonitoreo(Monitoreo*);
	void removerAsignatura(Asignatura*);
};
#include "Monitoreo.h"
#include "Asignatura.h"
#endif /* ESTUDIANTE_H_ */
