/*
 * Practico.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#ifndef PRACTICO_H_
#define PRACTICO_H_

#include "Clase.h"

using namespace std;

class Practico: public Clase {
public:
	Practico(string n, int i, DtFecha fI, DtFecha fF, DtHora hI, DtHora hF, string u, string cod, string nomA);
	~Practico();
};

#endif /* PRACTICO_H_ */
