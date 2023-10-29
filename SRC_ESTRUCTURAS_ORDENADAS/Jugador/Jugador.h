#ifndef TP_2_JUGADOR_H
#define TP_2_JUGADOR_H

#include "../Mazo/Mazo.h"

class Jugador{
    private:
        int idJugador;
        Lista<Carta*>* cartasDelJugador;
        int cantCartasDelJugador;
    public:
        Jugador(int numeroJugador);
        ~Jugador();
        int mostrarJugador();
        void obtenerCarta(Mazo* mazo);
        void jugarCarta(int posicion);
        void mostrarCartas();
        void validarCantCartas();
    }; 

#endif
