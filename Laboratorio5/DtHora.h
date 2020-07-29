#ifndef DtHora_H
#define DtHora_H
#include <iostream>

using namespace std;

class DtHora{
    private:
        int hora, minuto, segundo;

    public:
        DtHora();
        DtHora(int,int, int);
        int gethora() const;
        int getminuto() const;
        int getsegundo() const;
        bool operator<(DtHora);
        friend ostream& operator<<(ostream& os,DtHora dth);
        ~DtHora();
};

#endif
