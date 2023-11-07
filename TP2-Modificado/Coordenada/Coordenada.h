
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
    Coordenada(int ancho, int alto, int largo);
    int getAncho();
    int getAlto();
    int getLargo();

    void setAncho(int ancho);
    void setAlto(int alto);
    void setLargo(int largo);
    ~Coordenada();
};


#endif //TP_2_COORDENADA_H
