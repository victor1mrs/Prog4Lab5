#include "ControladorClase.h"

ControladorClase* ControladorClase::instancia = NULL;

ControladorClase::ControladorClase() {
	//this->Clase=NULL;
};

ControladorClase* ControladorClase::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorClase();
    return instancia;
};

void ControladorClase::logIn(string e){
	HandlerUsuario* HU = HandlerUsuario::getInstancia();
	Usuario* u = HU->find(e);
	//CHEQUEO SI EXISTE EN EL SISTEMA
	if (u == NULL) {
        throw std::invalid_argument ("El usuario no se encuentra registrado.");
    }
	this->usuarioLogueado=u;
}

set<DtAsignatura*> ControladorClase::listarAsignaturasDictadas(){
	HandlerUsuario* HU= HandlerUsuario::getInstancia();
	Usuario* usr = HU->find(usuarioLogueado->getEmail());
	Docente* d = dynamic_cast<Docente*>(usr);
	map<int, Asignacion*> lstasign =  d->getasignaciones();
	set<DtAsignatura*> dtasignaturas;
	if (!lstasign.empty()){
        map<int, Asignacion*>:: iterator it;
        set<DtAsignatura*>::iterator fin;
        for (it = lstasign.begin(); it!=lstasign.end(); it++){
            fin = dtasignaturas.end();
            if (it->second->getasignatura()!=NULL)
                dtasignaturas.insert(fin, it->second->getasignatura()->getInfo());
        }
	}
	return dtasignaturas;
}

void ControladorClase::seleccionarAsignatura(string codigo){
    HandlerAsignatura* HA =HandlerAsignatura::getInstancia();
    Asignatura* a = HA->find(codigo);
    this->asigRecordada = a;
};

void ControladorClase::ingresarDatosClase(string nombreClase, DtFecha fComienzo, DtHora hComienzo){
    this->nombreClase = nombreClase;
	this->fComienzo = fComienzo;
	this->hComienzo = hComienzo;
};

set<DtEstudiante*> ControladorClase::listarInscriptos(){
	set<DtEstudiante*> dts = asigRecordada->listarInscriptos();
	return dts;
};


void ControladorClase::agregarEstudiante(string email){
    inscriptos.insert(email);
};

DtClase* ControladorClase::mostrarInfoClase(){
    DtFecha a;
    DtHora b;
    string url = "www.FingClass.edu.uy/"+ this->nombreClase;
    set<DtDocente> d;
    HandlerAsignatura* HA = HandlerAsignatura::getInstancia();
    int id = HA->getCantClases();
    DtClase* dt = new DtClase(this->nombreClase, asigRecordada->getNombre(), asigRecordada->getCodigo(),id+1, fComienzo,a,hComienzo,b,url,d);
    return dt;
}

void ControladorClase::finalizarClase(DtHora horaFin){
	this->hFin=horaFin;
}

void ControladorClase::confirmarInicio(){
    DtFecha a;
    DtHora b;
    set<string> c;
    Docente* doc = dynamic_cast<Docente*> (usuarioLogueado);
    TipoClase rol = doc->getRol(asigRecordada);
    HandlerAsignatura* HA = HandlerAsignatura::getInstancia();
    int id = HA->getCantClases();
    id++;
    HA->setCantClases(id);
    string mail = doc->getEmail();
    asigRecordada->crearClase(nombreClase,fComienzo,hComienzo, id, rol, inscriptos, mail);
    Clase* claseRecordada = asigRecordada->getClase(id);
    this->clase=claseRecordada;

    this->nombreClase = "";
    this->fComienzo = a;
    this->hComienzo = b;
    this->inscriptos = c;
    this->asigRecordada = NULL;
    this->usuarioLogueado = NULL;
}
void ControladorClase::cancelarInicio(){
    DtFecha a;
    DtHora b;
    set<string> c;

    this->nombreClase = "";
    this->fComienzo = a;
    this->hComienzo = b;
    this->inscriptos = c;
    this->asigRecordada = NULL;
    this->usuarioLogueado = NULL;
}

//CASO DE USO FINALIZACION DE CLASE
set<DtNombreClase*> ControladorClase::listarClasesEnVivo(){//TAMBIEN LA USA ASISTENCIA A CLASE EN VIVO
    string a = "";
    if(asigRecordada!= NULL)
        a = asigRecordada->getCodigo();
    return usuarioLogueado->listarClasesEnVivo(a);
}



DtClase2* ControladorClase::mostrarDatos(){
    return clase->getInfo2();
}

void ControladorClase::cancelarFinalizacion(){
    this->usuarioLogueado = NULL;
    this->clase = NULL;
}

