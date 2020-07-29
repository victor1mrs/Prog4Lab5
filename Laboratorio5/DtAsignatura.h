#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H

#include <map>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class DtAsignatura{

    private:
            string codigo;
            string nombre;
            bool teorico;
            bool practico;
            bool monitoreo;
    public:
            DtAsignatura();
            DtAsignatura(string codigo, string nombre, bool teorico, bool practico, bool monitoreo);
            ~DtAsignatura();
            //Getters
            string getCodigo() const;
            string getNombre() const;
            bool getTeorico() const;
            bool getPractico() const;
            bool getMonitoreo() const;
            friend ostream& operator<<(ostream& os,DtAsignatura dtc);

};

#endif // DTASIGNATURA_H
