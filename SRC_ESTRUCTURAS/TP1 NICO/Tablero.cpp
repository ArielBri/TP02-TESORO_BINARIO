/*
 * Tablero.cpp
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#include "Tablero.h"


Tablero::Tablero(){
	this->x=20;
	this->y=20;
	this->tablero= new Casilla **[x];

	for(unsigned int i=0; i<this->x; i++){
		this->tablero[i]= new Casilla*[this->y];
		for(unsigned  int j=0; j<this->y; j++){
			this->tablero[i][j]= new Casilla();
		}
	}

	this->tablero[0][1]->getFicha()->setJugadorTipo(1,Tesoro);
	this->tablero[0][2]->getFicha()->setJugadorTipo(1,Tesoro);
	this->tablero[0][3]->getFicha()->setJugadorTipo(1,Tesoro);
	this->tablero[0][4]->getFicha()->setJugadorTipo(1,Tesoro);

	this->tablero[1][0]->getFicha()->setJugadorTipo(2,Tesoro);
	this->tablero[2][0]->getFicha()->setJugadorTipo(2,Tesoro);
	this->tablero[3][0]->getFicha()->setJugadorTipo(2,Tesoro);
	this->tablero[4][0]->getFicha()->setJugadorTipo(2,Tesoro);


}

int Tablero::getX(){
	return this->x;
}
int Tablero::getY(){
	return this->y;
}
Casilla * Tablero::getCasilla(unsigned int x, unsigned int y){
	return this->tablero[x][y];
}

Tablero::~Tablero() {
	for(unsigned int i=0; i<this->x; i++){
		for(unsigned  int j=0; j<this->y; j++){
					delete this->tablero[i][j];
		}
		delete [] this->tablero[i];
	}
	delete [] this->tablero;
}

