#ifndef DTPROMEDIOCLASE_H
#define DTPROMEDIOCLASE_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class DtPromedioClase {
    private:
        string nombre;
        int id;
        float promedio;
    public:
        DtPromedioClase(string, int, float);
        string getnombre();
        int getid();
        float getpromedio();
        friend ostream& operator<<(ostream& os,DtPromedioClase dtc);
        ~DtPromedioClase();
};

#endif // DTPROMEDIOCLASE_H
