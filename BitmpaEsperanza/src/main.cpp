#include "Lista.h"
#include "Tablero.h"
#include "Casillero.h"
#include "Coordenada.h"
#include "Bitmap.h"
#include "Jugador.h"
#include "Ficha.h"
#include "bitmap_image.hpp"
#include <iostream>

int main() {
    try {
        // Crear instancias de Tablero y Jugador
        Tablero * tablero = new Tablero(3, 5, 4);
        Jugador * jugador1 = new Jugador(1);
        /*std::cout << fichaJugador1->getTipo() << std::endl;
        std::cout << casilleroJugador1->getEstado() << std::endl;*/

        /*Jugador * jugador2 = new Jugador(2);
        Ficha fichaJugador2(Espia, 2);
        Casillero* casilleroJugador2 = tablero.getCasillero(4, 4, 4);
        casilleroJugador2->setFicha(&fichaJugador2);*/

        Bitmap bitmap;
        bitmap.mostrarTablero(tablero, jugador1);

        // Crea las imágenes del tablero en los planos XY, XZ y YZ
        std::cout << "Tablero generado y las imagenes se han creado con exito." << std::endl;
    
    } catch (const char* errorMessage) {
        std::cerr << "Error: " << errorMessage << std::endl;
    }
    return 0;
}
