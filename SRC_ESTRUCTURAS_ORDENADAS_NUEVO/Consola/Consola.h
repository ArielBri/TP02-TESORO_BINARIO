#ifndef TP_2_CONSOLA_H
#define TP_2_CONSOLA_H

#include <iostream>
#include <string>
#include "../Mazo/Carta.h"
class Consola {
public:
    Consola();
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
     * Pre:
     * Pos:
     */
    bool quiereEjecutarAccion(std::string accion);
    /*
     * Pre:
     * Pos:
     */
    void mostrarCartas(Lista<Carta*>* listaDeCartas);
    /*
     * Pre:
     * Pos: devuelve el número de la carta.
     */
    int pedirAlJugadorElIndiceDeCarta(int cantidadDeCartas);
    /*
	 *
	 *
	 */
    Coordenada* pedirCoordenada(std::string motivo);
    /*
     * Pre:
     * Pos:
     */
    void imprimirTexto(std::string texto);
    /*
     * Pre:
     * Pos: destruye la consola.
     */
    virtual ~Consola();
};


#endif