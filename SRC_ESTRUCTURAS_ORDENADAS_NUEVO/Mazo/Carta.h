#ifndef TP_2_CARTA_H
#define TP_2_CARTA_H

#include "../Pila/Pila.h"
#include "../Lista/Lista.h"

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
    /*
     * Pre:
     * Pos:
     */
    explicit Carta(TipoCarta tipo);
    /*
     * Pre:
     * Pos:
     */
    TipoCarta verCarta();
    /*
     * Pre:
     * Pos:
     */
    ~Carta();
};

void jugarBlindaje();
void jugarRadar();
void partirTesoro();
void jugarEspias2();
void jugarBloqueo();
void jugarCartas2();

#endif
