#include "TesoroBinario.h"


TesoroBinario::TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores, int cantidadDeTesoros) {
    this->tablero = new Tablero(ancho, alto, largo);
    this->vectorDeJugadores = new Vector<Jugador*>(cantidadDeJugadores, NULL);
    for (int i = 1; i <= cantidadDeJugadores; i++) {
         Jugador* jugador = new Jugador(i);
         this->vectorDeJugadores->agregar(i, jugador);
    }
    this->cantidadDeTesorosInicial = cantidadDeTesoros;
    this->jugadorActual = NULL;
    this->mazo = new Mazo();
    this->cantidadDeJugadores = cantidadDeJugadores;
    this->consola = new Consola(ancho,alto,largo);
    this->bitmap = new Bitmap();
}


bool TesoroBinario::hayGanador(){
    int contadorDeJugadoresActivos = 0;
    for(int i=1; i<=this->cantidadDeJugadores; i++){
        Jugador* jugador= this->vectorDeJugadores->obtener(i);
        if(jugador->getEstadoJugador() == Activo){
            contadorDeJugadoresActivos++;
        }
        if (contadorDeJugadoresActivos>=2){
            return false;
        }
    }
    return true;
}


void TesoroBinario::colocarFicha(Ficha* ficha) {
    this->tablero->getCasillero(ficha->getCoordenada())->setEstado(Ocupado);
    this->tablero->getCasillero(ficha->getCoordenada())->setFicha(ficha);
}


void TesoroBinario::ejecutarTurno() {
    this->consola->imprimirIdJugadorTurno(this->jugadorActual->devolverJugadorId());
    //OPCIONES DEL TURNO:
    // Metodo A: Cartas
    this->metodoCartas();

    // Metodo B: Tesoro Mina
    this->metodoTesoroMina();

    // Metodo C: Espias
    this->metodoEspias();

    // Metodo D: Mover Tesoro no blindado.
    this->metodoMoverTesoro();

    // Tablero
    this->actualizarTablero();
    //
}



void TesoroBinario::usarCarta(Carta* carta){
    switch (carta->verCarta()) {
        case Blindaje:
            this->jugarBlindaje();
            break;
        case Radar:
            this->jugarRadar();
            break;
        case PartirTesoro:
            this->partirTesoro();
            break;
        case MostrarEspiasDeJugadorActivo:
        	this->jugarMostrarEspiasDeJugadorActivo();
            break;
        case ObtenerCartas4:
            this->jugarObtenerCartas4();
            break;
        case Espias2:
            this->jugarEspias2();
            break;
        default:
            throw "No se encontro la carta";
    }
    delete carta;

}


void TesoroBinario::limpiarCasillerosQueContenganLasFichasDelJugador(Lista<Ficha*>* fichas){
    fichas->iniciarCursor();
    while (fichas->avanzarCursor()){
        Coordenada* coordenadaDeFicha = fichas->obtenerCursor()->getCoordenada();
        this->tablero->getCasillero(coordenadaDeFicha)->setEstado(Vacio);
        this->tablero->getCasillero(coordenadaDeFicha)->setFicha(NULL);
    }
}

void TesoroBinario::borrarJugadoresQuePerdieron(){

    for(int i = 1; i<=this->cantidadDeJugadores; i++){
        Jugador* jugador = this->vectorDeJugadores->obtener(i);
        if(jugador->devolverCantidadDeTesoros() == 0){
        	jugador->setEstadoJugador(NoActivo);
            this->limpiarCasillerosQueContenganLasFichasDelJugador(jugador->obtenerFichasDelJugador());
        }
    }
}


void TesoroBinario::jugar(){

    this->inicializarJuego();

    while(!this->hayGanador()){
        int posicion = 1;
        while(!this->hayGanador() && posicion <= this->cantidadDeJugadores){
            this->jugadorActual = this->vectorDeJugadores->obtener(posicion);
            this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
        	this->jugadorActual->restarPierdeTurno();
        	if(this->jugadorActual->getEstadoJugador()==Activo && this->jugadorActual->getPierdeTurno()==0){
                this->ejecutarTurno();
            }
            this->borrarJugadoresQuePerdieron();
            posicion++;
        }
    }
    this->anunciarGanador();
    this->consola->imprimirTexto("Termino el juego");
}


