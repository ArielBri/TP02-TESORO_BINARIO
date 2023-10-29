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
#include "Mazo.h"
#include "Jugador.h"
#include "Lista.h"

class TesoroBinario {

private:

	Tablero * tablero;
	Lista <Jugador*>* listaDeJugadores;
	Jugador * jugadorActual;
	Mazo * mazo;

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
