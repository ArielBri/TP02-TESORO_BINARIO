//============================================================================
// Name        : TP1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Tablero.h"
#include "Ficha.h"
#include "Casilla.h"
#include "TesoroBinario.h"


int main() {


	TesoroBinario *juego= new TesoroBinario();

	juego->jugar();

	delete juego;

	return 0;
}
