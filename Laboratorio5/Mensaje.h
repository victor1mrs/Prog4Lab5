#ifndef MENSAJE_H_
#define MENSAJE_H_

#include <set>
#include <map>

#include "DtFecha.h"
#include "DtHora.h"
#include "DtMensaje.h"
#include "Usuario.h"

using namespace std;


class Mensaje {

private:
	int id;
	string msj;
	DtFecha fMen;
	DtHora hMen;
	Usuario* usuario;
	map<int, Mensaje*> respuestas;
	int msjPadre;
public:
    Mensaje(int, string, DtFecha, DtHora, Usuario*);
	int getid();
	string getmsj();
	DtFecha getfMen();
	DtHora gethMen();
	Usuario* getusuario();
	map<int, Mensaje*> getrespuestas();
	int getmsjPadre();
    void setmsjPadre(int);

	void agregarMsj(Mensaje*);

	//ENVIO DE MENSAJE
	set<DtMensaje*> getListaDtRespuesta();
    DtMensaje* getMensaje();
    bool checkearUsuario(string);
    bool aplicaNotif(string, Mensaje*);

	~Mensaje();
};




#endif /* MENSAJE_H_ */
