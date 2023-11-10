#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "Mazo.h"
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
     * Pre: numero de jugador debe ser entero mayor a 0.
     * Pos: crea una instancia de jugador.
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
     * Pre: El parametro recibido debe ser mayor a 0.
     * Pos: Carga los tesoros al tablero de forma aleatoria
     */
    void inicializarTesoros(int cantidadDeTesoros);
    /*
     * Pre:
     * Pos: Devuelve el estado del jugador.
     */
    EstadoJugador getEstadoJugador();
    /*
     * Pre:
     * Pos: Cambia el estado del jugador.
     */
    void setEstadoJugador(EstadoJugador estadoJugador);
    /*
     * Pre:
     * Pos: Saca una carta del mazo y la agrega a la lista de cartas del jugador.
     */
    void obtenerCarta(Mazo* mazo);
    /*
     * Pre:
     * Pos: Destruye el jugador
     */
    ~Jugador();
};

#endif
