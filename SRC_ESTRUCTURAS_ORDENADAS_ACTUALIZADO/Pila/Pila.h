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
    // Pila devuelve una pila
    Pila();


    // pre: la pila debe haber sido creada
    // pos: Devuelve un valor indicando si la pila  está  vacía
    bool vacia();


    // pre: la pila debe haber sido creada y que la pila no este vacia.
    // pos: obtiene el valor del tope de la pila.
    T tope();


    // pre: la pila debe haber sido creada
    // pos: agrega un nuevo elemento a la pila.
    void push(T elemento);

    // pre: la pila debe haber sido creada y que la pila no este vacia.
    // pos: Desapilar saca el elemento tope de la pila.
    T pop();

    // pre: la pila debe haber sido creada
    // pos: se destruye la pila
    ~Pila();
};


#endif
