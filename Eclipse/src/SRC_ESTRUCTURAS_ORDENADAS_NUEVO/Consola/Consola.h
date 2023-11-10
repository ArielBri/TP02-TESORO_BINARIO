#ifndef TP_2_CONSOLA_H
#define TP_2_CONSOLA_H

#include <iostream>
#include <string>
#include "../Mazo/Carta.h"
#include "../Vector/Vector.h"
#include "../Jugador/Jugador.h"

class Consola {
public:
    /*
	 * Pre:
	 * Pos:
	 */
    Consola();

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
     * Pos:
     */
    void imprimirGandor(int idJugador);
    /*
     * Pre:
     * Pos:
     */
    Jugador* mostrarJugadoresActivosYElegirJugador(Vector<Jugador *> *vectorDeJugadores);
    /*
     * Pre:
     * Pos:
     */
    void mostrarEspiasDelJugador(Jugador* jugador);
    /*
     * Pre:
     * Pos:
     */
    void tesoroEnLaCoordenada(int x, int y, int z);
    /*
     * Pre:
     * Pos:
     */
    void cantidadDeCartasQueSeAgregaron(int cantidad);
    /*
     * Pre:
     * Pos: destruye la consola.
     */
    virtual ~Consola();
};


#endif
