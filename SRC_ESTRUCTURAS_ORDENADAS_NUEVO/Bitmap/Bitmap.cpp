#include "Bitmap.h"

void Bitmap::mostrarTablero(Tablero* tablero, Jugador* jugador) {

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

			if (a == longitudYCasilla-1) {
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

void Bitmap::crearImagenesTablero() {
	cout << "Creando imagenes..." << endl;
	bitmap_image imageXY(1920, 1080);
	bitmap_image imageXZ(1920, 1080);
	bitmap_image imageYZ(1920, 1080);
	for (unsigned int ejeX = 1; ejeX <= this->x+2; ejeX++) {
		for (unsigned int ejeY = 1; ejeY <= this->y+2; ejeY++) {
			for (unsigned int ejeZ = 1; ejeZ <= this->z+2; ejeZ++) {
				this->pintarPlano(imageYZ, ejeX, ejeY, this->z+3-ejeZ, this->y, this->z, this->x, 1920/(this->y+2), 1080/(this->z+2), ejeX, ejeY, ejeZ, "YZ");
				this->pintarPlano(imageXZ, ejeY, ejeX, this->z+3-ejeZ, this->x, this->z, this->y, 1920/(this->x+2), 1080/(this->z+2), ejeX, ejeY, ejeZ, "XZ");
				this->pintarPlano(imageXY, ejeZ, ejeX, ejeY, this->x, this->y, this->z, 1920/(this->x+2), 1080/(this->y+2), ejeX, ejeY, ejeZ, "XY");
			}
		}
	}
	imageXY.save_image("tableroXY.bmp");
	imageXZ.save_image("tableroXZ.bmp");
	imageYZ.save_image("tableroYZ.bmp");
}


void Bitmap::pintarPlano(bitmap_image &image, unsigned int ejeVista, unsigned int numeroCasillaHorizontalEnImagen, unsigned int numeroCasillaVerticalEnImagen,
		unsigned int cantidadCasillasHorizontalesEnImagen, unsigned int cantidadCasillasVerticalesEnImagen, unsigned int logitudEjeVista, unsigned int longituXCasilla,
		unsigned int longitudYCasilla, unsigned int i, unsigned int j, unsigned int k, std::string vista) {
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
		Casillero* casillero = this->tablero->obtener(i-1)->obtener(j-1)->obtener(k-1);
		this->pintar(image, ejeVista, casillero, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla);
	}
}

void Bitmap::pintar(bitmap_image &image, unsigned int ejeVista, Casillero* casillero, unsigned int numeroCasillaHorizontalEnImagen, unsigned int numeroCasillaVerticalEnImagen,
		unsigned int longituXCasilla, unsigned int longitudYCasilla) {
	if (numeroCasillaHorizontalEnImagen < 1 || numeroCasillaVerticalEnImagen < 1) {
		throw "El numero de casilla horizontal y vertical en imagen debe ser mayor a 0";
	}
	if (longituXCasilla < 1 || longitudYCasilla < 1) {
		throw "El numero de longitud horizontal y vertical en la casilla debe ser mayor a 0";
	}
	
	this->pintarFondoCasilla(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, 236, 226, 198, longituXCasilla, longitudYCasilla);
	if (casillero->getEstado() == Inactivo) {
		this->pintarFondoCasilla(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, 255, 0, 0, longituXCasilla, longitudYCasilla);
	}
	if (casillero->getFicha()->getTipo() == Tesoro /*&& casillero->getFicha->getJugadorId == JugadorActual()->getId()*/) {
		this->dibujarObjeto(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "tesoropixels.bmp");
	}
	if (casillero->getFicha()->getTipo() == Espia) {
		this->dibujarObjeto(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "espiapixels.bmp");
	}
	/*if (casillero->getFicha()->getTipo() == TesoroMina) {
		this->dibujarObjeto(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "tesorominapixel.bmp");
	}
	if (casillero->getFicha()->getTipo() == TesoroBlindado) {
		this->dibujarObjeto(image, numeroCasillaHorizontalEnImagen, numeroCasillaVerticalEnImagen, longituXCasilla, longitudYCasilla, "tesoroblindadopixelss.bmp");
	}*/
}
