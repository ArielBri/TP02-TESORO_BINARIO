/*
 * Ficha.h
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#ifndef FICHA_H_
#define FICHA_H_
#include <iostream>

enum TipoFicha{
	Tesoro,
	Espia,
	Vacia
};

class Ficha {

private:
	unsigned int jugador;
	TipoFicha tipo;

public:
	Ficha();
	unsigned int getJugador();
	void setJugador(unsigned int jugador);
	TipoFicha getTipo();
	void setTipo(TipoFicha tipo);
	void vaciarFichar();
	void setJugadorTipo(unsigned int jugador, TipoFicha tipo);
	virtual ~Ficha();
};

#endif /* FICHA_H_ */
