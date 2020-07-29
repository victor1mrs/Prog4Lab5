#include "Imprimir.h"




Imprimir::Imprimir(){
}

void Imprimir::imprimirlstDtAsignatura(set<DtAsignatura*> lst){
    set<DtAsignatura*>::iterator it;
    cout << "Asignaturas: " << endl;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << (**it) << endl;
    //    delete  (*it);
    }
};


void Imprimir::imprimirlstDtDocente(set<DtDocente*> lst){
    set<DtDocente*>::iterator it;
    cout << "Docentes: " << endl;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << (**it) << endl;
        //delete (*it);
    }
};



void Imprimir::imprimirlstDtEstudiante(set<DtEstudiante*> lst){
    set<DtEstudiante*>::iterator it;
    cout << "Estudiantes: " << endl;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << (**it) << endl;
        //delete (*it);
    }
};
void Imprimir::imprimirlstDtNombreClase(set<DtNombreClase*> lst){
    set<DtNombreClase*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << **it << endl;
        //delete (*it);
    }
};
void Imprimir::imprimirlstDtClase(set<DtClase*> lst){
    set<DtClase*>::iterator it;
    cout << "Clases: " << endl;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << (**it) << endl;//ver que tipo de clase
        //delete (*it);
    }
};
void Imprimir::imprimirlstDtTiempoAsig(set<DtTiempoAsignatura*> lst){
    set<DtTiempoAsignatura*>::iterator it;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << (**it) << endl;
        //delete (*it);
    }
};
void Imprimir::imprimirlstDtPromedioClase(set<DtPromedioClase*> lst){
    set<DtPromedioClase*>::iterator it;
    cout << "Promedios de clases: " << endl;
    for(it=lst.begin(); it!=lst.end(); it++){
        cout << (**it) << endl;
        //delete (*it);
    }
};
void Imprimir::imprimirNotificaciones(set<DtNotificacion*> lst){
    set<DtNotificacion*>::iterator it;
    unsigned int i=0;
    for(it=lst.begin(); i!=lst.size(); it++){
        cout << (**it) << endl;
        i++;
       // delete (*it);
    }
};


//IMPRIMIR MENSAJES
//void Imprimir::imprimirlstDtMensaje(set<DtMensaje*> lst, int &esp, DtMensaje &menActual, int& actual)


void Imprimir::imprimirlstDtMensaje(set<DtMensaje*> lst, int &esp,vector<bool>& visitados, DtMensaje& menActual, int& actual){
    if(!(lst.empty()) && !visitados[menActual.getId()]){
        visitados[menActual.getId()] = true;
        for(int i = 0; i<esp; i++){
                cout <<"     ";
        }
        cout << menActual.getId() << "- "<<menActual.getNombreAutor() << ": " << menActual.getEmailAutor() << " - Fecha: " << menActual.getFMen() << " - Hora: " << menActual.getHMen() << endl;
        for(int i = 0; i<esp; i++){
                cout <<"     ";
        }
        cout << menActual.getMsj() << endl;

        set<DtMensaje*>::iterator it;
        lst = menActual.getLstDtRespuestas();
        if(!lst.empty()){
            unsigned int j=0;
            for(it=lst.begin(); j!=lst.size(); it++){
                if (!visitados[(**it).getId()]){
                    esp++;
                    actual = j;
                    imprimirlstDtMensaje(lst, esp, visitados, **it, actual);
                    esp--;
                }
                j++;
            }
        }
    }
};



Imprimir::~Imprimir(){
}
