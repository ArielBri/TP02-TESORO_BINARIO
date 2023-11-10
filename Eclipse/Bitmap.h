#ifndef TP_2_BITMAP_H
#define TP_2_BITMAP_H

#include "Tablero.h"
#include "Jugador.h"
#include "Lista.h"
#include "Casillero.h"


#include <iostream>
#include <sstream>
using namespace std;

class Bitmap {
private:

public:
    /*
     * Pre: El tablero debe existir.
     * Pos: Se muestra el tablero de un jugador.
     */
    void mostrarTablero(Tablero* tablero, Jugador* jugador);


    ~Bitmap();

};

#endif
