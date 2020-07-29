#ifndef DOCENTE_H_
#define DOCENTE_H_

#include <map>
#include <string>
#include "Usuario.h"
#include "TipoClase.h"
#include "Asignatura.h"
#include "HandlerAsignatura.h"
using namespace std;
class Asignacion;
//class Asignatura;
class Clase;
class Docente: public Usuario {

private:
	string instituto;
	TipoClase tipoRecordado;
	map<int, Asignacion*> asignaciones;//puede ser el mismo codigo que la asignatura a la que corresponde?
	map<int, Clase*> clases;
public:
	Docente();
	Docente( string n, string e, string i, string p,string ins, tipoDataUsuario);
	Docente(string n, string e, string i, string p, string ins);
	string getinstituto();
	void setinstituto(string);
	map<int,Asignacion*> getasignaciones();
	void agregarasignacion(Asignacion*);
	DtDocente* getInfo();
	void setTipo(TipoClase);
	void confirmarAsignacion(Docente* , TipoClase, Asignatura*);//ARREGLAR

	set<DtNombreClase*> listarClasesEnVivo(string);
	Clase* seleccionarClaseVivo(int,string);
    map<int, Clase*> getclases();
	void setclase(Clase*);

	//CASO DE USO ENVIO DE MENSAJE
	set<DtClase*> listarClases();//IMPLEMENTAR BIEN
	set<DtMensaje*> verMensajes(int);
	TipoClase getRol(Asignatura* asig);//ARREGLAR

	~Docente();

	void removerAsignacion(Asignacion*);
	void removerClase(Clase*);
};
//#include "Asignacion.h"
#endif /* DOCENTE_H_ */




