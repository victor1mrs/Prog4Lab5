#ifndef DtFecha_H
#define DtFecha_H
#include <iostream>

using namespace std;


class DtFecha{
    private:
        int dia, mes, anio;

    public:
        DtFecha();
        DtFecha(int,int,int);
        int getdia() const;
        int getmes() const;
        int getanio() const;
        bool operator<(DtFecha);
        friend ostream& operator<<(ostream& os,DtFecha dtf);
        ~DtFecha();
};

#endif
