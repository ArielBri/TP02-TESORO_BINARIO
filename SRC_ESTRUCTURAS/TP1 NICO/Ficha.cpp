/*
 * Ficha.cpp
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#include "Ficha.h"

Ficha::Ficha(){
	this->jugador= 0;
	this->tipo= Vacia;
}

unsigned int Ficha::getJugador(){
	return this->jugador;
}

void Ficha::setJugador(unsigned int jugador){
	this->jugador= jugador;
}

TipoFicha Ficha::getTipo(){
	return this->tipo;
}

void Ficha::setTipo(TipoFicha tipo){
	this->tipo= tipo;
}

void Ficha::vaciarFichar(){
	this->jugador= 0;
	this->tipo= Vacia;
}

void Ficha::setJugadorTipo(unsigned int jugador, TipoFicha tipo){
	this->setJugador(jugador);
	this->setTipo(tipo);
}

Ficha::~Ficha() {
	// TODO Auto-generated destructor stub
}

