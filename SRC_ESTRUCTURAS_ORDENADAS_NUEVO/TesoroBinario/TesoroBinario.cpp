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

    //
    this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    //OPCIONES DEL TURNO:

    if(this->consola->quiereEjecutarAccion("¿Quiere sacar una Carta?")){
        this->jugadorActual->obtenerCarta(this->mazo);
    }

    this->consola->mostrarCartas(this->jugadorActual->obtenerCartasDelJugador());
    if(this->consola->quiereEjecutarAccion("¿Quiere usar una Carta?")){
        int indice = this->consola->pedirAlJugadorElIndiceDeCarta();
        this->usarCarta(this->jugadorActual->obtenerCartasDelJugador()->get(indice));
        this->jugadorActual->obtenerCartasDelJugador()->remover(indice);
    }

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
            this->jugarBlindaje();
            break;
        case Radar:
            this->jugarRadar();
            break;
        case PartirTesoro:
            this->partirTesoro();
            break;
        case Espias2:
            this->jugarEspias2();
            break;
        case Bloqueo:
            this->jugarBloqueo();
            break;
        case Cartas2:
            this->jugarCartas2();
            break;
        default:
            throw "No se encontró una carta";
    }
    delete carta;

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
        //WARNING: CASO EN EL QUE EL JUGADOR SE AUTODESTRUYE ->PENSAR Y RESOLVER
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

void TesoroBinario::jugarBlindaje() {

}

void TesoroBinario::jugarRadar() {

}

void TesoroBinario::partirTesoro() {

}

void TesoroBinario::jugarEspias2() {

}

void TesoroBinario::jugarBloqueo() {

}

void TesoroBinario::jugarCartas2() {

}


//CODEAR
TesoroBinario::~TesoroBinario(){
}
