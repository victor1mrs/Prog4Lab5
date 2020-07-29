#ifndef CLASE_H_
#define CLASE_H_

#include <string>
#include <set>
#include <map>

//#include "InfoVisita.h"
#include "DtFecha.h"
#include "DtClase.h"
#include "DtHora.h"
#include "DtMensaje.h"
#include "DtClase2.h"
#include "InfoVisita.h"
#include "DtNombreClase.h"
#include "HandlerMensaje.h"
#include "Mensaje.h"
//#include "Docente.h"

using namespace std;
//class InfoVisita;
class Docente;
class HandlerMensaje;
class Clase {

private:
	string nombre;
	int id;
	DtFecha fInicio;
	DtFecha fFin;
	DtHora hInicio;
	DtHora hFin;
	string url;
	map<int, Mensaje*> mensajes;
	map<string, Docente*> docentes;
	set<InfoVisita*> infosVisita;

	string codigoAsignatura;
	string nombreAsignatura;

public:
	Clase(string n, int i, DtFecha fI, DtFecha fF, DtHora hI, DtHora hF, string u, string cod, string nomA);
	void setNombre(string n);
	void setId(int id);
	void setfInicio(DtFecha fI);
	void setfFin(DtFecha fF);
	void sethInicio(DtHora hI);
	void sethFin(DtHora hF);
	void setUrl(string url);

	void agregarDocente(Docente*);
	void agregarInfoVisita(InfoVisita*);

	string getNombre();
	string getNombreAsignatura();
	int getId();
	DtFecha getfInicio();
	DtFecha getfFin();
	DtHora gethInicio();
	DtHora gethFin();
	string getUrl();
	string getCodigoAsignatura();

	map<int, Mensaje*> listarMensajes();
	map<string, Docente*> listarDocentes();
	set<InfoVisita*> listarInfosVisita();

	DtNombreClase* getNombreClase();


	//DtClase getInfo();
	DtClase getDtClase(string, string);//es lo mismo no? *** que el getInfo()?? PARECE que si
    void finalizarInfos();


	//DtClase getDtClase(string, string);//arreglar para que retorne absolutamente todo lo relacionado a la clase

	void setClase(DtFecha, DtHora, string);
    //virtual void agregarEstudiante(Estudiante*)=0;
    //virtual int getCantAsistentes()=0;
    //virtual void setCantAsistentes(int)=0;
    //virtual map<string, Estudiante*> getEstudiantes()=0;
    //ENVIO DE MENSAJES
    DtClase* getInfo();//(completo)
    DtClase2* getInfo2(); //para finalizacion de clase (datos basicos)
    set<DtMensaje*> listarDtMensajes();
    Mensaje* crearMensaje(Usuario*, string, DtFecha, DtHora);
    void respuesta(int, Mensaje*);
    void agregarMensaje(Mensaje*);


    //ELIMINACION DE ASIGNATURA
	virtual ~Clase();

	//Tiempo de dictado de clases
	float tiempoClase();
};
#include "Docente.h"
#include "HandlerMensaje.h"
#endif /* CLASE_H_ */
