#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "../Mazo/Mazo.h"

class Jugador {
private:
    Lista<Carta*>* cartasJugador;
public:
    Jugador();
    void obtenerCarta(Mazo* mazo);
    void jugarCarta(Carta* carta);
    ~Jugador();

};


#endif
