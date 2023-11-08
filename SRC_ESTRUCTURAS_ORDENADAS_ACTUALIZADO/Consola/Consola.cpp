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

void Consola::menuDeOpciones() {
    std::cout<<"MENU DE OPCIONES"<<std::endl;
    std::cout<<"A - Sacar carta del mazo, para jugarla o guardarla: "<<std::endl;
    std::cout<<"B - Atacar posicion del tablero con TesoroMina: "<<std::endl;
    std::cout<<"C - Colocar espia en una posicion del tablero: "<<std::endl;
    std::cout<<"D - Mover un tesoro de lugar: "<<std::endl;
}

void Consola::validarEleccion(char opcion){
    if(opcion!='A' && opcion!='B' && opcion!='C' && opcion!='D'){
        throw "Esa opcion no es valida";
    }
}

char Consola::eleccion(){
    char opcion;
    std::cout<<"Ingrese una opcion"<<std::endl;
    std::cin>> opcion;
    validarEleccion(opcion);
    return opcion;
}
