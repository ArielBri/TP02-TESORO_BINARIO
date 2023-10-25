
#include "Casillero.h"

Casillero::Casillero(TipoCasillero tipo) {
	this->tipo = tipo;
	this->estado = Vacio;
	this->ficha = NULL;
	this->turnosRestantesInactivo = 0;

}

EstadoCasillero Casillero::getEstado(){
	return this->estado;
}
void Casillero::setEstado(EstadoCasillero estado){
	this->estado= estado;
}
Ficha* Casillero::getFicha(){
	return this->ficha;
}
void Casillero::setFicha(Ficha* ficha){
	this->ficha= ficha;
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

