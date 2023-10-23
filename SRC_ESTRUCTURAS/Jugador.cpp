#include "Jugador.h"

Jugador::Jugador() {

}


void Jugador::obtenerCarta(Mazo* mazo){
    this->cartasJugador->add(mazo->obtenerCarta());
}

void Jugador::jugarCarta(Carta *carta) {
    carta->usarCarta();
}



Jugador::~Jugador(){
    delete cartasJugador;
}