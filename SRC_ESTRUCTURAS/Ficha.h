#ifndef FICHA_H_
#define FICHA_H_

enum TipoDeFicha{
    TESORO,
    ESPIA,
    MINA
};

class Ficha {
private:
    TipoDeFicha ficha;
    Jugador* jugador;
    
public:
    /**
	 * pre: se le pasa un tipo de ficha y un puntero a jugador para crear, cuando se da de alta el mapa ya se crea con tipo BLANCO y jugador en NULL
	 * pos: crea una ficha
	 */
    Ficha(TipoDeFicha ficha, Jugador* jugador);

    /**
	 * pos: elimina la ficha
	 */
    virtual ~Ficha();

    /**
	 * pos: devuelve el tipo de ficha como enum 
	 */
    TipoDeFicha getFicha();

    /**
	 * pos: Devuelve el jugador
	 */
    Jugador* getJugador();
};

#endif /* FICHA_H_ */
