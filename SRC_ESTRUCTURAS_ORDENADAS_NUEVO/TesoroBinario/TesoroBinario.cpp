#include "TesoroBinario.h"



void TesoroBinario::crearVectorDeJugadores(int cantidadJugadores) {
    Jugador* jugadorNULL = NULL;
    this->vectorDeJugadores = new Vector<Jugador*>(cantidadJugadores, jugadorNULL);
	for (unsigned int i = 1; i <= cantidadJugadores; i++) {
		Jugador* jugador = new Jugador(i);
        this->vectorDeJugadores->agregar(i, jugador);
	}
}

TesoroBinario::TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores, int cantidadDeTesoros) {
    this->tablero = new Tablero(ancho, alto, largo);
    this->crearVectorDeJugadores(cantidadDeJugadores);
    this->cantidadDeTesorosInicial = cantidadDeTesoros;
    this->jugadorActual = NULL;
    this->mazo = new Mazo(CANTIDAD_DE_CARTAS_INICIAL);
    this->turnoValido = Valido;
    this->cantidadDeJugadores = cantidadDeJugadores;
}


bool TesoroBinario::hayGanador(){
    int contadorDeJugadoresActivos = 0;
    for(int i=1; i<this->cantidadDeJugadores; i++){
        Jugador* jugador= this->vectorDeJugadores->obtener(i);
        if(jugador->getEstadoJugador() == Activo){
            contadorDeJugadoresActivos++;
        }
        if (contadorDeJugadoresActivos>=2){
            return false;
        }
    }
    return true;
}


void TesoroBinario::colocarFicha(Ficha* ficha) {
    this->tablero->getCasillero(ficha->getCoordenada())->setEstado(Ocupado);
    this->tablero->getCasillero(ficha->getCoordenada())->setFicha(ficha);
}



void TesoroBinario::ejecutarTurno() {
    //OPCIONES DEL TURNO:
    // Metodo A: Cartas
    this->metodoCartas();
    this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    // Metodo B: Tesoro Mina
    this->metodoTesoroMina();
    this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    // Metodo C: Espias
    this->metodoEspias();
    this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    // Metodo D: Mover Tesoro no blindado.
    this->metodoMoverTesoro();
    this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    // Tablero
    this->restarContadoresDeBlindajeDeTesoros();
    this->restarContadoresDeInactividad();
    //
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

    for(int i = 1; i<=this->cantidadDeJugadores; i++){
        Jugador* jugador = this->vectorDeJugadores->obtener(i);
        if(jugador->devolverCantidadDeTesoros() == 0){
            jugador->setEstadoJugador(NoActivo);
            this->limpiarCasillerosQueContenganLasFichasDelJugador(jugador->obtenerFichasDelJugador());

        }
    }
}

