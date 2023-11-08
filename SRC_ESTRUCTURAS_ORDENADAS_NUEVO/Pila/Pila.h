//
//

#ifndef TP_2
#define TP_2
#include <iostream>
const int CAPACIDAD_INICIAL = 2;


template <class T>
class Pila {
private:

    T*  datos;

    int cantidad;
    int dimension;

    void redimensionar(int capacidad);

public:
    /*
     * Pos: Pila devuelve una pila
     */
    Pila();

    /*
     * pre: la pila debe haber sido creada
     * pos: Devuelve un valor indicando si la pila  está  vacía
     */
    bool vacia();

    /*
     * pre: la pila debe haber sido creada y que la pila no este vacia.
     * pos: obtiene el valor del tope de la pila.
     */
    T tope();

    /*
     * pre: la pila debe haber sido creada
     * pos: agrega un nuevo elemento a la pila.
     */
    void push(T elemento);
    /*
    * pre: la pila debe haber sido creada y que la pila no este vacia.
    * pos: Desapilar saca el elemento tope de la pila.
    */
    T pop();

    /*
    * pre: la pila debe haber sido creada
    * pos: se destruye la pila
    */
    ~Pila();
};


template<class T>
Pila<T>::Pila() {
    this->datos = new T[CAPACIDAD_INICIAL];
    this->cantidad = 0;
    this->dimension = CAPACIDAD_INICIAL;
}

template<class T>
void Pila<T>::redimensionar(int capacidad) {
    T* nuevoDatos = new T[capacidad];

    for (int i = 0; i < cantidad; i++) {
        nuevoDatos[i] = datos[i];
    }
    delete[] this->datos;
    this->datos = nuevoDatos;
    this->dimension = capacidad;
}


template <class T>
bool Pila<T>::vacia(){
    return this->cantidad == 0;
}

template <class T>
T Pila<T>::tope() {
    if (this->vacia()) {
        throw "La pila está vacía";
    }
    return this->datos[this->cantidad-1];
}


template <class T>
void Pila<T>::push(T elemento) {
    if (this->cantidad == this->dimension) {
        this->redimensionar(2 * this->dimension);
    }
    this->datos[this->cantidad] = elemento;
    this->cantidad++;
}

template<class T>
T Pila<T>::pop() {
    if (this->vacia()) {
        throw "La pila está vacía";
    }

    this->cantidad--;

    if (4 * this->cantidad <= this->dimension) {
        this->redimensionar(this->dimension / 2);
    }

    return this->datos[this->cantidad];
}

template<class T>
Pila<T>::~Pila() {
    delete [] this->datos;
}

#endif



