#include "DtUsuario.h"




DtUsuario::DtUsuario(string nombre, string email, string imagen,string pass, tipoDataUsuario tipo){
    this->nombre=nombre;
    this->email=email;
    this->imagen=imagen;
    this->pass=pass;
    this->tipo=tipo;
}


DtUsuario::DtUsuario(string nombre,string email,string imagen, tipoDataUsuario td){
	 this->nombre=nombre;
	 this->email=email;
	 this->imagen=imagen;
	 this->tipo=td;
}

DtUsuario::DtUsuario(string nombre,string email,string imagen){
	this->nombre=nombre;
	this->email=email;
	this->imagen=imagen;
}

 string DtUsuario::getNombre() const{
    return nombre;
};

 string DtUsuario::getEmail() const{
    return email;
};

 string DtUsuario::getImagen() const{
    return imagen;
};

 string DtUsuario::getPass() const{
    return pass;
}


ostream& operator<<(ostream& os,DtUsuario dtc){
    os << "-   Nombre: " << dtc.getNombre() << endl;
	os << "-   Email: " << dtc.getEmail() << endl;
	os << "-   Imagen: " << dtc.getImagen() << endl;
    return os;
};



const tipoDataUsuario DtUsuario::getTipo() const{
	return this->tipo;
}

void DtUsuario::setTipo(tipoDataUsuario tipo){
	this->tipo=tipo;
};

DtUsuario::~DtUsuario()
{
    //dtor
}
