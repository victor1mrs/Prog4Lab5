
#include "Menu.h"
#include <stdio.h>
#include <time.h>

void Menu::PedirFechaYHora(DtFecha& dtf, DtHora& dth){
   cout << "Ingrese la fecha con el formato dd/mm/aaaa: ";

    struct tm tm;
    string s = "";
    while(true){
        getline(cin,s);
        if( (strptime(s.c_str(), "%d/%m/%Y", &tm)) && (s[2]=='/') && (s[5]=='/') && (s.size() == 10) ){
            break;
        }
        else
            cout << "Fecha invalida, por favor ingrese fecha en formato dd/mm/aaaa. " << endl;
    }

    string aux = "";
    int d, m, a;
    aux = aux + s[0] + s[1];
    d = atoi(aux.c_str());
    aux = "";
    aux = aux + s[3] + s[4];
    m = atoi(aux.c_str());
    aux = "";
    aux = aux + s[6] + s[7] + s[8] + s[9];
    a = atoi(aux.c_str());

    s = "";
    int h, mi, se;
    cout << "Hora con el formato hh:mm:ss:  ";
    while(true){
        getline(cin,s);
        if( (s[2]==':') && (s[5]==':') && (s.size() == 8) ){
            aux = "";
            aux = aux + s[0] + s[1];
            h = atoi(aux.c_str());
            aux = "";
            aux = aux + s[3] + s[4];
            mi = atoi(aux.c_str());
            aux = "";
            aux = aux + s[6] + s[7];
            se = atoi(aux.c_str());
            if( (h < 24) && (mi < 60) && (se < 60) )
                break;
            else
                cout << "Hora invalida, por favor ingrese una correctamente" << endl;
        }
        else
            cout << "Hora invalida, por favor ingrese en formato hh:mm." << endl;
    }

    dtf = DtFecha(d,m,a);
    dth = DtHora(h, mi, se);
}



