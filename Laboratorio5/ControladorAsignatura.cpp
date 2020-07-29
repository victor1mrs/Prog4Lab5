/*
    ControladorAsignatura.cpp
     SINGLETON
 */



#include "ControladorAsignatura.h"

ControladorAsignatura * ControladorAsignatura::instance = NULL;

ControladorAsignatura::ControladorAsignatura() {
}


ControladorAsignatura * ControladorAsignatura::getInstancia() {
    if (instance == NULL)
        instance = new ControladorAsignatura();
    return instance;
}


void ControladorAsignatura::altaAsig(string codigo, string nombre){
    this->codigo= codigo;
    this->nombre= nombre;
}

//para cargar datos
void ControladorAsignatura::altaAsig(string codigo, string nombre, bool t, bool p, bool m ){
	this->codigo=codigo;
	this->nombre=nombre;
	this->teorico=t;
	this->practico=p;
	this->monitoreo=m;
}

void ControladorAsignatura::indicarInstancias(bool teorico, bool practico, bool monitoreo){
    this->teorico= teorico;
    this->practico= practico;
    this->monitoreo= monitoreo;
}

DtAsignatura ControladorAsignatura::mostrarDatosAsig(){
    DtAsignatura a = DtAsignatura(codigo, nombre, teorico, practico, monitoreo);
    return a;
}

void ControladorAsignatura::cancelarAltaAsig(){
    this->codigo= "";  // 'this->' puede no ser necesario
    this->nombre= "";
    this->teorico= false;
    this->practico= false;
    this->monitoreo= false;
}

void ControladorAsignatura::confirmarAltaAsig(){
    Asignatura* a = new Asignatura(codigo, nombre, teorico, practico, monitoreo);
    HandlerAsignatura* ha = HandlerAsignatura::getInstancia();
    ha->add(a);
    this->codigo= "";
    this->nombre= "";
    this->teorico= false;
    this->practico= false;
    this->monitoreo= false;
}


//CASO DE USO ASIGNACION DE DOCENTES A UNA ASIGNATURA
set<DtAsignatura*> ControladorAsignatura::listarAsignaturas(){
	HandlerAsignatura* HA= HandlerAsignatura::getInstancia();
	set<DtAsignatura*> asignaturas = HA->getAsignaturas();
	return asignaturas;
}

void ControladorAsignatura::seleccionarAsignatura(string codigo){
	HandlerAsignatura* HA =HandlerAsignatura::getInstancia();
	this->asignatura= HA->seleccionarAsignatura(codigo);// recuerda la asignatura seleccionada, si no existe tira error
}

set<DtDocente*> ControladorAsignatura::verDocentesQNoDictan(string a){
	HandlerUsuario* HU = HandlerUsuario::getInstancia();//
	set<DtDocente*> docentesQND;
	HandlerAsignatura* HA = HandlerAsignatura::getInstancia();//
    Asignatura* asig = HA->seleccionarAsignatura(a);//
	docentesQND = HU->docentesQND(asig);
	this->dqnd= docentesQND;
	return docentesQND;
}

void ControladorAsignatura::seleccionarDocente(string nDocente, TipoClase tc){
	bool noDicta =  false;
    for (set<DtDocente*>::iterator it = dqnd.begin(); !noDicta && it != dqnd.end(); it++) {
        if ((*it)->getEmail()== nDocente)
        	noDicta=true;
    }

	if (noDicta){
        this->tc=tc;
        HandlerUsuario* HU = HandlerUsuario::getInstancia();
        Usuario* d= HU->find(nDocente);
        this->docente = dynamic_cast<Docente*>(d);
        this->docente->setTipo(tc);
	}
	else throw std::invalid_argument ("El docente ingresado ya esta vinculado con la asignatura.");
}

void ControladorAsignatura::cancelarAsignacion(){
	set<DtDocente*> a;
	this->dqnd= a;
	this->tc= otro;
	this->docente=NULL;
	this->asignatura=NULL;
}
void ControladorAsignatura::confirmarAsignacion(){
	Docente* d= this->docente;
	TipoClase tc= this->tc;
	Asignatura* a= this->asignatura;

	this->docente->confirmarAsignacion(d, tc, a);
}
void ControladorAsignatura::logOut(){
	this->asignatura=NULL;
	this->docente=NULL;
    set<DtDocente*> as;
	this->dqnd= as;
	this->tc=otro;
}


