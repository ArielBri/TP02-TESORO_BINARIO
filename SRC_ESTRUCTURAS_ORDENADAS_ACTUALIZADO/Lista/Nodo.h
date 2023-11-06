//
//

#ifndef NODO_H
#define NODO_H

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

#endif
