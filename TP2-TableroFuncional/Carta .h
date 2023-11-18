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
     * Pre: Un tipo de carta valido.
     * Pos: Devuelve una carta
     */
    explicit Carta(TipoCarta tipo);
    /*
     * Pre: La carta debe existir
     * Pos: Devuelve el tipo de carta
     */
    TipoCarta verCarta();
    /*
     * Pre: La carta debe existir
     * Pos: Destruye la carta
     */
    ~Carta();
};

#endif
