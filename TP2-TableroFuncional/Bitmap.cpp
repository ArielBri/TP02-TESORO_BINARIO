#include "Bitmap.h"
#include "Tablero.h"
void Bitmap::mostrarTablero(Tablero* tablero, Jugador* jugador) {
	crearImagenesTablero(tablero, jugador);
}

std::string Bitmap::intToString(int numero) {
    std::ostringstream convert;
    convert << numero;
    return convert.str();
}

void Bitmap::pintarFondoCasilla(bitmap_image &image, unsigned int numeroCasillaHorizontal, unsigned int numeroCasillaVertical, unsigned int rojo, unsigned int azul, unsigned int verde,
                                unsigned int longituXCasilla, unsigned int longitudYCasilla) {

    for (unsigned int b = 0; b < longituXCasilla; b++) {
        for (unsigned int a = 0; a < longitudYCasilla; a++) {
            image.set_pixel((numeroCasillaHorizontal-1)*longituXCasilla+b, (numeroCasillaVertical-1)*longitudYCasilla+a, rojo, azul, verde);

            if (a == longitudYCasilla-1) {//<--------------------------------------------------------------------------------originalmente en 0, 0, 0
                image.set_pixel((numeroCasillaHorizontal-1)*longituXCasilla+b, (numeroCasillaVertical-1)*longitudYCasilla+a, 0, 0, 0);
            }
            if (b == longituXCasilla-1) {
                image.set_pixel((numeroCasillaHorizontal-1)*longituXCasilla+b, (numeroCasillaVertical-1)*longitudYCasilla+a, 0, 0, 0);
            }
        }
    }
}


void Bitmap::dibujarNumero(bitmap_image &imagen, unsigned int numeroCasillaHorizontal, unsigned int numeroCasillaVertical, unsigned int longituXCasilla, unsigned int longitudYCasilla,
                           unsigned int nroCasilla) {
    bitmap_image imagen1(this->intToString(nroCasilla/10)+".bmp");
    bitmap_image imagen2(this->intToString(nroCasilla%10)+".bmp");
    unsigned char r1, g1, b1, r2, g2, b2;
    for (unsigned int i = 1; i <= longituXCasilla; i++) {
        for (unsigned int j = 1; j <= longitudYCasilla; j ++) {
            imagen1.get_pixel((i-1)*imagen1.width()/longituXCasilla, (j-1)*imagen1.height()/longitudYCasilla, r1, g1, b1);
            imagen2.get_pixel((i-1)*imagen2.width()/longituXCasilla, (j-1)*imagen2.height()/longitudYCasilla, r2, g2, b2);

            imagen.set_pixel((numeroCasillaHorizontal-1)*longituXCasilla+(i-1)/2, (numeroCasillaVertical-1)*longitudYCasilla+(j-1), r1, g1, b1);
            imagen.set_pixel(longituXCasilla/2 +(numeroCasillaHorizontal-1)*longituXCasilla+(i-1)/2, (numeroCasillaVertical-1)*longitudYCasilla+(j-1), r2, g2, b2);
        }
    }

    for (unsigned int i = 1; i <= longituXCasilla; i++) {
        for (unsigned int j = 1; j <= longitudYCasilla; j ++) {
            if (i == longituXCasilla) {
                imagen.set_pixel((numeroCasillaHorizontal-1)*longituXCasilla+(i-1), (numeroCasillaVertical-1)*longitudYCasilla+(j-1), 0, 0, 0);
            }
            if (j == longitudYCasilla) {
                imagen.set_pixel((numeroCasillaHorizontal-1)*longituXCasilla+(i-1), (numeroCasillaVertical-1)*longitudYCasilla+(j-1), 0, 0, 0);
            }
        }
    }
}

