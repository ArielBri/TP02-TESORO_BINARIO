#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "../Ficha/Ficha.h"

enum EstadoCasillero{
    Ocupado,
    Vacio,
    Inactivo
};

class Casillero {

private:
    EstadoCasillero estado;
    Ficha* ficha;
    int turnosRestantesInactivo;

public:
    /**
     * pre: -
     * pos: deja un casillero vacio creado de las coordenadas dadas
     */
    Casillero();
    EstadoCasillero getEstado();
    void setEstado(EstadoCasillero estado);
    Ficha* getFicha();
    void setFicha(Ficha* ficha);
    void restarTurnoInactivo();
    void ponerCasilleroInactivo();
    /**
     * pre: -
     * pos: elimina el casillero
     */
    virtual ~Casillero();
};



#endif /* CASILLERO_H_ */