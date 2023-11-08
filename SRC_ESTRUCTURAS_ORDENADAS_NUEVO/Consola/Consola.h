#ifndef TP_2_CONSOLA_H
#define TP_2_CONSOLA_H

#include <iostream>
class Consola {
private:
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
    bool quiereSacarCarta();
    /*
     * Pre:
     * Pos:
     */
    bool quiereEjecutarAccion(std::string accion);
    /*
     * Pre:
     * Pos:
     */
    void mostrarCartas();
    /*
	 * Pre:
	 * Pos: destruye la consola.
	 */
    virtual ~Consola();
};


#endif
