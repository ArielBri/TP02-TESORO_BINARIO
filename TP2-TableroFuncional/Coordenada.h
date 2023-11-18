
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
     * pos: crea una coordenada con los parametros pasados
     */
    Coordenada(int ancho, int alto, int largo);

    /**
     * pre: -
     * pos: devuelve el ancho de la coordenada
     */
    int getAncho();
    /**
     * pre: -
     * pos: devuelve el alto de la coordenada
     */
    int getAlto();
    /**
     * pre: -
     * pos: devuelve el largo de la coordenada
     */
    int getLargo();
    /**
    * pre: -
    * pos: cambia el largo de la coordenada
    */
    void setAncho(int ancho);
    /**
     * pre: -
     * pos: cambia el ancho de la coordenada
     */
    void setAlto(int alto);
    /**
     * pre: -
     * pos: cambia el alto de la coordenada
     */
    void setLargo(int largo);
    /**
     * pre: -
     * pos: -
     */
    ~Coordenada();
};

#endif
