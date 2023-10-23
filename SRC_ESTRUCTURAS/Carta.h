#ifndef TP_2_CARTA_H
#define TP_2_CARTA_H

#include "Pila.h"
#include "Lista.h"

enum TipoCarta {
    Blindaje,
    Radar,
    PartirTesoro,
    Espias2,
    Bloqueo,
    Cartas2,
};


class Carta {
private:
    TipoCarta tipo;
public:
    explicit Carta(TipoCarta tipo);
    void usarCarta();
    ~Carta();
};

void jugarBlindaje();
void jugarRadar();
void partirTesoro();
void jugarEspias2();
void jugarBloqueo();
void jugarCartas2();

#endif
