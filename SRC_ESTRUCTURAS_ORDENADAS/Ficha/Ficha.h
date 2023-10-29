/*
 * Ficha.h
 *
 *  Created on: 12/09/2023
 *      Author: algo2
 */

#ifndef FICHA_H_
#define FICHA_H_
#include <iostream>
#include "Jugador.h"

enum TipoFicha{
	Tesoro,
	Espia,
	TesoroMina,
	TesoroBlindado
};

class Ficha {

private:
	TipoFicha tipo;
	Jugador * jugador;
	int turnosRestantesBlindaje;

public:
	Ficha(TipoFicha tipo, Jugador* jugador);
	TipoFicha getTipo();
	void setTipo(TipoFicha tipo);
	Jugador* getJugador();
	void setJugador(Jugador* jugador);
	void blindarTesoro();
	void restarContadorBlindaje();
	virtual ~Ficha();
};

#endif /* FICHA_H_ */