void Bitmap::dibujarObjeto(bitmap_image &imagen, unsigned int numeroCasillaHorizontalEnImagen, unsigned int numeroCasillaVerticalEnImagen, unsigned int longituXCasilla,
                           unsigned int longitudYCasilla, std::string nombreImagen) {

    if (numeroCasillaHorizontalEnImagen < 1 || numeroCasillaVerticalEnImagen < 1) {
        throw "El numero de casilla horizontal y vertical en imagen debe ser mayor a 0";
    }
    if (longituXCasilla < 1 || longitudYCasilla < 1) {
        throw "El numero de longitud horizontal y vertical en la casilla debe ser mayor a 0";
    }

    bitmap_image imagen1(nombreImagen);
    unsigned char r1, g1, b1;
    for (unsigned int i = 1; i <= longituXCasilla; i++) {
        for (unsigned int j = 1; j <= longitudYCasilla; j ++) {
            imagen1.get_pixel((i-1)*imagen1.width()/longituXCasilla, (j-1)*imagen1.height()/longitudYCasilla, r1, g1, b1);

            if (r1 != 255 && g1 != 255 && b1 != 255) {
                imagen.set_pixel((numeroCasillaHorizontalEnImagen-1)*longituXCasilla+(i-1), (numeroCasillaVerticalEnImagen-1)*longitudYCasilla+(j-1), r1, g1, b1);
            }
            if (i == longituXCasilla) {
                imagen.set_pixel((numeroCasillaHorizontalEnImagen-1)*longituXCasilla+(i-1), (numeroCasillaVerticalEnImagen-1)*longitudYCasilla+(j-1), 0, 0, 0);
            }
            if (j == longitudYCasilla) {
                imagen.set_pixel((numeroCasillaHorizontalEnImagen-1)*longituXCasilla+(i-1), (numeroCasillaVerticalEnImagen-1)*longitudYCasilla+(j-1), 0, 0, 0);
            }
        }
    }
}

void Bitmap::crearImagenesTablero(Tablero* tablero,Jugador*jugador) {
    cout << "Creando imagenes..." << endl;
    bitmap_image imageXY(1920, 1080);
    bitmap_image imageXZ(1920, 1080);
    bitmap_image imageYZ(1920, 1080);
    for (unsigned int ejeX = 1; ejeX <= tablero->getAncho()+2; ejeX++) {
        for (unsigned int ejeY = 1; ejeY <= tablero->getAlto()+2; ejeY++) {
            for (unsigned int ejeZ = 1; ejeZ <= tablero->getLargo()+2; ejeZ++) {
                this->pintarPlano(imageYZ, ejeX, ejeY, tablero->getLargo()+3-ejeZ, tablero->getAlto(), tablero->getLargo(), tablero->getAncho(), 1920/(tablero->getAlto()+2), 1080/(tablero->getLargo()+2), ejeX, ejeY, ejeZ, "YZ",tablero,jugador);
                this->pintarPlano(imageXZ, ejeY, ejeX, tablero->getLargo()+3-ejeZ, tablero->getAncho(), tablero->getLargo(), tablero->getAlto(), 1920/(tablero->getAncho()+2), 1080/(tablero->getLargo()+2), ejeX, ejeY, ejeZ, "XZ",tablero,jugador);
                this->pintarPlano(imageXY, ejeZ, ejeX, ejeY, tablero->getAncho(), tablero->getAlto(), tablero->getLargo(), 1920/(tablero->getAncho()+2), 1080/(tablero->getAlto()+2), ejeX, ejeY, ejeZ, "XY",tablero,jugador);
            }
        }
    }
    imageXY.save_image("tableroXY.bmp");
    imageXZ.save_image("tableroXZ.bmp");
    imageYZ.save_image("tableroYZ.bmp");
    std::cout<<"Tablero generado y las imagenes se han creado con exito"<<std::endl;
}


