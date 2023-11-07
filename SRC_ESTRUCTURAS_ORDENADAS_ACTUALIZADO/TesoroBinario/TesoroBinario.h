#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include <iostream>
#include "../Tablero/Tablero.h"
#include "../Jugador/Jugador.h"
#include "../Lista/Lista.h"

class TesoroBinario {
private:
    Tablero * tablero;
    Lista <Jugador*>* listaDeJugadores;
    Jugador * jugadorActual;
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
    void colocarFicha(Jugador* jugador, Ficha* ficha);
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
    virtual ~TesoroBinario();
};


#endif