void ControladorClase::finalizarClaseDDP(DtFecha fFin, DtHora hFin){
	this->clase->setfFin(fFin);
	this->clase->sethFin(hFin);
}

void ControladorClase::confirmarFinalizacion(){
    Reloj* relojito = Reloj::getInstancia();
    DtFecha Ffinal = relojito->getfecha();
    DtHora Hfinal = relojito->gethora();
    string url2 = clase->getUrl() + "Diferida";
    clase->setClase(Ffinal, Hfinal, url2);

    //FINALIZACION DE ASISTENCIA A CLASE EN VIVO PARA TODOS LOS ESTUDIANTES QUE ESTEN VIENDO EN EL MOMENTO
    Clase* c= clase;
    c->finalizarInfos();


    this->usuarioLogueado = NULL;
    this->clase = NULL;
}


//CASO DE USO ENVIO DE MENSAJE
set<DtClase*> ControladorClase::listarClases(){
    return usuarioLogueado->listarClases();
};
set<DtMensaje*> ControladorClase::verMensajes(int idClase){
    if(usuarioLogueado->getTipo()==TIPODOCENTE){//(typeid(usuarioLogueado).name() == typeid(Docente*).name()){
        Docente* d = dynamic_cast<Docente*> (usuarioLogueado);
        map<int, Clase*>::iterator it = d->getclases().find(idClase);
        clase = it->second;
    }else if (usuarioLogueado->getTipo()==TIPOESTUDIANTE){ //if (typeid(usuarioLogueado).name() == typeid(Estudiante*).name()){
        Estudiante* e = dynamic_cast<Estudiante*> (usuarioLogueado);
        map<int, InfoVisita*>::iterator it = e->getinfovisitas().find(idClase);//ACA
        clase = it->second->getClaseAsociada();
    }
    return usuarioLogueado->verMensajes(idClase);
};
//PARA CARGAR DATOS DE PRUEBA
void ControladorClase::fijarClase(int idClase){
    if(usuarioLogueado->getTipo()==TIPODOCENTE){
        Docente* d = dynamic_cast<Docente*> (usuarioLogueado);
        map<int, Clase*>::iterator it = d->getclases().find(idClase);
        clase = it->second;
    } else if (usuarioLogueado->getTipo()==TIPOESTUDIANTE){
        Estudiante* e = dynamic_cast<Estudiante*> (usuarioLogueado);
        map<int, InfoVisita*>::iterator it = e->getinfovisitas().find(idClase);
        clase = it->second->getClaseAsociada();
    }
}

//ENVIO DE MENSAJE
void ControladorClase::responder(int id, string txt){
    idmsjPadre = id;
    contenido = txt;
    es_respuesta=true;
};
void ControladorClase::enviarMensaje(string txt){
    contenido = txt;
    es_respuesta=false;
};
void ControladorClase::cancelarEnvio(){
    idmsjPadre = -1;
    contenido = "";
    es_respuesta = false;
    usuarioLogueado = NULL;
    clase = NULL;
    asignatura = NULL;
};
void ControladorClase::confirmarEnvio(){
    Reloj* r = Reloj::getInstancia();
    DtReloj dtr = r->consultarfecha();//para ingresar la hora de envío
    Mensaje* msj_nuevo = clase->crearMensaje(usuarioLogueado, contenido, dtr.getfecha(), dtr.gethora());
    if (es_respuesta){
        clase->respuesta(idmsjPadre, msj_nuevo);//mando id del msj padre
        msj_nuevo->setmsjPadre(idmsjPadre);
    }
    else {
        clase->agregarMensaje(msj_nuevo);
    }

    HandlerMensaje* HM =HandlerMensaje::getInstancia();
    HM->agregarMensaje(msj_nuevo, usuarioLogueado->getnombre(), clase->getCodigoAsignatura(), clase->getNombreAsignatura(), clase->getId(), clase->getNombre(), es_respuesta);

    idmsjPadre = -1;
    contenido = "";
    es_respuesta = false;
    usuarioLogueado = NULL;
    clase = NULL;
    asignatura = NULL;
};

//ASISTENCIA A CLASE EN VIVO
set<DtAsignatura*> ControladorClase::listarAsigCursadas(){//SOLO ESTUDIANTES INVOCAN ESTA OPERACION
    set<DtAsignatura*> seRetorna;
    Estudiante* e = dynamic_cast<Estudiante*> (usuarioLogueado);
    map<string, Asignatura*> mapasig = e->getasignaturas();
    map<string, Asignatura*>:: iterator it;
    set<DtAsignatura*>::iterator fin;
    if (!mapasig.empty()){
        for (it = mapasig.begin(); it!=mapasig.end(); it++){
            fin = seRetorna.end();
            if (it->second!=NULL)
                seRetorna.insert(fin, it->second->getInfo());
        }
    }
    return seRetorna;
}

