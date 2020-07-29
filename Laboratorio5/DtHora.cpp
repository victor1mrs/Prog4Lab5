#include "DtHora.h"

DtHora::DtHora()
{
	hora = -1;
	minuto = -1;
	segundo = -1;
};
DtHora::DtHora(int h,int m, int s)
{
	hora = h;
	minuto = m;
	segundo = s;
};
int DtHora::gethora() const
{
	return hora;
};
int DtHora::getminuto() const
{
	return minuto;
};
int DtHora::getsegundo() const
{
	return segundo;
};
bool DtHora::operator<(DtHora dth)
{
    if(this->hora < dth.hora)
    {
        return true;
    }
    else if (this->hora > dth.hora)
    {
        return false;
    }
    else if(this->minuto < dth.minuto)
    {
        return true;
    }
    else if(this->minuto > dth.minuto)
    {
        return false;
    }
    else
    {
        return false;
    }
};

ostream& operator<<(ostream& os,DtHora dth){
    //HORAS
    if(dth.gethora() == 0){
        os << "00:";
    }
    else if(dth.gethora() < 10){
        os <<"0" << dth.gethora() << ":";
    }
    else{
        os << dth.gethora() << ":";
    }
    //MINUTOS
    if(dth.getminuto() == 0){
        os << "00:";
    }
    else{
        if(dth.getminuto() < 10)
            os << "0" << dth.getminuto()<<":";
        else
            os << dth.getminuto()<<":";
    }
    //SEGUNDOS
    if(dth.getsegundo() == 0){
        os << "00";
    }
    else{
        if(dth.getsegundo() < 10)
            os << "0" << dth.getsegundo();
        else
            os << dth.getsegundo();
    }

    return os;
};
DtHora::~DtHora()
{

};
