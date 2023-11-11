#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "Ficha.h"

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
     * pos: deja un casillero vacio creado.
     */
    Casillero();
    /**
     * pre: El casillero debe existir.
     * pos: Devuelve el estado del casillero.
     */
    EstadoCasillero getEstado();
    /**
     * pre: El casillero debe existir.
     * pos: Devuelve el casillero con un estado=estado.
     */
    void setEstado(EstadoCasillero estado);
    /**
     * pre: El casillero debe existir.
     * pos: Devuelve la ficha almacenada en el casillero tambien en caso que sea NULL;
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
    void setTurnosRestantesInactivo(int cantidadDeTurnos);
    /**
     * pre: -
     * pos: elimina el casillero
     */

    virtual ~Casillero();
};



#endif /* CASILLERO_H_ */
