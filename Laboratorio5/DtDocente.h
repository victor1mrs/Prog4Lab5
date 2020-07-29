


#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include <string>
#include <iostream>

#include "DtUsuario.h"

using namespace std;

class DtDocente : public DtUsuario{

        private:
            string instituto;

        public:
            DtDocente(string nombre, string email, string img);
            DtDocente(string nombre, string email, string imagen, string instituto, tipoDataUsuario);
            DtDocente(string nombre, string email, string imagen, string pass, string instituto, tipoDataUsuario);
            ~DtDocente();
           // friend ostream& operator<<(ostream& os,DtDocente dtc);
            string getInstituto() const;

};

#endif // DTDOCENTE_H

/*#ifndef DTDOCENTE_H
#define DTDOCENTE_H

#include <string>
#include <iostream>

#include "DtUsuario.h"

using namespace std;

class DtDocente : public DtUsuario{

        private:
            string instituto;

        public:
            DtDocente(string instituto, string nombre, string email, string imagen);
            DtDocente(string instituto, string nombre, string email, string imagen, tipoDataUsuario);
            DtDocente(string instituto, string nombre, string email, string imagen, string pass);

            virtual ~DtDocente();
            //~DtDocente();

            DtDocente(string nombre, string email, string imagen, string instituto);
            DtDocente(string nombre, string email, string imagen, string pass, string instituto);
            ~DtDocente();
            friend ostream& operator<<(ostream& os,DtDocente dtc);

            string getInstituto() const;

};

#endif // DTDOCENTE_H*/
