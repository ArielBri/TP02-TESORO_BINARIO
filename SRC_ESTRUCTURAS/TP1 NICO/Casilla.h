/*
 * Casilla.h
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#ifndef CASILLA_H_
#define CASILLA_H_
#include "Ficha.h"
#include <iostream>

enum EstadoCasilla{
	Activa,
	Inactiva
};

class Casilla {

private:
	EstadoCasilla estado;
	Ficha *ficha;
	unsigned int turnosRestantesInactiva;
	unsigned int x;
	unsigned int y;

public:
	Casilla();
	EstadoCasilla getEstado();
	void ponerInactiva();
	void restarUnoACantididadDeTurnosInactiva();
	Ficha* getFicha();
	void setX(unsigned int x);
	void setY(unsigned int y);
	unsigned int getX();
	unsigned int getY();
	virtual ~Casilla();
};

#endif /* CASILLA_H_ */
