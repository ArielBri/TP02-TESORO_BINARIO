#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include <iostream>
#include "../Tablero/Tablero.h"
#include "../Jugador/Jugador.h"


class TesoroBinario {
private:
    Tablero * tablero;
    Lista <Jugador*>* listaDeJugadores;
    Jugador * jugadorActual;
    Mazo * mazo;
    Lista<Jugador*>* crearListaDeJugadores(int cantidadDeJugadores);
public:
    //cantidadDeJugadores*CantidadTesoros<ancho*largo*alto
    TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores);
    void jugar();
    bool hayGanador();
    void mostrarTablero();
    void ponerEspia();
    bool quiereMoverTesoro();
    void moverTesoro();
    void colocarFicha(Jugador* jugador, TipoFicha ficha);
    void exportarTablero();
    void restarContadoresDeInactividad();
    void cambiarTurnoDe();
    bool jugadorTieneAlMenosUnTesoro(Jugador* jugadorActual);


    virtual ~TesoroBinario();
};


#endif