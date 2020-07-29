#ifndef IMPRIMIR_H_
#define IMPRIMIR_H_

#include <string>
#include <set>
#include <vector>

#include "DtAsignatura.h"
#include "DtMensaje.h"
#include "DtDocente.h"
#include "DtEstudiante.h"
#include "DtNombreClase.h"
#include "DtClase.h"
#include "DtTiempoAsignatura.h"
#include "DtNotificacion.h"
#include "DtPromedioClase.h"

using namespace std;

class Imprimir {
public:
    Imprimir();
    void imprimirlstDtAsignatura(set<DtAsignatura*>);
    void imprimirlstDtDocente(set<DtDocente*>);
    void imprimirlstDtEstudiante(set<DtEstudiante*>);
    void imprimirlstDtNombreClase(set<DtNombreClase*>);
    void imprimirlstDtClase(set<DtClase*>);
    void imprimirlstDtTiempoAsig(set<DtTiempoAsignatura*>);
    void imprimirlstDtPromedioClase(set<DtPromedioClase*>);
    void imprimirNotificaciones(set<DtNotificacion*>);
    void imprimirlstDtMensaje(set<DtMensaje*>, int &,vector<bool>&, DtMensaje&, int&);
    ~Imprimir();
};


#endif
