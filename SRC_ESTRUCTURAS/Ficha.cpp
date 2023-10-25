#include "Ficha.h"

Ficha::Ficha(TipoDeFicha ficha, Jugador* jugador){
  this->ficha = ficha;
  this->jugador = jugador;
}

Ficha::~Ficha() {
	// TODO Auto-generated destructor stub
}

TipoDeFicha Ficha::getFicha(){
  return this->ficha;
}

Jugador* Ficha::getJugador(){
  return this->jugador;
}