void Bitmap::pintarPlano(bitmap_image &image, unsigned int ejeVista, unsigned int numeroCasillaHorizontalEnImagen, unsigned int numeroCasillaVerticalEnImagen,
                         unsigned int cantidadCasillasHorizontalesEnImagen, unsigned int cantidadCasillasVerticalesEnImagen, unsigned int logitudEjeVista, unsigned int longituXCasilla,
                         unsigned int longitudYCasilla, unsigned int i, unsigned int j, unsigned int k, std::string vista,Tablero* tablero,Jugador* jugador) {
    if (numeroCasillaHorizontalEnImagen < 1 || numeroCasillaVerticalEnImagen < 1) {
        throw "El numero de casilla horizontal y vertical en imagen debe ser mayor a 0";
    }
    if (longituXCasilla < 1 || longitudYCasilla < 1) {
        throw "El numero de longitud horizontal y vertical en la casilla debe ser mayor a 0";
    }



    if (numeroCasillaHorizontalEnImagen == 1 || numeroCasillaHorizontalEnImagen == cantidadCasillasHorizontalesEnImagen+2 || numeroCasillaVerticalEnImagen == 1 ||
        numeroCasillaVerticalEnImagen == cantidadCasillasVerticalesEnImagen+2) {

        if (1 < numeroCasillaVerticalEnImagen && numeroCasillaVerticalEnImagen <= cantidadCasillasVerticalesEnImagen+1) {
            if (vista != "XY") {
                this->dibujarNumero(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla,
                                    cantidadCasillasVerticalesEnImagen+2-numeroCasillaVerticalEnImagen);
            }
            else {
                this->dibujarNumero(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, numeroCasillaVerticalEnImagen-1);
            }

        }
        if (1 < numeroCasillaHorizontalEnImagen && numeroCasillaHorizontalEnImagen <= cantidadCasillasHorizontalesEnImagen+1) {
            this->dibujarNumero(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, numeroCasillaHorizontalEnImagen-1);
        }
    }
    else if (ejeVista != 1 && ejeVista != logitudEjeVista+2){
        Casillero* casillero = tablero->getCasilleros()->obtener(i-1)->obtener(j-1)->obtener(k-1);
        this->pintar(image, ejeVista, casillero, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla,jugador);
    }
}

void Bitmap::pintar(bitmap_image &image, unsigned int ejeVista, Casillero* casillero, unsigned int numeroCasillaHorizontalEnImagen, unsigned int numeroCasillaVerticalEnImagen,
                    unsigned int longituXCasilla, unsigned int longitudYCasilla, Jugador* jugador) {
    if (numeroCasillaHorizontalEnImagen < 1 || numeroCasillaVerticalEnImagen < 1) {
        throw "El numero de casilla horizontal y vertical en imagen debe ser mayor a 0";
    }
    if (longituXCasilla < 1 || longitudYCasilla < 1) {
        throw "El numero de longitud horizontal y vertical en la casilla debe ser mayor a 0";
    }
    //Agrego la condicion para vacio
    if ((casillero->getEstado() == Vacio || casillero->getEstado() == Ocupado) && ejeVista == 2){
    	this->pintarFondoCasilla(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, 236, 226, 198, longituXCasilla, longitudYCasilla);
    }
    else if (casillero->getEstado() == Inactivo && ejeVista == 2) {
        this->pintarFondoCasilla(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, 255, 0, 0, longituXCasilla, longitudYCasilla);
    }
    if(casillero->getFicha()!=NULL){
    	if ( casillero->getFicha()->getTipo() == Tesoro && casillero->getFicha()->getJugadorId() == jugador->devolverJugadorId() ) {
    		this->dibujarObjeto(image,numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "tesoropixels.bmp");
    	}
    	if (casillero->getFicha()->getTipo() == Espia && casillero->getFicha()->getJugadorId() == jugador->devolverJugadorId()) {
        	this->dibujarObjeto(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "espiapixels.bmp");
    	}
    	if (casillero->getFicha()->getTipo() == TesoroMina && casillero->getFicha()->getJugadorId() == jugador->devolverJugadorId()) {
        	this->dibujarObjeto(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "tesorominapixel.bmp");
    	}
    	if (casillero->getFicha()->getTipo() == TesoroBlindado && casillero->getFicha()->getJugadorId() == jugador->devolverJugadorId()) {
        	this->dibujarObjeto(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "tesoroblindadopixelss.bmp");
    	}
    }
  }