void ControladorAsignatura::seleccionarAsig(string cod){
    codigo = cod;
    HandlerAsignatura* HA =HandlerAsignatura::getInstancia();
    Asignatura* asig = HA->find(codigo);
    this->asignatura = asig;
}

void ControladorAsignatura::cancelarEliminacion(){
    codigo = "";
    asignatura = NULL;
}

void ControladorAsignatura::confirmarEliminacion(){
    HandlerAsignatura* HA =HandlerAsignatura::getInstancia();
	HA->removerAsig(codigo);
	codigo = "";
	asignatura = NULL;
}


//Tiempo de Dictado de Clase
set<DtTiempoAsignatura*> ControladorAsignatura::obtenerTiempo(){
	set<DtTiempoAsignatura*> res;
	set<DtTiempoAsignatura*>::iterator itd;

	HandlerAsignatura* HA =HandlerAsignatura::getInstancia();
	map<string, Asignatura*> lstasig = HA->listarAsignaturas();
	map<string, Asignatura*>::iterator it;
	for (it = lstasig.begin();it != lstasig.end(); it++){

		Asignatura* a = it->second;
		DtTiempoAsignatura* unaasignatura = a->getTiemposClases();
		itd=res.end();
		res.insert(itd,unaasignatura);

	}
	return res;
}

//Tiempo de Asistencia a Clase

set<DtAsignatura*> ControladorAsignatura::listarAsigDictadas(){

    HandlerUsuario* HU= HandlerUsuario::getInstancia();
	Usuario* usr = HU->find(usuarioLogueado->getEmail());
	Docente* d = dynamic_cast<Docente*>(usr);

    map<int, Asignacion*> lstasign =  d->getasignaciones();
	map<int, Asignacion*>:: iterator it;
	set<DtAsignatura*> dtasignaturas;
	set<DtAsignatura*>::iterator fin;
	for (it = lstasign.begin(); it!=lstasign.end(); it++){
        fin = dtasignaturas.end();
        dtasignaturas.insert(fin, it->second->getasignatura()->getInfo());
	}
	return dtasignaturas;

}

void ControladorAsignatura::logIn(string e){
HandlerUsuario* HU = HandlerUsuario::getInstancia();
    Usuario* u = HU->find(e);
    //chequeo que este en el sistema
	if (u == NULL) {
        throw std::invalid_argument ("El usuario no se encuentra registrado.");
    }
	this->usuarioLogueado=u;
}

//TIEMPO DE ASISTENCIA A CLASES
set<DtPromedioClase*> ControladorAsignatura::mostrarPromedios(){

    set<DtPromedioClase*> res;
	set<DtPromedioClase*>::iterator itd;

    //HandlerAsignatura* HA = HandlerAsignatura::getInstancia();
    //Asignatura* a = HA->find(this->asignatura->getCodigo());

    map<int, Clase*> clases = asignatura->getClases();
    map<int, Clase*>:: iterator it;
    Docente* d = dynamic_cast<Docente*>(usuarioLogueado);
    map<int, Clase*> clasesDocente = d->getclases();
    map<int, Clase*>:: iterator itdoc;
    float promedioClase=0;
    int cantInfoVisitas=0;
    float suma = 0;
    float tiempo = 0;
    int id = 0;
    set<InfoVisita*>::iterator iter;
    set<InfoVisita*> infos;



    for (it = clases.begin(); it!=clases.end(); it++){
        for (itdoc=clasesDocente.begin(); itdoc != clasesDocente.end(); itdoc++){
            if (it->second->getId() == itdoc->second->getId()){
                promedioClase = 0;
                cantInfoVisitas = 0; //calcular la cantidad de infovisitas por clase
                suma = 0;

                infos = it->second->listarInfosVisita();

                for (iter = infos.begin(); iter!=infos.end(); iter++){
                    cantInfoVisitas++;

                    tiempo = (*iter)->TiempoInfoVisita();
                    suma = suma + tiempo;
                }
                if (cantInfoVisitas!=0)
                    promedioClase = suma / cantInfoVisitas;
                itd=res.end();
                string nombre = it->second->getNombre();
                id = it->second->getId();
                DtPromedioClase* Dt = new DtPromedioClase(nombre, id, promedioClase);

                res.insert(itd,Dt);

            }
        }
    }
    return res;
}

