#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "../Ficha/Ficha.h"

#ifndef NULL
#define NULL 0
#endif

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
    /**
     * pre: -
     * pos: -
     */
    EstadoCasillero getEstado();
    /**
     * pre: -
     * pos: -
     */
    void setEstado(EstadoCasillero estado);
    /**
     * pre: -
     * pos: -
     */
    Ficha* getFicha();
    /**
     * pre: -
     * pos: -
     */
    void setFicha(Ficha* ficha);
    /**
     * pre: -
     * pos: -
     */
    void restarTurnoInactivo();
    /**
     * pre: -
     * pos: -
     */
    void ponerCasilleroInactivo();
    /**
     * pre: -
     * pos: elimina el casillero
     */

    virtual ~Casillero();
};



#endif /* CASILLERO_H_ */