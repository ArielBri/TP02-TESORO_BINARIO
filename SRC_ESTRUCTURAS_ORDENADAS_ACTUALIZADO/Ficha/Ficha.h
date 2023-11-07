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
    Coordenada* coordenada;
    int  idJugador;
    int turnosRestantesBlindaje;

public:
    Ficha(TipoFicha tipo, int idJugador, Coordenada* coordenada);
    TipoFicha getTipo();
    void setTipo(TipoFicha tipo);

    Coordenada* getCoordenada();

    void setCoordenada(Coordenada* coordenada);

    int getJugadorId();
    void setJugador(int jugador);



    void blindarTesoro();
    void restarContadorBlindaje();
    virtual ~Ficha();
};

#endif