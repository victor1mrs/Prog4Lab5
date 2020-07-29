#include "HandlerAsignatura.h"

HandlerAsignatura* HandlerAsignatura::instancia=NULL;

HandlerAsignatura::HandlerAsignatura()
{
	this->cantAsingaciones=0;
	this->cantClases=0;
    map<string, Asignatura*> a;
    this->asignaturas=a;
}

HandlerAsignatura* HandlerAsignatura::getInstancia(){
	if (instancia==NULL)
		instancia= new HandlerAsignatura();
	return instancia;
}

int HandlerAsignatura::getCantAsignaciones(){
	return this->cantAsingaciones;
}

void HandlerAsignatura::aumentarCantAsignaciones(){
	this->cantAsingaciones++;
}

void HandlerAsignatura::setCantClases(int c){
    cantClases = c;
};


int HandlerAsignatura::getCantClases(){
	return this->cantClases;
}

void HandlerAsignatura::add(Asignatura* a) {
   //this->asignaturas[a->getCodigo()] = a;
    map<string,Asignatura*>::iterator it = asignaturas.end();
    asignaturas.insert(it, std::pair<string, Asignatura*>(a->getCodigo(), a));
};

set<DtAsignatura*> HandlerAsignatura::getAsignaturas(){
	set<DtAsignatura*> dtAsignaturas;
	set<DtAsignatura*>::iterator itdt;
	//if (this->asignaturas.empty())
		//return dtAsignaturas;
	for (map<string, Asignatura*>::iterator it = asignaturas.begin(); it!=asignaturas.end();it++){
		Asignatura* a = it->second;
        itdt = dtAsignaturas.end();
		dtAsignaturas.insert(itdt, a->getInfo());
	}
	return dtAsignaturas;
}

//Devuelve el set de DtDocentes que dictan la asignatura
Asignatura* HandlerAsignatura::seleccionarAsignatura(string codigoAsignatura){
	Asignatura* asig= asignaturas[codigoAsignatura];
	if (asig==NULL){
		throw std::invalid_argument ("Esta asignatura no esta registrada en el sistema.");
	}
	return asig;

	// HACER LA DIFERENCIA DE LOS DOCENTES DEL SISTEMA MENOS LOS DOCENTES QUE DVUELVE LISTAR DOCENTES

}

Asignatura* HandlerAsignatura::find(string c){
	map<string, Asignatura*>::iterator it = asignaturas.find(c);
	if (it == asignaturas.end()){
        return NULL;
	}
	else return it->second;
}



/*Asignatura* HandlerAsignatura::getAsignatura(string cod){
    map<string, Asignatura*>::iterator it = asignaturas.find(cod);
    return it->second;
};*/

void HandlerAsignatura::removerAsig(string cod){
    map<string, Asignatura*>::iterator it = asignaturas.find(cod);
    Asignatura* a = it->second;
    asignaturas.erase(it);
    a->~Asignatura();
    delete (a);
};

/*map<string, Asignatura*>::iterator HandlerAsignatura::find(string c){
    return asignaturas.find(c);
};*/
map<string, Asignatura*>::iterator HandlerAsignatura::end(){
    return asignaturas.end();
};
map<string, Asignatura*>::iterator HandlerAsignatura::begin(){
    return asignaturas.begin();
};


map<string, Asignatura*> HandlerAsignatura::listarAsignaturas(){
    return asignaturas;
};

set<DtAsignatura*> HandlerAsignatura::asignaturasQNC(string mailEstudiante){
	set<DtAsignatura*> dta;
	set<DtAsignatura*>::iterator ita;
	for (map<string, Asignatura*>::iterator it = asignaturas.begin(); it!=asignaturas.end();it++){
		bool cursa= it->second->cursa(mailEstudiante);
		if (!cursa){
			set<DtAsignatura*>::iterator ita;
			ita= dta.end();
			DtAsignatura* dtAsig= it->second->getInfo();
			dta.insert(dtAsig);
        }
	}
	return dta;
}


HandlerAsignatura::~HandlerAsignatura(){
    if (!asignaturas.empty()){
        map<string, Asignatura*>::iterator ita;
        Asignatura* a;
        for(ita=asignaturas.begin(); ita!=asignaturas.end();ita++){
            a=ita->second;
            asignaturas.erase(ita->first);
            a->~Asignatura();
            delete(a);
        }
    }
}
