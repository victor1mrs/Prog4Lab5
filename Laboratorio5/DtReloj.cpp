#include "DtReloj.h"

DtReloj::DtReloj(DtFecha f,DtHora h){
    fecha = f;
    hora = h;
};
DtFecha DtReloj::getfecha() const{
    return fecha;
};
DtHora DtReloj::gethora() const{
    return hora;
};
