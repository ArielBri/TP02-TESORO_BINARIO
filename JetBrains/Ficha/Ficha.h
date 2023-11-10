#ifndef FICHA_H_
#define FICHA_H_

#include "../Coordenada/Coordenada.h"

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

    TipoFicha getTipo();

    /**
     * pre: -
     * pos: -
     */
    void setTipo(TipoFicha tipo);

    /**
     * pre: -
     * pos: devuelve un puntera a la coordenada de la ficha
     */
    Coordenada *getCoordenada();

    /**
     * pre: -
     * pos: -
     */
    void setCoordenada(Coordenada *coordenada);

    /**
     * pre: -
     * pos: -
     */
    int getJugadorId();

    /**
     * pre: -
     * pos: -
     */
    void setJugador(int jugador);

    /**
     * pre: -
     * pos: -
     */
    void blindarTesoro();

    /**
     * pre: -
     * pos: -
     */
    void restarContadorDeBlindaje();
    /**
     * pre: -
     * pos: -
     */
    virtual ~Ficha();
};

#endif