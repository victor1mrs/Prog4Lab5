#ifndef DTESTUDIANTE_H
#define DTESTUDIANTE_H

#include <string>
#include <iostream>
#include "DtUsuario.h"

using namespace std;

class DtEstudiante : public DtUsuario{

    private:
        string ci;

    public:
        DtEstudiante(string nombre, string email, string imagen, string pass, string ci);
        string getCi() const;
        friend ostream& operator<<(ostream& os,DtEstudiante dtc);
        ~DtEstudiante();
};

#endif // DTESTUDIANTE_H
