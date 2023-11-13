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
     * Pos: modifica el vector de jugadores, cambia el estado de los jugadores sin tesoros para que no sigan jugando
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
     * Pos: cambia la primer ficha tesoro que encuentra por un tesoro blindado
     */
    void jugarBlindaje();
    /*
     * Pre:
     * Pos: muestra las coordenadas de los tesoros que rodean el radar, 3 casilleros a la redornda
     */
    void jugarRadar();
    /*
     * Pre:
     * Pos: se agrega un tesoro al tablero y a la lista de fichas del jugador
     */
    void partirTesoro();
    /*
     * Pre:
     * Pos: se agregan dos espias al tablero y a la lista de fichas del jugador
     */
    void jugarEspias2();
    /*
     * Pre:
     * Pos: muestra las coordenadas de los espias del jugador elegido por el jugador de turno
     */
    void jugarMostrarEspiasDeJugadorActivo();
    /*
     * Pre:
     * Pos: Agrega una cantidad una cantidad random entre 0 y 4 de cartas a la mano del jugador
     */
    void jugarObtenerCartas4();
    /*
     * Pre:
     * Pos: elimina la ficha recibida por parametro de la lista del jugador correspondiente
     */
    void eliminarFichaDeLaListaDeFichasDelJugador(Ficha* ficha);
    /*
     * Pre:
     * Pos: resta un turno a los casilleros inactivos y a los que poseen tesoros blindados
     */
    void actualizarTablero();
    /*
     * Pre:
     * Pos: agrega o quita una carta al jugador en caso de que decida usarla o no
     */
    void metodoCartas();
    /*
     * Pre:
     * Pos: agrega un tesoroMina al tablero, en caso de no se posible ejecuta otra condicion
     */
    void metodoTesoroMina();
    /*
     * Pre:
     * Pos: Mueve el tesoro de casillero o se pierde dependiendo del tipo de ficha que está almacenada en el casillero nuevo  
     */
    void metodoChoqueTesoro(Coordenada* coordenadaActual,Coordenada *coordenadaNueva, Casillero* casilleroActual,Casillero* casilleroNuevo);
    /*
     * Pre: el casillero debe tener una ficha dentro
     * Pos: cambia el estado del casillero recibido a Inactivo y lo deja sin fichas dentro
     */
    void metodoTesoroMinaOcupado(Casillero* casillero);
    /*
     * Pre:
     * Pos: coloca un espia en el tablero si el casillero lo permite, caso contrario modifica
     *      el contendido del casillero segun lo indiquen las condiciones 
     */
    void metodoEspias();
    /*
     * Pre:
     * Pos: Invoca a la funcion adecuada para evaluar que sucede con el tesoro segun el contenido del casillero a donde se lo quiere mover
     */
    void subMetodoMoverTesoro(Casillero* casilleroNuevo, Coordenada* coordenadaNueva);
    /*
     * Pre:
     * Pos: Pide las coordenadas del casillero donde se quiere mover el tesoro e invoca a la funcion que realiza el movimiento
     */
    void metodoMoverTesoro();
    /*
     * Pre:
     * Pos: Notifica al jugador que perdio su tesoro por moverlo a un casillero Inactivo
     */
    void metodoMoverTesoroCasilleroInactivo(Coordenada* coordenadaNueva);
    /*
    * Pre:
    * Pos: El tesoro fue movido a un casillero ocuapado, evalua que hacer y modifica el contenido del casillero e infoma que paso con el tesoro
    */
    void metodoMoverTesoroCasilleroOcupado(Coordenada* coordenadaActual,Coordenada *coordenadaNueva,
                                           Casillero* casilleroActual,Casillero* casilleroNuevo);
    /*
    * Pre:
    * Pos: Mueve el tesoro al casillero nuevo y libera el casillero actual
    */
    void metodoMoverTesoroCasilleroVacio(Coordenada* coordenadaActual,Coordenada *coordenadaNueva,
                                         Casillero* casilleroActual,Casillero* casilleroNuevo);
    /*
     * Pre: Debe quedar un solo jugador con estado Activo
     * Pos: Muestra por consola el jugador que ganó el juego
     */
    void anunciarGanador();
    /*
     * Pre:
     * Pos: Devuelve true si en las coordenadas recibidas se almacena en el casillero una ficha tesoro
     */
    bool hayTesoroEnCasillero(int X, int Y, int Z);
    /*
     * Pre:
     * Pos: Carga los tesoros de los jugadores al tablero
     */
    void inicializarTesoros(int cantidadDeTesorosPorJugador, Jugador* jugador);
    /*
     * Pre:
     * Pos: Coloca un espía en un casillero ocupado y avisa por mesaje que sucedio con el espia
     */
    void metodoEspiaChoque(Casillero *casillero, TipoFicha ficha);
    /*
     * Pre:
     * Pos: Coloca el espia si el casillero está vacio, si el casillero esta ocupado evalua que paso con el espia y avisa
     */
    void metodoEspiasChoqueCasilleroNoInactivo(Casillero* casillero, Coordenada* coordenada);
    /*
     * Pre:
     * Pos: Destuye la instancia TesoroBinario
     */
    virtual ~TesoroBinario();
};


#endif

 
  
