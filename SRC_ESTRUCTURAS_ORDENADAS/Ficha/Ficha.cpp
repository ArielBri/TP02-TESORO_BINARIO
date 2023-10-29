/*
 * Ficha.cpp
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#include "Ficha.h"

Ficha::Ficha(TipoFicha tipo, Jugador* jugador){
	this->tipo= tipo;
	this->jugador= jugador;
	this->turnosRestantesBlindaje=0;
}

TipoFicha Ficha::getTipo(){
	return this->tipo;
}

void Ficha::setTipo(TipoFicha tipo){
	this->tipo= tipo;
}
Jugador* Ficha::getJugador(){
	return this->jugador;
}
void Ficha::setJugador(Jugador* jugador){
	this->jugador= jugador;
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
