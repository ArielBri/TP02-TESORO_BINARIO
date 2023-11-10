#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_


#include "../Consola/Consola.h"
#include "../Bitmap/Bitmap.h"
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
    void crearVectorDeJugadores(int cantidadDeJugadores);

public:
    /*
     * Pre:
     * Pos:
     */
    TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores, int cantidadDeTesoros);
    /*
     * Pre:
     * Pos:
     */
    void jugar();
    /*
     * Pre:
     * Pos:
     */
    void inicializarJuego();
    /*
     * Pre:
     * Pos:
     */
    bool hayGanador();
    /*
     * Pre:
     * Pos:
     */
    void colocarFicha(Ficha* ficha);
    /*
    * Pre:
    * Pos:
    */
    void ejecutarTurno();
    /*
     * Pre:
     * Pos:
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
     * Pos:
     */
    virtual ~TesoroBinario();
};


#endif

 
  
