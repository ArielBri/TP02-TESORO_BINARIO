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


bool TesoroBinario::jugadorTieneAlMenosUnTesoro(){
	this->listaDeJugadores->reiniciarCursor();
	while (this->listaDeJugadores->avanzarCursor()){
		Jugador* jugador = this->listaDeJugadores->getCursor();
		if (jugador->devolverCantidadDeTesoros()>1){
			return true;
		}
	}
    return false;
}

bool TesoroBinario::hayGanador(){
    return this->listaDeJugadores->contarElementos() == 1;
}


void TesoroBinario::moverTesoro() {

}

void TesoroBinario::colocarFicha(Jugador *jugador, TipoFicha ficha) {

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
            //this->mostrarTablero();//Metodo que puede estar dentro del TDA intefaz(en ese caso se ledeberia spar por parametro el tablero y el jugadorActual)
            //jugador  obtiene una carta del mazo;
            this->jugadorActual->obtenerCarta(this->mazo);
            //jugador ve la opciones de cartas y elije si quiera usar();
            int posicion = this->jugadorActual->mostrarCartas();
            this->jugadorActual->jugarCarta(posicion);
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
    }

    std::cout<<"Termino el juego"<<std::endl;

}


void TesoroBinario::inicializarJuego() {
    this->listaDeJugadores->reiniciarCursor();
    while(this->listaDeJugadores->avanzarCursor()){
        Jugador* actualJugador = this->listaDeJugadores->getCursor();
        actualJugador->inicializarTesoros(this->cantidadDeTesorosInicial);

        Lista<Ficha*>* fichasJugador = actualJugador->obtenerFichasDelJugador();
        fichasJugador->reiniciarCursor();
        while (fichasJugador->avanzarCursor()){

            //this->colocarFicha(actualJugador, F);
        }
    }
}


//CODEAR
TesoroBinario::~TesoroBinario(){

}
