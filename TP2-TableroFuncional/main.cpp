#include "TesoroBinario.h"
#include <iostream>

	/*
	 * Pre: los parámentros deben ser positivos
	 * Pos: Establece las dimensiones que tendra el tablero
	 */
	void determinarParametros(int &ancho, int &alto, int &largo, int cantidadDeJugadores, int cantidadDeTesoros){
	    int cantidadDeCasillerosMinima = cantidadDeJugadores*cantidadDeTesoros;
	    if (cantidadDeCasillerosMinima==2){
	        ancho=cantidadDeCasillerosMinima*2;
	        alto = ancho;
	        largo = cantidadDeJugadores*2;
	    } else{
	        ancho = cantidadDeCasillerosMinima/2;
	        if(cantidadDeJugadores%2!=0){
	            ancho++;
	        }
	        alto = ancho;
	        largo = cantidadDeJugadores;
	    }

	}

	/*
	 * Pos: Devuelve una cantidad de jugadores valida
	 */
int solicitarCantidadDeJugadores() {
	int cantidadDeJugadores;
	 std::cout << "Ingrese la cantidad de jugadores: ";
	 std::cin >> cantidadDeJugadores;
	    while(cantidadDeJugadores<2){
	        std::cout << "La cantidad de jugadores debe ser mayor o igual a 2.\nIngrese la cantidad de jugadores: ";
	        std::cin >> cantidadDeJugadores;
	    }
	    return cantidadDeJugadores;
	}
	/*
	 * Pos: Devuelve una cantidad de tesoros valida.
	 */
	int solicitarCantidadDeTesoros() {
	    int cantidadDeTesoros;
	    std::cout << "Ingrese la cantidad de tesoros: ";
	    std::cin >> cantidadDeTesoros;
	    while(cantidadDeTesoros<1){
	        std::cout << "La cantidad de tesoros debe ser mayor a 0.\nIngrese la cantidad de tesoros: ";
	        std::cin >> cantidadDeTesoros;
	    }
	    return cantidadDeTesoros;
	}

	int main() {
	    int cantidadJugadores, cantidadDeTesoros, alto, largo, ancho;
	    TesoroBinario* tesoro;
	    cantidadJugadores = solicitarCantidadDeJugadores();
	    cantidadDeTesoros = solicitarCantidadDeTesoros();
	    determinarParametros(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
	    tesoro = new TesoroBinario(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
	    tesoro->jugar();
	    delete tesoro;
		  std::cout<<0;
	    return 0;
	}
