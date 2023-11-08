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

/*//<----------------------------------------------------MODIFICACION Y OBSERVACION: ESTA FUNCION DEBERIA ESTAR EN coordenadas.cpp
*
*/
void Coordenada::validarCoordenadas(unsigned int anchoIngresado, unsigned int altoIngresado, unsigned int largoIngresado){
	if (anchoIngresado < 1 || anchoIngresado > this->getAncho() || altoIngresado < 1 || altoIngresado > this->getAlto() || largoIngresado < 1 || largoIngresado > this->getLargo()) {
		throw "Las coordenadas deben estar dentro del rango del tablero";
	}
	this->coordenadas[0] = anchoIngresado;
	this->coordenadas[1] = altoIngresado;
	this->coordenadas[2] = largoIngresado;
}
/*
*/

Coordenada::~Coordenada(){

}
