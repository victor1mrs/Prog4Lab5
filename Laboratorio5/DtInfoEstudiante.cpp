#include "DtInfoEstudiante.h"

DtInfoEstudiante::DtInfoEstudiante(string nombre, string ci){
    this->nombre = nombre;
    this->ci = ci;
}

string DtInfoEstudiante::getNombre() const{
    return nombre;
}

string DtInfoEstudiante::getCi() const{
    return ci;
}

DtInfoEstudiante::~DtInfoEstudiante()
{
    //dtor
}
