#ifndef DTCLASE2_H
#define DTCLASE2_H

#include <string>
#include <set>
#include <iostream>
#include "DtFecha.h"
#include "DtHora.h"

using namespace std;

class DtClase2{

    private:
        string nombre;
        int id;
        DtFecha fInicio;
        DtFecha fFin;
        DtHora hInicio;
        DtHora hFin;
        string url;
    public:
        DtClase2(string nombre, int id, DtFecha fInicio, DtFecha fFin, DtHora hInicio, DtHora hFin, string url);
        ~DtClase2();
        string getNombre() const;
        int getId() const;
        DtFecha getFInicio() const;
        DtFecha getFFin() const;
        DtHora getHInicio() const;
        DtHora getHFin() const;
        string getUrl() const;
        friend ostream& operator<<(ostream& os,DtClase2 dtc);

};

#endif // DTCLASE_H
