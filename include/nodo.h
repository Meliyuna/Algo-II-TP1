#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <cstddef>
#include <string>

// Estos Nodos son Doblemente Enlazados
template <typename Dato>
class Nodo
{
private:
    Nodo* anterior;
    Dato dato;
    Nodo* siguiente;
public:

    // Constructor
    // Pre: El dato debe ser valido
    // Post: Crea un Nodo Doblemente Enlazado iniciandolo con el dato pasado por parametro. Por defecto se asigna NULL para todos los atributos.
    Nodo(Dato dato);

    // Modificar Dato
    // Pre: Nodo creado. Dato valido
    // Post: Se modificara el dato perteneciente al nodo
    void setDato(Dato dato);

    // Cambiar Puntero Anterior
    // Pre: Nodo Creado
    // Post: Se modificara el puntero anterior
    void setAnterior(Nodo<Dato>* puntero);

    // Cambiar Puntero Siguiente
    // Pre: Nodo creado
    // Post: Se modificara el puntero siguiente
    void setSiguiente(Nodo<Dato>* puntero);

    // Obtener puntero Anterior
    // Pre: Nodo creado
    // Post: Se devuelve el puntero "anterior"
    Nodo<Dato>* getAnterior();

    // Obtener puntero Siguiente
    // Pre: Nodo creado
    // Post: Se devuelve el puntero "siguiente"
    Nodo<Dato>* getSiguiente();

    // Obtener Dato
    // Pre: Nodo Creado
    // Post: Devuelve el valor del "dato" perteneciente al nodo
    Dato getDato();

    // Averigua si tiene un siguiente
    // Pre: Nodo Creado
    // Post: Devuelve TRUE si el puntero siguiente no apunta al NULL
    bool tieneSiguiente();

    // Averigua si tiene un anterior
    // Pre: Nodo Creado
    // Post: Devuelve TRUE si el puntero anterior no apunta al NULL
    bool tieneAnterior();

    // Destructor
    // Pre: Nodo Creado. Al menos un elemento.
    // Post: No hace nada. El constructor no pide espacio en memoria.
    ~Nodo();

};

// Constructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato dato)
{
    this ->dato=dato;
    this ->siguiente=NULL;
    this ->anterior=NULL;
}

// Modificar Dato
template <typename Dato>
void Nodo<Dato>::setDato(Dato dato)
{
    this->dato=dato;
}

// Modificar Anterior
template <typename Dato>
void Nodo<Dato>::setAnterior(Nodo<Dato>* puntero)
{
    this->anterior=puntero;
}

// Modificar Siguiente
template <typename Dato>
void Nodo<Dato>::setSiguiente(Nodo<Dato>* puntero)
{
    this->siguiente=puntero;
}

// Obtener puntero Anterior
template <typename Dato>
Nodo<Dato>* Nodo<Dato>::getAnterior()
{
    return anterior;
}

// Obtener puntero Siguiente
template <typename Dato>
Nodo<Dato>* Nodo<Dato>::getSiguiente()
{
    return siguiente;
}

// Obtener Dato
template <typename Dato>
Dato Nodo<Dato>::getDato()
{
    return this->dato;
}

// Averigua si tiene Anterior
template <typename Dato>
bool Nodo<Dato>::tieneAnterior()
{
    return (!anterior);
}

// Averigua si tiene Siguiente
template <typename Dato>
bool Nodo<Dato>::tieneSiguiente()
{
    return (!siguiente);
}

// Destructor
template <typename Dato>
Nodo<Dato>::~Nodo()
{
    // No hago nada, no me mires =(
}



#endif // NODODE_H_INCLUDED
