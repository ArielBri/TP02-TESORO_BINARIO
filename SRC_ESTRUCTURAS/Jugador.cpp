#include "Jugador.h"
#include <iostream>
Jugador::Jugador(int numeroDeJugador)
{
    this->idJugador=numeroDeJugador;
    this->cantCartasDelJugador=0;
    this->cartasDelJugador= new Lista<Carta*>();
}
Jugador::~Jugador(){
    delete []this->cartasDelJugador;
}
int Jugador::mostrarJugador(){
    return this->idJugador;
}
void Jugador::obtenerCarta(Mazo* mazo){
    this->cartasDelJugador->add(mazo->obtenerCarta());
}
void Jugador::mostrarCartas(){
    int posicion=0;
    this->cartasDelJugador->reiniciarCursor();
    while(this->cartasDelJugador->avanzarCursor()){
        Carta* carta= this->cartasDelJugador->getCursor();
        //cartaAMostrar= carta->mostrarCarta();
        std::cout<<"posicion - Carta"<<std::endl;
        posicion++;
    }
}
void Jugador::jugarCarta(int posicion){
    Carta* carta= this->cartasDelJugador->get(posicion);
    carta->usarCarta();
    this->cartasDelJugador->remover(posicion);
    }
