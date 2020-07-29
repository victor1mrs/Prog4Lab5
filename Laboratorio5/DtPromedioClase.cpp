#include "DtPromedioClase.h"


DtPromedioClase::DtPromedioClase(string n, int i, float p){
    nombre = n;
    id = i;
    promedio = p;
};

string DtPromedioClase::getnombre(){
    return nombre;
};

int DtPromedioClase::getid(){
    return id;
};
float DtPromedioClase::getpromedio(){
    return promedio;
};

ostream& operator<<(ostream& os,DtPromedioClase dtc){
    os << "-   Nombre de clase: " << dtc.getnombre() << endl;
	os << "-   Id de clase: " << dtc.getid() << endl;
	//float promEnSeg = dtc.getpromedio()*60;
	//int redond = (int)promEnSeg;
	//int redond2 = (int)dtc.getpromedio();
	int horas = dtc.getpromedio()/3600;
	int minutos = (dtc.getpromedio() - horas*3600)/60;
	int segundos = dtc.getpromedio() - (horas*3600 + minutos*60);
	os << "-   Promedio: " << horas << " horas,"<< minutos << " minutos," << segundos<<" segundos." <<endl;
	return os;
};


DtPromedioClase::~DtPromedioClase()
{
    //dtor
}
