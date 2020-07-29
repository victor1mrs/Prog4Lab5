
#ifndef RESPUESTA_H
#define RESPUESTA_H
#include "Suscripcion.h"
#include "HandlerMensaje.h"
class Respuesta: public Suscripcion{
    public:
        Respuesta();
        virtual ~Respuesta();
        bool aplicaNotif(Mensaje*, string, bool);
};

#endif // RESPUESTA_H
