#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "../Mazo/Mazo.h"



class Jugador{
private:
    int idJugador;
    int cantidadDeTesoros;
    Lista<Carta*>* cartasDelJugador;
public:
	/*
	 * Pre: numero de jugador y cantidad de tesoros debe ser entero mayor a 0
	 * Pos: crea una instancia de jugador
	 */
    Jugador(int numeroJugador, int cantidadDeTesoros);
    ~Jugador();
	/*
	 * Pre:
	 * Pos: devuelve la cantidad de tesoros
	 */
	int devolverCantidadDeTesoros();

	/*
	 * Pre:
	 * Pos: devuelve el numero de jugador
	 */
    int devolverJugadorId();
    void obtenerCarta(Mazo* mazo);
    void jugarCarta(int posicion);
    int mostrarCartas();
    void validarCantCartas();
    bool ganoJuego();
};

#endif
