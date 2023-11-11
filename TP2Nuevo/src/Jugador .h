#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "Mazo .h"
#include "Ficha.h"

enum EstadoJugador{
    Activo,
    NoActivo
};

class Jugador{
private:
    int idJugador;
    Lista<Carta*>* cartasDelJugador;
    Lista<Ficha*>* fichas;
    EstadoJugador estado;

public:
	/*
	 * Pre: numero de jugador debe ser entero mayor a 0
	 * Pos: crea una instancia de jugador
	 */
    explicit Jugador(int numeroJugador);
	/*
	 * Pre:
	 * Pos: devuelve la cantidad de tesoros
	 */
	int devolverCantidadDeTesoros();
    /*
	 * Pre:
	 * Pos: devuelve la lista de fichas del jugador
	 */
    Lista<Ficha*>* obtenerFichasDelJugador();
    /*
	 * Pre:
	 * Pos: devuelve la lista de cartas del jugador
	 */
    Lista<Carta*>* obtenerCartasDelJugador();
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
    EstadoJugador getEstadoJugador();
    /*
     * Pre:
     * Pos:
     */
    void setEstadoJugador(EstadoJugador estadoJugador);
    /*
     * Pre:
     * Pos:
     */
    void obtenerCarta(Mazo* mazo);
    /*
     * Pre:
     * Pos: Destruye el jugador
     */
    ~Jugador();
};

#endif
