#include "Jugador .h"

Jugador::Jugador(int numeroDeJugador){
    if(numeroDeJugador<=0){
        throw "Numero negativo o cero";
    }
    this->estado = Activo;
    this->fichas = new Lista<Ficha*>();
    this->idJugador=numeroDeJugador;
    this->cartasDelJugador= new Lista<Carta*>();
    this->pierdeTurno = 0;
}

//_____________________________________________________FUNCIONES PARA CUANDO PIERDE UN TURNO

void Jugador::setPierdeTurno(){
	this->pierdeTurno=2;
}

int Jugador::getPierdeTurno(){
	return this->pierdeTurno;
}

void Jugador::restarPierdeTurno(){
	if(this->pierdeTurno>0){
		this->pierdeTurno--;
	}
}
//_____________________________________________________FUNCIONES PARA CUANDO PIERDE UN TURNO

int Jugador::devolverCantidadDeTesoros(){
    this->fichas->iniciarCursor();
    int contadorDeTesoros = 0;

    while(this->fichas->avanzarCursor()){
        if(this->fichas->obtenerCursor()->getTipo()==Tesoro || this->fichas->obtenerCursor()->getTipo()==TesoroBlindado){
            contadorDeTesoros++;
        }
    }
    return contadorDeTesoros;
}


int Jugador::devolverJugadorId(){
    return this->idJugador;
}


void Jugador::obtenerCarta(Mazo* mazo){
    this->cartasDelJugador->agregar(mazo->obtenerCarta());
}


Lista<Ficha*>* Jugador::obtenerFichasDelJugador(){
    return this->fichas;
}


Lista<Carta *> *Jugador::obtenerCartasDelJugador() {
    return this->cartasDelJugador;
}


EstadoJugador Jugador::getEstadoJugador() {
    return this->estado;
}


Jugador::~Jugador(){
    // CARTAS
    this->cartasDelJugador->iniciarCursor();
    while (cartasDelJugador->avanzarCursor()){
        delete cartasDelJugador->obtenerCursor();
    }
    delete this->cartasDelJugador;
    // FICHAS
    this->fichas->iniciarCursor();
    while (this->fichas->avanzarCursor()){
        delete this->fichas->obtenerCursor();
    }
    delete this->fichas;
}

void Jugador::setEstadoJugador(EstadoJugador estadoJugador) {
    this->estado = estadoJugador;
}
