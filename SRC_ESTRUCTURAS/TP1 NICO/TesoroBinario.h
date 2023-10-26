/*
 * TesoroBinario.h
 *
 *  Created on: 13/09/2023
 *      Author: algo2
 */

#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include "Tablero.h"
#include <iostream>
#include <fstream>

class TesoroBinario {

private:

	Tablero * tablero;
	unsigned int turnoDeJugador;

public:
	TesoroBinario();
	void jugar();
	bool noHayGanador();
	void mostrarTablero();
	void ponerEspia();
	bool quiereMoverTesoro();
	void moverTesoro();
	void exportarTablero();
	void restarContadoresDeInactividad();
	void cambiarTurnoDe();
	virtual ~TesoroBinario();
};


#endif /* TESOROBINARIO_H_ */
