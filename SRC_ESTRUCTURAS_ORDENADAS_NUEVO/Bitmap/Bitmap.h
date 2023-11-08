#ifndef TP_2_BITMAP_H
#define TP_2_BITMAP_H

#include "../Tablero/Tablero.h"
#include "../Jugador/Jugador.h"

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
    /*
     * Pre:
     * Pos:
     */
    ~Bitmap();
};


#endif //TP_2_BITMAP_H
