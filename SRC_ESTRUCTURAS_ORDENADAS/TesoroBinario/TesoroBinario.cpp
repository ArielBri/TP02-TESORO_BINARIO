/*
 * TesoroBinario.cpp
 *
 *  Created on: 13/09/2023
 *      Author: algo2
 */

#include "TesoroBinario.h"


TesoroBinario::TesoroBinario() {
	this->tablero= new Tablero();

}

void TesoroBinario::jugar(){
	//Asumimos que el tablero ya esta creado y se puede usar

	//Comienza el juego
	while(this->noHayGanador()){
		this->listaDeJugadores->iniciarCursor();
		while(this->noHayGanador() && this->listaDeJugadores->avanzarCursor()){
			//Comienza turno
			this->jugadorActual= this->listaDeJugadores->obtenerCursor();
			this->mostrarTablero();//Metodo que puede estar dentro del TDA intefaz(en ese caso se ledeberia spar por parametro el tablero y el jugadorActual)
			//opcion A
			jugador  obtiene una carta del mazo();
			jugador  ve la opciones de cartas y elije si quiera usar();

			//Opcion B

			jugador pone un tesoro MINA;
			//Opcion C
			jugador pone un espia;{


			}

			//Opcion D

			jugador mueve tesoro;

			this->ponerEspia();
			if(this->quiereMoverTesoro()){
				this->moverTesoro();
			}
			this->exportarTablero();
			this->restarContadoresDeInactividad();
			this->cambiarTurnoDe();
		}
	}

	std::cout<<"Termino el juego"<<std::endl;

}



