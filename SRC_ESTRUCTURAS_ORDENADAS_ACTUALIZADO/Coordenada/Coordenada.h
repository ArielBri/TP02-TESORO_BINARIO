
#ifndef TP_2_COORDENADA_H
#define TP_2_COORDENADA_H


//VALIDAR CON LOS DATOS TABLERO
// ANCHO = X, ALTO = Y, LARGO = Z
class Coordenada {
private:
    int ancho;
    int alto;
    int largo;
   	unsigned int* coordenadas; /*//<----------------------------------------------------MODIFICACION Y OBSERVACION: ESTA FUNCION DEBERIA ESTAR EN coordenadas.cpp


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

    /*//<----------------------------------------------------MODIFICACION Y OBSERVACION: ESTA FUNCION DEBERIA ESTAR EN coordenadas.cpp
    *
    * pos: si los valores no estan en rango, tira una excepcion
    */
    void validarCoordenadas(unsigned int ancho, unsigned int alto, unsigned int largo);
    /*
    */

    /**
    * pre: -
    * pos: -
    */
    ~Coordenada();
};

#endif
