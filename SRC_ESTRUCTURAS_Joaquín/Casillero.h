
#ifndef CASILLERO_H
#define CASILLERO_H

#include "Tesoro.h"
#include "Espia.h"
#include "Lista.h"


class Casillero {
     Lista<Espia>* pEspias;
     Lista<Tesoro>* pTesoros;
};


#endif
