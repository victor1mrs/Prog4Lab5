/*
 * Teorico.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "Teorico.h"

Teorico::Teorico(string n, int i, DtFecha fI, DtFecha fF, DtHora hI, DtHora hF, string u, int cant, string cod, string nomA):Clase(n, i, fI, fF, hI, hF, u,cod, nomA) {
    cantAsistentes = cant;
};

int Teorico::getCantAsistentes(){
    return cantAsistentes;
};

void Teorico::setCantAsistentes(int c){
    cantAsistentes = c;
};

Teorico::~Teorico() {
	cantAsistentes=0;
};

