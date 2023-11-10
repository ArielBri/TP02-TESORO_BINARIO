#include "Jugador.h"

Jugador::Jugador(int numeroDeJugador){
    if(numeroDeJugador<=0){
        throw "Numero negativo o cero";
    }
    this->fichas = new Lista<Ficha*>();
    this->idJugador=numeroDeJugador;
    //this->cartasDelJugador= new Lista<Carta*>();
}



int Jugador::devolverJugadorId(){
    return this->idJugador;
}


/*void Jugador::obtenerCarta(Mazo* mazo){
    this->cartasDelJugador->add(mazo->obtenerCarta());
}*/


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


/*Lista<Carta *> *Jugador::obtenerCartasDelJugador() {
    return this->cartasDelJugador;
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
}*/
Jugador::~Jugador(){
    
}