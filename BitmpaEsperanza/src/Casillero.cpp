#include "Casillero.h"

Casillero::Casillero() {
    this->estado = Vacio;
    this->ficha = new Ficha(TesoroMina,1);
    this->turnosRestantesInactivo = 0;
}

EstadoCasillero Casillero::getEstado(){
    return this->estado;
}
void Casillero::setEstado(EstadoCasillero estadoIngresado){
    this->estado= estadoIngresado;
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

void Casillero::ponerCasilleroInactivo(){
    this->turnosRestantesInactivo = 5;
}

Casillero::~Casillero() {
}
