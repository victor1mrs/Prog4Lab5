#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

#include "DtFecha.h"
#include "DtHora.h"

class DtMensaje
{
    private:
        int id;
        string msj;
        DtFecha fMen;
        DtHora hMen;
        set<DtMensaje*> lstdtrespuestas;
        string emailAutor;
        string nombreAutor;
    public:
        DtMensaje(int, string, DtFecha, DtHora, string, string, set<DtMensaje*>);
        ~DtMensaje();
        int getId() const;
        string getMsj() const;
        string getEmailAutor() const;
        string getNombreAutor() const;
        DtFecha getFMen() const;
        DtHora getHMen() const;
        set<DtMensaje*> getLstDtRespuestas();
       friend ostream& operator<<(ostream& os,DtMensaje dtc);
};

#endif // DTMENSAJE_H