void TesoroBinario::inicializarTesoros(int cantidadDeTesorosPorJugador, Jugador* jugador){
    int limite = (this->cantidadDeTesorosInicial*this->cantidadDeJugadores)/2;
	for(int i=1; i<=cantidadDeTesorosPorJugador; i++){
        Coordenada* coordenadaTesoro = new Coordenada(i,1+(rand()%limite),jugador->devolverJugadorId());
        Ficha* tesoro = new Ficha(Tesoro, jugador->devolverJugadorId(), coordenadaTesoro);
        jugador->obtenerFichasDelJugador()->agregar(tesoro);
        this->colocarFicha(tesoro);
    }
}


void TesoroBinario::inicializarJuego() {
    for(int i=1; i<= this->cantidadDeJugadores; i++){
        Jugador* jugador = this->vectorDeJugadores->obtener(i);
        this->inicializarTesoros(this->cantidadDeTesorosInicial,jugador);
    }
}


void TesoroBinario::jugarBlindaje() {
    Lista<Ficha*>* fichas = this->jugadorActual->obtenerFichasDelJugador();
    fichas->iniciarCursor();
    while (fichas->avanzarCursor()){
        Ficha* ficha = fichas->obtenerCursor();
        if (ficha->getTipo()==Tesoro){
            ficha->blindarTesoro();
            return;
        }
    }

}


bool TesoroBinario::hayTesoroEnCasillero(int X, int Y, int Z){
    return this->tablero->coordenadaDentroDelTablero(X, Y, Z)
           &&this->tablero->getCasillero(X, Y, Z)->getEstado()==Ocupado
           &&this->tablero->getCasillero(X, Y, Z)->getFicha()->getTipo()==Tesoro;
}


void TesoroBinario::jugarRadar() {
    Coordenada* coordenada = this->consola->pedirCoordenada("poner el Radar");
    int Xc = coordenada->getAncho(), Yc = coordenada->getAlto(), Zc = coordenada->getLargo();
    int Xi = Xc-3, Yi = Yc -3, Zi = Zc-3;
    int Xf = Xc+3, Yf = Yc+3, Zf = Zc+3;
    for(int X = Xi; X<=Xf; X++){
        for(int Y = Yi; Y<=Yf; Y++){
            for(int Z = Zi; Z<=Zf; Z++){
                if(this->hayTesoroEnCasillero(X,Y,Z)){
                    this->consola->tesoroEnLaCoordenada(X,Y,Z);
                }
            }
        }
    }

}


void TesoroBinario::partirTesoro() {
    Coordenada* coordenada;
    unsigned int ancho, alto, largo;
    ancho = this->tablero->getAncho();
    alto =  this->tablero->getAlto();
    largo = this->tablero->getLargo();
    for(unsigned int x=1; x<=ancho; x++){
        for(unsigned int y=1; y<=alto; y++){
            for(unsigned int z=1; z<=largo; z++){
                Casillero* casillero = this->tablero->getCasillero(x,y,z);
                if(casillero->getEstado()==Vacio){
                    coordenada = new Coordenada(x,y,z);
                    Ficha* tesoro = new Ficha(Tesoro, this->jugadorActual->devolverJugadorId(), coordenada);
                    casillero->setFicha(tesoro);
                    this->jugadorActual->obtenerFichasDelJugador()->agregar(tesoro);
                    return;
                }
            }
        }

    }
}


void TesoroBinario::jugarEspias2() {
    this->metodoEspias();
    this->metodoEspias();
}


void TesoroBinario::jugarMostrarEspiasDeJugadorActivo() {
    Jugador* jugador = this->consola->mostrarJugadoresActivosYElegirJugador(this->vectorDeJugadores);
    this->consola->mostrarEspiasDelJugador(jugador);
}


