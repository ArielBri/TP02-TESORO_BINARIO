#include "Interacciones.h"
using namespace std;
/*const int MAXIMO=50;
const int MINIMO=5;*/
Interacciones::Interacciones() {
	// TODO Auto-generated constructor stub

}

Interacciones::~Interacciones() {
	// TODO Auto-generated destructor stub
}


unsigned int Interacciones::solicitarCantidadDeJugadores() {
	int cantidadDeJugadores;
	cout << "Ingrese la cantidad de jugadores: ";
	cin >> cantidadDeJugadores;
	return cantidadDeJugadores;
}

unsigned int Interacciones::solicitarCantidadDeTesoros() {
	int cantidadDeTesoros;
	cout << "Ingrese la cantidad de tesoros: ";
	cin >> cantidadDeTesoros;
	return cantidadDeTesoros;
}

int* Interacciones::solicitarTamanioTablero() {
	/*if (cantidadDeJugadores <= 1) {
		throw "Cantidad de jugadores debe ser mayor a 0";
	}*/
	int* coordenadas = new int [3];
	cout << "Ingrese el tamaño del tablero: " << endl;
	coordenadas[0] = validarIngresoEntero(5, "Tamaño ANCHO: ", 50);
	coordenadas[1] = validarIngresoEntero(5, "Tamaño ALTO: ", 50);
	coordenadas[2] = validarIngresoEntero(5, "Tamaño LARGO: ", 50);

	return coordenadas;
}

unsigned int Interacciones::validarIngresoEntero(unsigned int minimo, string texto, unsigned int maximo) {
	if (maximo < 1) {
		throw "Tamanio debe ser mayor a 0";
	}
	if (minimo < 1) {
		throw "Minimo debe ser mayor a 0";
	}
	unsigned int coordenada;
	bool incorrecto = true;
	while (incorrecto){
		cout << texto;
		cin >> coordenada;
		if (minimo <= coordenada && coordenada <= maximo) {
			incorrecto = false;
		}
		else {
			cout << "Invalido, ingrese un numero entre " << minimo << " y " << maximo << endl;
		}
	}
	return coordenada;
}
