#include <iostream>
#include "Lista/Lista.h"
#include "Pila/Pila.h"
#include "Mazo/Mazo.h"
#include "Tablero/Tablero.h"
#include "TesoroBinario/TesoroBinario.h"
#include <cstdlib>
#include "Jugador/Jugador.h"
#include "Coordenada/Coordenada.h"
#include "Ficha/Ficha.h"
#include "Interacciones.h"

int main(){
	Interacciones* interacciones = new Interacciones();
	int cantidadJugadores = interacciones->solicitarCantidadDeJugadores();
	int cantidadTesoros = interacciones->solicitarCantidadDeTesoros();
	int* tamanioDeTablero = interacciones->solicitarTamanioTablero();
	TesoroBinario* tesoroBinario = new TesoroBinario(tamanioDeTablero[0],tamanioDeTablero[1], tamanioDeTablero[2],cantidadJugadores,cantidadTesoros);
	return 0;
}