void Menu::AltaUsuario(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorUsuario* IU = F->getIUsuario();
    string opcion, nombre, email, pass, img, instituto, ci;
    bool quiero_seguir = true;
    while (quiero_seguir){
        cout<<"Opciones: "<<endl;
        cout<<"1- Agregar Estudiante."<<endl;
        cout<<"2- Agregar Docente."<<endl;
        cout<<"Ingresar opcion: ";
        getline(cin, opcion);//sirve saber que opcion eligió?
        cout<<"Ingresar nombre: ";
        getline(cin, nombre);
        Usuario* ituser;
        bool user_valido=false;
        while (!user_valido){
            cout<<"Ingresar email: ";
            getline(cin, email);
            HandlerUsuario* hu = HandlerUsuario::getInstancia();
            ituser = hu->find(email);
            if (ituser!= NULL){
                cout<< "Ya existe un usuario con ese email en el sistema."<<endl;
            }
            else user_valido=true;
        }
        cout<<"Ingresar contraseña: ";
        getline(cin, pass);
        cout<<"Ingresar URL de la imagen: ";
        getline(cin, img);
        int op = atoi(opcion.c_str());
        if (op == 1){
            cout<<"Ingresar C.I.: ";
            getline(cin, ci);
            IU->agregarEstudiante(nombre, email, pass, img, ci);
        }else{
            cout<<"Ingresar instituto: ";
            getline(cin, instituto);
            IU->agregarDocente(nombre, email, pass, img, instituto);
        }
        cout<<"¿Desea dar de alta el usuario? "<<endl;
        cout<<"1- Confirmar."<<endl;
        cout<<"0- Cancelar."<<endl;
        cout<<"Ingresar opcion: ";
        getline(cin, opcion);
        op = atoi(opcion.c_str());
        if (op == 1){
            IU->confirmarAltaUsuario();
            cout<<"¡Ha ingresado un usuario con éxito!"<<endl<<endl;
        }else{
            IU->cancelarAltaUsuario();
            cout<<"Ha cancelado el alta de usuario."<<endl<<endl;
        }

        //test
        /*HandlerUsuario* hu = HandlerUsuario::getInstancia();
        map<string, Usuario*>::iterator it = hu->listarUsuarios().begin();
        cout<<it->second->getnombre()<<endl;
        cout<<it->second->getEmail()<<endl;*/


        cout<<"¿Desea continuar agregando usuarios?"<<endl;
        cout<<"1- Sí."<<endl;
        cout<<"0- No."<<endl;
        cout<<"Ingresar opcion: ";
        getline(cin, opcion);
        op = atoi(opcion.c_str());
        if (op == 0){
            quiero_seguir = false;
        }
    }
};
void Menu::AltaAsignatura(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorAsignatura* IA = F->getIAsignatura();
    string opcion, codigo, nombre;
    bool teorico, practico, monitoreo;
    cout<<"Ingresar nombre: ";
    getline(cin, nombre);
    HandlerAsignatura* ha = HandlerAsignatura::getInstancia();
    bool asig_valida=false;
    Asignatura* itasig ;
    while (!asig_valida){
        cout<<"Ingresar codigo: ";
        getline(cin, codigo);
        itasig = ha->find(codigo);
        if (itasig != NULL){
             cout<<"Ya existe una asignatura con ese codigo en el sistema."<<endl;
        }
        else asig_valida = true;
    }
    cout<<"¿Tiene instancias de teorico?"<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    teorico = atoi(opcion.c_str());
    cout<<"¿Tiene instancias de practico?"<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    practico = atoi(opcion.c_str());
    cout<<"¿Tiene instancias de monitoreo?"<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    monitoreo = atoi(opcion.c_str());
    IA->altaAsig(codigo, nombre);
    IA->indicarInstancias(teorico, practico, monitoreo);
    DtAsignatura dta = IA->mostrarDatosAsig();
    cout<<"Datos de la asignatura:"<<endl;
    cout<<dta<<endl;
    cout<<"¿Desea dar de alta la asignatura?"<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    if (atoi(opcion.c_str())==1){
        IA->confirmarAltaAsig();
        cout<<"¡Ha ingresado una asignatura con éxito!"<<endl<<endl;

        /*//test
        HandlerAsignatura* hu = HandlerAsignatura::getInstancia();
        map<string, Asignatura*>::iterator it = hu->listarAsignaturas().find(codigo);
        cout<<it->second->getCodigo()<<endl;
        //cout<<it->second->getEmail()<<endl;*/
    }else {
        IA->cancelarAltaAsig();
        cout<<"Ha cancelado el alta de asignatura."<<endl<<endl;
    }

};
void Menu::AsigDeDocAsig(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorAsignatura* IA = F->getIAsignatura();
    string email, rol, opcion,codigo;
    set<DtAsignatura*> lstAsig = IA->listarAsignaturas();
    if (lstAsig.size()==0){
        throw std::invalid_argument ("No hay asignaturas en el sistema.");
    }
    Imprimir i =Imprimir();
    i.imprimirlstDtAsignatura(lstAsig);
    bool asig_valida=false;
    while (!asig_valida){
        cout<<"Ingresar codigo: ";
        getline(cin, codigo);
        set<DtAsignatura*>::iterator it;
        for(it = lstAsig.begin(); it!= lstAsig.end() && (!asig_valida); it++){
            if ((*it)->getCodigo()==codigo)
                asig_valida = true;
            }
            if (!asig_valida)
                cout<< "No existe una asignatura con ese codigo en el sistema."<<endl;
    }
    IA->seleccionarAsig(codigo);
    cout<<"¿Desea agregar un docente a la asignatura seleccionada?"<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    bool quiero_seguir = stoi(opcion);
    int cant=0;
    while (quiero_seguir){

        set<DtDocente*> lstDoc= IA->verDocentesQNoDictan(codigo);
        if (lstDoc.size()==0){
            throw std::invalid_argument ("No hay docentes para asignar a la asignatura seleccionada.");
        }
        i.imprimirlstDtDocente(lstDoc);

        //1-ASEGURARME QUE LA ASIGNATURA NO TENGA ASIGNACION CON ESE DOCENTE
        //2-ver los booleanos de la asignatura para imprimir opciones


        bool docente_valido=false;
        while (!docente_valido){
            cout<<"Ingresar email: ";
            getline(cin, email);
            set<DtDocente*>::iterator it;
            for(it = lstDoc.begin(); it!= lstDoc.end() && (!docente_valido); it++){
                if ((*it)->getEmail()==email)
                    docente_valido = true;
            }
             if (!docente_valido)
                 cout<< "Seleccione un docente de la lista."<<endl;
        }
        HandlerAsignatura* ha = HandlerAsignatura::getInstancia();
        Asignatura* asig = ha->find(codigo);
        cout<<"Ingresar rol: "<<endl;
        if (asig->getTeorico()){
            cout<<"1- Teorico"<<endl;
        }
        if (asig->getPractico()){
            cout<<"2- Practico"<<endl;
        }
        if (asig->getMonitoreo()){
            cout<<"3- Monitoreo"<<endl;
        }
    //como controlo las opciones?
        getline(cin, rol);
        IA->seleccionarDocente(email, TipoClase(atoi(rol.c_str())-1));
        cout<<"Agregar docente: "<<endl;
        cout<<"1- Confirmar."<<endl;
        cout<<"0- Cancelar."<<endl;
        cout<<"Ingresar opcion: ";
        getline(cin, opcion);
        if (atoi(opcion.c_str())==1){
            IA->confirmarAsignacion();
            cout<<"Se ha confirmado la asginacion con exito!"<<endl<<endl;
            cout<<"¿Desea seguir agregando docentes a la asignatura seleccionada?"<<endl;
            cout<<"1- Sí."<<endl;
            cout<<"0- No."<<endl;
            cout<<"Ingresar opcion: ";
            getline(cin, opcion);
            quiero_seguir = atoi(opcion.c_str());
            cant++;
            if(!quiero_seguir)
                IA->logOut();
        }
        else{
            quiero_seguir = false;
            IA->cancelarAsignacion();
            cout<<"Se ha cancelado la asignacion."<<endl<<endl;
        }
    }
    //EliminarSet e = EliminarSet();
    //e.eliminarlstDtAsignatura(lstAsig);
};
void Menu::InscripcionAsignaturas(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorUsuario* IU = F->getIUsuario();
    string email, codigo, opcion;

    HandlerUsuario* hu = HandlerUsuario::getInstancia();
    cout<<"Ingresar email: ";
    getline(cin, email);
    Usuario* u = hu->find(email);
    if (u == NULL || (u->getTipo()!=TIPOESTUDIANTE))
        throw std::invalid_argument ("El email ingresado NO pertenece a un estudiante registrado.");

    IU->logIn(email);
    cout<<"¿Desea inscribirse a una asignatura?"<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    bool quiere_seguir = stoi(opcion);
    set<DtAsignatura*> lstAsig;
    while(quiere_seguir){
        lstAsig = IU->asignaturasDisponibles();//falta esto para testear
        if (lstAsig.size()==0){
            throw std::invalid_argument ("No hay asignaturas disponibles.");
        }
        Imprimir i = Imprimir();
        i.imprimirlstDtAsignatura(lstAsig);
        bool asig_valida=false;
        while (!asig_valida){
            cout<<"Ingresar codigo: ";
            getline(cin, codigo);
            set<DtAsignatura*>::iterator it;
            for(it = lstAsig.begin(); it!= lstAsig.end() && (!asig_valida); it++){
                if ((*it)->getCodigo()==codigo)
                    asig_valida = true;
                }
                if (!asig_valida)
                    cout<< "El estudiante no esta inscripto a una asignatura con ese codigo."<<endl;
        }
        IU->seleccionarAsignatura(codigo);
        cout<<"Terminar inscripcion: "<<endl;
        cout<<"1- Confirmar."<<endl;
        cout<<"0- Cancelar."<<endl;
        cout<<"Ingresar opcion: ";
        getline(cin, opcion);
        if (stoi(opcion)==1){
            IU->confirmarInscripcion();
            cout<<"Se ha confirmado la inscripcion con exito!"<<endl<<endl;
            cout<<"¿Desea inscribirse a otra asignatura?"<<endl;
            cout<<"1- Sí."<<endl;
            cout<<"0- No."<<endl;
            cout<<"Ingresar opcion: ";
            getline(cin, opcion);
            quiere_seguir = stoi(opcion);
            if(!quiere_seguir)
                IU->logOut();
        } else{
            quiere_seguir = false;
            IU->cancelarInscripcion();
            cout<<"Se ha cancelado la inscripcion."<<endl<<endl;
        }
    }
    //EliminarSet e = EliminarSet();
//    e.eliminarlstDtAsignatura(lstAsig);
};
void Menu::InicioClase(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorClase* IC = F->getIClase();
    string email, codigo, opcion, nombreClase;

    HandlerUsuario* hu = HandlerUsuario::getInstancia();
    cout<<"Ingresar email: ";
    getline(cin, email);
    Usuario* u = hu->find(email);
    if (u == NULL || (u->getTipo()!=TIPODOCENTE))
        throw std::invalid_argument ("El email ingresado NO pertenece a un docente registrado.");

    IC->logIn(email);
    set<DtAsignatura*> lstAsig = IC->listarAsignaturasDictadas();
    if (lstAsig.size()==0){
        throw std::invalid_argument ("El docente no fue asignado a una asignatura.");
    }
    Imprimir i = Imprimir();
    i.imprimirlstDtAsignatura(lstAsig);
    bool asig_valida=false;
    while (!asig_valida){
        cout<<"Ingresar codigo: ";
        getline(cin, codigo);
        set<DtAsignatura*>::iterator it;
        for(it = lstAsig.begin(); it!= lstAsig.end() && (!asig_valida); it++){
            if ((*it)->getCodigo()==codigo)
                asig_valida = true;
        }
         if (!asig_valida)
             cout<< "Ingrese un codigo que este en la lista."<<endl;
    }
    IC->seleccionarAsignatura(codigo);
    cout<<"Ingresar nombre de clase: ";
    getline(cin, nombreClase);

    DtFecha fComienzo;
    DtHora hComienzo;
    PedirFechaYHora(fComienzo, hComienzo);

    IC->ingresarDatosClase(nombreClase, fComienzo, hComienzo);
    //ver el rol del docente primero
    Docente* doc = dynamic_cast<Docente*>(hu->find(email));
    HandlerAsignatura* ha = HandlerAsignatura::getInstancia();
    Asignatura* asig = ha->find(codigo);
    if (doc->getRol(asig)==monitoreo){
        set<DtEstudiante*> lstEst = IC->listarInscriptos();
            if (lstEst.size()==0)
                    throw std::invalid_argument ("No hay estudiantes inscriptos.");
            
            Imprimir i = Imprimir();
            i.imprimirlstDtEstudiante(lstEst);

            cout<<"¿Desea agregar un estudiante a la clase?"<<endl;
            cout<<"1- Sí."<<endl;
            cout<<"0- No."<<endl;
            cout<<"Ingresar opcion: ";
            getline(cin, opcion);

            bool quiere_agregar = atoi(opcion.c_str());
            int cant_est=0;
            while (quiere_agregar && cant_est<15){
                //controlar que esten inscriptos
                bool estudiante_valido=false;
                while (!estudiante_valido){
                    cout<<"Ingresar email del estudiante: ";
                    getline(cin, email);
                    set<DtEstudiante*>::iterator it;
                    for(it = lstEst.begin(); it!= lstEst.end() && (!estudiante_valido); it++){
                        if ((*it)->getEmail()==email){
                            estudiante_valido = true;
                            lstEst.erase(*it);
                        }
                    }
                    if (!estudiante_valido)
                        cout<< "Ingrese un estudiante que este en la lista."<<endl;
                }
                IC->agregarEstudiante(email);
                cant_est++;
                cout<<"Estudiante agregado con éxito!"<<endl<<endl;

                cout<<"¿Desea agregar otro estudiante a la clase?"<<endl;
                cout<<"1- Sí."<<endl;
                cout<<"0- No."<<endl;
                cout<<"Ingresar opcion: ";
                getline(cin, opcion);
                quiere_agregar = atoi(opcion.c_str());
                if (quiere_agregar){
                    if (lstEst.size()==0){
                        cout<<"No hay mas estudiantes para agregar."<<endl;
                        quiere_agregar = false;
                    }
                    else{
                        Imprimir i = Imprimir();
                        i.imprimirlstDtEstudiante(lstEst);
                    }
                }
            }
    }
    DtClase* dtc = IC->mostrarInfoClase();
    cout<<(*dtc)<<endl;//parece estar bien
    //delete(dtc);

    cout<<"¿Desea dar de alta la clase? "<<endl;
    cout<<"1- Confirmar."<<endl;
    cout<<"0- Cancelar."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    if (atoi(opcion.c_str())==1){
        IC->confirmarInicio();
        //test
       /* HandlerAsignatura* ha = HandlerAsignatura::getInstancia();
        map<string, Asignatura*>::iterator it = ha->listarAsignaturas().find(codigo);
        map<int, Clase*> ::iterator it1 = it->second->getClases().begin();
        cout<<it1->second->getNombre()<<endl;
        HandlerUsuario* hu = HandlerUsuario::getInstancia();
        map<string, Usuario*>::iterator itu = hu->listarUsuarios().find(email);
        Docente* d = dynamic_cast<Docente*>(itu->second);
        map<int, Clase*> ::iterator it2 = d->getclases().begin();
        cout<<it2->second->getNombre()<<endl;
        //cout<<it->second->getCodigo()<<endl;
        //cout<<it->second->getEmail()<<endl;*/
        cout<<"Se ha iniciado la clase con exito!"<<endl<<endl;
    } else{
        IC->cancelarInicio();
        cout<<"Se ha cancelado el inicio de clase."<<endl<<endl;
    }
};
void Menu::FinalizacionClase(){//FINALIZAR LOS DTINFO DE LOS Q ESTAN ASISTIENDO
    Fabrica* F = Fabrica::getInstancia();
    IControladorClase* IC = F->getIClase();
    string email, id, opcion;

    HandlerUsuario* hu = HandlerUsuario::getInstancia();
    cout<<"Ingresar email: ";
    getline(cin, email);
    Usuario* u = hu->find(email);
    if (u == NULL || (u->getTipo()!=TIPODOCENTE))
        throw std::invalid_argument ("El email ingresado NO pertenece a un docente registrado.");

    IC->logIn(email);//Solo continua si existe el email en el sistema
    set<DtNombreClase*>lstDtNombreClase = IC->listarClasesEnVivo();
    if (lstDtNombreClase.size()==0){
        throw std::invalid_argument ("No hay clases en vivo.");
    }
    Imprimir i=Imprimir();
    i.imprimirlstDtNombreClase(lstDtNombreClase);
    bool clase_valida=false;
    while (!clase_valida){
        cout<<"Ingresar id de clase: ";
        getline(cin, id);
        set<DtNombreClase*>::iterator it;
        for(it = lstDtNombreClase.begin(); it!= lstDtNombreClase.end() && (!clase_valida); it++){
            if ((*it)->getId()==stoi(id))
                clase_valida= true;
            }
            if (!clase_valida)
                cout<< "Elija una clase de la lista."<<endl;
    }
    IC->seleccionarClaseVivo(atoi(id.c_str()));
    DtClase2* dtc = IC->mostrarDatos();
    cout << *dtc << endl;//IMPLEMENTAR
    cout<<"¿Desea finalizar la clase? "<<endl;
    cout<<"1- Confirmar."<<endl;
    cout<<"0- Cancelar."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    if (atoi(opcion.c_str())==1){
        IC->confirmarFinalizacion();
        cout<<"Clase finalizada con exito!"<<endl<<endl;
    } else{
        IC->cancelarFinalizacion();
        cout<<"Se ha cancelado la finalizacion."<<endl<<endl;
    }
    //EliminarSet e = EliminarSet();
//    e.eliminarlstDtNombreClase(lstDtNombreClase);
};
void Menu::EnvioMensaje(){
    //CONTROLAR QUE HAYA ASISTIDO A LA CLASE
    Fabrica* F = Fabrica::getInstancia();
    IControladorClase* IC = F->getIClase();
    string email, codAsig,idClase, opcion, idmsj, contenido;
    cout<<"Ingresar email: ";
    getline(cin, email);
    IC->logIn(email);//Solo continua si existe el email en el sistema
    set<DtClase*> lstDtClase = IC->listarClases();//falta arreglar
    if (lstDtClase.size()==0)
        throw std::invalid_argument ("No hay clases en las que participe este usuario.");
    Imprimir i = Imprimir();
    i.imprimirlstDtClase(lstDtClase);
    bool clase_valida=false;
    while (!clase_valida){
        cout<<"Ingresar id de clase: ";
        getline(cin, idClase);
        set<DtClase*>::iterator it;
        for(it = lstDtClase.begin(); it!= lstDtClase.end() && (!clase_valida); it++){
            if ((*it)->getId()==stoi(idClase))
                clase_valida= true;
            }
            if (!clase_valida)
                cout<< "Elija una clase de la lista."<<endl;
    }
    set<DtMensaje*> lstDtMensaje = IC->verMensajes(atoi(idClase.c_str()));
    if (lstDtMensaje.size()!=0){
        unsigned int t=0;
        int idmax = 0;
        set<DtMensaje*>::iterator itm;
        for(itm=lstDtMensaje.begin(); itm!=lstDtMensaje.end(); itm++){
            if(((*itm)->getId()) > idmax){
                idmax = ((*itm)->getId());
            }
            t++;
        }
        vector<bool> visitados;//todos falsos
        for(int h=0; h<=idmax;h++)
                visitados.push_back(false);
        int espacios = 0;
        int actual=0;
        for(itm=lstDtMensaje.begin(); itm!=lstDtMensaje.end(); itm++){
            i.imprimirlstDtMensaje(lstDtMensaje, espacios, visitados, **itm, actual);
            actual++;
        }
        cout<<"¿Quiere responder a un mensaje de la lista? "<<endl;
        cout<<"1- Sí."<<endl;
        cout<<"0- No."<<endl;
        cout<<"Ingresar opcion: ";
        getline(cin, opcion);
        if (atoi(opcion.c_str())==1){
            bool idmsj_valido=false;
            while (!idmsj_valido){
                cout<<"Id del mensaje que se quiere responder: ";
                getline(cin, idmsj);
                set<DtMensaje*>::iterator it;
                for(it = lstDtMensaje.begin(); it!= lstDtMensaje.end() && (!idmsj_valido); it++){
                    if ((*it)->getId()==stoi(idmsj))
                        idmsj_valido = true;
                    }
                    if (!idmsj_valido)
                        cout<< "Elija una clase de la lista."<<endl;
            }
            cout<<"Escribir mensaje: "<<endl;
            getline(cin, contenido);
            IC->responder(atoi(idmsj.c_str()), contenido);
        } else {
            cout<<"Escribir mensaje: "<<endl;
            getline(cin, contenido);
            IC->enviarMensaje(contenido);
        }
    } else {
        cout<<"Sé el primero en escribir un mensaje: "<<endl;
        getline(cin, contenido);
        IC->enviarMensaje(contenido);
    }

    cout<<"¿Desea confirmar envío? "<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    if (atoi(opcion.c_str())==1){
        IC->confirmarEnvio();
        cout<<"Se ha enviado con exito!"<<endl<<endl;
    }else {
        IC->cancelarEnvio();
        cout<<"Se ha cancelado el envio."<<endl<<endl;
    }
    //EliminarSet e = EliminarSet();
    //e.eliminarlstDtClase(lstDtClase);
    //e.eliminarlstDtMensaje(lstDtMensaje);

};
void Menu::AsistenciaClaseEnVivo(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorClase* IC = F->getIClase();
    string email, codAsig, idClase, opcion;

    HandlerUsuario* hu = HandlerUsuario::getInstancia();
    cout<<"Ingresar email: ";
    getline(cin, email);
    Usuario* u = hu->find(email);
    if (u == NULL || (u->getTipo()!=TIPOESTUDIANTE))
        throw std::invalid_argument ("El email ingresado NO pertenece a un estudiante registrado.");

    IC->logIn(email);
    set<DtAsignatura*> lstAsigCurs = IC->listarAsigCursadas();
    if (lstAsigCurs.size()==0)
        throw std::invalid_argument ("No esta inscripto a asignaturas.");
    Imprimir i = Imprimir();
    i.imprimirlstDtAsignatura(lstAsigCurs);
    bool asig_valida=false;
    while (!asig_valida){
        cout<<"Ingresar codigo: ";
        getline(cin, codAsig);
        set<DtAsignatura*>::iterator it;
        for(it = lstAsigCurs.begin(); it!= lstAsigCurs.end() && (!asig_valida); it++){
            if ((*it)->getCodigo()==codAsig)
                asig_valida = true;
        }
         if (!asig_valida)
             cout<< "Ingrese un codigo de la lista."<<endl;
    }
    IC->seleccionarAsignatura(codAsig);
    set<DtNombreClase*> lstClasesVivo = IC->listarClasesEnVivo();
    if (lstClasesVivo.size()==0)
        throw std::invalid_argument ("No hay clases en vivo para la asignatura elegida.");
    i.imprimirlstDtNombreClase(lstClasesVivo);

    bool clase_valida=false;
    while (!clase_valida){
        cout<<"Ingresar id de clase: ";
        getline(cin, idClase);
        set<DtNombreClase*>::iterator it;
        for(it = lstClasesVivo.begin(); it!= lstClasesVivo.end() && (!clase_valida); it++){
            if ((*it)->getId()==stoi(idClase))
                clase_valida= true;
            }
            if (!clase_valida)
                cout<< "Elija una clase de la lista."<<endl;
    }
    IC->seleccionarClaseVivo(atoi(idClase.c_str()));
    //SE MUESTRAN LOS DATOS INGRESADOS
    cout<<"Datos seleccionados: " <<endl;
    cout<<" - Codigo de asignatura: " << codAsig<<endl;
    cout<<" - Identificador de clase: " << idClase<<endl;

    cout<<"¿Desea asistir a esta clase? "<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    if (atoi(opcion.c_str())==1){
        IC->confirmarAsistencia();
        cout<<"Se ha confirmado asistencia con exito!"<<endl<<endl;
    }else{
        IC->cancelarAsistencia();
        cout<<"Se ha cancelado asistencia."<<endl<<endl;
    }
    //EliminarSet e = EliminarSet();
    //e.eliminarlstDtAsignatura(lstAsigCurs);
    //e.eliminarlstDtNombreClase(lstClasesVivo);
};
void Menu::FinAsistenciaClaseEnVivo(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorClase* IC = F->getIClase();
    string email, codAsig, idClase, opcion;

    HandlerUsuario* hu = HandlerUsuario::getInstancia();
    cout<<"Ingresar email: ";
    getline(cin, email);
    Usuario* u = hu->find(email);
    if (u == NULL || (u->getTipo()!=TIPOESTUDIANTE))
        throw std::invalid_argument ("El email ingresado NO pertenece a un estudiante registrado.");

    IC->logIn(email);//Solo continua si existe el email en el sistema
    set<DtClase*> lstClasesAsist = IC->listarClasesAsistiendo();
    if (lstClasesAsist.size()==0)
        throw std::invalid_argument ("No hay clases a las que este asistiendo este usuario.");
    Imprimir i = Imprimir();
    i.imprimirlstDtClase(lstClasesAsist);

    bool clase_valida=false;
    while (!clase_valida){
        cout<<"Ingresar id de clase: ";
        getline(cin, idClase);
        set<DtClase*>::iterator it;
        for(it = lstClasesAsist.begin(); it!= lstClasesAsist.end() && (!clase_valida); it++){
            if ((*it)->getId()==stoi(idClase))
                clase_valida= true;
            }
            if (!clase_valida)
                cout<< "Elija una clase de la lista."<<endl;
    }
    IC->seleccionarClaseAsistiendo(stoi(idClase));
    cout<<"¿Desea finalizar la asistencia a esta clase? "<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    if (stoi(opcion)==1){
        IC->confirmarFinAsistencia();
        cout<<"Se ha finalizado la asistencia con exito!"<<endl<<endl;
    }else{
        IC->cancelarFinAsistencia();
        cout<<"Se ha cancelado la finalizacion de asistencia."<<endl<<endl;
    }

    //EliminarSet e = EliminarSet();
    //e.eliminarlstDtClase(lstClasesAsist);
};
void Menu::TiempoDictadoClase(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorAsignatura* IA = F->getIAsignatura();
    set<DtTiempoAsignatura*>lstDtTiempoAsig = IA->obtenerTiempo();
    if (lstDtTiempoAsig.size()==0)
        throw std::invalid_argument ("No hay asignaturas en el sistema.");
    Imprimir i = Imprimir();
    i.imprimirlstDtTiempoAsig(lstDtTiempoAsig);
    //EliminarSet e = EliminarSet();
    //e.eliminarlstDtTiempoAsig(lstDtTiempoAsig);
}
void Menu::TiempoAsistenciaClase(){//TESTEAR PORQUE EXPLOTA
    Fabrica* F = Fabrica::getInstancia();
    IControladorAsignatura* IA = F->getIAsignatura();
    string email, codAsig;

    HandlerUsuario* hu = HandlerUsuario::getInstancia();
    cout<<"Ingresar email: ";
    getline(cin, email);
    Usuario* u = hu->find(email);
    if (u == NULL || (u->getTipo()!=TIPODOCENTE))
        throw std::invalid_argument ("El email ingresado NO pertenece a un docente registrado.");

    IA->logIn(email);
    set<DtAsignatura*>lstDtAsig = IA->listarAsigDictadas();
    if (lstDtAsig.size()==0){
        throw std::invalid_argument ("No hay asignaturas dictadas por este usuario.");
    }
    Imprimir i = Imprimir();
    i.imprimirlstDtAsignatura(lstDtAsig);
    bool asig_valida=false;
    while (!asig_valida){
        cout<<"Ingresar codigo: ";
        getline(cin, codAsig);
        set<DtAsignatura*>::iterator it;
        for(it = lstDtAsig.begin(); it!= lstDtAsig.end() && (!asig_valida); it++){
            if ((*it)->getCodigo()==codAsig)
                asig_valida = true;
        }
         if (!asig_valida)
             cout<< "Ingrese un codigo que este en la lista."<<endl;
    }
    IA->seleccionarAsig(codAsig);
    set<DtPromedioClase*> lstDtProm = IA->mostrarPromedios();
    if (lstDtProm.size()==0){
        throw std::invalid_argument ("No tiempos promedios de asistencia.");
    }
    i.imprimirlstDtPromedioClase(lstDtProm);
    //EliminarSet e = EliminarSet();
    //e.eliminarlstDtAsignatura(lstDtAsig);
    //e.eliminarlstDtPromedioClase(lstDtProm);
};
void Menu::EliminacionAsignatura(){//TESTEAR PORQUE SE ROMPE
    Fabrica* F = Fabrica::getInstancia();
    IControladorAsignatura* IA = F->getIAsignatura();
    string opcion, codAsig;
    set<DtAsignatura*> lstDtAsig = IA->listarAsignaturas();
    if (lstDtAsig.size()==0)
        throw std::invalid_argument ("No hay asignaturas en el sistema.");
    Imprimir i = Imprimir();
    i.imprimirlstDtAsignatura(lstDtAsig);
    bool asig_valida=false;
    while (!asig_valida){
        cout<<"Ingresar codigo de asignatura: ";
        getline(cin, codAsig);
        set<DtAsignatura*>::iterator it;
        for(it = lstDtAsig.begin(); it!= lstDtAsig.end() && (!asig_valida); it++){
            if ((*it)->getCodigo()==codAsig)
                asig_valida = true;
        }
         if (!asig_valida)
             cout<< "Ingrese un codigo que este en la lista."<<endl;
    }
    IA->seleccionarAsig(codAsig);
    cout<<"¿Desea eliminar esta asignatura? "<<endl;
    cout<<"1- Sí."<<endl;
    cout<<"0- No."<<endl;
    cout<<"Ingresar opcion: ";
    getline(cin, opcion);
    if (atoi(opcion.c_str())==1){
        IA->confirmarEliminacion();
        cout<<"La asignatura con codigo: ("<<codAsig<< ") fue eliminada con éxito!"<<endl<<endl;
    }else{
        IA->cancelarEliminacion();
        cout<<"Se ha cancelado la eliminacion."<<endl<<endl;
    }

    //EliminarSet e = EliminarSet();
    //e.eliminarlstDtAsignatura(lstDtAsig);
};
void Menu::SuscribirseNotificaciones(){
   Fabrica* F = Fabrica::getInstancia();
    IControladorUsuario* IU = F->getIUsuario();
    string email, modo;
    cout<<"Ingresar email: ";
    getline(cin, email);
    IU->logIn(email);
    bool modo_valido = false;
    while(!modo_valido){
        cout<<"Modos de suscripcion:"<<endl;
        cout<<"1- Respuesta"<<endl;
        cout<<"Ingresar opcion: ";
        getline(cin, modo);
        if (modo=="1"){
            modo_valido = true;
            IU->suscribirse("Respuesta");
            cout<<"Suscripcion realizada con exito!"<<endl<<endl;
        }
        else cout<<"Ingresar un modo de suscripcion valido"<<endl;
    }
};
void Menu::ConsultaNotificaciones(){
    Fabrica* F = Fabrica::getInstancia();
    IControladorUsuario* IU = F->getIUsuario();
    string email;
    cout<<"Ingresar email: ";
    getline(cin, email);
    IU->logIn(email);
    set<DtNotificacion*>lstNotif = IU->getNotificaciones();
    if (lstNotif.size()==0)
        throw std::invalid_argument ("No hay notificaciones para este usuario.");


    cout<<"--------NOTIFICACIONES--------"<<endl<<endl;
    Imprimir i = Imprimir();
    i.imprimirNotificaciones(lstNotif);
    IU->eliminarNotificaciones();
};

