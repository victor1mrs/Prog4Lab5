#include "DtMensaje.h"

DtMensaje::DtMensaje(int id, string msj, DtFecha fMen, DtHora hMen, string em, string nom, set<DtMensaje*> resp){
    this->id = id;
    this->msj = msj;
    this->fMen = fMen;
    this->hMen = hMen;
    nombreAutor = nom;
    emailAutor = em;
	lstdtrespuestas = resp;
};
set<DtMensaje*> DtMensaje::getLstDtRespuestas(){
    return lstdtrespuestas;
};
int DtMensaje::getId() const{
    return id;
};
string DtMensaje::getMsj() const{
    return msj;
};
string DtMensaje::getEmailAutor() const{
    return emailAutor;
};
string DtMensaje::getNombreAutor() const{
    return nombreAutor;
};

DtFecha DtMensaje::getFMen() const{
    return fMen;
};

DtHora DtMensaje::getHMen() const{
    return hMen;
};

ostream& operator<<(ostream& os, DtMensaje dtc){
    os << dtc.getId() << "- "<<dtc.getNombreAutor() << ": " << dtc.getEmailAutor() << "."<< endl;
    os << dtc.getMsj() << endl;
    os << "Fecha: " << dtc.getFMen() << "   -   Hora: " << dtc.getHMen() <<endl;

	return os;
};


DtMensaje::~DtMensaje()
{
    //dtor
}
