#include "SRC_ESTRUCTURAS_ORDENADAS_ACTUALIZADO/SRC.h"


void determinarParametros(int &ancho, int &alto, int &largo, int cantidadDeJugadores, int cantidadDeTesoros){
    int cantidadDeCasillerosMinima = cantidadDeJugadores*cantidadDeTesoros;
    ancho = cantidadDeCasillerosMinima/2;
    alto = ancho;
    alto = cantidadDeJugadores;
}


int main() {
    int cantidadJugadores = 3, cantidadDeTesoros=3, alto = 5, largo = 5, ancho = 5;
    determinarParametros(ancho, alto, largo, cantidadDeJugadores, cantidadDeTesoros);
    TesoroBinario* tesoro;
    tesoro = new TesoroBinario(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
    tesoro->jugar();
    delete tesoro;
    return 0;
}
