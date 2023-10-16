// Tablero.cpp

#include "Tablero.h"


Tablero::Tablero(int cantidad_de_casilleros_direccion_X, int cantidad_de_casilleros_direccion_Y, int cantidad_de_casilleros_direccion_Z) {
    pLista = new Lista<Lista<Lista<Casillero*>>>();

    for (int x = 0; x < cantidad_de_casilleros_direccion_X; x++) {
        Lista<Lista<Casillero*>> listaY;
        for (int y = 0; y < cantidad_de_casilleros_direccion_Y; y++) {
            Lista<Casillero*> listaZ;
            for (int z = 0; z < cantidad_de_casilleros_direccion_Z; z++) {
                listaZ.add(new Casillero());
            }
            listaY.add(listaZ);
        }
        pLista->add(listaY);
    }
}

Casillero* Tablero::obtenercasillero(int posicionX, int posicionY, int posicionZ) {
    if (posicionX < 0 || posicionX >= pLista->contarElementos()) return nullptr;
    if (posicionY < 0 || posicionY >= pLista->get(posicionX).contarElementos()) return nullptr;
    if (posicionZ < 0 || posicionZ >= pLista->get(posicionX).get(posicionY).contarElementos()) return nullptr;

    return pLista->get(posicionX).get(posicionY).get(posicionZ);
}


Tablero::~Tablero() {
    for (int x = 0; x < pLista->contarElementos(); x++) {
        for (int y = 0; y < pLista->get(x).contarElementos(); y++) {
            for (int z = 0; z < pLista->get(x).get(y).contarElementos(); z++) {
                delete pLista->get(x).get(y).get(z);
            }
        }
    }
    delete pLista;
}
