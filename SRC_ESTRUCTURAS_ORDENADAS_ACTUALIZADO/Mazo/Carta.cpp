#include "Carta.h"

Carta::Carta(TipoCarta tipo) {
    this->tipo = tipo;
}
void Carta::usarCarta() {
    switch (this->tipo) {
        case Blindaje:
            jugarBlindaje();
            break;
        case Radar:
            jugarRadar();
            break;
        case PartirTesoro:
            partirTesoro();
            break;
        case Espias2:
            jugarEspias2();
            break;
        case Bloqueo:
            jugarBloqueo();
            break;
        case Cartas2:
            jugarCartas2();
            break;
        default:
            throw std::runtime_error("No se encontró una carta");
    }
}


TipoCarta Carta::verCarta(){
    return this->tipo;
}


void jugarBlindaje(){
}
void jugarRadar(){

}
void partirTesoro(){

}
void jugarEspias2(){

}
void jugarBloqueo(){

}
void jugarCartas2(){

}


Carta::~Carta() {
}
