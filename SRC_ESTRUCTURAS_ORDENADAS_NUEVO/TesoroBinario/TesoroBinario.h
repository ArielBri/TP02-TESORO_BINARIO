#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_


#include "../Consola/Consola.h"
#include "../Bitmap/Bitmap.h"
#include "../Vector/Vector.h"

enum TipoTurno{
    Invalido,
    Valido
};

class TesoroBinario {
private:
    Tablero * tablero;
    Lista <Jugador*>* listaDeJugadores; // Turnos
    Vector<Jugador*>*  vectorDeJugadores;
    Jugador * jugadorActual;
    Consola * consola;
    Mazo * mazo;
    Bitmap* bitmap;
    TipoTurno turnoValido;
    int cantidadDeJugadores;
    int cantidadDeTesorosInicial;
    void crearListaDeJugadoresYarrayDeJugadores(int cantidadDeJugadores);

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
    void jugarBloqueo();
    /*
     * Pre:
     * Pos:
     */
    void jugarCartas2();
    /*
     * Pre:
     * Pos:
     */
    void eliminarFichaDeLaListaDeFichasDelJugador(Ficha* ficha);
    /*
     * Pre:
     * Pos:
     */
    void restarContadoresDeInactividad();
    /*
     * Pre:
     * Pos:
     */
    void restarContadoresDeBlindajeDeTesoros();
    /*
     * Pre:
     * Pos:
     */
    // void crearFichaSiElCasilleroNoEstaInactivo(Ficha* ficha, Casillero* casillero, std::string motivo, TipoFicha tipoDeFicha);
    /*
     * Pre:
     * Pos:
     */
    virtual ~TesoroBinario();
};


#endif
