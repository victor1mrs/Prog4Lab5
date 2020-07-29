#ifndef DTNOMBRECLASE_H
#define DTNOMBRECLASE_H

#include <string>
#include <iostream>

using namespace std;

class DtNombreClase{
    private:
        string nombre;
        int id;
    public:
        DtNombreClase();
        DtNombreClase(string, int);
        virtual ~DtNombreClase();
        string getNombre() const;
        int getId() const;
        friend ostream& operator<<(ostream& os,DtNombreClase dtc);
};

#endif // DTNOMBRECLASE_H

