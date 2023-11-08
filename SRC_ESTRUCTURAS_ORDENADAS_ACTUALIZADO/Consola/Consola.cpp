#include "Consola.h"



unsigned int Consola::solicitarCantidadDeJugadores() {
    int cantidadDeJugadores;
    std::cout << "Ingrese la cantidad de jugadores: ";
    std::cin >> cantidadDeJugadores;
    return cantidadDeJugadores;
}

unsigned int Consola::solicitarCantidadDeTesoros() {
    int cantidadDeTesoros;
    std::cout << "Ingrese la cantidad de tesoros: ";
    std::cin >> cantidadDeTesoros;
    return cantidadDeTesoros;
}