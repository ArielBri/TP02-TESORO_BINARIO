#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_


#include "Consola.h"
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
    void crearVectorDeJugadores(int cantidadDeJugadores);

public:
    /*
     * Pre: Los parametros recibidos deben ser mayores a 0.
     * Pos: Crea las instancias necesarias para el juego, e inicializa sus atributos.
     */
    TesoroBinario();
    /*
     * Pre: 
     * Pos:
     */
    void jugar();
    /*
     * Pre: 
     * Pos: Carga los tesoros de cada jugador al tablero de forma aleatoria
     */
    void inicializarJuego();
    /*
     * Pre: 
     * Pos: Devuelve un booleano que indica si hay ganador del juego.
     */
    bool hayGanador();
    /*
     * Pre:
     * Pos: Cambia el estado del casillero a ocupado
     */
    void colocarFicha(Ficha* ficha);
    /*
    * Pre:
    * Pos: Llama a las funciones que permiten el desarrolo del turno del jugador
    */
    void ejecutarTurno();
    /*
     * Pre:
     * Pos: Cambia el estado de los jugadores sin tesoros para que no puedan seguir jugando
     */
    void borrarJugadoresQuePerdieron();
    /*
     * Pre: El jugador debe existir.
     * Pos: Elimina todas las fichas del jugador dueño de la lista pasada por parametro.
     */
    void limpiarCasillerosQueContenganLasFichasDelJugador(Lista<Ficha*>* fichas);
    /*
     * Pre: Se requiere una carta del juego
     * Pos: Realiza la accion de la carta
     */
    void usarCarta(Carta* carta);
    /*
     * Pre: El jugador eligio usar esta carta.
     * Pos: Protege todos los tesoros del jugador actual de los espias y tesorominas.
     */
    void jugarBlindaje();
    /*
     * Pre: El jugador eligio usar esta carta.
     * Pos: Detecta 3 casilleros a la redonda de la posicion en la que se ubica, y avisa al jugador si hay tesoros, .
     */
    void jugarRadar();
    /*
     * Pre: El jugador eligio usar esta carta.
     * Pos: Permite al jugador insertar un tesoro extra en el tablero.
     */
    void partirTesoro();
    /*
     * Pre: El jugador eligio usar esta carta.
     * Pos: Permite al jugador cargar dos espias extra en su turno.
     */
    void jugarEspias2();
    /*
     * Pre: El jugador eligio usar esta carta.
     * Pos: Permite al jugador de turno ver los espias del jugador que elija.
     */
    void jugarMostrarEspiasDeJugadorActivo();
    /*
     * Pre:
     * Pos: Agrega una cantidad random entre 0 y 4 de cartas a la mano del jugador
     */
    void jugarObtenerCartas4();
    /*
     * Pre:
     * Pos: Elimina la ficha de la lista del jugador.
     */
    void eliminarFichaDeLaListaDeFichasDelJugador(Ficha* ficha);
    /*
     * Pre:
     * Pos: Actualiza la imagen del tablero con las modificaciones hechas por el jugador durante su turno.
     */
    void actualizarTablero();
    /*
     * Pre:
     * Pos: Ejecuta la obtencion y uso de una carta por el jugador de turno.
     */
    void metodoCartas();
    /*
     * Pre:
     * Pos: Modifica el casillero donde se coloca un TesoroMina, dependiendo del contenido previo.
     */
    void metodoTesoroMina();
    /*
     * Pre:
     * Pos: Modifica el casillero donde se coloca un Espia, dependiendo del contenido previo.
     */
    void metodoEspias();
    /*
     * Pre:
     * Pos: Mueve un Tesoro y modifica el casillero dependiendo del contenido previo.
     */
    void metodoMoverTesoro();
    /*
     * Pre:
     * Pos: Muestra por consola que jugador gano la partida.
     */
    void anunciarGanador();
    /*
     * Pre: Los parametros deben ser mayores a 0.
     * Pos: Devuelve un booleano si en las coordenadas recibidas por parametro hay un tesoro.
     */
    bool hayTesoroEnCasillero(int X, int Y, int Z);
    /*
     * Pre: cantidadDeTesorosPorJugador debe ser mayor a 0 y el puntero debe ser distinto de NULL.
     * Pos: Coloca los tesoros en el tablero y los agrega a la lista de fichas del jugador recibido por parametro.
     */
    void inicializarTesoros();
    /*
     * Pre:
     * Pos: Destruye la instancia de TesoroBinario
     */
    virtual ~TesoroBinario();
};


#endif
