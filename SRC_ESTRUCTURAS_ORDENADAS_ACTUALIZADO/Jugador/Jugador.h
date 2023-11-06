#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "../Mazo/Mazo.h"

enum estadoJugador{
    noGano,
    gano,
};

class Jugador{
private:
    int idJugador;
    estadoJugador estado;
    Lista<Carta*>* cartasDelJugador;

public:
    Jugador(int numeroJugador);
    ~Jugador();
    int mostrarJugadorId();
    void obtenerCarta(Mazo* mazo);
    void jugarCarta(int posicion);
    int mostrarCartas();
    void validarCantCartas();
    bool ganoJuego();
};

#endif
