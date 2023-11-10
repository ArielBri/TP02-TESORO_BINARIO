#include "Casillero.h"

Casillero::Casillero() {
    this->estado = Vacio;
    this->ficha = NULL;
    this->turnosRestantesInactivo = 0;
}

EstadoCasillero Casillero::getEstado(){
    return this->estado;
}
void Casillero::setEstado(EstadoCasillero estadoIngresado){
    if(estadoIngresado==Inactivo){
        this->setTurnosRestantesInactivo(5);
    }
    this->estado = estadoIngresado;
}

Ficha* Casillero::getFicha(){
    return this->ficha;
}

void Casillero::setFicha(Ficha* fichaIngresada){
    this->ficha = fichaIngresada;
    if(fichaIngresada==NULL){
        this->setEstado(Vacio);
    } else{
        this->setEstado(Ocupado);
    }
}

void Casillero::restarTurnoInactivo(){
    this->turnosRestantesInactivo -= 1;
    if (this->turnosRestantesInactivo == 0){
        this->estado = Vacio;
    }
}


void Casillero::setTurnosRestantesInactivo(int cantidadDeTurnos) {
    if(cantidadDeTurnos<0){
        throw "ERROR";
    }
    this->turnosRestantesInactivo = cantidadDeTurnos;
}


Casillero::~Casillero() {
}
