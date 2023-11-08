#include "Consola.h"



unsigned int Consola::solicitarCantidadDeJugadores() {
    int cantidadDeJugadores;
    std::cout << "Ingrese la cantidad de jugadores: ";
    std::cin >> cantidadDeJugadores;
    return cantidadDeJugadores;
}


unsigned int Consola::solicitarCantidadDeTesoros() {
    int cantidadDeTesoros;
    std::cout << "Ingrese la cantidad de tesoros: ";
    std::cin >> cantidadDeTesoros;
    return cantidadDeTesoros;
}


bool Consola::quiereEjecutarAccion(std::string accion){
    std::string respuesta = "vacio";
    std::cout<<accion<<" si/no"<<std::endl;
    std::cin>>respuesta;

    while (respuesta!="si"&&respuesta!="no"){
        std::cout<<"Respuesta Invalida"<<std::endl;
        std::cout<<accion<<" si/no"<<std::endl;
        std::cin>>respuesta;
    }
    return respuesta == "si";
}


Consola::Consola() {

}


void Consola::mostrarCartas(Lista<Carta *> *cartasDelJugador) {
    int indice = 1;
    int cartaNumero;
    cartasDelJugador->reiniciarCursor();
    while(cartasDelJugador->avanzarCursor()){
        Carta* carta = cartasDelJugador->getCursor();
        cartaNumero = carta->verCarta();
        std::cout<<indice<<".";
        switch (cartaNumero){
            case 0:
                std::cout<<"Blindaje";
                break;
            case 1:
                std::cout<<"Radar";
                break;
            case 2:
                std::cout<<"PartirTesoro";
                break;
            case 3:
                std::cout<<"Espias2";
                break;
            case 4:
                std::cout<<"Bloqueo";
                break;
            case 5:
                std::cout<<"Cartas2";
                break;
        }
        std::cout<<std::endl;
        indice++;
    }
}


Consola::~Consola() {

}


int Consola::pedirAlJugadorElIndiceDeCarta(int cantidadDeCartas) {
    int indice;
    std::cout << " Ingrese el indice de la carta a jugar: ";
    std::cin >> indice;
    // validar que sea un numero.
    while (indice < 1 || indice > cantidadDeCartas) {
        std::cout << "Ingrese el indice de la carta dentro de rango: [1," << cantidadDeCartas << "]" << " a jugar: ";
        std::cin >> indice;
    }
    return indice;
}

Coordenada *Consola::pedirCoordenada(std::string motivo) {
    Coordenada* coordenada;
    int ancho, alto, largo;
    std::cout<<"Ingrese coordenadas para "<<motivo<<std::endl;
    std::cout<<"Ingrese Ancho: ";
    std::cin>>ancho;
    std::cout<<"Ingrese Alto: ";
    std::cin>>alto;
    std::cout<<"Ingrese Largo: ";
    std::cin>>largo;
    coordenada = new Coordenada(ancho, alto, largo);
    return coordenada;

}

void Consola::imprimirTexto(std::string texto) {
     std::cout<<texto<<std::endl;
}

