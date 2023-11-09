#ifndef TP_2_BITMAP_H
#define TP_2_BITMAP_H

#include "../Tablero/Tablero.h"
#include "../Jugador/Jugador.h"
#include "../Lista/Lista.h"
#include "../Casillero/Casillero.h"
#include "bitmap_image.hpp"

#include <iostream>
#include <sstream>
using namespace std;

class Bitmap {
private:

public:
    /*
     * Pre: El tablero debe existir.
     * Pos: Se muestra el tablero de un jugador.
     */
    void mostrarTablero(Tablero* tablero, Jugador* jugador);

    /*
	 * Pre:
	 * Pos:
	 */
    std::string intToString(int numero);

	/*
	 * Pre:
	 * Pos: Pinta la casilla del color del terreno
	 */
	void pintarFondoCasilla(bitmap_image &image, unsigned int numeroCasillaHorizontal, unsigned int numeroCasillaVertical, unsigned int rojo, unsigned int azul, unsigned int verde,
			unsigned int anchoCasilla, unsigned int altoCasilla);

	/*
	 * Pre:
	 * Pos: genera tres bitmap, cada uno con la vista XY, XZ y YZ del tablero
	 */
	void crearImagenesTablero();

	/*
	 * Pre:
	 * Pos: En funcion del objeto a pintar, llama a los metodos necesarios para pintar los objetos
	 */
	void pintar(bitmap_image &image, unsigned int ejeVista, Casillero* casillero, unsigned int numeroCasillaHorizontalEnImagen, unsigned int numeroCasillaVerticalEnImagen,
			unsigned int anchoCasilla, unsigned int altoCasilla);

	/*
	 * Pre:
	 * Pos: El plano tiene en sus bordes el numero de casillero, para ello se llama a dibujar numero, para las casillas, se llama al metodo pintar
	 */
	void pintarPlano(bitmap_image &image, unsigned int ejeVista, unsigned int numeroCasillaHorizontalEnImagen, unsigned int numeroCasillaVerticalEnImagen,
			unsigned int cantidadCasillasHorizontalesEnImagen, unsigned int cantidadCasillasVerticalesEnImagen, unsigned int logitudEjeVista, unsigned int anchoCasilla,
			unsigned int altoCasilla, unsigned int i, unsigned int j, unsigned int k, std::string vista);
	/*
	 * Pre:
	 * Pos: Dibuja el numero correspondiente en la casilla
	 */
	void dibujarNumero(bitmap_image &imagen, unsigned int numeroCasillaHorizontal, unsigned int numeroCasillaVertical, unsigned int anchoCasilla, unsigned int altoCasilla, unsigned int nroCasilla);

	/*
	 * Pre:
	 * Pos: dibuja los soldados, minas o vehiculos en la casilla, tambien el efecto de contaminacion
	 */
	void dibujarObjeto(bitmap_image &imagen, unsigned int numeroCasillaHorizontal, unsigned int numeroCasillaVertical, unsigned int anchoCasilla, unsigned int altoCasilla,
			std::string nombreImagen);
};

#endif //BITMAP_H

