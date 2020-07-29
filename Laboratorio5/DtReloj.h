#ifndef DtReloj_H
#define DtReloj_H

#include "DtFecha.h"
#include "DtHora.h"

class DtReloj{
    private:
        DtFecha fecha;
        DtHora hora;
    public:
        DtReloj(DtFecha,DtHora);
        DtFecha getfecha() const;
        DtHora gethora() const;
};
#endif
