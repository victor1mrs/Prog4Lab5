#ifndef DTNOTIFICACION_H_
#define DTNOTIFICACION_H_

#include "DtHora.h"
#include <string>
#include <iostream>
using namespace std;

class DtNotificacion {

private:
	DtHora horaMensaje;
    string nombreAutor;
    string texto;
    string nombreClase;
    string nombreAsignatura;
    string codAsig;
    int idClase;
public:
	DtNotificacion(DtHora, string nomUsuario, string contenido, string nomClase, string codAsig, int idClase, string nomAsig);
	DtHora gethoraMensaje();
    string getnombreAutor();
    string gettexto();
    string getnombreClase();
    string getnombreAsignatura();
    string getcodAsig();
    int getidClase();
    friend ostream& operator<<(ostream& os,DtNotificacion dtc);
	~DtNotificacion();
};

#endif /* DtNotificacion_H_ */

