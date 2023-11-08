#include "SRC_ESTRUCTURAS_ORDENADAS_ACTUALIZADO/SRC.h"


void determinarParametros(int &ancho, int &alto, int &largo, int cantidadDeJugadores, int cantidadDeTesoros){
    int cantidadDeCasillerosMinima = cantidadDeJugadores*cantidadDeTesoros;
    ancho = cantidadDeCasillerosMinima/2;
    alto = ancho;
    alto = cantidadDeJugadores;
}


int main() {
    /*
    int cantidadJugadores = 3, cantidadDeTesoros=3, alto, largo, ancho;


    determinarParametros(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
    TesoroBinario* tesoro;
    tesoro = new TesoroBinario(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
    tesoro->jugar();
    delete tesoro;
    */


    Consola* consola;
    consola = new Consola();
    Lista<Carta*>* listaCartas = new Lista<Carta*>;
    Carta* carta1;
    Carta* carta2;
    Carta* carta3;
    carta1 = new Carta(Blindaje);
    carta2 = new Carta(Radar);
    carta3 = new Carta(Bloqueo);
    listaCartas->add(carta1);
    listaCartas->add(carta2);
    listaCartas->add(carta3);
    consola->mostrarCartas(listaCartas);
    delete consola;
    delete listaCartas;
    delete carta1;
    delete carta2;
    delete carta3;
    return 0;
}
