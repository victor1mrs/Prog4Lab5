//Asignatura.cpp


#include "Asignatura.h"
#include "DtTiempoAsignatura.h"

Asignatura::Asignatura(){}

Asignatura::Asignatura(string c, string n, bool t, bool p, bool m) {
	codigo = c;
	nombre = n;
	tiene_monitoreo = m;
	tiene_practico = p;
	tiene_teorico = t;
}
string Asignatura::getCodigo(){
    return codigo;
}
string Asignatura::getNombre(){
    return nombre;
}
bool Asignatura::getMonitoreo(){
    return tiene_monitoreo;
}
bool Asignatura::getPractico(){
    return tiene_practico;
}
bool Asignatura::getTeorico(){
    return tiene_teorico;
}
map<int, Clase*> Asignatura::getClases(){
    return clases;
};
map<int, Asignacion*> Asignatura::getAsignaciones(){
    return asignaciones;
};
void Asignatura::setCodigo(string c){
    codigo = c;
}
void Asignatura::setNombre(string n){
    nombre = n;
}
void Asignatura::setMonitoreo(bool m){
    tiene_monitoreo = m;
}
void Asignatura::setPractico(bool p){
    tiene_practico = p;
}
void Asignatura::setTeorico(bool t){
    tiene_teorico = t;
}

void Asignatura::agregarAsignacion(Asignacion* a){
    asignaciones.insert(std::pair<int, Asignacion*>(a->getid(),a));
};


DtAsignatura* Asignatura::getInfo(){
	DtAsignatura* dt = new DtAsignatura(this->getCodigo(), this->getNombre(), this->getTeorico(), this->getPractico(), this->getMonitoreo());
	return dt;
}


//esta operacion devuelve los docentes que dictan la asignatura
/*set<DtDocente*> Asignatura::listarDocentes(){
	set<DtDocente*> dts;
	if(this->asignaciones.empty())
		return dts;
	for (map<string, Asignacion*>::iterator it = asignaciones.begin(); it!=asignaciones.end();it++){
			Asignacion a = *it->second;
			DtDocente* dt= a.getDocente();
			dts.insert(dt);
		}
	return dts;
}*/

set<DtEstudiante*> Asignatura::listarInscriptos(){
    set<DtEstudiante*> dts;
	if(this->estudiantes.empty())
		return dts;
	for (map<string, Estudiante*>::iterator it = estudiantes.begin(); it!=estudiantes.end();it++){
			Estudiante* e = it->second;
			DtEstudiante* dt= e->getInfo();
			dts.insert(dt);
		}
	return dts;
};

//inscripcion asignatura
void Asignatura::agregarEstudiante(Estudiante* e){
    map<string, Estudiante*>::iterator it = estudiantes.end();
    estudiantes.insert(it, std::pair<string, Estudiante*>(e->getEmail(),e));
};

bool Asignatura::dictaAsignatura(string emailDocente){
	bool res= false;
	for (map<int, Asignacion*>::iterator it = asignaciones.begin(); it !=asignaciones.end() && !res;it++){
		if (emailDocente == it->second->getEmailDocente())
			res=true;
		}
	return res;
}

void Asignatura::crearClase (string nombreClase,DtFecha fComienzo,DtHora hComienzo,int id, TipoClase rol,set<string> inscriptos, string mail){
    DtFecha f= DtFecha(-1,-1,-1);
    DtHora h = DtHora(-1,-1,-1);
    string url = "www.FingClass.edu.uy/"+ nombreClase;
    HandlerUsuario* HU = HandlerUsuario::getInstancia();

    if(rol == monitoreo){
        Monitoreo* c = new Monitoreo(nombreClase, id, fComienzo, f, hComienzo, h, url, codigo, nombre);
        //para cada email *it de estudiantes inscriptos
        set<string>::iterator it;
        for(it=inscriptos.begin(); it!=inscriptos.end(); it++){
            Usuario* u = HU->find(*it); // Usuario?
            //linkeo a cada estudiante e con la clase c creada anteriormente
            Estudiante* e = dynamic_cast<Estudiante*>(u);
            e->agregarmonitoreo(c);
        }
        map<int, Clase*>::iterator iti = clases.end();
        clases.insert(iti, std::pair<int, Clase*>(c->getId(), c));
        Usuario* us = HU->find(mail);
        Docente* d = dynamic_cast<Docente*>(us);
        d->setclase(c);
        c->agregarDocente(d);

    }
    else if(rol == teorico){ //TipoClase
        int cantAsistentes = 0;
        Teorico* c = new Teorico(nombreClase, id, fComienzo, f, hComienzo, h, url, cantAsistentes, codigo, nombre);
        map<int, Clase*>::iterator iti= clases.end();
        clases.insert(iti, std::pair<int, Clase*>(c->getId(), c));
        Usuario* us = HU->find(mail);
        Docente* d = dynamic_cast<Docente*>(us);
        d->setclase(c);
        c->agregarDocente(d);
    }
    else if(rol == practico){
        Practico* c = new Practico(nombreClase, id, fComienzo, f, hComienzo, h, url, codigo, nombre);
        map<int, Clase*>::iterator iti = clases.end();
        clases.insert(iti, std::pair<int, Clase*>(c->getId(), c));
        Usuario* us = HU->find(mail);
        Docente* d = dynamic_cast<Docente*>(us);
        d->setclase(c);
        c->agregarDocente(d);
    } //else cout<<"NO AGREGA BIEN/NO ENTRA AL IF de crear en asignatura"<<endl;

};

