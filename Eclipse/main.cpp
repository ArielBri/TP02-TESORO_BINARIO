#include "TesoroBinario.h"

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
int solicitarCantidadDeJugadores(Consola* consola) {
    int cantidadDeJugadores;
    std::cout << "Ingrese la cantidad de jugadores: ";
    std::cin >> cantidadDeJugadores;
    //<______________________________________________________________Se agrega validacion
    while(cantidadDeJugadores<2){
    	consola->imprimirTexto("La cantidad de jugadores debe ser mayor o igual a 2.\n");
	    std::cout << "Ingrese la cantidad de jugadores: ";
    	std::cin >> cantidadDeJugadores;    	
	}
    return cantidadDeJugadores;
}
/*
 * Pos: Devuelve una cantidad de tesoros valida.
 */
int solicitarCantidadDeTesoros(Consola* consola) {
    int cantidadDeTesoros;
    std::cout << "Ingrese la cantidad de tesoros: ";
    std::cin >> cantidadDeTesoros;
    //<______________________________________________________________Se agrega validacion
    while(cantidadDeTesoros<1){
    	consola->imprimirTexto("La cantidad de tesoros debe ser mayor a 0.\n");
	    std::cout << "Ingrese la cantidad de tesoros: ";
    	std::cin >> cantidadDeTesoros;    	
	}
    return cantidadDeTesoros;
}




int main() {

    TesoroBinario* tesoro;
    Consola* consola;//<___________________________________________Se agrega para imprimir texto en las validaciones
    int cantidadJugadores, cantidadDeTesoros, alto, largo, ancho;
    cantidadJugadores = solicitarCantidadDeJugadores(consola);
    cantidadDeTesoros = solicitarCantidadDeTesoros(consola);

    determinarParametros(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
    tesoro = new TesoroBinario(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
    tesoro->jugar();
    delete tesoro;
	delete consola;
    return 0;
}
