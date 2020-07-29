
/*
 * InfoVisita.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef INFOVISITA_H_
#define INFOVISITA_H_


#include <set>
#include <string>
#include "DtInfo.h"
//#include "Usuario.h"


#include "DtInfo.h"
#include "Reloj.h"

#include <string>
#include "DtInfo.h"
#include "Reloj.h"


using namespace std;

class Clase;
//class Usuario;
class InfoVisita {
private:
	int id;
	set<DtInfo*> info;
	Clase* claseAsociada;
	string usuario;
public:
	InfoVisita(int id, Clase*);
	int getId();
	set<DtInfo*> getInfo();
	void agregarDtInfo(DtInfo*);
	Clase* getClaseAsociada();
	//Usuario* getUsuarioAsociado();
	//void setUsuarioAsociado(Usuario*);
	string getUsuarioAsociado();
	void setUsuarioAsociado(string);
	void terminarVisitas();



	~InfoVisita();

	float TiempoInfoVisita();
};

#endif /* INFOVISITA_H_ */
