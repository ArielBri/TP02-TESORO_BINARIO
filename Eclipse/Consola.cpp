#include "Consola.h"


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


void Consola::imprimirGandor(int idJugador) {
    std::cout<<"El ganador es el jugador numero: "<<idJugador<<std::endl;
}


Jugador* Consola::mostrarJugadoresActivosYElegirJugador(Vector<Jugador *> *vectorDeJugadores) {
    int indice = 1;
    int Id;
    Lista<int>* idJugadoresActivos = new Lista<int>;
    for(int i=1; i<=vectorDeJugadores->getLongitud(); i++){
        Jugador* jugador = vectorDeJugadores->obtener(i);
        if(jugador->getEstadoJugador()==Activo){
            std::cout<<indice<<".Jugador id:"<<i<<std::endl;
            idJugadoresActivos->add(i);
            indice++;
        }
    }
    do{
        std::cout<<"Ingrese el Id del jugador: "<<std::endl;
        std::cin>>Id;
        if(!idJugadoresActivos->pertenece(Id)){
            std::cout<<"Id no valido"<<std::endl;
        }
    } while (!idJugadoresActivos->pertenece(Id));
    delete idJugadoresActivos;
    return vectorDeJugadores->obtener(Id);
}

void Consola::mostrarEspiasDelJugador(Jugador *jugador) {
    Lista<Ficha*>* fichas = jugador->obtenerFichasDelJugador();
    fichas->reiniciarCursor();
    int contadorDeEspias = 0;
    std::cout<<"El Jugador "<<jugador->devolverJugadorId()<<std::endl;
    while (fichas->avanzarCursor()){
        Ficha* ficha = fichas->getCursor();
        if(ficha->getTipo()==Espia){
            Coordenada* coordenada = ficha->getCoordenada();
            contadorDeEspias++;
            std::cout<<"tiene un espia en la coordenada en (";
            std::cout<<coordenada->getAncho()<<","<<coordenada->getAlto()<<","<<coordenada->getLargo()<<")"<<std::endl;
        }
    }
    if(contadorDeEspias==0){
        std::cout<<"No tiene espias"<<std::endl;
    }
}

void Consola::tesoroEnLaCoordenada(int x, int y, int z){
	std::cout<<"Hay un tesoro en la coordenada: "<<x<<","<<y<<","<<z<<","<<std::endl;
}

void Consola::cantidadDeCartasQueSeAgregaron(int cantidad){
	std::cout<<"El numero de cartas que se agregaron es: "<<cantidad<<std::endl;
}

/*
int Consola::pedirJugadorId(int cant) {
    int Id;
    std::cout << " Ingrese el indice de la carta a jugar: ";
    std::cin >> Id;
    // validar que sea un numero.
    while (Id < 1 || Id > cantidadDeCartas) {
        std::cout << "Ingrese el indice de la carta dentro de rango: [1," << cantidadDeCartas << "]" << " a jugar: ";
        std::cin >> Id;
    }
    return Id;


}
*/
