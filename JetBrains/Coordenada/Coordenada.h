
#ifndef TP_2_COORDENADA_H
#define TP_2_COORDENADA_H


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
    /**
     * pre: -
     * pos: -
     */
    ~Coordenada();
};

#endif
