#include "Tablero.h"


// ANCHO = X, ALTO = Y, LARGO = Z
Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
    //validarCoordenadas(ancho, alto, largo);//<---------------------------------------La validacion de ancho, alto y largo se realiza en consola
										//<--------------------------------------- cuando se pide el ingreso del tamaño del tablero
    this->casilleros = new Lista<Lista<Lista<Casillero *> *> *>();
    this->ancho = ancho;
    this->alto = alto;
    this->largo = largo;

    for( int i= 0; i < ancho; i++){
        // lista[i]
        Lista<Lista<Casillero *> *>* fila = new Lista<Lista<Casillero *>*>();

        for( int j = 0; j < alto; j++) {
            // lista[i][j]
            Lista<Casillero *> * columna = new Lista<Casillero *>();
            for( int z = 0; z < largo; z++) {
                // lista[i][j][z]
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
// ANCHO = X, ALTO = Y, LARGO = Z
Casillero * Tablero::getCasillero(unsigned int ancho, unsigned int alto, unsigned int largo) {
    validarCoordenadas(ancho, alto, largo);
    return this->casilleros->get(ancho)->get(alto)->get(largo);
}

Casillero * Tablero::getCasillero(Coordenada *coordenada) {
    return getCasillero(coordenada->getAncho(), coordenada->getAlto(), coordenada->getAlto());
}

//<----------------------------------------------------MODIFICACION Y OBSERVACION: ESTA FUNCION DEBERIA ESTAR EN coordenadas.cpp
void Tablero::validarCoordenadas(unsigned int anchoIngresado, unsigned int altoIngresado, unsigned int largoIngresado){
	if (anchoIngresado < 1 || anchoIngresado > this->getAncho() || altoIngresado < 1 || altoIngresado > this->getAlto() || largoIngresado < 1 || largoIngresado > this->getLargo()) {
		throw "Las coordenadas deben estar dentro del rango del tablero";
	}	
}
/*void Tablero::validarCoordenadas(unsigned int anchoIngresado, unsigned int altoIngresado, unsigned int largoIngresado){
    // Tienen un minimo
    if(anchoIngresado < 1||altoIngresado < 1||largoIngresado < 1){
        throw "Los parametros deben ser mayor a 0";
    }
    // ver bien que deben cumplir los parametros.
}*/

