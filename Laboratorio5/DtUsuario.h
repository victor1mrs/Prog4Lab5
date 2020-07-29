#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <string>
#include <iostream>



enum tipoDataUsuario  {TIPODOCENTE, TIPOESTUDIANTE, INDEFINIDO};


using namespace std;

class DtUsuario{
    private:
        string nombre;
        string email;
        string imagen;
        string pass;
        tipoDataUsuario tipo;
    public:
        DtUsuario(string nombre, string email, string imagen, string pass, tipoDataUsuario);
        DtUsuario(string nombre, string email, string imagen,  tipoDataUsuario);
       DtUsuario(string nombre,string email,string imagen);
        virtual ~DtUsuario();


        const tipoDataUsuario getTipo() const;
        void setTipo(tipoDataUsuario);

        string getNombre() const;
        string getEmail() const;
        string getImagen() const;
        string getPass() const;
        friend ostream& operator<<(ostream& os,DtUsuario dtc);

};

#endif // DTUSUARIO_H
