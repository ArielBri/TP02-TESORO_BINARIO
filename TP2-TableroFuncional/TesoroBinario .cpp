#include "TesoroBinario.h"


TesoroBinario::TesoroBinario(int ancho, int alto, int largo, int cantidadDeJugadores, int cantidadDeTesoros) {
    this->tablero = new Tablero(ancho, alto, largo);
    Jugador* jugadorNULL = NULL;
    this->vectorDeJugadores = new Vector<Jugador*>(cantidadDeJugadores, jugadorNULL);
    for (int i = 1; i <= cantidadDeJugadores; i++) {
         Jugador* jugador = new Jugador(i);
         this->vectorDeJugadores->agregar(i, jugador);
         //std::cout<<"Jugador creado: "<<this->vectorDeJugadores->obtener(i)->devolverJugadorId()<<std::endl;
     }
    this->cantidadDeTesorosInicial = cantidadDeTesoros;
    this->jugadorActual = NULL;
    this->mazo = new Mazo();
    this->turnoValido = Valido;
    this->cantidadDeJugadores = cantidadDeJugadores;
    this->consola = new Consola(ancho,alto,largo); //Se modifica para consola
    this->bitmap = new Bitmap();
    /*std::cout<<"Se ejecuta tablero vacio"<<std::endl;
    this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);//usado para debug*/
}


