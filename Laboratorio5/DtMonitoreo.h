#ifndef DTMONITOREO_H
#define DTMONITOREO_H

#include "DtClase.h"
#include "DtEstudiante.h"
#include<iostream>

class DtMonitoreo : public DtClase{

    private:
        set<DtEstudiante> estudiantes;

    public:
        DtMonitoreo(set<DtEstudiante> estudiantes, string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio,
                DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes);
        set<DtEstudiante> getEstudiantes() const;
        friend ostream& operator<<(ostream& os,DtMonitoreo dtc);
        ~DtMonitoreo();

};

#endif // DTMONITOREO_H
