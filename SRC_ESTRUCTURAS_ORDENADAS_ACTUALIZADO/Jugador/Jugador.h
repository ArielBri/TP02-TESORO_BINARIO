#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "../Mazo/Mazo.h"



class Jugador{
private:
    int idJugador;
    Lista<Carta*>* cartasDelJugador;
public:
    Jugador(int numeroJugador, int cantidadDeTesoros);
    ~Jugador();
    int devolverJugadorId();
    void obtenerCarta(Mazo* mazo);
    void jugarCarta(int posicion);
    int mostrarCartas();
    void validarCantCartas();
    bool ganoJuego();
};

#endif