void Menu::ModificarFechaSistema(){
    DtFecha dtf;
    DtHora dth;
    Reloj* r = Reloj::getInstancia();
    PedirFechaYHora(dtf, dth);
    r->modificarfecha(dtf,dth);
    cout << "Se ha modificado con éxito la fecha y hora del sistema." << endl<<endl;
};
void Menu::ConsultarFechaSistema(){
    DtFecha dtf;
    DtHora dth;
    Reloj* r = Reloj::getInstancia();
    DtReloj dtr = r->consultarfecha();
    cout<<"Fecha: "<<dtr.getfecha()<<endl;
    cout<<"Hora: "<<dtr.gethora()<<endl;
};






bool Menu::MENU_ESTUDIANTE(){
    string opcion = "";
	 cout << "Bienvenido. Elija la opcion." << endl;
	 cout << "---------------------------------------------" << endl;
	 cout << "MENU ESTUDIANTE:" << endl;
	 cout << "   1) Inscripcion a las asignaturas" << endl;
	 cout << "   2) Envio de mensaje" << endl;
	 cout << "   3) Asistencia a clase en vivo" << endl;
	 cout << "   4) Finalizacion de asistencia a clase en vivo" << endl;
	 cout << "   5) Suscribirse a notificaciones" << endl;
	 cout << "   6) Consulta de notificaciones" << endl;
	 cout << "   0) Salir" << endl;
	 cout << "Ingrese una opcion para continuar: ";

     getline(cin, opcion);
     int op = atoi(opcion.c_str());

     switch (op){
        case 1: InscripcionAsignaturas();break;
        case 2: EnvioMensaje();break;
        case 3: AsistenciaClaseEnVivo();break;
        case 4: FinAsistenciaClaseEnVivo();break;
        case 5: SuscribirseNotificaciones();break;
        case 6: ConsultaNotificaciones();break;
        case 0: cout << endl << "¡Hasta pronto!" <<endl;return false;break;
    }
    // fin menu
    return 1;
};

