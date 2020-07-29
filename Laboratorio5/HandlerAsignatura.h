#ifndef HANDLERASIGNATURA_H
#define HANDLERASIGNATURA_H

#include <map>
#include <string>
#include<set>
#include<iterator>
#include "DtAsignatura.h"
#include "Asignatura.h"

using namespace std;
//class Asignatura;

class HandlerAsignatura{//Singleton
    private:
		int cantClases;
		int cantAsingaciones;
        map<string, Asignatura*> asignaturas;
        static HandlerAsignatura* instancia;
        HandlerAsignatura();
    public:
        static HandlerAsignatura* getInstancia();
        map<string, Asignatura*> listarAsignaturas();
        virtual ~HandlerAsignatura();
        void add(Asignatura*);
        int getCantClases();
        int getCantAsignaciones();
        void aumentarCantAsignaciones();
        void setCantClases(int);
        set<DtAsignatura*> getAsignaturas();
        Asignatura* seleccionarAsignatura(string codigoAsignatura);


        //ELIMINACION DE ASIGNATURA
        //Asignatura* getAsignatura(string);
        void removerAsig(string);

        //map<string, Asignatura*>::iterator find(string);


        //INSCRIPCION DE ASIGNAURA
        set<DtAsignatura*> asignaturasQNC(string mailEstudiante);

        map<string, Asignatura*>::iterator end();
        map<string, Asignatura*>::iterator begin();
        Asignatura* find(string);




};
//#include "Asignatura.h"

#endif // HANDLERASIGNATURA_H
