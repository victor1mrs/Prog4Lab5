#include "DtFecha.h"

DtFecha::DtFecha()
{
	dia = -1;
	mes = -1;
	anio = -1;
};
DtFecha::DtFecha(int d,int m,int a)
{
	dia = d;
	mes = m;
	anio = a;
};
int DtFecha::getdia() const
{
	return dia;
};
int DtFecha::getmes() const
{
	return mes;
};
int DtFecha::getanio() const
{
	return anio;
};
bool DtFecha::operator<(DtFecha dtf)
{
    if(this->anio < dtf.anio)
    {
        return true;
    }
    else if (this->anio > dtf.anio)
    {
        return false;
    }
    else if(this->mes < dtf.mes)
    {
        return true;
    }
    else if(this->mes > dtf.mes)
    {
        return false;
    }
    else if (this->dia < dtf.dia)
    {
        return true;
    }
    else
    {
        return false;
    }
};
ostream& operator<<(ostream& os,DtFecha dtf){
    if (dtf.getdia() < 10)
        os<< "0" <<dtf.getdia() << "/";
    else
        os<< dtf.getdia()<< "/" ;

    if (dtf.getmes() < 10)
        os << "0"<<dtf.getmes() << "/";
    else os << dtf.getmes() << "/";

    os << dtf.getanio();
    return os;
};
DtFecha::~DtFecha()
{

};
