#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_


#include "Consola .h"
#include "Bitmap.h"
#include <cstdlib>
#include <string>



enum TipoTurno{
    Invalido,
    Valido
};


class TesoroBinario {
private:
    Tablero * tablero;
    Vector<Jugador*>*  vectorDeJugadores; // [*Jugador1, *Jugador2,..., *JugadorN]
    Jugador * jugadorActual;
    Consola * consola;
    Mazo * mazo;
    Bitmap* bitmap;

    TipoTurno turnoValido;
    int cantidadDeJugadores;
    int cantidadDeTesorosInicial;

public:
    /*
     * Pre: parametros deben ser enteros positivos.
     * Pos: crea la instancia TesoroBinario
     */
    TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores, int cantidadDeTesoros);
    /*
     * Pre:
     * Pos:
     */
    void jugar();
    /*
     * Pre:
     * Pos: carga los jugadores al vector de jugadores e invoca a la funcion que carga los tesoros de cada jugador al tablero
     */
    void inicializarJuego();
    /*
     * Pre:
     * Pos: devuelve false si hay 2 o mas jugadores con tesoros y true si queda un solo jugador.
     */
    bool hayGanador();
    /*
     * Pre: 
     * Pos: coloca la ficha recibida por parametro en un casillero y cambia el estado del casillero.
     */
    void colocarFicha(Ficha* ficha);
    /*
    * Pre:
    * Pos: muestra y actualiza el tablero del jugador con los movimientos que hizo en su turno
    */
    void ejecutarTurno();
    /*
     * Pre:
     * Pos: modifica el vector de jgadores, cambia el estado de los jugadores sin tesoros para que no sigan jugando
     */
    void borrarJugadoresQuePerdieron();
    /*
     * Pre: El jugador debe existir.
     * Pos: Recorre el tablero eliminando las fichas de los jugadores.
     */
    void limpiarCasillerosQueContenganLasFichasDelJugador(Lista<Ficha*>* fichas);
    /*
     * Pre: Se requiere una carta del juego
     * Pos: Realiza la accion de la carta
     */
    void usarCarta(Carta* carta);
    /*
     * Pre:
     * Pos: 
     */
    void jugarBlindaje();
    /*
     * Pre:
     * Pos:
     */
    void jugarRadar();
    /*
     * Pre:
     * Pos:
     */
    void partirTesoro();
    /*
     * Pre:
     * Pos:
     */
    void jugarEspias2();
    /*
     * Pre:
     * Pos:
     */
    void jugarMostrarEspiasDeJugadorActivo();
    /*
     * Pre:
     * Pos: Agrega una cantidad una cantidad random entre 0 y 4 de cartas a la mano del jugador
     */
    void jugarObtenerCartas4();
    /*
     * Pre:
     * Pos:
     */
    void eliminarFichaDeLaListaDeFichasDelJugador(Ficha* ficha);
    /*
     * Pre:
     * Pos:
     */
    void actualizarTablero();
    /*
     * Pre:
     * Pos:
     */
    void metodoCartas();
    /*
     * Pre:
     * Pos:
     */
    void metodoTesoroMina();
    /*
     * Pre:
     * Pos:
     */
    void metodoChoqueTesoro(Coordenada* coordenadaActual,Coordenada *coordenadaNueva, Casillero* casilleroActual,Casillero* casilleroNuevo);
    /*
     * Pre:
     * Pos:
     */
    void metodoTesoroMinaOcupado(Casillero* casillero);
    /*
     * Pre:
     * Pos:
     */
    void metodoEspias();
    /*
     * Pre:
     * Pos:
     */
    void subMetodoMoverTesoro(Casillero* casilleroNuevo, Coordenada* coordenadaNueva);
    /*
     * Pre:
     * Pos:
     */
    void metodoMoverTesoro();
    /*
     * Pre:
     * Pos:
     */
    void metodoMoverTesoroCasilleroInactivo(Coordenada* coordenadaNueva);
    /*
    * Pre:
    * Pos:
    */
    void metodoMoverTesoroCasilleroOcupado(Coordenada* coordenadaActual,Coordenada *coordenadaNueva,
                                           Casillero* casilleroActual,Casillero* casilleroNuevo);
    /*
    * Pre:
    * Pos:
    */
    void metodoMoverTesoroCasilleroVacio(Coordenada* coordenadaActual,Coordenada *coordenadaNueva,
                                         Casillero* casilleroActual,Casillero* casilleroNuevo);
    /*
     * Pre:
     * Pos:
     */
    void anunciarGanador();
    /*
     * Pre:
     * Pos:
     */
    bool hayTesoroEnCasillero(int X, int Y, int Z);
    /*
     * Pre:
     * Pos:
     */
    void inicializarTesoros(int cantidadDeTesorosPorJugador, Jugador* jugador);
    /*
     * Pre:
     * Pos:
     */
    void metodoEspiaChoque(Casillero *casillero, TipoFicha ficha);
    /*
     * Pre:
     * Pos:
     */
    void metodoEspiasChoqueCasilleroNoInactivo(Casillero* casillero, Coordenada* coordenada);
    /*
     * Pre:
     * Pos: Destuye la instancia TesoroBinario
     */
    virtual ~TesoroBinario();
};


#endif

 
  