bool Menu::MENU_DOCENTE(){
    string opcion = "";
	 cout << "Bienvenido. Elija la opcion." << endl;
	 cout << "---------------------------------------------" << endl;
	 cout << "MENU DOCENTE:" << endl;
	 cout << "   1) Inicio de clase" << endl;
	 cout << "   2) Finalizacion de clase" << endl;
     cout << "   3) Envio de mensaje" << endl;
	 cout << "   4) Tiempo de asistencia a clase" << endl;
	 cout << "   5) Suscribirse a notificacion" << endl;
	 cout << "   6) Consulta de notificaciones" << endl;
	 cout << "   0) Salir" << endl;
	 cout << "Ingrese una opcion para continuar: ";

     getline(cin, opcion);
     int op = atoi(opcion.c_str());

     switch (op){
        case 1: InicioClase();break;
        case 2: FinalizacionClase();break;
        case 3: EnvioMensaje();break;
        case 4: TiempoAsistenciaClase();break;
        case 5: SuscribirseNotificaciones();break;
        case 6: ConsultaNotificaciones();break;
        case 0: cout << endl << "¡Hasta pronto!" <<endl;return false;break;
    }
    // fin menu
    return 1;
};

bool Menu::MENU_ADMINISTRADOR(){
    string opcion = "";
	 cout << "Bienvenido. Elija la opcion." << endl;
	 cout << "---------------------------------------------" << endl;
	 cout << "MENU ADMINISTRADOR:" << endl;
	 cout << "   1) Alta usuario" << endl;
	 cout << "   2) Alta asignatura" << endl;
	 cout << "   3) Asignacion de docentes a una asignatura" << endl;
	 cout << "   4) Tiempo de dictado de clases" << endl;
	 cout << "   5) Eliminacion de asignatura" << endl;
	 cout << "   6) Modificar fecha del sistema" << endl;
	 cout << "   7) Consultar fecha del sistema" << endl;
	 cout << "   0) Salir" << endl;
	 cout << "Ingrese una opcion para continuar: ";

     getline(cin, opcion);
     int op = atoi(opcion.c_str());

     switch (op){
        case 1: AltaUsuario();break;
        case 2: AltaAsignatura();break;
        case 3: AsigDeDocAsig();break;
        case 4: TiempoDictadoClase();break;
        case 5: EliminacionAsignatura();break;
        case 6: ModificarFechaSistema();break;
        case 7: ConsultarFechaSistema();break;
        case 0: cout << endl << "¡Hasta pronto!" <<endl;return false;break;
    }
    // fin menu
    return 1;
};

