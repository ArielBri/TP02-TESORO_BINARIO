//
//

#ifndef NODO_H
#define NODO_H

#ifndef NULL
#define NULL 0
#endif


template<class T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;

public:
    explicit Nodo(T valor);
    bool haySiguiente();
    Nodo<T>* getSiguiente();
    void setSiguiente(Nodo<T>* nuevoSig);
    T getValor();
    void setValor(T nuevoValor);
    ~Nodo();
};


template<class T>
Nodo<T>::Nodo(T valor) {
    this->dato = valor;
    this->siguiente = NULL;
}

template<class T>
bool Nodo<T>::haySiguiente(){
    return (this->siguiente != NULL);
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {
    return (this->siguiente);
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* nuevoSig) {
    this->siguiente = nuevoSig;
}

template<class T>
T Nodo<T>::getValor() {
    return (this->dato);
}

template<class T>
void Nodo<T>::setValor(T nuevoValor) {
    this->dato = nuevoValor;
}

template<class T>
Nodo<T>::~Nodo() {

}



#endif