void TesoroBinario::jugar(){
    //ASIGNAR TESOROS A LOS JUGADORES Y POSICIONAR EN LOS TESOROS
    this->inicializarJuego();
    //Comienza el juego

    while(!this->hayGanador()){
        int posicion = 1;
        while(!this->hayGanador() && posicion <= this->cantidadDeJugadores){

            this->turnoValido = Valido;
            this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
            this->jugadorActual = this->vectorDeJugadores->obtener(posicion);

            if(this->jugadorActual->getEstadoJugador()==Activo){
                this->ejecutarTurno();
            }
            this->borrarJugadoresQuePerdieron();
            posicion++;
        }
    }
    this->anunciarGanador();

    std::cout<<"Termino el juego"<<std::endl;

}
// TERMINAR
// Crea mapa para jugar el juego con los tesoros  de cada jugador.
void TesoroBinario::inicializarJuego() {
    /*this->listaDeJugadores->reiniciarCursor();
    // while(this->listaDeJugadores->avanzarCursor()){
   //     Jugador* actualJugador = this->listaDeJugadores->getCursor();
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
     */
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


void TesoroBinario::eliminarFichaDeLaListaDeFichasDelJugador(Ficha* ficha) {
    int idJugador = ficha->getJugadorId(), posicion=1;
    Lista<Ficha*>* fichas;
    fichas =  this->vectorDeJugadores->obtener(idJugador)->obtenerFichasDelJugador();

    fichas->reiniciarCursor();
    while (fichas->avanzarCursor()){
        Ficha* fichaLista = fichas->getCursor();
        if(fichaLista==ficha){
            fichas->remover(posicion);
            return;
        }
        posicion++;
    }

}



void TesoroBinario::metodoCartas() {
    if(this->consola->quiereEjecutarAccion("Quiere sacar una Carta?")){
        this->jugadorActual->obtenerCarta(this->mazo);
    }

    Lista<Carta*>* cartas = this->jugadorActual->obtenerCartasDelJugador();
    this->consola->mostrarCartas(cartas);

    if(this->consola->quiereEjecutarAccion("Quiere usar una Carta?")){

        int indice = this->consola->pedirAlJugadorElIndiceDeCarta(cartas->contarElementos());
        this->usarCarta(cartas->get(indice));
        cartas->remover(indice);
    }

}



void TesoroBinario::metodoTesoroMina() {
    if(this->consola->quiereEjecutarAccion("Quiere poner un TesoroMina?") && this->turnoValido==Valido){
        Coordenada* coordenada;
        Casillero* casillero;
        coordenada = this->consola->pedirCoordenada("poner un TesoroMina");
        casillero = this->tablero->getCasillero(coordenada);
        if(casillero->getEstado()!=Inactivo) {
            Ficha* tesoroMina;
            tesoroMina = new Ficha(TesoroMina, this->jugadorActual->devolverJugadorId(), coordenada);
            if(casillero->getEstado()==Ocupado){
                this->eliminarFichaDeLaListaDeFichasDelJugador(casillero->getFicha());
                casillero->setEstado(Inactivo);
                casillero->setTurnosRestantesInactivo(5);
                if(casillero->getFicha()->getTipo()==TesoroMina){
                    this->turnoValido  = Invalido;
                }
                delete casillero->getFicha();
                casillero->setFicha(NULL);
                delete tesoroMina;

            } else {
                this->colocarFicha(tesoroMina);
                this->jugadorActual->obtenerFichasDelJugador()->add(tesoroMina);
            }
        } else {
            this->consola->imprimirTexto("perdiste la ficha porque el casillero estaba inactivo");
            delete coordenada;
        }
    }

}


void TesoroBinario::metodoEspias() {
    if(this->consola->quiereEjecutarAccion("Quiere poner un espia?") && this->turnoValido==Valido){
        Coordenada* coordenada;
        Casillero* casillero;
        coordenada = this->consola->pedirCoordenada("poner un espia");
        casillero = this->tablero->getCasillero(coordenada);
        if(casillero->getEstado()!=Inactivo) {
            Ficha* espia;
            espia = new Ficha(Espia, this->jugadorActual->devolverJugadorId(), coordenada);
            if(casillero->getEstado()==Ocupado){
                switch (casillero->getFicha()->getTipo()) {
                    case Tesoro:
                        this->eliminarFichaDeLaListaDeFichasDelJugador(casillero->getFicha());
                        casillero->setEstado(Inactivo);
                        casillero->setTurnosRestantesInactivo(5);
                        delete casillero->getFicha();
                        casillero->setFicha(NULL);
                        break;
                    case Espia:
                        this->eliminarFichaDeLaListaDeFichasDelJugador(casillero->getFicha());
                        delete casillero->getFicha();
                        casillero->setFicha(NULL);
                        break;
                    case TesoroMina:
                        // Pierde el turno
                        this->eliminarFichaDeLaListaDeFichasDelJugador(casillero->getFicha());
                        casillero->setEstado(Inactivo);
                        casillero->setTurnosRestantesInactivo(5);
                        this->turnoValido = Invalido;
                        delete casillero->getFicha();
                        casillero->setFicha(NULL);
                        break;
                    case TesoroBlindado:
                        break;
                }
                delete espia;
            } else {
                this->colocarFicha(espia);
                this->jugadorActual->obtenerFichasDelJugador()->add(espia);
            }
        } else {
            this->consola->imprimirTexto("perdiste la ficha porque el casillero estaba inactivo");
        }
    }

}


void TesoroBinario::anunciarGanador() {

}


void TesoroBinario::metodoMoverTesoro() {
    if(this->consola->quiereEjecutarAccion("Quiere mover un tesoro de lugar") && this->turnoValido==Valido){
        Coordenada* coordenadaActual;
        Coordenada* coordenadaNueva;
        Casillero* casilleroActual, casilleroNuevo;


        coordenadaNueva = this->consola->pedirCoordenada("colocar Tesoro");
        //casilleroNuevo = this->tablero->getCasillero(coordenadaNueva);
        //TERMINAR!!!
        if(casilleroNuevo.getEstado() != Inactivo) {
            Ficha* fichaActual;
            coordenadaActual = this->consola->pedirCoordenada("elegir el tesoro a mover(no se puede mover Tesoro blindado)");
            casilleroActual = this->tablero->getCasillero(coordenadaActual);
            fichaActual = casilleroActual->getFicha();
            casilleroActual->setFicha(NULL);
            casilleroActual->setEstado(Vacio);
            delete coordenadaActual;
            fichaActual->setCoordenada(coordenadaNueva);

        } else {
            this->consola->imprimirTexto("perdiste la ficha porque el casillero estaba inactivo");
        }



    }

}


void TesoroBinario::restarContadoresDeInactividad() {

}


void TesoroBinario::restarContadoresDeBlindajeDeTesoros() {

}



//CODEAR
TesoroBinario::~TesoroBinario(){
}



//=)
