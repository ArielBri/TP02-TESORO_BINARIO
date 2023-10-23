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

    //Devuelve un valor indicando si la pila  está  vacía
    //Precondicion : la pila debe haber sido creada
    //Postcondicion : no tiene
    bool vacia();


    // Tope obtiene el valor del tope de la pila. Si la pila tiene elementos se devuelve el valor del tope.
    // Si está vacía, entra en pánico con un mensaje "La pila esta vacia".
    T tope();

    // Push agrega un nuevo elemento a la pila.
    void push(T elemento);

    // Desapilar saca el elemento tope de la pila. Si la pila tiene elementos, se quita el tope de la pila, y
    // se devuelve ese valor. Si está vacía, entra en pánico con un mensaje "La pila esta vacia".
    T pop();

    // Destruye la pila
    // Precondicion : la pila debe haber sido creada
    //Postcondicion : no tiene
    ~Pila();
};


#endif
