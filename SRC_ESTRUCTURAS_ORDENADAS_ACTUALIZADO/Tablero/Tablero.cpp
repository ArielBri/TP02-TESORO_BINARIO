#include "Tablero.h"

Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
    validarCoordenadas(ancho, alto, largo);

    this->casilleros = new Lista<Lista<Lista<Casillero *> *> *>();
    this->ancho = ancho;
    this->alto = alto;
    this->largo = largo;

    for( int i = 0; i < ancho; i++){
        Lista<Lista<Casillero *> *>* fila = new Lista<Lista<Casillero *>*>();
        for( int j = 0; j < alto; j++) {
            Lista<Casillero *> * columna = new Lista<Casillero *>();
            for( int z = 0; z < largo; z++) {
                Casillero* casillero = new Casillero();
                columna->add(casillero);
            }
            fila->add(columna);
        }
        casilleros->add(fila);
    }
}

Tablero::~Tablero() {
    this->casilleros->reiniciarCursor();
    while (this->casilleros->avanzarCursor()) {
        Lista<Lista<Casillero *> *> * fila = this->casilleros->getCursor();
        fila->reiniciarCursor();
        while (fila->avanzarCursor()) {
            Lista<Casillero *> * columna = fila->getCursor();
            columna->reiniciarCursor();
            while (columna->avanzarCursor()) {
                delete columna->getCursor();
            }
            delete columna;
        }
        delete fila;
    }
    delete this->casilleros;
}

unsigned int Tablero::getAncho() {
    return this->ancho;
}

unsigned int Tablero::getAlto() {
    return this->alto;
}

unsigned int Tablero::getLargo() {
    return this->largo;
}

Casillero * Tablero::getCasillero(unsigned int ancho, unsigned int alto, unsigned int largo) {
    validarCoordenadas(ancho, alto, largo);
    return this->casilleros->get(ancho)->get(alto)->get(largo);
}

void Tablero::validarCoordenadas(unsigned int anchoIngresado, unsigned int altoIngresado, unsigned int largoIngresado){
    if(anchoIngresado < 1){
        throw "El ancho debe ser mayor igual a 0";
    }
    if(altoIngresado < 1){
        throw "El alto debe ser mayor igual a 0";
    }
    if(largoIngresado < 1){
        throw "El largo debe ser mayor igual a 0";
    }
    if(anchoIngresado > this->getAncho()){
        throw &"El amcho debe ser menor igual a " [  this->getAncho()];
    }
    if(altoIngresado > this->getAlto()){
        throw &"El alto debe ser menor igual a " [  this->getAlto()];
    }
    if(largoIngresado > this->getLargo()){
        throw &"El largo debe ser menor igual a " [ this->getLargo()];
    }
}

