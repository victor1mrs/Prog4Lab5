#include "Reloj.h"

Reloj* Reloj::instancia = NULL;

Reloj::Reloj(){
    fecha = DtFecha();
    hora = DtHora();
};
Reloj* Reloj::getInstancia()
{
    if (instancia == NULL)
        instancia = new Reloj();
    return instancia;
};
DtFecha Reloj::getfecha(){
    return fecha;
};
void Reloj::setfecha(DtFecha f){
    fecha = f;
};
DtHora Reloj::gethora(){
    return hora;
};
void Reloj::sethora(DtHora h){
    hora = h;
};
void Reloj::modificarfecha(DtFecha f,DtHora h){
    fecha = f;
    hora = h;
};
DtReloj Reloj::consultarfecha(){
    return DtReloj(this->fecha,this->hora);
};
