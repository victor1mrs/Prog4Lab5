#ifndef DTTEORICO_H
#define DTTEORICO_H

#include "DtClase.h"
#include <iostream>

class DtTeorico : public DtClase{
    private:
        int cantAsistentes;

    public:
        DtTeorico(int cantAsistentes, string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes);
        int getCantAsistentes() const;
        friend ostream& operator<<(ostream& os,DtTeorico dtc);
        ~DtTeorico();

};

#endif // DTTEORICO_H
