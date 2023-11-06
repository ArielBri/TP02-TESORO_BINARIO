#include "Ficha.h"

Ficha::Ficha(TipoFicha tipo, Jugador* jugador){
    this->tipo= tipo;
    this->jugador= jugador;
    this->turnosRestantesBlindaje=0;
}

TipoFicha Ficha::getTipo(){
    return this->tipo;
}

void Ficha::setTipo(TipoFicha tipoFicha){
    this->tipo=  tipoFicha;
}
Jugador* Ficha::getJugador(){
    return this->jugador;
}
void Ficha::setJugador(Jugador* jugadorSet){
    this->jugador = jugadorSet;
}
void Ficha::blindarTesoro(){
    this->tipo= TesoroBlindado;
    this->turnosRestantesBlindaje= 5;
}

void Ficha::restarContadorBlindaje(){
    this->turnosRestantesBlindaje -=1;
    if(this->turnosRestantesBlindaje== 0){
        this->tipo= Tesoro;
    }
}

Ficha::~Ficha() {

}
