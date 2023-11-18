#ifndef TP_2_MAZO_H
#define TP_2_MAZO_H

#include "Carta .h"
#include <cstdlib>


const int CANTIDAD_DE_CARTAS_INICIAL=3;


class Mazo {
private:
    int valor;
public:
    /*
     * Pre:
     * Pos: crea el mazo
     */
    Mazo();
    /*
     * Pre:
     * Pos: obtenerCarta devuelve una carta del mazo
     */
    Carta* obtenerCarta();
    /*
     * Pre:
     * Pos: Destruye el mazo
     */
    ~Mazo();
};



#endif
