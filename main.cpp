#include "SRC_ESTRUCTURAS_ORDENADAS_NUEVO/SRC.h"


void determinarParametros(int &ancho, int &alto, int &largo, int cantidadDeJugadores, int cantidadDeTesoros){
    int cantidadDeCasillerosMinima = cantidadDeJugadores*cantidadDeTesoros;

    ancho = cantidadDeCasillerosMinima/2;
    if(cantidadDeJugadores%2!=0){
        ancho++;
    }

    alto = ancho=5;

    largo = cantidadDeJugadores = 3;
}



int main() {
    std::cout<<rand()%4<<std::endl;
    std::cout<<rand()%4<<std::endl;
    std::cout<<rand()%4<<std::endl;
    std::cout<<rand()%4<<std::endl;
    /*
    int cantidadJugadores = 3, cantidadDeTesoros=3, alto, largo, ancho;

    std
    determinarParametros(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
    TesoroBinario* tesoro;
    tesoro = new TesoroBinario(ancho, alto, largo, cantidadJugadores, cantidadDeTesoros);
    tesoro->jugar();
    delete tesoro;
    */
    /*
    Consola* consola;
    consola = new Consola();
    Coordenada* coordenada = new Coordenada(1,1,1);
    Ficha* ficha = new Ficha(Espia, 3, coordenada);
    Jugador* jugadorNULL = NULL;
    Jugador* jugador1 = new Jugador(1);
    Jugador* jugador2 = new Jugador(2);
    Jugador* jugador3 = new Jugador(3);
    Vector<Jugador*>* vector = new Vector(3, jugadorNULL);

    vector->agregar(1,jugador1);
    vector->agregar(2, jugador2);
    vector->agregar(3, jugador3);
    jugador3->obtenerFichasDelJugador()->add(ficha);
    jugador2->setEstadoJugador(NoActivo);
    Jugador* jugador = consola->mostrarJugadoresActivosYElegirJugador(vector);
    consola->mostrarEspiasDelJugador(jugador);

    delete vector;
    delete jugador1;
    delete jugador2;
    delete jugador3;
    */
    //delete consola;
    /*

    Lista<Carta*>* listaCartas = new Lista<Carta*>;
    Carta* carta1;
    Carta* carta2;
    Carta* carta3;
    carta1 = new Carta(Blindaje);
    carta2 = new Carta(Radar);
    carta3 = new Carta(Bloqueo);
    listaCartas->add(carta1);
    listaCartas->add(carta2);
    listaCartas->add(carta3);
    // consola->mostrarCartas(listaCartas);
    std::cout<<consola->pedirAlJugadorElIndiceDeCarta(3)<<std::endl;
    delete consola;
    delete listaCartas;
    delete carta1;
    delete carta2;
    delete carta3;
     */
    return 0;
}
