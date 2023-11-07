#ifndef TP_2_MAZO_H
#define TP_2_MAZO_H

#include "Carta.h"

#include <cstdlib>

//int cantidadDeJugadores=10;
const int CANTIDAD_DE_CARTAS_INICIAL=60;
class Mazo {
private:
    Pila<Carta*>* mazoDeCartas;
    int cantidadDeCartas;
    void recargarMazo(int cantidadDeCartas);
public:
    explicit Mazo(int cantidadDeCartas);
    // obtenerCarta devuelve una carta del mazo
    Carta* obtenerCarta();
    ~Mazo();
};



#endif
