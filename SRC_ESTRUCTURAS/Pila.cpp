#include "Pila.h"

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
        throw std::runtime_error("La pila está vacía");
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
        throw std::runtime_error("La pila está vacía");
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