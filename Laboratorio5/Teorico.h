/*
 * Teorico.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef TEORICO_H_
#define TEORICO_H_


#include "Clase.h"

using namespace std;

class Teorico: public Clase {

private:
	int cantAsistentes;

public:
	Teorico(string n, int i, DtFecha fI, DtFecha fF, DtHora hI, DtHora hF, string u, int cantAsistentes, string cod, string nomA);
	int getCantAsistentes();
    void setCantAsistentes(int);

	~Teorico();
};

#endif /* TEORICO_H_ */
