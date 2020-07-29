#ifndef DTTIEMPOASIGNATURA_H_
#define DTTIEMPOASIGNATURA_H_

#include <string>
#include <iostream>

using namespace std;

class DtTiempoAsignatura {

private:
	string id;
	string nombre;
	int tiempo;
public:
	DtTiempoAsignatura(string, string, int);
	string getid();
	string getnombre();
	int gettiempo();
	friend ostream& operator<<(ostream& os,DtTiempoAsignatura dtc);

	DtTiempoAsignatura(string, string);
	void setTiempo(int);

	~DtTiempoAsignatura();
};

#endif /* DTTIEMPOASIGNATURA_H_ */

