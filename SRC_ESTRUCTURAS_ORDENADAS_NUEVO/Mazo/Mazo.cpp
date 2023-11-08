#include "Mazo.h"


Mazo::Mazo(int cantidadDeCartas) {
    this->mazoDeCartas = new Pila<Carta*>;
    this->cantidadDeCartas = 0;
    this->recargarMazo(cantidadDeCartas);
}

Carta* Mazo::obtenerCarta() {
    if (this->mazoDeCartas->vacia()){
        this->recargarMazo(CANTIDAD_DE_CARTAS_INICIAL);
    }
    this->cantidadDeCartas--;
    return this->mazoDeCartas->pop();
}


void Mazo::recargarMazo(int cantidadDeCartasNueva) {

    Carta* cartas[cantidadDeCartasNueva];

    for (int i = 0; i < cantidadDeCartasNueva; i++) {
        auto tipo = static_cast<TipoCarta>(rand() % 6);
        cartas[i] = new Carta(tipo);
    }

    while (cantidadDeCartas<cantidadDeCartasNueva){
        mazoDeCartas->push(cartas[cantidadDeCartas]);
        cantidadDeCartas++;
    }
}


Mazo::~Mazo() {
    delete mazoDeCartas;
}
