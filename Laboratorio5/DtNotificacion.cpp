#include "DtNotificacion.h"

DtNotificacion::DtNotificacion(DtHora hm, string na, string t, string nc, string ca, int ic, string nas){
    horaMensaje = hm;
    nombreAutor = na;
    texto = t;
    nombreClase = nc;
    nombreAsignatura = nas;
    codAsig = ca;
    idClase = ic;
};
DtHora DtNotificacion::gethoraMensaje(){
    return horaMensaje;
};
string DtNotificacion::getnombreAutor(){
    return nombreAutor;
};
string DtNotificacion::gettexto(){
    return texto;
};
string DtNotificacion::getnombreClase(){
    return nombreClase;
};
string DtNotificacion::getnombreAsignatura(){
    return nombreAsignatura;
};
string DtNotificacion::getcodAsig(){
    return codAsig;
};
int DtNotificacion::getidClase(){
    return idClase;
};

ostream& operator<<(ostream& os,DtNotificacion dtc){
    os << "-   Nombre de la asignatura: " << dtc.getnombreAsignatura() << endl;
	os << "-   Codigo de la asignatura: " << dtc.getcodAsig() << endl<<endl;
    os << "-   Nombre del autor: " << dtc.getnombreAutor() << endl;
	os << "-   Nombre de la clase: " << dtc.getnombreClase() << endl;
	os << "-   Id de la clase: " << dtc.getidClase() << endl;
	os << "-   Hora del mensaje: " << dtc.gethoraMensaje() << endl;
	os << "-   Contenido: " << dtc.gettexto() << endl;

	return os;
};
DtNotificacion::~DtNotificacion(){
};
