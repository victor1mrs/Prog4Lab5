#ifndef DTCLASE_H
#define DTCLASE_H
#include <string>
#include <set>
#include <iostream>
#include "DtDocente.h"
#include "DtFecha.h"
#include "DtHora.h"

using namespace std;

class DtClase{

    private:
        string nombre;
        string nombreAsig;
        string idAsig;
        int id;
        DtFecha fInicio;
        DtFecha fFin;
        DtHora hInicio;
        DtHora hFin;
        string url;
        set<DtDocente> docentes;
    public:
        DtClase(string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio, DtFecha fFin, DtHora hInicio, DtHora hFin, string url, set<DtDocente> docentes);
        DtClase(string nombre, string nombreAsig, string idAsig, int id, DtFecha fInicio, DtFecha fFin, DtHora hInicio, DtHora hFin, string url);
        DtClase(string nombre, int id, DtFecha fInicio, DtHora hInicio, string url);//para enviar mensaje
        virtual ~DtClase();
        string getNombre() const;
        string getNombreAsig() const;
        string getidAsig() const;
        int getId() const;
        DtFecha getFInicio() const;
        DtFecha getFFin() const;
        DtHora getHInicio() const;
        DtHora getHFin() const;
        string getUrl() const;
        set<DtDocente> getDocentes() const;
        friend ostream& operator<<(ostream& os,DtClase dtc);

};

#endif // DTCLASE_H

