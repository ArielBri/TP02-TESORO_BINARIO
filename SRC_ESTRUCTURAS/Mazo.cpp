#include "Mazo.h"


Mazo::Mazo(int cantidadDeCartas) {
    this->mazoDeCartas = new Pila<Carta*>;
}

Carta* Mazo::obtenerCarta() {
    if (this->mazoDeCartas == nullptr){
        return nullptr;
    }
    if (this->mazoDeCartas->vacia()){
        this->recargarMazo(this->cantidadDeCartas);
    }
    return this->mazoDeCartas->pop();
}


void Mazo::recargarMazo(int cantidadDeCartas){
    for(int i = 0; i<cantidadDeCartas; i++){

    }

}

Mazo::~Mazo() {
    delete mazoDeCartas;
}
