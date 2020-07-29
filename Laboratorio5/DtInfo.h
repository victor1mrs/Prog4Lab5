/*
 * DtInfo.h
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */



#include "DtFecha.h"
#include "DtHora.h"

#ifndef DTINFO_H_
#define DTINFO_H_

class DtInfo {
private:
	DtFecha fIni;
	DtFecha fFin;
	DtHora hIni;
	DtHora hFin;
public:
	DtInfo(DtFecha, DtFecha, DtHora, DtHora);
	DtFecha getfIni();
	DtFecha getfFin();
	DtHora gethIni();
	DtHora gethFin();
	void setFechaYHoraFinales(DtFecha, DtHora);
	~DtInfo();

	float calculoTiempoDtInfo();
};

#endif /* DTINFO_H_ */
