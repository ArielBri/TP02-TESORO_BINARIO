#include "TesoroBinario.h"
// TERMINAR DE CODEAR
// crea la lista de jugadores  segun la cantidad
Lista<Jugador*>* TesoroBinario::crearListaDeJugadores(int cantidadDeJugadores) {
    Lista<Jugador*>* lista;
    return lista;
}

TesoroBinario::TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores) {
    this->tablero= new Tablero(ancho, alto, largo);
    this->listaDeJugadores = crearListaDeJugadores(cantidadDeJugadores);
    this->jugadorActual = NULL;
    this->mazo = new Mazo(CANTIDAD_DE_CARTAS_INICIAL);
}


bool TesoroBinario::jugadorTieneAlMenosUnTesoro(Jugador *jugadorActual) {
    this->tablero->reiniciarCursor();
    while (this->tablero->avanzar){
        Casillero* casillero = this->tablero->getCursor();

        if(casillero->getEstado()==Ocupado){
            Ficha* ficha= casillero->getFicha();
            if(ficha->getJugador()==jugadorActual && ficha->getEstado()== 'Tesoro') {
                return true;
            }
        }
    }
    return false;
}

bool TesoroBinario::hayGanador(){
    int cantidadDeJugadoresConAlmenosUnTesoro=0;
    this->listaDeJugadores->reiniciarCursor();
    while (listaDeJugadores->avanzarCursor()){
        Jugador* jugadorActual = listaDeJugadores->getCursor();

        if (this->jugadorTieneAlMenosUnTesoro(jugadorActual)){
            cantidadDeJugadoresConAlmenosUnTesoro++;
        }
        if(cantidadDeJugadoresConUnTesoro>2){
            return false;
        }

    }
    return

}


void TesoroBinario::moverTesoro() {

}

void TesoroBinario::colocarFicha(Jugador *jugador, TipoFicha ficha) {

}



void TesoroBinario::jugar(){

    //Comienza el juego
    while(this->noHayGanador()){
        this->listaDeJugadores->reiniciarCursor();
        while(this->noHayGanador() && this->listaDeJugadores->avanzarCursor()){
            //Comienza turno
            this->jugadorActual = this->listaDeJugadores->getCursor();
            this->mostrarTablero();//Metodo que puede estar dentro del TDA intefaz(en ese caso se ledeberia spar por parametro el tablero y el jugadorActual)
            //jugador  obtiene una carta del mazo;
            this->jugadorActual->obtenerCarta(this->mazo);
            //jugador ve la opciones de cartas y elije si quiera usar();
            int posicion = this->jugadorActual->mostrarCartas();
            this->jugadorActual->jugarCarta(posicion);
            // jugador pone un tesoro mina
            this->colocarFicha(this->jugadorActual, TesoroMina);
            //Opcion PONER ESPIA
            this->colocarFicha(this->jugadorActual, Espia);
            // En caso que el jugador quiera mover el tesoro, mueve tesoro;
            this->moverTesoro();
            //?
            this->exportarTablero();
            //
            this->restarContadoresDeInactividad();
        }
    }

    std::cout<<"Termino el juego"<<std::endl;

}

//CODEAR
TesoroBinario::~TesoroBinario(){

}
