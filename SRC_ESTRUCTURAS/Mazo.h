#ifndef TP_2_MAZO_H
#define TP_2_MAZO_H

#include "Carta.h"

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
