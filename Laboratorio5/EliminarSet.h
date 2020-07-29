#ifndef ELIMINARSET_H
#define ELIMINARSET_H

#include "Imprimir.h"
class EliminarSet
{
    public:
        EliminarSet();
        void eliminarlstDtAsignatura(set<DtAsignatura*>);
        void eliminarlstDtDocente(set<DtDocente*>);
        void eliminarlstDtEstudiante(set<DtEstudiante*>);
        void eliminarlstDtNombreClase(set<DtNombreClase*>);
        void eliminarlstDtClase(set<DtClase*>);
        void eliminarlstDtTiempoAsig(set<DtTiempoAsignatura*>);
        void eliminarlstDtPromedioClase(set<DtPromedioClase*>);
        //void eliminarNotificaciones(set<DtNotificacion*>);
        void eliminarlstDtMensaje(set<DtMensaje*>);
        ~EliminarSet();

};

#endif // ELIMINARSET_H
