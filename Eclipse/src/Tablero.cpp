#include "Tablero.h"


// ANCHO = X, ALTO = Y, LARGO = Z
Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
    validarCoordenadas(ancho, alto, largo);

    this->casilleros = new Lista<Lista<Lista<Casillero *> *> *>();
    this->ancho = ancho;
    this->alto = alto;
    this->largo = largo;

    for( int i= 0; i < ancho; i++){
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



unsigned int Tablero::getAncho() {
    return this->ancho;
}

unsigned int Tablero::getAlto() {
    return this->alto;
}

unsigned int Tablero::getLargo() {
    return this->largo;
}
// ANCHO = X, ALTO = Y, LARGO = Z
Casillero * Tablero::getCasillero(unsigned int anchoCasillero, unsigned int altoCasillero, unsigned int largoCasillero) {
    validarCoordenadas(anchoCasillero, altoCasillero, largoCasillero);
    return this->casilleros->get(anchoCasillero)->get(altoCasillero)->get(largoCasillero);
}

Casillero * Tablero::getCasillero(Coordenada *coordenada) {
    return getCasillero(coordenada->getAncho(), coordenada->getAlto(), coordenada->getLargo());
}


void Tablero::validarCoordenadas(unsigned int anchoIngresado, unsigned int altoIngresado, unsigned int largoIngresado){
    // Tienen un minimo
    if(anchoIngresado < 1||altoIngresado < 1||largoIngresado < 1){
        throw "Los parametros deben ser mayor a 0";
    }
    // ver bien que deben cumplir los parametros.
}


bool Tablero::coordenadaDentroDelTablero(unsigned int anchoIngresado, unsigned int altoIngresado,
                                         unsigned int largoIngresado) {
    if (anchoIngresado < 1 || anchoIngresado > this->getAncho() || altoIngresado < 1 || altoIngresado > this->getAlto()
                           || largoIngresado < 1 || largoIngresado > this->getLargo()) {
        return false;
    }
    return true;
}

Lista<Lista<Lista<Casillero *> *> *> * Tablero::getCasilleros (){
	return this->casilleros;
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


