/*
 * Tablero.h
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casilla.h"
#include <iostream>


class Tablero {

private:
	unsigned int x;
	unsigned int y;
	Casilla ***tablero;

public:
	Tablero();
	int getX();
	int getY();
	Casilla * getCasilla(unsigned int x, unsigned int y);

	virtual ~Tablero();
};


#endif /* TABLERO_H_ */


