#include "Mazo .h"


Mazo::Mazo() {
    this->valor = 3;
}


Carta* Mazo::obtenerCarta() {
    TipoCarta tipo;
    int numero = 0;
    for(int  i = 0; i< this->valor; i++){
        numero = (rand()%6);
    }
    if(this->valor==10){
        this->valor = 3;
    }
    switch (numero) {
        case 0:
            tipo = Blindaje;
            break;
        case 1:
            tipo = Radar;
            break;
        case 2:
            tipo = PartirTesoro;
            break;
        case 3:
            tipo = MostrarEspiasDeJugadorActivo;
            break;
        case 4:
            tipo =  ObtenerCartas4;
            break;
        case 5:
            tipo = Espias2;
    }
    this->valor++;
    return new Carta(tipo);
}


Mazo::~Mazo() {
}
