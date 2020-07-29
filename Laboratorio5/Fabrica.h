#ifndef FABRICA_H_
#define FABRICA_H_

#include "IControladorUsuario.h"
#include "IControladorAsignatura.h"
#include "IControladorClase.h"
#include "ControladorUsuario.h"
#include "ControladorAsignatura.h"
#include "ControladorClase.h"


class Fabrica {
private:
	static Fabrica * instance;
public:
	static Fabrica * getInstancia();
	Fabrica();
	IControladorUsuario* getIUsuario();
	IControladorAsignatura* getIAsignatura();
   	IControladorClase* getIClase();
};
#endif // FABRICA_H_
