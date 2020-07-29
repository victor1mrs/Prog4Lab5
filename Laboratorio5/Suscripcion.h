#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H
#include <iostream>
class Mensaje;
//class Usuario;
using namespace std;
class Suscripcion{
    public:
        Suscripcion(){};
        virtual ~Suscripcion(){};
        virtual bool aplicaNotif(Mensaje*, string, bool)=0;
};

#endif // SUSCRIPCION_H