bool Menu::CARGAR_DATOS_PRUEBA(){


	Fabrica* fabrica= Fabrica::getInstancia();
	IControladorUsuario* CU= fabrica->getIUsuario();
	IControladorAsignatura* CA = fabrica->getIAsignatura();
	IControladorClase* CC = fabrica->getIClase();


	//REGISTRO DE USUARIOS
	//registro docentes
	CU->agregarDocente("Juan Perez", "juan@mail.com","0", "0", "INCO" );
    CU->confirmarAltaUsuario();
	CU->agregarDocente("Maria Pires", "maria@mail.com","0", "0", "INCO" );
	CU->confirmarAltaUsuario();
	CU->agregarDocente("Jorge Chacho", "jorge@mail.com","0", "0", "INCO" );
	CU->confirmarAltaUsuario();
	//registro estudiantes
	CU->agregarEstudiante("Roberto Parra", "roberto@mail.com", "0", "0", "12345678");
	CU->confirmarAltaUsuario();
	CU->agregarEstudiante("Ana Rodriguez", "ana@mail.com", "0", "0", "23456789");
	CU->confirmarAltaUsuario();
	CU->agregarEstudiante("Ramon Valdes", "ramon@mail.com", "0", "0", "34567890");
	CU->confirmarAltaUsuario();


	//ALTA DE ASIGNATURAS
	CA->altaAsig("P1", "Programacion 1 ", 1,1,1);
	CA->confirmarAltaAsig();
	CA->altaAsig("P2", "Programacion 2",1,1,1 );
	CA->confirmarAltaAsig();
	CA->altaAsig("P3", "Programacion 3",1,1,0);
	CA->confirmarAltaAsig();

	//ASIGNACION DE DOCENTES
	CA->seleccionarAsig("P1");
	CA->verDocentesQNoDictan("P1");
	CA->seleccionarDocente("juan@mail.com", teorico);
	CA->confirmarAsignacion();

	CA->seleccionarAsig("P1");
	CA->verDocentesQNoDictan("P1");
	CA->seleccionarDocente("maria@mail.com", practico);
	CA->confirmarAsignacion();

	CA->seleccionarAsig("P1");
	CA->verDocentesQNoDictan("P1");
	CA->seleccionarDocente("jorge@mail.com", monitoreo);
	CA->confirmarAsignacion();

	//INSCRIPCION A ASGINATURAS
	CU->seleccionarAsignatura("P1");
	CU->logIn("roberto@mail.com");
	CU->confirmarInscripcion();
    CU->logOut();

	CU->seleccionarAsignatura("P1");
	CU->logIn("ana@mail.com");
	CU->confirmarInscripcion();
    CU->logOut();

	CU->seleccionarAsignatura("P2");
	CU->logIn("ana@mail.com");
	CU->confirmarInscripcion();
    CU->logOut();

	CU->seleccionarAsignatura("P1");
	CU->logIn("ramon@mail.com");
	CU->confirmarInscripcion();
	CU->logOut();

	//CLASES

	CC->logIn("juan@mail.com");
	CC->seleccionarAsignatura("P1");
	DtFecha fC= DtFecha(01,05,2020);
	DtHora hC= DtHora(9,0,0);
	CC->ingresarDatosClase("Intro", fC, hC);
	CC->confirmarInicio();
	DtFecha fF= DtFecha(01,05,2020);
	DtHora hF= DtHora(10,00,00);
	CC->finalizarClaseDDP(fF,hF);

	CC->logIn("juan@mail.com");
	CC->seleccionarAsignatura("P1");
	DtFecha fC2= DtFecha(03,05,2020);
	DtHora hC2= DtHora(9,00,00);
	CC->ingresarDatosClase("Tema 1", fC2, hC2);
	CC->confirmarInicio();
	DtFecha fF2= DtFecha(03,05,2020);
	DtHora hF2= DtHora(10,00,00);
	CC->finalizarClaseDDP(fF2,hF2);

    CC->logIn("juan@mail.com");
	CC->seleccionarAsignatura("P1");
	DtFecha fC3= DtFecha(8,05,2020);
	DtHora hC3= DtHora(9,00,00);
	CC->ingresarDatosClase("Tema 2", fC, hC);
	CC->confirmarInicio();
	DtFecha fF3= DtFecha(8,05,2020);
	DtHora hF3= DtHora(10,00,00);
	CC->finalizarClaseDDP(fF3,hF3);

    CC->logIn("maria@mail.com");
	CC->seleccionarAsignatura("P1");
	DtFecha fC4= DtFecha(02,05,2020);
	DtHora hC4= DtHora(16,00,00);
	CC->ingresarDatosClase("Pra 1", fC4, hC4);
	CC->confirmarInicio();
	DtFecha fF5= DtFecha(02,05,20);
	DtHora hF5= DtHora(17,00,00);
	CC->finalizarClaseDDP(fF5,hF5);

    CC->logIn("maria@mail.com");
	CC->seleccionarAsignatura("P1");
	DtFecha fC6= DtFecha(03,05,2020);
	DtHora hC6= DtHora(16,00,00);
	CC->ingresarDatosClase("Pra 2", fC6, hC6);
	CC->confirmarInicio();
	DtFecha fF7= DtFecha(03,05,2020);
	DtHora hF7= DtHora(17,00,00);
	CC->finalizarClaseDDP(fF7,hF7);

    CC->logIn("jorge@mail.com");
	CC->seleccionarAsignatura("P1");
	DtFecha fC8= DtFecha(04,05,2020);
	DtHora hC8= DtHora(16,00,00);
	CC->ingresarDatosClase("06/01/20", fC8, hC8);
	CC->agregarEstudiante("ana@mail.com");
	CC->agregarEstudiante("ramon@mail.com");
	CC->confirmarInicio();
	DtFecha fF9= DtFecha(04,05,2020);
	DtHora hF9= DtHora(17,00,00);
	CC->finalizarClaseDDP(fF9,hF9);



	//ASISTENCIA A CLASE EN VIVO Y  FINALIZACION DE ASISTENCIA
	CC->logIn("roberto@mail.com");
	CC->seleccionarAsignatura("P1");
	CC->seleccionarClaseVivo(1);
	Reloj* reloj= Reloj::getInstancia();
	DtFecha fA1= DtFecha(01,05,2020);
	DtHora hA1= DtHora(9,01,00);
	reloj->setfecha(fA1);
	reloj->sethora(hA1);
	CC->confirmarAsistencia();
	CC->logIn("roberto@mail.com");
	CC->listarClasesAsistiendo();
	CC->seleccionarClaseAsistiendo(1);
	DtFecha fFA1= DtFecha(01,05,2020);
	DtHora hFA1= DtHora(9,21,00);
	reloj->setfecha(fFA1);
	reloj->sethora(hFA1);
	CC->confirmarFinAsistencia();


	CC->logIn("ana@mail.com");
	CC->seleccionarAsignatura("P1");
	CC->seleccionarClaseVivo(1);
    DtFecha fA2= DtFecha(01,05,2020);
	DtHora hA2= DtHora(9,02,00);
	reloj->setfecha(fA2);
	reloj->sethora(hA2);
	CC->confirmarAsistencia();
	CC->logIn("ana@mail.com");
	CC->seleccionarClaseAsistiendo(1);
	DtFecha fFA2= DtFecha(01,05,2020);
	DtHora hFA2= DtHora(9,32,00);
	reloj->setfecha(fFA2);
	reloj->sethora(hFA2);
	CC->confirmarFinAsistencia();




	CC->logIn("ramon@mail.com");
	CC->seleccionarAsignatura("P1");
	CC->seleccionarClaseVivo(1);
	DtFecha fA3= DtFecha(01,05,2020);
	DtHora hA3= DtHora(9,03,00);
	reloj->setfecha(fA3);
	reloj->sethora(hA3);
	CC->confirmarAsistencia();
	CC->logIn("ramon@mail.com");
	CC->seleccionarClaseAsistiendo(1);
	DtFecha fFA3= DtFecha(01,05,2020);
	DtHora hFA3= DtHora(9,43,00);
	reloj->setfecha(fFA3);
	reloj->sethora(hFA3);
	CC->confirmarFinAsistencia();


	CC->logIn("ramon@mail.com");
	CC->seleccionarAsignatura("P1");
	CC->seleccionarClaseVivo(6);
	DtFecha fA4= DtFecha(04,05,2020);
	DtHora hA4= DtHora(16,00,00);
	reloj->setfecha(fA4);
	reloj->sethora(hA4);
	CC->confirmarAsistencia();
	CC->logIn("ramon@mail.com");
	CC->seleccionarClaseAsistiendo(6);
	DtFecha fFA4= DtFecha(04,05,2020);
	DtHora hFA4= DtHora(17,00,00);
	reloj->setfecha(fFA4);
	reloj->sethora(hFA4);
	CC->confirmarFinAsistencia();

    //PRUEBA NO VA
    /*CC->logIn("ana@mail.com");
	CC->seleccionarAsignatura("P1");
	CC->seleccionarClaseVivo(6);
	DtFecha fAa4= DtFecha(04,05,2020);
	DtHora hAa4= DtHora(16,10,20);
	reloj->setfecha(fAa4);
	reloj->sethora(hAa4);
	CC->confirmarAsistencia();
	CC->logIn("ana@mail.com");
	CC->seleccionarClaseAsistiendo(6);
	DtFecha fFAa4= DtFecha(04,05,2020);
	DtHora hFAa4= DtHora(17,00,00);
	reloj->setfecha(fFAa4);
	reloj->sethora(hFAa4);
	CC->confirmarFinAsistencia();
	//SACAAAAR
    */


	//MENSAJES
	//1
	CC->logIn("juan@mail.com");
	CC->fijarClase(1);
	DtFecha f10= DtFecha(01,05,2020);
	DtHora h10= DtHora(9,01,00);
	reloj->setfecha(f10);
	reloj->sethora(h10);
	CC->enviarMensaje("Bienvenidos!");
	CC->confirmarEnvio();

	//2
	CC->logIn("juan@mail.com");
	CC->fijarClase(1);
	DtFecha f1= DtFecha(01,05,2020);
	DtHora h2= DtHora(9,02,00);
	reloj->setfecha(f1);
	reloj->sethora(h2);
	CC->enviarMensaje("Confirmen materiales por favor");
	CC->confirmarEnvio();

	//3
	CC->logIn("jorge@mail.com");
	CC->fijarClase(6);
	DtFecha f3= DtFecha(04,05,2020);
	DtHora h3= DtHora(16,01,00);
	reloj->setfecha(f3);
	reloj->sethora(h3);
	CC->enviarMensaje("Comparto pantalla");
	CC->confirmarEnvio();

	//4
	CC->logIn("roberto@mail.com");
	CC->fijarClase(1);
	DtFecha f4= DtFecha(01,05,2020);
	DtHora h4= DtHora(9,05,00);
	reloj->setfecha(f4);
	reloj->sethora(h4);
	CC->responder(1, "Listo para aprender ");
	CC->confirmarEnvio();

    //5
	CC->logIn("juan@mail.com");
	CC->fijarClase(1);
	DtFecha f5= DtFecha(01,05,2020);
	DtHora h5= DtHora(9,06,00);
	reloj->setfecha(f5);
	reloj->sethora(h5);
	CC->responder(4,"Me alegro");
	CC->confirmarEnvio();

    //6
	CC->logIn("ana@mail.com");
	CC->fijarClase(1);
	DtFecha f6= DtFecha(01,05,2020);
	DtHora h6= DtHora(9,06,00);
	reloj->setfecha(f6);
	reloj->sethora(h6);
	CC->responder(2,"Todo listo");
	CC->confirmarEnvio();

	//7
	CC->logIn("ramon@mail.com");
	CC->fijarClase(6);
	DtFecha f7= DtFecha(04,05,2020);
	DtHora h7= DtHora(16,05,00);
	reloj->setfecha(f7);
	reloj->sethora(h7);
	CC->responder(3,"Ya la vemos");
	CC->confirmarEnvio();


	cout<<"DATOS CARGADOS CON EXITO!"<<endl<<endl;

    return true;
};






bool Menu::mostrarmenu(){
	 string opcion = "";
	 cout << "Bienvenido. Elija la opcion." << endl;
	 cout << "---------------------------------------------" << endl;
	 cout << "MENU PRINCIPAL:" << endl;
	 cout << "   1) Administrador" << endl;
	 cout << "   2) Docente" << endl;
	 cout << "   3) Estudiante" << endl;
	 cout << "   4) Cargar datos de prueba" << endl;
	 cout << "   5) Salir" << endl;
	 cout << "Ingrese una opcion para continuar: ";

     getline(cin, opcion);
     int op = atoi(opcion.c_str());

     switch (op){
        case 1: MENU_ADMINISTRADOR();break;
        case 2: MENU_DOCENTE();break;
        case 3: MENU_ESTUDIANTE();break;
        case 4: CARGAR_DATOS_PRUEBA();break;
        case 5: cout << endl << "¡Hasta pronto!" <<endl;return false;break;
    }
    // fin menu
    return 1;
};
