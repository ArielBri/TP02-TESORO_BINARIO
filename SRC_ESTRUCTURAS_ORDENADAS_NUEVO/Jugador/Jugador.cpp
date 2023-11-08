#include "Jugador.h"

Jugador::Jugador(int numeroDeJugador){
    if(numeroDeJugador<=0){
        throw "Numero negativo o cero";
    }
    this->fichas = new Lista<Ficha*>();
    this->idJugador=numeroDeJugador;
    this->cartasDelJugador= new Lista<Carta*>();
}

//CODEAR
int Jugador::devolverCantidadDeTesoros(){

    return 0;
}


int Jugador::devolverJugadorId(){
    return this->idJugador;
}


void Jugador::obtenerCarta(Mazo* mazo){
    this->cartasDelJugador->add(mazo->obtenerCarta());
}


void Jugador::validarCantCartas(){
    if (this->cartasDelJugador->contarElementos()<0){
        throw "El numero de cartas tiene que ser mayor a 0";
    }
}


void Jugador::jugarCarta(int posicion){
    validarCantCartas();
    Carta* carta= this->cartasDelJugador->get(posicion);
    this->cartasDelJugador->remover(posicion);
}


// CODEAR crea de forma aleatoria los tesoros
void Jugador::inicializarTesoros(int cantidadDeTesoros){
    Lista<Ficha*>* fichasJugador = this->fichas;
    for(int i=0; i<cantidadDeTesoros; i++){
        //fichasJugador->add(new Ficha(Tesoro, this->idJugador));
    }

}


Lista<Ficha*>* Jugador::obtenerFichasDelJugador(){
    return this->fichas;
}


Jugador::~Jugador(){
    this->cartasDelJugador->reiniciarCursor();
    while (cartasDelJugador->avanzarCursor()){
        delete cartasDelJugador->getCursor();
    }
    this->fichas->reiniciarCursor();
    while (this->fichas->avanzarCursor()){
        delete this->fichas->getCursor();
    }
    delete this->cartasDelJugador;
    delete this->fichas;
}

Lista<Carta *> *Jugador::obtenerCartasDelJugador() {
    return this->cartasDelJugador;
}
