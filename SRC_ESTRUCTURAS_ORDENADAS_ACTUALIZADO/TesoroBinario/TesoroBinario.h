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
public:
    TesoroBinario(int ancho, int alto, int largo, Lista <Jugador*>* listaJugadores);
    void jugar();
    bool noHayGanador();
    void mostrarTablero();
    void ponerEspia();
    bool quiereMoverTesoro();
    void moverTesoro();
    void colocarFicha(Jugador* jugador, TipoFicha ficha);
    void exportarTablero();
    void restarContadoresDeInactividad();
    void cambiarTurnoDe();
    virtual ~TesoroBinario();
};


#endif
