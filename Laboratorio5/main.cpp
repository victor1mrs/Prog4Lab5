#include "Menu.h"
#include <iostream>


int main() {
    Menu * m = new Menu();
    bool seguir;
    do{
        try{
            seguir = m->mostrarmenu(); // Para hacer menu
        }catch (std::out_of_range& e) {
        	 cout<<"Ocurrio un error: "<<e.what()<<endl;
        	 seguir = true;
		}catch (std::invalid_argument& e) {
			cout<<"Ocurrio un error: "<<e.what()<<endl;
			seguir = true;
		}catch(exception& e) {
			cout<<"Ocurrio un error: "<<e.what()<<endl;
            seguir = true;
        }
    }while(seguir);

    delete m;

    return 0;
};
