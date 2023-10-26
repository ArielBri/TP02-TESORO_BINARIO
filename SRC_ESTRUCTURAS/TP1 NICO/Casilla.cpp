/*
 * Casilla.cpp
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#include "Casilla.h"


Casilla::Casilla(){
	this->estado= Activa;
	this->ficha= new Ficha();
	this->turnosRestantesInactiva= 0;
	this->x= 0;
	this->y= 0;
}

EstadoCasilla Casilla::getEstado(){
	return this->estado;
}
void Casilla::ponerInactiva(){
	this->estado= Inactiva;
	this->turnosRestantesInactiva= 5;
}

void Casilla::restarUnoACantididadDeTurnosInactiva(){
	this->turnosRestantesInactiva -= 1;
	if(this->turnosRestantesInactiva == 0){
		this->estado= Activa;
	}
}

void Casilla::setX(unsigned int x){
	this->x= x;
}
void Casilla::setY(unsigned int y){
	this->y= y;
}
unsigned int Casilla::getX(){
	return this->x;
}
unsigned int Casilla::getY(){
	return this->y;
}

Ficha * Casilla::getFicha(){
	return this->ficha;
}

Casilla::~Casilla() {
	delete this->ficha;
}

