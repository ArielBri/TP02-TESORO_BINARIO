#ifndef INTERACCIONES_H_
#define INTERACCIONES_H_


#include <iostream>

class Interacciones {
public:

	/*
	 * Pre:
	 * Pos: crear una instancia de interacciones
	 */
	Interacciones();

	/*
	 * Pre:
	 * Pos: destruye la instancia creada
	 */
	virtual ~Interacciones();

	/*
	 * Pre:
	 * Pos: Solicita el ingreso de un entero y lo retorna
	 */
	unsigned int solicitarCantidadDeJugadores();
	
	/*
	 * Pre:
	 * Pos: Solicita el ingreso de un entero y lo retorna
	 */
	unsigned int solicitarCantidadDeTesoros();
	
	/*
	 * Pre: catidad de jugadores debe ser entero mayor a 0
	 * Pos: Solicita el ingreso de enteros que seran las coordenadas ancho, alto y largo. Crea array dinamico y le asigna los valores ingresados. Devuelve el puntero al array
	 * En funcion de la cantidad de jugadores, limita los valores x y z ingresados
	 */
	int* solicitarTamanioTablero(int cantidadDeJugadores);

	/*
	 * Pre: tamanio y minimo deben ser enteros maqyores a 0
	 * Pos: Pedira el ingreso de un entero hasta que este este en el rango entre minimo y tamanio, luego lo retorna
	 */
	unsigned int validarIngresoEntero(unsigned int maximo, std::string texto, unsigned int minimo);

};

#endif 
