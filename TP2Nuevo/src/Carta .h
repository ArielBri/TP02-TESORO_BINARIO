#ifndef TP_2_CARTA_H
#define TP_2_CARTA_H


#include "Lista.h"

enum TipoCarta {
    Blindaje,
    Radar,
    PartirTesoro,
    MostrarEspiasDeJugadorActivo,
    ObtenerCartas4,
    Espias2
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

#endif