void ControladorClase::seleccionarClaseVivo(int id){
    string a = "";
    if(asigRecordada!= NULL)
        a = asigRecordada->getCodigo();
    clase = usuarioLogueado->seleccionarClaseVivo(id, a);
}

string ControladorClase::mostrarCodAsig(){
    return clase->getCodigoAsignatura();
};

int ControladorClase::mostrarIdClase(){
    return clase->getId();
};

void ControladorClase::confirmarAsistencia(){
    /* Se crea un DtInfo en el InfoVisita correspondiente al Estudiante
    y la clase seleccionada, con la hora y fecha del sistema*/
    DtFecha Ffinal= DtFecha(-1,-1,-1);
    DtHora Hfinal = DtHora(-1,-1,-1);
    Reloj* relojito = Reloj::getInstancia();
    DtFecha Finicio = relojito->getfecha();
    DtHora Hinicio = relojito->gethora();

    DtInfo* info = new DtInfo(Finicio, Ffinal, Hinicio, Hfinal);
    map<int, InfoVisita*> mapinfo = usuarioLogueado->getinfovisitas();
    map<int, InfoVisita*>:: iterator it;
    bool InfoEncontrado = false;
    for (it = mapinfo.begin(); it!=mapinfo.end() && !InfoEncontrado; it++){
        if(it->second->getId() == clase->getId()){
            it->second->agregarDtInfo(info);
            InfoEncontrado=true;
        }
    }
    if(it==mapinfo.end() && !InfoEncontrado){
        InfoVisita* infovisit = new InfoVisita(clase->getId(), clase);
        infovisit->agregarDtInfo(info);
        infovisit->setUsuarioAsociado(usuarioLogueado->getEmail());
        usuarioLogueado->agregarinfovisita(infovisit);
        clase->agregarInfoVisita(infovisit);
    }
    //Se libera la memoria del sistema
    this->clase = NULL;
    this->usuarioLogueado = NULL;
    this->asigRecordada = NULL;
}

void ControladorClase::cancelarAsistencia(){
    this->clase = NULL;
    this->usuarioLogueado = NULL;
    this->asigRecordada = NULL;
}

//FINALIZACION DE ASISTENCIA A CLASE EN VIVO
set<DtClase*> ControladorClase::listarClasesAsistiendo(){
    Estudiante* e = dynamic_cast<Estudiante*>(usuarioLogueado);
    map<int, InfoVisita*> lstInfos = e->getinfovisitas();
    map<int, InfoVisita*>::iterator it;
    set<DtClase*> a_retornar;
    set<DtClase*>::iterator fin;
    Clase* c;
    set<DtInfo*> lstdt;
    set<DtInfo*>::iterator iti;
    for(it=lstInfos.begin(); it!=lstInfos.end();it++){
        c = it->second->getClaseAsociada();
        lstdt = it->second->getInfo();
        for(iti=lstdt.begin();iti!=lstdt.end();iti++){
            if ((c->gethFin().gethora()==-1) && ((*iti)->gethFin().gethora()==-1)){
                fin = a_retornar.end();
                a_retornar.insert(fin, c->getInfo());
            }
        }
    }
    return a_retornar;
};

void ControladorClase::seleccionarClaseAsistiendo(int id){
	map<int, InfoVisita*>::iterator it = usuarioLogueado->getinfovisitas().find(id);
    this->clase = it->second->getClaseAsociada();
}


void ControladorClase::confirmarFinAsistencia(){
    map<int, InfoVisita*>::iterator it = usuarioLogueado->getinfovisitas().find(clase->getId());
    set<DtInfo*> dtinfos = it->second->getInfo();
    set<DtInfo*>::iterator iti;
    bool encuentro = false;
    Reloj* r = Reloj::getInstancia();
    DtFecha dtf = r->getfecha();
    DtHora dth = r->gethora();
    for(iti=dtinfos.begin(); iti != dtinfos.end() && !encuentro; ++iti){
        if(((*iti)->gethFin()).gethora() == -1){
            encuentro=true;
            (*iti)->setFechaYHoraFinales(dtf, dth);
        }
    }
    usuarioLogueado = NULL;
    clase=NULL;
}
void ControladorClase::cancelarFinAsistencia(){
    usuarioLogueado = NULL;
    clase=NULL;
}

ControladorClase::~ControladorClase(){
}

