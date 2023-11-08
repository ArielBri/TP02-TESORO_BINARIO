#ifndef TP_2_CONSOLA_H
#define TP_2_CONSOLA_H

#include "iostream"
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



    bool quiereSacarCarta();
    bool quiereEjecutarAccion(std::string accion);
    void mostrarCartas();

    /*
    * Pre:
    * Pos: devuelve la eleccion del jugador.
    */
    char eleccion(char opcion);

    /*
    * Pre:
    * Pos: crea un menu de opciones.
    */
    void menuDeOpciones();

    /*
    * Pre:
    * Pos: valida que la eleccion del jugador sea valida.
    */
    void validarEleccion();

    /*	
    /*
    * Pre:
    * Pos: destruye la instancia creada
    */
    virtual ~Consola();
};


#endif