void TesoroBinario::jugarObtenerCartas4() {
    int contador = 0;
    for(int i=0; i<rand()%4; i++){
        this->jugadorActual->obtenerCarta(this->mazo);
        contador++;
    }

    this->consola->cantidadDeCartasQueSeAgregaron(contador);
}


void TesoroBinario::metodoCartas() {
    if(this->consola->quiereEjecutarAccion("Quiere sacar una Carta?")){
        this->jugadorActual->obtenerCarta(this->mazo);
    }
    Lista<Carta*>* cartas = this->jugadorActual->obtenerCartasDelJugador();
    if(!cartas->estaVacia() && this->consola->quiereEjecutarAccion("Quiere usar una Carta?")){
        this->consola->mostrarCartas(cartas);
        int indice = this->consola->pedirAlJugadorElIndiceDeCarta(cartas->contarElementos());
        this->usarCarta(cartas->obtener(indice));
        cartas->remover(indice);
    }
    this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);

}


void TesoroBinario::eliminarFichaDeLaListaDeFichasDelJugador(Ficha* ficha) {
    int idJugador = ficha->getJugadorId(), posicion=1;
    Lista<Ficha*>* fichas;
    fichas =  this->vectorDeJugadores->obtener(idJugador)->obtenerFichasDelJugador();

    fichas->iniciarCursor();
    while (fichas->avanzarCursor()){
        Ficha* fichaLista = fichas->obtenerCursor();
        if(fichaLista==ficha){
            fichas->remover(posicion);
            return;
        }
        posicion++;
    }

}


void TesoroBinario::metodoTesoroMinaOcupado(Casillero* casillero){
    this->eliminarFichaDeLaListaDeFichasDelJugador(casillero->getFicha());
    if(casillero->getFicha()->getTipo()==TesoroMina){
    	this->consola->imprimirTexto("\nEl casillero tiene una mina, ambas minas explotan y el jugador actual pierde un turno.");
        this->jugadorActual->setPierdeTurno();
    }
    delete casillero->getFicha();
    casillero->setFicha(NULL);
    casillero->setEstado(Inactivo);

}


void TesoroBinario::metodoTesoroMina() {
    if(this->jugadorActual->devolverCantidadDeTesoros()!=0 && this->consola->quiereEjecutarAccion("\nQuiere poner un TesoroMina?")){
        Coordenada* coordenada;
        Casillero* casillero;
        coordenada = this->consola->pedirCoordenada("poner un TesoroMina");
        casillero = this->tablero->getCasillero(coordenada);
        if(casillero->getEstado()!=Inactivo) {
            Ficha* tesoroMina;
            tesoroMina = new Ficha(TesoroMina, this->jugadorActual->devolverJugadorId(), coordenada);
            if(casillero->getEstado()==Ocupado){
                this->metodoTesoroMinaOcupado(casillero);
                delete tesoroMina;
            }
            else {
                this->colocarFicha(tesoroMina);
                this->jugadorActual->obtenerFichasDelJugador()->agregar(tesoroMina);
            }
        }
        else {
            this->consola->imprimirTexto("Perdiste la ficha porque el casillero estaba inactivo");
            delete coordenada;
        }

        this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    }

}


void TesoroBinario::metodoEspiaChoque(Casillero *casillero, TipoFicha ficha) {
	if (ficha!=TesoroBlindado){
    	this->eliminarFichaDeLaListaDeFichasDelJugador(casillero->getFicha());
    	delete casillero->getFicha();
		casillero->setFicha(NULL);
	}
    switch (ficha) {
        case Tesoro:
        	casillero->setEstado(Inactivo);
            this->consola->imprimirTexto("\nEl espia encontro un teosoro y lo va a capturar..");
            break;
        case TesoroMina:
            casillero->setEstado(Inactivo);
            this->jugadorActual->setPierdeTurno();
            this->consola->imprimirTexto("\nEl espia se encontro con una mina, se eliminaron ambos y el jugador actual pierde el turno.");
            break;
        case Espia:
            this->consola->imprimirTexto("\nEl espia se encontro con otro espia, ambos son eliminados.");
            break;
        case TesoroBlindado:
            this->consola->imprimirTexto("\nEl espia encontro un teosoro blindado, espia es eliminado.");
            break;
    }

}

