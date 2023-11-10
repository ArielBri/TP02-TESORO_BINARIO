#ifndef COORDENADA_H
#define COORDENADA_H


//VALIDAR CON LOS DATOS TABLERO
// ANCHO = X, ALTO = Y, LARGO = Z
class Coordenada {
private:
    int ancho;
    int alto;
    int largo;

public:
    /**
     * pre: -
     * pos: -
     */
    Coordenada(int ancho, int alto, int largo);

    /**
     * pre: -
     * pos: -
     */
    int getAncho();
    /**
     * pre: -
     * pos: -
     */
    int getAlto();
    /**
     * pre: -
     * pos: -
     */
    int getLargo();
    /**
    * pre: -
    * pos: -
    */
    void setAncho(int ancho);
    /**
     * pre: -
     * pos: -
     */
    void setAlto(int alto);
    /**
     * pre: -
     * pos: -
    */
    void setLargo(int largo);
    /*
    * pos: si los valores no estan en rango, tira una excepcion
    */
    void validarCoordenadas(unsigned int anchoIngresado, unsigned int altoIngresado, unsigned int largoIngresado);
    /*
    */

    /**
    * pre: -
    * pos: -
    */
    ~Coordenada();
};

#endif