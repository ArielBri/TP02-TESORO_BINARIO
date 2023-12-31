#ifndef JUGADOR_H
#define JUGADOR_H

#include "Ficha.h"
#include "Lista.h"

// enum estadoJugador

class Jugador{
private:
    int idJugador;
    //Lista<Carta*>* cartasDelJugador;
    Lista<Ficha*>* fichas;

public:
	/*
	 * Pre: numero de jugador y cantidad de tesoros debe ser entero mayor a 0
	 * Pos: crea una instancia de jugador
	 */
    explicit Jugador(int numeroJugador);
	/*
	 * Pre:
	 * Pos: devuelve la cantidad de tesoros
	 */
	//int devolverCantidadDeTesoros();
    /*
	 * Pre:
	 * Pos: devuelve la lista de fichas del jugador
	 */
    Lista<Ficha*>* obtenerFichasDelJugador();
    /*
	 * Pre:
	 * Pos: devuelve la lista de cartas del jugador
	 */
    //Lista<Carta*>* obtenerCartasDelJugador();
	/*
	 * Pre:
	 * Pos: devuelve el numero de jugador
	 */
    int devolverJugadorId();
    /*
    * Pre:
    * Pos:
    */
    void inicializarTesoros(int cantidadDeTesoros);

    /*
    * Pre:
    * Pos:
    */
    //void obtenerCarta(Mazo* mazo);
    /*
    * Pre:
    * Pos: Destruye el jugador
    */
    ~Jugador();
};

#endif