void TesoroBinario::metodoEspiasChoqueCasilleroNoInactivo(Casillero* casillero, Coordenada* coordenada){
    Ficha* espia;
    espia = new Ficha(Espia, this->jugadorActual->devolverJugadorId(), coordenada);
    if(casillero->getEstado()==Ocupado){
        this->metodoEspiaChoque(casillero, casillero->getFicha()->getTipo());
        delete espia;
    }
    else {
        this->colocarFicha(espia);
        this->jugadorActual->obtenerFichasDelJugador()->agregar(espia);
    }
}

void TesoroBinario::metodoEspias() {
    if(this->jugadorActual->devolverCantidadDeTesoros()!=0 && this->consola->quiereEjecutarAccion("\nQuiere poner un espia?")){
        Coordenada* coordenada;
        Casillero* casillero;
        coordenada = this->consola->pedirCoordenada("poner un espia");
        casillero = this->tablero->getCasillero(coordenada);
        if(casillero->getEstado()!=Inactivo) {
            this->metodoEspiasChoqueCasilleroNoInactivo(casillero, coordenada);
            this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
            return;
        }
        this->consola->imprimirTexto("\nPerdiste la ficha porque el casillero estaba inactivo");
        this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    }
}


void TesoroBinario::anunciarGanador() {
    for(int i=1; i<=this->cantidadDeJugadores; i++){
        Jugador* jugadorGanador = this->vectorDeJugadores->obtener(i);
        if(jugadorGanador->getEstadoJugador() == Activo){
            this->consola->imprimirGanador(jugadorGanador->devolverJugadorId());
            return;
        }
    }
}


void TesoroBinario::metodoMoverTesoroCasilleroInactivo(Coordenada* coordenadaNueva){
    this->consola->imprimirTexto(
            "\nPerdiste la opcion de mover el tesoro porque el casillero estaba inactivo");
    delete coordenadaNueva;
}


void TesoroBinario::metodoChoqueTesoro(Coordenada* coordenadaActual,Coordenada *coordenadaNueva, Casillero* casilleroActual,Casillero* casilleroNuevo){
    Ficha* fichaCasilleroNuevo = casilleroNuevo->getFicha();
    Ficha* fichaActual = casilleroActual->getFicha();
    TipoFicha tipo = fichaCasilleroNuevo->getTipo();
    if(tipo == Tesoro || tipo == TesoroBlindado){
    	std::cout<<"\nEn el casillero de destino:"<<std::endl;
        this->consola->tesoroEnLaCoordenada(coordenadaNueva->getAncho(), coordenadaNueva->getAlto(),
                                            coordenadaNueva->getLargo());
    	std::cout<<"Se pierde la posibilidad de mover el tesoro."<<std::endl;
    }
    else if(tipo==Espia||tipo==TesoroMina){
    	std::cout<<"El casillero nuevo tiene un espia o tesoro mina, pierde su tesoro."<<std::endl;
    	if (tipo==TesoroMina){
    		this->consola->imprimirTexto("\nEl casillero tiene una mina, pierde su tesoro y el jugador actual pierde el turno.");
    		this->jugadorActual->setPierdeTurno();
    	}
		this->eliminarFichaDeLaListaDeFichasDelJugador(fichaActual);
		this->eliminarFichaDeLaListaDeFichasDelJugador(fichaCasilleroNuevo);
		casilleroActual->setFicha(NULL);
		casilleroNuevo->setFicha(NULL);
		casilleroNuevo->setEstado(Inactivo);
		delete fichaCasilleroNuevo;
		delete fichaActual;
    }

}

