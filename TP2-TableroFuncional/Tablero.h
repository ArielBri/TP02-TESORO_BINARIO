#ifndef TABLERO_H_
#define TABLERO_H_
#include "Casillero.h"
#include "Lista.h"

class Tablero {
private:
    Lista<Lista<Lista<Casillero *> *> *> * casilleros;
    unsigned int ancho;
    unsigned int alto;
    unsigned int largo;
public:
    /**
    pre: las dimensiones deber ser iguales o mayor a 0
    pos: deja un tablero creado de las dimensiones dadas con todos los casillas vacias
    */
    Tablero(unsigned int ancho, unsigned int alto, unsigned int largo);

    /*
     * pos: elimina el tablero
     */
    virtual ~Tablero();

    /*
     * pos: devuelve el ancho del tablero
     */
    unsigned int getAncho();

    /*
     * pos: devuelve el alto del tablero
     */
    unsigned int getAlto();

    /*
     * pos: devuelve el largo del tablero
     */
    unsigned int getLargo();

    /*
     * pre: las dimensiones deber ser iguales o mayor a 0 y menos o igual al maximo asignado
     * pos: devuelve el casillero indicado
     */
    Casillero * getCasillero(unsigned int ancho, unsigned int alto, unsigned int largo);
    /*
     * Pre: las dimensiones de las coordenadas deber ser iguales o mayor a 0 y menos o igual al maximo asignado
     * Pos: devuelve el casillero indicado
     */
    Casillero * getCasillero(Coordenada* coordenada);
    /*
     * pos: devuelve el puntero al tablero dinamico
     */
    Lista<Lista<Lista<Casillero *> *> *> * getCasilleros();
    /*
     * pos: determina si los valores no estan en rango.
     */
    bool coordenadaDentroDelTablero(unsigned int anchoIngresado, unsigned int altoIngresado, unsigned int largoIngresado);


private:
    /*
     * Pos: si los valores no estan en rango, tira una excepcion
     */
    void validarCoordenadas(unsigned int ancho, unsigned int alto, unsigned int largo);

};

#endif /* TABLERO_H_ */
