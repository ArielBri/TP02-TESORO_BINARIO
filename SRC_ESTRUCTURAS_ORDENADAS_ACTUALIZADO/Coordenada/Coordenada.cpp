#include "Coordenada.h"


Coordenada::Coordenada(int ancho, int alto, int largo){
    setAncho(ancho);
    setAlto(alto);
    setLargo(largo);
}

int Coordenada::getAncho(){
    return this->ancho;
}
int Coordenada::getAlto(){
    return this->alto;
}
int Coordenada::getLargo(){
    return this->largo;
}

void Coordenada::setAncho(int ancho){
    this->ancho = ancho;
}
void Coordenada::setAlto(int alto){
    this->alto = alto;
}
void Coordenada::setLargo(int largo){
    this->largo = largo;
}

Coordenada::~Coordenada(){

}