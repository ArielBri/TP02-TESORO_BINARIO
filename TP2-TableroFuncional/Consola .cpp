#include "Consola .h"

unsigned int Consola::coordenadaValida(unsigned int longitud, std::string dimension, unsigned int londitudMaximaDeLaDimension){
	while(longitud <1 || longitud > londitudMaximaDeLaDimension){
		std::cout<<"El "<< dimension<<" debe estar entre 1 y "<<londitudMaximaDeLaDimension<<"\nIngrese "<<dimension<<": ";
		std::cin>>longitud;
	}
	return longitud;
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


Consola::Consola(unsigned int ancho, unsigned int alto, unsigned int largo) {
	this->anchoTablero=ancho;
	this->altoTablero=alto;
	this->largoTablero=largo;

}


void Consola::mostrarCartas(Lista<Carta *> *cartasDelJugador) {
    int indice = 1;
    int cartaNumero;
    std::cout<<"Cartas del mazo del jugador: "<<std::endl;
    cartasDelJugador->iniciarCursor();
    while(cartasDelJugador->avanzarCursor()){
        Carta* carta = cartasDelJugador->obtenerCursor();
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
                std::cout<<"MostrarEspiasDeJugadorActivo";
                break;
            case 4:
                std::cout<<"ObtenerCartas4";
                break;
            case 5:
                std::cout<<"Espias2";
                break;
        }
        std::cout<<std::endl;
        indice++;
    }
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
    unsigned int ancho, alto, largo;
    std::cout<<"Ingrese coordenadas para "<<motivo<<std::endl;
    std::cout<<"Ingrese Ancho: ";
    std::cin>>ancho;
    ancho = coordenadaValida(ancho,"ancho",this->anchoTablero);

    std::cout<<"Ingrese Alto: ";
    std::cin>>alto;
    alto = coordenadaValida(alto,"alto",this->altoTablero);

    std::cout<<"Ingrese Largo: ";
    std::cin>>largo;
    largo = coordenadaValida(largo,"largo",this->largoTablero);

    coordenada = new Coordenada(ancho, alto, largo);
    return coordenada;

}


void Consola::imprimirTexto(std::string texto) {
    std::cout<<texto<<std::endl;
}


void Consola::imprimirGanador(int idJugador) {
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
            idJugadoresActivos->agregar(i);
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
    fichas->iniciarCursor();
    int contadorDeEspias = 0;
    std::cout<<"El Jugador "<<jugador->devolverJugadorId()<<std::endl;
    while (fichas->avanzarCursor()){
        Ficha* ficha = fichas->obtenerCursor();
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
    std::cout<<"Hay un tesoro en la coordenada: ("<<x<<","<<y<<","<<z<<")"<<std::endl;
}

void Consola::cantidadDeCartasQueSeAgregaron(int cantidad){
    std::cout<<"El numero de cartas que se agregaron es: "<<cantidad<<std::endl;
}

void Consola::imprimirIdJugadorTurno(int idJugador){
    std::cout<<"\nEs el turno del Jugador: "<<idJugador<<std::endl;
}

Consola::~Consola() {

}
