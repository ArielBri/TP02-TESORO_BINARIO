#ifndef TP_2_BITMAP_H
#define TP_2_BITMAP_H



#include <iostream>
#include <sstream>
using namespace std;

class Bitmap {
private:

public:
    /*
     * Pre:
     * Pos:
     */
    Bitmap();
    /*
     * Pre: El tablero debe existir.
     * Pos: Se muestra el tablero de un jugador.
     */
    void mostrarTablero(Tablero* tablero, Jugador* jugador);

};

#endif /*TP_2_BITMAP_H*/
