#include "SRC_ESTRUCTURAS/SRC.h"

int main() {
    Lista<int> miLista;
    Pila<int> miPila;
    if(miLista.vacia()){
        std::cout<<"La lista no esta Vacia"<<std::endl;
    }
    if(miPila.vacia()){
        std::cout<<"Mi pila esta vacia"<<std::endl;
    }
    miPila.push(55);
    if(!miPila.vacia()){
        std::cout<<"mi Pila no esta vacia, hay un "<<miPila.tope()<<std::endl;
    }
    miPila.push(21);
    if(!miPila.vacia()){
        std::cout<<"mi Pila no esta vacia, hay un "<<miPila.tope()<<std::endl;
    }
    miPila.push(73);
    if(!miPila.vacia()){
        std::cout<<"mi Pila no esta vacia, hay un "<<miPila.tope()<<std::endl;
    }
    miPila.pop();
    if(!miPila.vacia()){
        std::cout<<"mi Pila no esta vacia, hay un "<<miPila.tope()<<std::endl;
    }
    std::cout<<"hola"<<std::endl;
    miPila.pop();
    if(!miPila.vacia()){
        std::cout<<"mi Pila no esta vacia, hay un "<<miPila.tope()<<std::endl;
    }
    miPila.pop();
    if(miPila.vacia()){
        std::cout<<"Mi pila esta vacia"<<std::endl;
    }
    miPila.push(44);
    if(!miPila.vacia()){
        std::cout<<"mi Pila no esta vacia, hay un "<<miPila.tope()<<std::endl;
    }
    miPila.pop();
    return 0;
}
