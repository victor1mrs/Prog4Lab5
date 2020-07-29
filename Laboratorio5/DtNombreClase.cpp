#include "DtNombreClase.h"


DtNombreClase::DtNombreClase(){}

DtNombreClase::DtNombreClase(string nombre, int id){
    this->nombre = nombre;
    this->id = id;
}

string DtNombreClase::getNombre() const{
    return nombre;
}

int DtNombreClase::getId() const{
    return id;
}

ostream& operator<<(ostream& os,DtNombreClase dtc){
    os << "-   Id clase: " << dtc.getId() << endl;
	os << "-   Nombre: " << dtc.getNombre() << endl;
	return os;
}

DtNombreClase::~DtNombreClase()
{
    //dtor
}
