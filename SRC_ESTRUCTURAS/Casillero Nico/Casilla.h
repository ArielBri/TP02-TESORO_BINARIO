/*
 * Casillero.h
 *
 *  Created on: 12/06/2023
 *      Author: algo2
 */

#ifndef Casillero_H_
#define Casillero_H_
#include <string>
#include "Ficha.h"


enum EstadoCasillero{
	Ocupado,
	Vacio,
	Inactivo
}

class Casillero {

private:
	EstadoCasillero estado;
	Ficha* ficha;
	int turnosRestantesInactivo;

public:
	Casillero();
	EstadoCasillero getEstado();
	void setEstado(EstadoCasillero estado);
	Ficha* getFicha();
	void setFicha(Ficha* ficha);
	void restarTurnoInactivo();
	void ponerCasilleroInactivo();
	virtual ~Casillero();
};

#endif /* Casillero_H_ */
