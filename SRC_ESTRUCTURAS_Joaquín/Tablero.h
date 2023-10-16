//
//

#ifndef TABLERO_H
#define TABLERO_H

#include "Lista.h"
#include "Casillero.h"


const int CANTIDAD_DE_CASILLEROS_DIRECCION_X = 10;
const int CANTIDAD_DE_CASILLEROS_DIRECCION_Y = 10;
const int CANTIDAD_DE_CASILLEROS_DIRECCION_Z = 10;


class Tablero {
private:
     Lista<Lista<Lista<Casillero*>>>* pLista;
public:
     Tablero(int cantidad_de_casilleros_direccion_X,int cantidad_de_casilleros_direccion_Y,int cantidad_de_casilleros_direccion_Z);
     Casillero* obtenercasillero(int posicionX, int posicionY, int posicionZ);
     ~Tablero();
};


#endif //TP_2_TABLERO_H