void TesoroBinario::metodoMoverTesoroCasilleroVacio(Coordenada* coordenadaActual,Coordenada *coordenadaNueva,
                                                    Casillero* casilleroActual,Casillero* casilleroNuevo) {
    Ficha *fichaActual;
	fichaActual = casilleroActual->getFicha();
	casilleroActual->setFicha(NULL);
	fichaActual->setCoordenada(coordenadaNueva);
	this->colocarFicha(fichaActual);

}



void TesoroBinario::subMetodoMoverTesoro(Casillero* casilleroNuevo, Coordenada* coordenadaNueva){
    int indiceTesoro=1;
	Lista<Ficha*>* fichasJugador = jugadorActual->obtenerFichasDelJugador();
	Ficha* fichaJugador;
	Coordenada* coordenadaActual;
    Casillero* casilleroActual;
    fichasJugador->iniciarCursor();
    while (fichasJugador->avanzarCursor()){
    	fichaJugador = fichasJugador->obtenerCursor();
    	if (fichaJugador->getTipo()==Tesoro){
    		std::cout<<"Tesoro "<<indiceTesoro<<" en las coordenadas: ("<<fichaJugador->getCoordenada()->getAncho()<<", "<<fichaJugador->getCoordenada()->getAlto()<<", "<<fichaJugador->getCoordenada()->getLargo()<<")"<<std::endl;
    		indiceTesoro++;
    	}
    }
    coordenadaActual = this->consola->pedirCoordenada("elegir el tesoro a mover.");
    casilleroActual = this->tablero->getCasillero(coordenadaActual);
    if (casilleroActual->getEstado() == Ocupado && casilleroActual->getFicha()->getTipo()==Tesoro && this->jugadorActual->devolverJugadorId()==casilleroActual->getFicha()->getJugadorId()){

		switch (casilleroNuevo->getEstado()) {
			case Inactivo:
				this->metodoMoverTesoroCasilleroInactivo(coordenadaNueva);
				break;
			case Vacio:
				this->metodoMoverTesoroCasilleroVacio(coordenadaActual, coordenadaNueva,casilleroActual, casilleroNuevo);
				break;
			case Ocupado:
				this->metodoChoqueTesoro(coordenadaActual, coordenadaNueva, casilleroActual, casilleroNuevo);
				break;
		}
    }
    else{
        this->consola->imprimirTexto("\nNo hay un tesoro en esta coordenada. Pierde la posibilidad de mover un tesoro.");
    }


}

void TesoroBinario::metodoMoverTesoro() {
    if(this->jugadorActual->devolverCantidadDeTesoros()!=0 && this->consola->quiereEjecutarAccion("\nQuiere mover un tesoro de lugar?")){
        Coordenada* coordenadaNueva;
        Casillero* casilleroNuevo;
        coordenadaNueva = this->consola->pedirCoordenada("colocar Tesoro");
        casilleroNuevo = this->tablero->getCasillero(coordenadaNueva);
        this->subMetodoMoverTesoro(casilleroNuevo, coordenadaNueva);

        this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    }
}


void TesoroBinario::actualizarTablero() {
    int ancho, alto, largo;
    ancho = this->tablero->getAncho();
    alto =  this->tablero->getAlto();
    largo = this->tablero->getLargo();
    for(int x=1; x<=ancho; x++){
        for(int y=1; y<=alto; y++){
            for(int z=1; z<=largo; z++){
                Casillero* casillero = this->tablero->getCasillero(x,y,z);
                if(casillero->getEstado()==Inactivo){
                    casillero->restarTurnoInactivo();
                }
                if(casillero->getEstado()==Ocupado){
                    Ficha* ficha = casillero->getFicha();
                    ficha->restarContadorDeBlindaje();
                }
            }
        }

    }

}


TesoroBinario::~TesoroBinario(){
    for(int i=1; i<=this->cantidadDeJugadores;i++){
        delete this->vectorDeJugadores->obtener(i);
    }
    delete this->vectorDeJugadores;
    delete this->tablero;
    delete consola;
    delete mazo;
    delete bitmap;

}
