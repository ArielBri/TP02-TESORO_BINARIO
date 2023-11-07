#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "../Mazo/Mazo.h"
#include "../Ficha/Ficha.h"


class Jugador{
private:
    int idJugador;
    Lista<Carta*>* cartasDelJugador;
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
    Lista<Ficha*>* obtenerFichasDelJugador();

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
    void obtenerCarta(Mazo* mazo);
    void jugarCarta(int posicion);
    int mostrarCartas();
    void validarCantCartas();
    bool ganoJuego();
};

#endif
