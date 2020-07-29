#ifndef Menu_H
#define Menu_H
#include "Fabrica.h"
#include "Reloj.h"
#include "Imprimir.h"
#include "EliminarSet.h"
#include <iostream>


using namespace std;

class Menu {
    public:
        bool mostrarmenu();
        bool MENU_ADMINISTRADOR();
        bool MENU_DOCENTE();
        bool MENU_ESTUDIANTE();
        bool CARGAR_DATOS_PRUEBA();
    private:
        void AltaUsuario();
        void AltaAsignatura();
        void AsigDeDocAsig();
        void InscripcionAsignaturas();
        void InicioClase();
        void FinalizacionClase();
        void EnvioMensaje();
        void AsistenciaClaseEnVivo();
        void FinAsistenciaClaseEnVivo();
        void TiempoDictadoClase();
        void TiempoAsistenciaClase();
        void EliminacionAsignatura();
        void SuscribirseNotificaciones();//solo a respuesta a msjs
        void ConsultaNotificaciones();
        void ModificarFechaSistema();
        void ConsultarFechaSistema();
        void PedirFechaYHora(DtFecha&, DtHora&);
};

#endif


