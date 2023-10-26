/*
 * TesoroBinario.cpp
 *
 *  Created on: 13/09/2023
 *      Author: algo2
 */

#include "TesoroBinario.h"


TesoroBinario::TesoroBinario() {
	this->tablero= new Tablero();
	this->turnoDeJugador= 1;

}

void TesoroBinario::jugar(){

	while(this->noHayGanador()){
		this->mostrarTablero();
		this->ponerEspia();
		if(this->quiereMoverTesoro()){
			this->moverTesoro();
		}
		this->exportarTablero();
		this->restarContadoresDeInactividad();
		this->cambiarTurnoDe();
	}

	std::cout<<"Termino el juego"<<std::endl;

}

bool TesoroBinario::noHayGanador(){
	int tesorosJugador1=0;
	int tesorosJugador2=0;

	for(int x=0; x<this->tablero->getX(); x++){
		for(int y=0; y<this->tablero->getY(); y++){
			if( (this->tablero->getCasilla(x,y)->getEstado()== Activa) && (this->tablero->getCasilla(x,y)->getFicha()->getTipo()== Tesoro) ){
				if(this->tablero->getCasilla(x,y)->getFicha()->getJugador()== 1){
					tesorosJugador1 += 1;
				}
				else{
					tesorosJugador2 += 1;
				}
			}
		}
	}
	if( (tesorosJugador1 == 0) || (tesorosJugador2 == 0) ){
		return false;
	}

	return true;
}

void TesoroBinario::mostrarTablero(){
	std::cout << "Turno de jugador: " << this->turnoDeJugador << std::endl;

	std::cout << " ";

	std::cout<<std::endl;



	for (int x=0; x<this->tablero->getX(); x++){

		for (int y=0; y<tablero->getY(); y ++){

			if(tablero->getCasilla(x,y)->getEstado()== Inactiva){
				std::cout << "X";
			}
			else{

				if(tablero->getCasilla(x,y)->getFicha()->getJugador()== this->turnoDeJugador){
					if(tablero->getCasilla(x,y)->getFicha()->getTipo()== Tesoro){
						std::cout << "T";
					}
					else{
						std::cout << "E";
					}
				}
				else{
					std::cout << "?";
				}
			}

		}
		std::cout <<std::endl;
	}
	std::cout <<std::endl;
}

void TesoroBinario::ponerEspia(){
	int x;
	int y;

	std::cout << "Ingrese numero de X a dejar Espia" << std::endl;
	std::cin >>x;
	std::cout << "Ingrese numero de Y a dejar Espia" << std::endl;
	std::cin >>y;

	if(this->tablero->getCasilla(x,y)->getFicha()->getTipo()== Tesoro){
		this->tablero->getCasilla(x,y)->ponerInactiva();
		this->tablero->getCasilla(x,y)->getFicha()->vaciarFichar();
	}
	if(this->tablero->getCasilla(x,y)->getFicha()->getTipo()== Vacia){
		this->tablero->getCasilla(x,y)->getFicha()->setJugadorTipo(this->turnoDeJugador,Espia);
	}
	if( (this->tablero->getCasilla(x,y)->getFicha()->getTipo()== Espia) && (this->tablero->getCasilla(x,y)->getFicha()->getJugador() != this->turnoDeJugador) ){
		this->tablero->getCasilla(x,y)->getFicha()->vaciarFichar();
	}

}

bool TesoroBinario::quiereMoverTesoro(){
	int respuesta;
	std::cout << "Ingrese 1 siquiere mover un Tesoro, 0 en caso contrario" << std::endl;
	std::cin >>respuesta;
	if(respuesta == 1){
		return true;
	}
	return false;
}

void TesoroBinario::moverTesoro(){
	int xActual;
	int yActual;

	int xSiguiente;
	int ySiguiente;

	std::cout << "Ingrese numero de X de Tesoro a mover" << std::endl;
	std::cin >>xActual;
	std::cout << "Ingrese numero de Y de Tesoro a mover" << std::endl;
	std::cin >>yActual;

	std::cout << "Ingrese numero de X donde mover" << std::endl;
	std::cin >>xSiguiente;
	std::cout << "Ingrese numero de Y donde mover" << std::endl;
	std::cin >>ySiguiente;

	if( (this->tablero->getCasilla(xSiguiente,ySiguiente)->getFicha()->getTipo()== Tesoro) && (this->tablero->getCasilla(xSiguiente,ySiguiente)->getFicha()->getJugador() != this->turnoDeJugador) ){
		std::cout << "En los X,Y ingresados hay un tesoro enemigo" << std::endl;
	}
	if( this->tablero->getCasilla(xSiguiente,ySiguiente)->getFicha()->getTipo()== Espia ){
		this->tablero->getCasilla(xActual,yActual)->getFicha()->vaciarFichar();
		this->tablero->getCasilla(xSiguiente,ySiguiente)->getFicha()->vaciarFichar();
		this->tablero->getCasilla(xSiguiente,ySiguiente)->ponerInactiva();
	}
	if( this->tablero->getCasilla(xSiguiente,ySiguiente)->getFicha()->getTipo()== Vacia ){
		this->tablero->getCasilla(xSiguiente,ySiguiente)->getFicha()->setJugadorTipo(this->turnoDeJugador, Tesoro);
		this->tablero->getCasilla(xActual,yActual)->getFicha()->vaciarFichar();
	}

}

void TesoroBinario::exportarTablero(){
	std::string ruta;

	if(this->turnoDeJugador == 1){
		ruta="Tablero jugador 1";
	}else{
		ruta="Tablero jugador 2";
	}

	std::ofstream salida;
	salida.open(ruta.c_str());


	salida << "Turno de jugador: " << this->turnoDeJugador << std::endl;

	salida << " ";


	for (int x=0; x<this->tablero->getX(); x++){

		for (int y=0; y<tablero->getY(); y ++){

			if(tablero->getCasilla(x,y)->getEstado()== Inactiva){
				salida << "X";
			}
			else{

				if(tablero->getCasilla(x,y)->getFicha()->getJugador()== this->turnoDeJugador){
					if(tablero->getCasilla(x,y)->getFicha()->getTipo()== Tesoro){
						salida << "T";
					}
					else{
						salida << "E";
					}
				}
				else{
					salida << "?";
				}
			}

		}
		salida <<std::endl;
	}
	salida <<std::endl;

	salida.close();
}

void TesoroBinario::restarContadoresDeInactividad(){

	for (int x=0; x<this->tablero->getY(); x++){
		for (int y=0; y<tablero->getY(); y ++){
			if(tablero->getCasilla(x,y)->getEstado()== Inactiva){
				tablero->getCasilla(x,y)->restarUnoACantididadDeTurnosInactiva();
			}
		}
	}

}

void TesoroBinario::cambiarTurnoDe(){
	if(this->turnoDeJugador==1){
		this->turnoDeJugador=2;
	}
	else{
		this->turnoDeJugador=1;
	}
}

TesoroBinario::~TesoroBinario() {
	delete this->tablero;
}

