#include "Carta.h"

Carta::Carta(TipoCarta tipo) {
    this->tipo = tipo;
}


TipoCarta Carta::verCarta(){
    return this->tipo;
}



Carta::~Carta() {

}
