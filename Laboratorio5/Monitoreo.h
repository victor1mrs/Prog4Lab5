#ifndef MONITOREO_H_
#define MONITOREO_H_

#include "stdio.h"
#include "Clase.h"
using namespace std;


class Estudiante;

class Monitoreo: public Clase {
private:
	map<string, Estudiante*> estudiantes;//controlar [1..15]
public:
	Monitoreo(string n, int i, DtFecha fI, DtFecha fF, DtHora hI, DtHora hF, string u, string cod, string nomA);

	void agregarEstudiante(Estudiante*);
	map<string, Estudiante*> getEstudiantes();

	~Monitoreo();
};
#include "Estudiante.h"

#endif /* MONITOREO_H_ */
