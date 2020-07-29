#ifndef DTINFOESTUDIANTE_H
#define DTINFOESTUDIANTE_H

#include <string>
using namespace std;

class DtInfoEstudiante{
    private:
        string nombre;
        string ci;
    public:
        DtInfoEstudiante(string, string);
        virtual ~DtInfoEstudiante();
        string getNombre() const;
        string getCi() const;
};

#endif // DTINFOESTUDIANTE_H
