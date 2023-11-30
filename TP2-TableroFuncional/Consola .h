#ifndef TP_2_CONSOLA_H
#define TP_2_CONSOLA_H

#include <iostream>
#include <string>
#include "Carta .h"
#include "Vector.h"
#include "Jugador .h"

class Consola {
private:
	unsigned int anchoTablero;
	unsigned int altoTablero;
	unsigned int largoTablero;
    /*
     * Pre:
     * Pos: Devuelve la coordenada dentro del las dimensiones del tablero
     */
    unsigned int coordenadaValida(unsigned int longitud, std::string dimension, unsigned int londitudMaximaDeLaDimension);
public:
    /*
     * Pre:
     * Pos: Crea la instancia Consola
     */
    Consola(unsigned int ancho, unsigned int alto, unsigned int largo);

    /*
     * Pre:
     * Pos: Devuelve un booleano que indica si el jugador desea realizar la accion o no.
     */
    bool quiereEjecutarAccion(std::string accion);
    /*
     * Pre:
     * Pos: Muestra por consola al jugador las cartas que posee.
     */
    void mostrarCartas(Lista<Carta*>* listaDeCartas);
    /*
     * Pre: El parametro debe ser mayor a 0.
     * Pos: devuelve el nÃƒÂºmero de la carta.
     */
    int pedirAlJugadorElIndiceDeCarta(int cantidadDeCartas);
    /*
     * Pre: El parametro debe ser un string que especifique para que se piden las coordenadas.
     * Pos: Pide al jugador el ingreso de coordenadas, crea la instancia con ellas y devuelve un puntero a Coordenada.
     */
    Coordenada* pedirCoordenada(std::string motivo);
    /*
     * Pre: El parametro debe ser un string.
     * Pos: Muestra por pantalla el texto recibido por parametro.
     */
    void imprimirTexto(std::string texto);
    /*
     * Pre: El idJugador debe existir y ser mayor a 0.
     * Pos: Muestra por consola el jugador que gano la partida.
     */
    void imprimirGanador(int idJugador);
    /*
     * Pre:
     * Pos: El jugador actual elige un jugador rival, la funcion devuelve un puntero que apunta al jugador elegido.
     */
    Jugador* mostrarJugadoresActivosYElegirJugador(Vector<Jugador *> *vectorDeJugadores);
    /*
     * Pre:
     * Pos: Muestra si el jugador tiene espias y las coordenadas de los mismos.
     */
    void mostrarEspiasDelJugador(Jugador* jugador);
    /*
     * Pre:
     * Pos: Indica que que hay un tesoro los los x y z pasados
     */
    void tesoroEnLaCoordenada(int x, int y, int z);
    /*
     * Pre:
     * Pos:indica la cantidad de carras que se agregaron 
     */
    void cantidadDeCartasQueSeAgregaron(int cantidad);
    /*
     * Pre:
     * Pos: imprime el ide id del jugador
     */
    void imprimirIdJugadorTurno(int idJugador);
    /*
     * Pre:
     * Pos: destruye la consola.
     */
    virtual ~Consola();
};


#endif