bool TesoroBinario::hayGanador(){
    int contadorDeJugadoresActivos = 0;
    for(int i=1; i<=this->cantidadDeJugadores; i++){
        Jugador* jugador= this->vectorDeJugadores->obtener(i);
        std::cout<<this->vectorDeJugadores->obtener(i)->devolverJugadorId()<<std::endl;
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
    	this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    // Metodo B: Tesoro Mina
    this->metodoTesoroMina();
     	this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    // Metodo C: Espias
    this->metodoEspias();
     	this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
    // Metodo D: Mover Tesoro no blindado.
    this->metodoMoverTesoro();
     	this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
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
            throw "No se encontrÃ³ una carta";
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

            this->turnoValido = Valido;
            this->jugadorActual = this->vectorDeJugadores->obtener(posicion);
            this->bitmap->mostrarTablero(this->tablero,this->jugadorActual);
            if(this->jugadorActual->getEstadoJugador()==Activo){
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
	std::cout<<"Tesoros del Jugador: "<<jugador->devolverJugadorId()<<std::endl; //debug
    for(int i=1; i<=cantidadDeTesorosPorJugador; i++){
        Coordenada* coordenadaTesoro = new Coordenada(i,1+(rand()%limite),jugador->devolverJugadorId());
        Ficha* tesoro = new Ficha(Tesoro, jugador->devolverJugadorId(), coordenadaTesoro);
        jugador->obtenerFichasDelJugador()->agregar(tesoro);
        this->colocarFicha(tesoro);
        std::cout<<"Tesoro"<<i<<"\nCoordenadas:"<<coordenadaTesoro->getAncho()<<coordenadaTesoro->getAlto()<<coordenadaTesoro->getLargo()<<std::endl;//debug
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
    for(int x=1; x<=ancho; x++){
        for(int y=1; y<=alto; y++){
            for(int z=1; z<=largo; z++){
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
    this->consola->mostrarCartas(cartas);

    if(!cartas->estaVacia() && this->consola->quiereEjecutarAccion("Quiere usar una Carta?")){
        this->consola->mostrarCartas(this->jugadorActual->obtenerCartasDelJugador());
        int indice = this->consola->pedirAlJugadorElIndiceDeCarta(cartas->contarElementos());
        this->usarCarta(cartas->obtener(indice));
        cartas->remover(indice);
    }

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
    casillero->setEstado(Inactivo);
    casillero->setTurnosRestantesInactivo(5);
    if(casillero->getFicha()->getTipo()==TesoroMina){
        this->turnoValido  = Invalido;
    }
    delete casillero->getFicha();
    casillero->setFicha(NULL);

}


void TesoroBinario::metodoTesoroMina() {
    if(this->consola->quiereEjecutarAccion("Quiere poner un TesoroMina?") && this->turnoValido==Valido){
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
            } else {
                this->colocarFicha(tesoroMina);
                this->jugadorActual->obtenerFichasDelJugador()->agregar(tesoroMina);
            }
        } else {
            this->consola->imprimirTexto("perdiste la ficha porque el casillero estaba inactivo");
            delete coordenada;
        }
    }

}


void TesoroBinario::metodoEspiaChoque(Casillero *casillero, TipoFicha ficha) {
    this->eliminarFichaDeLaListaDeFichasDelJugador(casillero->getFicha());
    switch (ficha) {
        case Tesoro:
            this->consola->imprimirTexto("El espia encontro un teosoro y lo va a capturar");
            break;
        case TesoroMina:
            casillero->setEstado(Inactivo);
            this->turnoValido = Invalido;
            this->consola->imprimirTexto("El espia se encontro con una mina, se eliminaron ambos y el jugador actual pierde el turno");
            break;
        case Espia:
            this->consola->imprimirTexto("El espia se encontro con otro espia y murio");
            break;
        case TesoroBlindado:
            this->consola->imprimirTexto("El espia encontro un teosoro blindado y murio");
            break;
    }
    delete casillero->getFicha();
    casillero->setFicha(NULL);
}

void TesoroBinario::metodoEspiasChoqueCasilleroNoInactivo(Casillero* casillero, Coordenada* coordenada){
    Ficha* espia;
    espia = new Ficha(Espia, this->jugadorActual->devolverJugadorId(), coordenada);
    if(casillero->getEstado()==Ocupado){
        this->metodoEspiaChoque(casillero, casillero->getFicha()->getTipo());
        delete espia;
    } else {
        this->colocarFicha(espia);
        this->jugadorActual->obtenerFichasDelJugador()->agregar(espia);
    }
}

void TesoroBinario::metodoEspias() {
    if(this->consola->quiereEjecutarAccion("Quiere poner un espia?") && this->turnoValido==Valido){
        Coordenada* coordenada;
        Casillero* casillero;
        coordenada = this->consola->pedirCoordenada("poner un espia");
        casillero = this->tablero->getCasillero(coordenada);
        if(casillero->getEstado()!=Inactivo) {
            this->metodoEspiasChoqueCasilleroNoInactivo(casillero, coordenada);
            return;
        }
        this->consola->imprimirTexto("perdiste la ficha porque el casillero estaba inactivo");

    }

}


void TesoroBinario::anunciarGanador() {
    for(int i=1; i<=this->cantidadDeJugadores; i++){
        Jugador* jugadorGanador = this->vectorDeJugadores->obtener(i);
        if(jugadorGanador->getEstadoJugador() == Activo){
            this->consola->imprimirGanador(jugadorActual->devolverJugadorId());
            return;
        }
    }
}


void TesoroBinario::metodoMoverTesoroCasilleroInactivo(Coordenada* coordenadaNueva){
    this->consola->imprimirTexto(
            "perdiste la opcion de mover el tesoro porque el casillero estaba inactivo");
    delete coordenadaNueva;
}


void TesoroBinario::metodoChoqueTesoro(Coordenada* coordenadaActual,Coordenada *coordenadaNueva, Casillero* casilleroActual,Casillero* casilleroNuevo){
    Ficha* fichaCasilleroNuevo = casilleroNuevo->getFicha();
    Ficha* fichaActual = casilleroActual->getFicha();
    TipoFicha tipo = fichaCasilleroNuevo->getTipo();
    if(tipo == Tesoro || tipo == TesoroBlindado){
        this->consola->tesoroEnLaCoordenada(coordenadaNueva->getAncho(), coordenadaNueva->getAlto(),
                                            coordenadaNueva->getLargo());
    }else if(tipo==Espia||tipo==TesoroMina){
            this->eliminarFichaDeLaListaDeFichasDelJugador(fichaActual);
            this->eliminarFichaDeLaListaDeFichasDelJugador(fichaCasilleroNuevo);
            casilleroActual->setFicha(NULL);
            casilleroNuevo->setFicha(NULL);
            casilleroNuevo->setEstado(Inactivo);
            delete fichaCasilleroNuevo;
            delete fichaActual;
    }
    delete coordenadaNueva;
    delete coordenadaActual;
};



void TesoroBinario::metodoMoverTesoroCasilleroOcupado(Coordenada* coordenadaActual,Coordenada *coordenadaNueva,
                                                      Casillero* casilleroActual,Casillero* casilleroNuevo) {
    coordenadaActual = this->consola->pedirCoordenada("elegir el tesoro a mover(no se puede mover Tesoro blindado)");
    casilleroActual = this->tablero->getCasillero(coordenadaActual);
    if (casilleroActual->getEstado() == Ocupado && casilleroActual->getFicha()->getTipo() == Tesoro) {

    }
}


void TesoroBinario::metodoMoverTesoroCasilleroVacio(Coordenada* coordenadaActual,Coordenada *coordenadaNueva,
                                                    Casillero* casilleroActual,Casillero* casilleroNuevo) {
    Ficha *fichaActual;
    coordenadaActual = this->consola->pedirCoordenada("elegir el tesoro a mover(no se puede mover Tesoro blindado)");
    casilleroActual = this->tablero->getCasillero(coordenadaActual);
    if (casilleroActual->getEstado() == Ocupado && casilleroActual->getFicha()->getTipo()==Tesoro){
        fichaActual = casilleroActual->getFicha();
        casilleroActual->setFicha(NULL);
        fichaActual->setCoordenada(coordenadaNueva);
        this->colocarFicha(fichaActual);
        return;
    }
    this->consola->imprimirTexto("No hay un tesoro en esta coordenada");
}



void TesoroBinario::subMetodoMoverTesoro(Casillero* casilleroNuevo, Coordenada* coordenadaNueva){
    Coordenada* coordenadaActual;
    Casillero* casilleroActual;
    switch (casilleroNuevo->getEstado()) {
        case Inactivo:
            this->metodoMoverTesoroCasilleroInactivo(coordenadaNueva);
            break;
        case Vacio:
            this->metodoMoverTesoroCasilleroVacio(coordenadaActual, coordenadaNueva,casilleroActual, casilleroNuevo);
            break;
        case Ocupado:
            this->metodoMoverTesoroCasilleroOcupado(coordenadaActual, coordenadaNueva, casilleroActual, casilleroNuevo);
            break;
    }
}

void TesoroBinario::metodoMoverTesoro() {
    if(this->consola->quiereEjecutarAccion("Quiere mover un tesoro de lugar?") && this->turnoValido==Valido){
        Coordenada* coordenadaNueva;
        Casillero* casilleroNuevo;
        coordenadaNueva = this->consola->pedirCoordenada("colocar Tesoro");
        casilleroNuevo = this->tablero->getCasillero(coordenadaNueva);
        this->subMetodoMoverTesoro(casilleroNuevo, coordenadaNueva);
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
