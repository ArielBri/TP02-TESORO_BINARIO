#include "TesoroBinario.h"

/*
 * Pre:
 * Pos:
 */
void determinarParametros(int &ancho, int &alto, int &largo, int cantidadDeJugadores, int cantidadDeTesoros){
    int cantidadDeCasillerosMinima = cantidadDeJugadores*cantidadDeTesoros;

    ancho = cantidadDeCasillerosMinima/2;
    if(cantidadDeJugadores%2!=0){
        ancho++;
    }
    alto = ancho;
    largo = cantidadDeJugadores;
}


/*
 * Pre:
 * Pos:
 */
int solicitarCantidadDeJugadores() {
    int cantidadDeJugadores;
    std::cout << "Ingrese la cantidad de jugadores: ";
    std::cin >> cantidadDeJugadores;
    return cantidadDeJugadores;
}
/*
 * Pre:
 * Pos:
 */
int solicitarCantidadDeTesoros() {
    int cantidadDeTesoros;
    std::cout << "Ingrese la cantidad de tesoros: ";
    std::cin >> cantidadDeTesoros;
    return cantidadDeTesoros;
}




int main() {

    TesoroBinario* tesoro;
    tesoro = new TesoroBinario();
    tesoro->jugar();
    delete tesoro;

    return 0;
}