Clase* Asignatura::getClase(int id ){
	Clase* res= NULL;
	for (map<int, Clase*>::iterator it = clases.begin(); it !=clases.end();++it){
		if(it->second->getId()== id){
			res = it->second;
		}
	}
	return res;
}





//Tiempo de dictado de clases

DtTiempoAsignatura* Asignatura::getTiemposClases(){

	DtTiempoAsignatura* res = new DtTiempoAsignatura(this->codigo, this->nombre);
	int temp = 0;

    for(map<int, Clase*>::iterator it = clases.begin(); it!=clases.end(); it++){

		Clase* clase = it->second;

		if (clase !=NULL){
		int tunaclase = clase->tiempoClase();
		temp = temp + tunaclase;
		}

	}

	res->setTiempo(temp);
	return res;
}


bool Asignatura::cursa(string email){
	bool res= false;
	map<string, Estudiante*>::iterator ite;
	for(ite=estudiantes.begin(); ite!=estudiantes.end() && !res; ite++){
		 if (ite->second->getEmail()== email){
			 res= true;
		 }
	 }
	return res;
}


//eliminacion de asignatura
Asignatura::~Asignatura() {
    /*//LA SACO DEL MANEJADOR
    HandlerAsignatura* HA = HandlerAsignatura::getInstancia();
    map<string, Asignatura*> lst = HA->listarAsignaturas();
    lst.erase(codigo);*/

	if (!clases.empty()){
        map<int, Clase*>::iterator itc;
        Clase* c;
        for (itc = clases.begin(); 0 != clases.size(); itc = clases.begin()){
            //cout<< itc->first<<endl;//  TEST, LUEGO BORRAR
            c = itc->second;
            clases.erase(itc);//SACO LA CLASE DEL MAP DE ASIGNATURA
            c->~Clase();//BORRO LAS COSAS DE CLASE
            //cout<< itc->second->getId()<<endl;
           // delete c;
        }
	}
	if(!asignaciones.empty()){
        map<int, Asignacion*>::iterator ita;
        Asignacion* a=NULL;
        for (ita = asignaciones.begin(); 0!= asignaciones.size(); ita = asignaciones.begin()){
            a = ita->second;
            asignaciones.erase(ita);//SACO LA ASIGNACION DEL MAP DE ASIGNATURA
            a->~Asignacion();//BORRO LAS COSAS DE ASIGNACION
            //delete(a);//BORRO LA ASIGNACION
        }
	}
    if (!estudiantes.empty()){
        map<string, Estudiante*>::iterator ite;
        Estudiante* e;
        for (ite = estudiantes.begin(); 0 != estudiantes.size(); ite = estudiantes.begin()){
            e = ite->second;
            e->removerAsignatura(this);
            estudiantes.erase(ite->first);//SACO EL ESTUDIANTE DEL MAP DE ASIGNATURA
        }
    }
}




   //delete(c);//borro la clase
            /*if ((typeid(Monitoreo).name()) == (typeid(*c).name())){
                Monitoreo* m = dynamic_cast<Monitoreo*>(c);
                m->~Monitoreo();//BORRO LAS COSAS DE CLASE
                //delete(m);//BORRO LA CLASE
            }
            else{
                c->~Clase();//BORRO LAS COSAS DE CLASE
                //delete(c);//BORRO LA CLASE
            }*/
