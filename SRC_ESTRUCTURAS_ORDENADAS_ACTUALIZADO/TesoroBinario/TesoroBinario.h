#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include <iostream>
#include "../Tablero/Tablero.h"
#include "../Jugador/Jugador.h"
#include "../Lista/Lista.h"
#include "../Consola/Consola.h"

class TesoroBinario {
private:
    Tablero * tablero;
    Lista <Jugador*>* listaDeJugadores;
    Jugador * jugadorActual;
    Consola * consola;
    Mazo * mazo;

    int cantidadDeTesorosInicial;
    void crearListaDeJugadores(int cantidadDeJugadores, int cantidadDeTesoros);

public:
    /*
    * Pre:
    * Pos:
    */
    TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores, int cantidadDeTesoros);
    /*
     * Pre:
     * Pos:
     */
    void jugar();
    /*
     * Pre:
     * Pos:
     */
    void inicializarJuego();
    /*
    * Pre:
    * Pos:
    */
    bool hayGanador();
    /*
     * Pre:
     * Pos:
     */
    void mostrarTablero();
    /*
     * Pre:
     * Pos:
     */
    void ponerEspia();
    /*
     * Pre:
     * Pos:
     */
    bool quiereMoverTesoro();
    /*
     * Pre:
     * Pos:
     */
    void moverTesoro();
    /*
     * Pre:
     * Pos:
     */
    void colocarFicha(Ficha* ficha);
    /*
    * Pre:
    * Pos:
    */
    void ejecutarTurno();
    /*
     * Pre:
     * Pos:
     */
    void borrarJugadoresQuePerdieron();
    /*
     * Pre:
     * Pos:
     */
    void limpiarCasillerosQueContenganLasFichasDelJugador(Lista<Ficha*>* fichas);
    /*
     * Pre:
     * Pos:
     */
    void exportarTablero();
    /*
     * Pre:
     * Pos:
     */
    void restarContadoresDeInactividad();
    /*
     * Pre:
     * Pos:
     */
    bool jugadorTieneAlMenosUnTesoro();
    /*
    * Pre:
    * Pos:
    */
    void eliminarFichas(Jugador* jugador);
    /*
    * Pre:
    * Pos:
    */

    void usarCarta(Carta* carta);

    virtual ~TesoroBinario();
};


#endif
