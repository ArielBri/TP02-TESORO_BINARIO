#include "Jugador.h"

Jugador::Jugador(int numeroDeJugador, int cantidadDeTesoros){
    if(numeroDeJugador<=0){
        throw "Numero negativo o cero";
    }
    this->idJugador=numeroDeJugador;
    this->cartasDelJugador= new Lista<Carta*>();
}



int Jugador::devolverJugadorId(){
    return this->idJugador;
}
void Jugador::obtenerCarta(Mazo* mazo){
    this->cartasDelJugador->add(mazo->obtenerCarta());
}
void Jugador::validarCantCartas(){
    if (this->cartasDelJugador->contarElementos()<0){
        throw &"El numero de cartas tiene que ser mayor a 0";
    }
}
int Jugador::mostrarCartas(){
    validarCantCartas();
    int posicion=0;
    int cartaNumero;
    std::string cartaAMostrar;
    this->cartasDelJugador->reiniciarCursor();
    while(this->cartasDelJugador->avanzarCursor()){
        Carta* carta= this->cartasDelJugador->getCursor();
        cartaNumero = carta->verCarta();
        switch (cartaNumero){
            case 0: cartaAMostrar = "Blindaje";
                break;
            case 1:
                cartaAMostrar = "Radar";
                break;
            case 2:
                cartaAMostrar = "PartirTesoro";
                break;
            case 3:
                cartaAMostrar = "Espias2";
                break;
            case 4:
                cartaAMostrar = "Bloqueo";
                break;
            case 5:
                cartaAMostrar = "Cartas2";
                break;
        }
        std::cout<<posicion<< "- " << cartaAMostrar <<std::endl;
        posicion++;
    }
    return posicion;
}
void Jugador::jugarCarta(int posicion){
    validarCantCartas();
    Carta* carta= this->cartasDelJugador->get(posicion);
    carta->usarCarta();
    this->cartasDelJugador->remover(posicion);
}


Jugador::~Jugador(){
    delete []this->cartasDelJugador;
}