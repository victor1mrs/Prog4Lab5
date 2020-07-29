#ifndef Reloj_H
#define Reloj_H

#include "DtReloj.h"
#include "DtFecha.h"
#include "DtHora.h"
#include <string>

class Reloj{
    private:
        static Reloj* instancia;
        DtFecha fecha;
        DtHora hora;
        Reloj();
    public:
        static Reloj* getInstancia();
        DtFecha getfecha();
        void setfecha(DtFecha);
        DtHora gethora();
        void sethora(DtHora);
        void modificarfecha(DtFecha,DtHora);
        DtReloj consultarfecha();
};
#endif
