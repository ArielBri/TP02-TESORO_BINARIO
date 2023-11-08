#include "TesoroBinario.h"



void TesoroBinario::crearListaDeJugadores(int cantidadDeJugadores,int cantidadDeTesoros) {
	this->listaDeJugadores = new Lista<Jugador*>();
	for (unsigned int i = 1; i <= cantidadDeJugadores; i++) {
		Jugador* jugador = new Jugador(i);
		listaDeJugadores->add(jugador);
	}
}

TesoroBinario::TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores, int cantidadDeTesoros) {
    this->tablero= new Tablero(ancho, alto, largo);//ok
    crearListaDeJugadores(cantidadDeJugadores, cantidadDeTesoros);//ok
    this->cantidadDeTesorosInicial = cantidadDeTesoros;//ok
    this->jugadorActual = NULL;//ok
    this->mazo = new Mazo(CANTIDAD_DE_CARTAS_INICIAL);//revizar
}


bool TesoroBinario::hayGanador(){
    return this->listaDeJugadores->contarElementos() == 1;
}

void TesoroBinario::colocarFicha(Ficha* ficha) {
    this->tablero->getCasillero(ficha->getCoordenada())->setEstado(Ocupado);
    this->tablero->getCasillero(ficha->getCoordenada())->setFicha(ficha);

}



void TesoroBinario::ejecutarTurno() {

    // Metodo que puede estar dentro del TDA intefaz(en ese caso se le deberia spar por parametro el tablero y el jugadorActual)
    this->bitmap->mostrarTablero(Tablero* tablero, Jugador* jugador)
    //OPCIONES DEL TURNO:

    //jugador  obtiene una carta del mazo;
    //bool = consola->sacarCarta?

    if(this->consola->quiereEjecutarAccion("¿Quiere sacar una Carta?")){
        this->jugadorActual->obtenerCarta(this->mazo);
    }
    this->consola->mostrarCartas();
    if(this->consola->quiereEjecutarAccion("¿Quiere usar una Carta?")){
        this->jugadorActual->obtenerCarta(this->mazo);
    }


    //jugador ve la opciones de cartas y elije si quiera usar();

    //this->jugadorActual->jugarCarta(posicion);
    // jugador pone un tesoro mina
    //this->colocarFicha(this->jugadorActual, );
    //Opcion PONER ESPIA
    // this->colocarFicha(this->jugadorActual, Espia);
    // En caso que el jugador quiera mover el tesoro, mueve tesoro;
    //this->moverTesoro();
    //?
    // this->exportarTablero();
    //
    // this->restarContadoresDeInactividad();

}



void TesoroBinario::usarCarta(Carta* carta){
    switch (carta->verCarta()) {
        case Blindaje:
            jugarBlindaje();
            break;
        case Radar:
            jugarRadar();
            break;
        case PartirTesoro:
            partirTesoro();
            break;
        case Espias2:
            jugarEspias2();
            break;
        case Bloqueo:
            jugarBloqueo();
            break;
        case Cartas2:
            jugarCartas2();
            break;
        default:
            throw "No se encontró una carta";
    }

}


void TesoroBinario::limpiarCasillerosQueContenganLasFichasDelJugador(Lista<Ficha*>* fichas){
    fichas->reiniciarCursor();
    while (fichas->avanzarCursor()){
        Coordenada* coordenadaDeFicha = fichas->getCursor()->getCoordenada();
        this->tablero->getCasillero(coordenadaDeFicha)->setEstado(Vacio);
        this->tablero->getCasillero(coordenadaDeFicha)->setFicha(NULL);
    }
}




void TesoroBinario::borrarJugadoresQuePerdieron(){
    int posicion = 0;
    this->listaDeJugadores->reiniciarCursor();
    while (this->listaDeJugadores->avanzarCursor()){
        Jugador* jugador = this->listaDeJugadores->getCursor();
        posicion++;
        if(jugador->devolverCantidadDeTesoros() == 0){
            this->limpiarCasillerosQueContenganLasFichasDelJugador(jugador->obtenerFichasDelJugador());
            this->listaDeJugadores->remover(posicion);
            delete jugador;
            posicion--;
        }
    }
}

void TesoroBinario::jugar(){
    //ASIGNAR TESOROS A LOS JUGADORES Y POSICIONAR EN LOS TESOROS
    this->inicializarJuego();
    //Comienza el juego

    while(!this->hayGanador()){
        this->listaDeJugadores->reiniciarCursor();
        while(!this->hayGanador() && this->listaDeJugadores->avanzarCursor()){
            //Comienza turno
            this->jugadorActual = this->listaDeJugadores->getCursor();
            if(this->jugadorActual->devolverCantidadDeTesoros() > 1){
                this->ejecutarTurno();
            }
        }
        this->borrarJugadoresQuePerdieron();
    }

    std::cout<<"Termino el juego"<<std::endl;

}
// TERMINAR
// Crea mapa para jugar el juego con los tesoros  de cada jugador.
void TesoroBinario::inicializarJuego() {
    this->listaDeJugadores->reiniciarCursor();
    while(this->listaDeJugadores->avanzarCursor()){
        Jugador* actualJugador = this->listaDeJugadores->getCursor();
        actualJugador->inicializarTesoros(this->cantidadDeTesorosInicial);

        // Largo  = idJugador
        Lista<Ficha*>* fichasJugador = actualJugador->obtenerFichasDelJugador();
        fichasJugador->reiniciarCursor();
        while (fichasJugador->avanzarCursor()){
            Coordenada* coordenadaTesoro;
            Ficha* tesoro = new Ficha(Tesoro, actualJugador->devolverJugadorId(), coordenadaTesoro);
            this->colocarFicha(tesoro);
        }
    }
}


//CODEAR
TesoroBinario::~TesoroBinario(){
}
