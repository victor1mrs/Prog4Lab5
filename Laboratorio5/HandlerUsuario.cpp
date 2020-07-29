/*
 * HandlerUsuario.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "HandlerUsuario.h"

HandlerUsuario* HandlerUsuario::instancia=NULL;


HandlerUsuario::HandlerUsuario() {
    map<string, Usuario*> u;
	this->usuarios=u;
}

HandlerUsuario* HandlerUsuario::getInstancia(){
	if (instancia==NULL)
		instancia= new HandlerUsuario();
	return instancia;
}

void HandlerUsuario::add(Usuario* u) {
    usuarios.insert(std::pair<string, Usuario*>(u->getEmail(), u));
};


Usuario* HandlerUsuario::find(string e){
	map<string, Usuario*>::iterator it = usuarios.find(e);
	if (usuarios.end()==it){
        return NULL;
	}
	else{
        return it->second;
	}
};

map<string,Usuario*>::iterator HandlerUsuario::begin() {
   return usuarios.begin();
};


map<string,Usuario*>::iterator HandlerUsuario::end() {
   return usuarios.end();
};

map<string, Usuario*> HandlerUsuario::listarUsuarios(){
	return usuarios;
};





set<DtDocente*> HandlerUsuario::docentesQND(Asignatura* asig){
	set<DtDocente*> dts;
	set<DtDocente*>::iterator itd;
	if (this->usuarios.empty()){
        return dts;
	}

	for (map<string, Usuario*>::iterator it = usuarios.begin(); it!=usuarios.end(); it++){
		Usuario* u= it->second;

        //if(typeid(Docente).name() == typeid(*u).name()){
		if (u->getTipo() ==TIPODOCENTE){
			string emailDocente= u->getEmail();
			bool dicta = asig->dictaAsignatura(emailDocente);
			if (!dicta){
				DtDocente* docente= new DtDocente(u->getnombre(), u->getEmail(), u->getimagen());
				itd=dts.end();
				dts.insert(itd,docente);
            }
        }

	}
	return dts;
}


HandlerUsuario::~HandlerUsuario() {
    if (!usuarios.empty()){
        map<string, Usuario*>::iterator ita;
        Usuario* a;
        for(ita=usuarios.begin(); ita!=usuarios.end();ita++){
            a=ita->second;
            usuarios.erase(ita->first);
            a->~Usuario();
            delete(a);
        }
    }

}

