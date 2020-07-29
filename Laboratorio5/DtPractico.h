#ifndef DTPRACTICO_H
#define DTPRACTICO_H

#include "DtClase.h"

class DtPractico : public DtClase{
    //private:
    public:
        DtPractico(string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes);
        ~DtPractico();

};

#endif // DTPRACTICO_H
