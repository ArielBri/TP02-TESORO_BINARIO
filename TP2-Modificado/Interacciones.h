#ifndef INTERACCIONES_H_
#define INTERACCIONES_H_
#include <iostream>

class Interacciones{
	public:
		
		/*
		 * Pos: Crea una instancia de interacciones
		 */
		Interacciones();
		
		/*
		 * Pos: Destruye la instancia creada
		 */
		virtual ~Interacciones();
		
		/*
		 * Pos: Devuelve un entero con la cantidad de Jugadores.
		 */
		unsigned int solicitarCantidadDeJugadores();
		
		/*
		 * Pos: Devuelve un entero con la cantidad de Tesoros.
		 */
		unsigned int solicitarCantidadDeTesoros(); 
		
		/*
		 * Pre: Cantidad de jugadores debe ser un entero mayor a 0.
		 * Pos: Devuelve un puntero a un array de enteros con las longitudes de ancho, alto y largo.
		 */
		int* solicitarTamanioTablero();
		
		/*
		 * Pos: Devuelve un entero valido dentro del rango establecido entre maximo y minimo. 
		 */
		unsigned int validarIngresoEntero(unsigned int minimo, std::string texto, unsigned int maximo);
};
#endif
