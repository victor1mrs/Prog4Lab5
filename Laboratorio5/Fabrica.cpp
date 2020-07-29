#include "Fabrica.h"


Fabrica* Fabrica::instance = NULL;

Fabrica::Fabrica(){
}

Fabrica * Fabrica::getInstancia() {
    if (instance == NULL)
        instance = new Fabrica();
    return instance;
}

IControladorUsuario* Fabrica::getIUsuario(){
    return ControladorUsuario::getInstancia();
};
IControladorAsignatura* Fabrica::getIAsignatura(){
    return ControladorAsignatura::getInstancia();
};
IControladorClase* Fabrica::getIClase(){
    return ControladorClase::getInstancia();//hacer
};
