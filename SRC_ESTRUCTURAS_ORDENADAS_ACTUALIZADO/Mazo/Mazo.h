#ifndef TP_2_MAZO_H
#define TP_2_MAZO_H

#include "Carta.h"
#include "Carta.cpp"

int cantidadDeJugadores=10;
const int CANTIDAD_DE_CARTAS_INICIAL=6*cantidadDeJugadores;


class Mazo {
private:
    Pila<Carta*>* mazoDeCartas;
    int cantidadDeCartas;
    /*
     * Pre:
     * Pos:
     */
    void recargarMazo(int cantidadDeCartas);
public:
    /*
     * Pre:
     * Pos:
     */
    explicit Mazo(int cantidadDeCartas);
    /*
     * Pre:
     * Pos: obtenerCarta devuelve una carta del mazo
     */
    Carta* obtenerCarta();
    /*
     * Pre:
     * Pos: obtenerCarta devuelve una carta del mazo
     */
    ~Mazo();
};



#endif
