#include "Ficha.h"

Ficha::Ficha(TipoFicha tipo, int idJugador, Coordenada* coordenada){
    this->tipo= tipo;
    this->idJugador = idJugador;
    this->turnosRestantesBlindaje=0;
    this->coordenada = coordenada;
}

TipoFicha Ficha::getTipo(){
    return this->tipo;
}

void Ficha::setTipo(TipoFicha tipoFicha){
    this->tipo=  tipoFicha;
}
int Ficha::getJugadorId(){
    return this->idJugador;
}

void Ficha::setJugador(int jugadorId){
    this->idJugador = jugadorId;
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


void Ficha::setCoordenada(Coordenada* coordenada){
    this->coordenada = coordenada;
}

Coordenada* Ficha::getCoordenada(){
    return this->coordenada;
}
Ficha::~Ficha() {
    delete this->coordenada;
}
