#ifndef FICHA_H_
#define FICHA_H_

#include "Coordenada.h"

enum TipoFicha{
    Tesoro,
    Espia,
    TesoroMina,
    TesoroBlindado
};

class Ficha {

private:
    TipoFicha tipo;
    Coordenada *coordenada;
    int idJugador;
    int turnosRestantesBlindaje;

public:
    /**
     * pre: -
     * pos: -
     */
    Ficha(TipoFicha tipo, int idJugador, Coordenada *coordenada);
    /**
     * pre: -
     * pos: Devuelve el tipo de ficha
     */
    TipoFicha getTipo();

    /**
     * pre: -
     * pos: cambia el tipo de ficha
     */
    void setTipo(TipoFicha tipo);

    /**
     * pre: -
     * pos: devuelve un puntera a la coordenada de la ficha
     */
    Coordenada *getCoordenada();

    /**
     * pre: -
     * pos: cambia la coordenada de la ficha
     */
    void setCoordenada(Coordenada *coordenada);

    /**
     * pre: -
     * pos: devuelve el id del jugador de la ficha
     */
    int getJugadorId();

    /**
     * pre: -
     * pos: cambia el jugador de la ficha
     */
    void setJugador(int jugador);

    /**
     * pre: -
     * pos: cambia el estado del tesoro a tesoro blindado y queda en ese estado 5 turnos
     */
    void blindarTesoro();

    /**
     * pre:
     * pos: restar la cantiddad de turnos que el tesoro este blindado, si es un teosoro blindado 
     */
    void restarContadorDeBlindaje();
    /**
     * pre: -
     * pos: elimina la referencia a la coordenada que contiene
     */
    virtual ~Ficha();
};

#endif
