#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"
// Esta lista utiliza NODOS Doblemente Enlazados
// A su vez Utiliza CURSOR
template <typename Dato>
class Lista
{
private:
    Nodo<Dato>* primero;
    unsigned int tamanio;
    Nodo<Dato>* cursor;
public:
    // Constructor
    // Pre: Ninguna
    // Post: Crea la lista iniciando los punteros en el NULL y con tamaño cero
    Lista();

    // Iniciar Cursor
    // Pre: Lista Creada
    // Post: Inicia el cursor haciendo que apunte al NULL
    void iniciarCursor();

    // Cambiar Cursor
    // Pre: Lista Creada
    // Post: Se le asigna al cursor el puntero pasado por parametro.
    void setCursor(Nodo<Dato>* puntero);

    // Obtener Cursor
    // Pre: Lista Creada
    // Post: Devuleve el puntero cursor
    Nodo<Dato>* getCursor();

    // Cursor Vacio
    // Pre: Lista Creada
    // Post: Devuelve TRUE si el cursor apunta al NULL
    bool cursorVacio();

    // Avanzar Cursor
    // Pre: Lista Creada
    // Post: Se modifica el cursor tomando el puntero siguiente del nodo. Si el mismo apunta al null tomara el primero como resultado.
    void avanzarCursor();

    // Avanzar Cursor Posicion Dada
    // Pre: Lista Creada. 1 <= Posicion <= Tamanio
    // Post: Avanza el cursor a la posicion pasada por parametro. Para esto se reinicia el cursor y luego se avanza tomando el primero y los susceivos siguientes.
    void avanzarCursor(unsigned int posicion);

    // Retroceder Cursor
    // Pre: Lista Creada
    // Post: Retrocede una posicion el cursor tomando el puntero anterior del nodo en el cual esta parado. Si apuntaba al NULL lo seguira haciendo.
    void retrocederCursor();

    // Obtener puntero Primero
    // Pre: Lista Creada
    // Post: Se obtiene el puntero Primero
    Nodo<Dato>* getPrimero();

    // Obtener Tamaño
    // Pre: Lista Creada
    // Post: Se devuele el tamanio
    unsigned int getTamanio();

    // Lista Vacia
    // Pre: Lista Creada
    // Post: Devuelve TRUE si la lista esta vacia
    bool listaVacia();

    // Obtener Dato
    // Pre: Lista Creada. 0 < posicion <= tamanio.
    // Post: Devuelve el dato ubicado en la posicion pasada por parametro.
    Dato getElemento(unsigned int posicion);

    // Modificar puntero Primero
    // Pre: Lista Creada
    // Post: Modifica el puntero Primero al cual apunta la Lista. Se le asigna el puntero pasado por parametro.
    void setPrimero(Nodo<Dato>* puntero);

    // Agregar Elemento
    // Pre: Lista Creada. 0 < posicion <= tamanio +1.
    // Post: Agrega un elemento pasado por parametro en la posicion pasada. Suma uno al tamanio.
    void agregarElemento(Dato elemento,unsigned int posicion);

    // Borrar Elemento
    // Pre: Lista Creada. Al menos debe posser un elemento la lista. Tamanio>=1
    // Post: Libera los recursos solicitados por el elemento de la posicion pasada por parametro. Resta uno al tamanio.
    void eliminarElemento(unsigned int posicion);

    // Destructor
    // Pre: Lista Creada
    // Post: Libera todos los recursos solicitados.
    ~Lista();
};

// Constructor
template <typename Dato>
Lista<Dato>::Lista()
{
    this -> primero=NULL;
    this -> tamanio=0;
    this -> cursor=NULL;
}

// Inciar Cursor
template <typename Dato>
void Lista<Dato>::iniciarCursor()
{
    this ->cursor=NULL;
}

// Cambiar Cursor
template <typename Dato>
void Lista<Dato>::setCursor(Nodo<Dato>* puntero)
{
    this ->cursor=puntero;
}

// Obtener Cursor
template <typename Dato>
Nodo<Dato>* Lista<Dato>::getCursor()
{
    return this->cursor;
}

// Cursor Vacio
template <typename Dato>
bool Lista<Dato>::cursorVacio()
{
    return (!cursor);
}

// Avanzar Cursor
template <typename Dato>
void Lista<Dato>::avanzarCursor()
{
    if (this->cursor!=NULL)
        this->cursor = cursor->getSiguiente();
    else
        cursor=primero;
}

// Avanzar Cursor
template <typename Dato>
void Lista<Dato>::avanzarCursor(unsigned int posicion)
{
    setCursor(this->primero);
    for (unsigned int contador=1; contador<posicion;contador++)
        avanzarCursor();
}
// Retroceder Cursor
template <typename Dato>
void Lista<Dato>::retrocederCursor()
{
    if (this->cursor!=NULL)
        this->cursor = cursor->getAnterior();
}

// Obtener Primero
template <typename Dato>
Nodo<Dato>* Lista<Dato>::getPrimero()
{
    return this->primero;
}

// Obtener Tamaño
template <typename Dato>
unsigned int Lista<Dato>::getTamanio()
{
    return tamanio;
}

// Lista Vacia
template <typename Dato>
bool Lista<Dato>::listaVacia()
{
    return (!primero);
}

// Obtener Dato
template <typename Dato>
Dato Lista<Dato>::getElemento(unsigned int posicion)
{
    avanzarCursor(posicion);
    return (cursor->getDato());
}

// Modificar puntero Primero
template <typename Dato>
void Lista<Dato>::setPrimero(Nodo<Dato>* puntero)
{
    this->primero=puntero;
}

// Agregar Elemento
template <typename Dato>
void Lista<Dato>::agregarElemento(Dato elemento,unsigned int posicion)
{
    Nodo<Dato>* nuevo = new Nodo<Dato>(elemento);
    if (posicion>1)
        avanzarCursor(posicion-1);
    else
        iniciarCursor();
    Nodo<Dato>* auxiliar=cursor;
    // Auxiliar apuntara al elemento anterior al que esta en la posicion a modificar. De el solo se cambiar el puntero siguiente.
    // Pero antes de cambiarlo, avanzo el cursor asi llego al elemento ubicado en la posicion que quiero para mi nuevo elemento.
    // Si se queria agregar un elemento en la posicion 1, el cursor apuntara al NULL. Recordar que avanzar si estaba en el NULL da el primer elemento.
    avanzarCursor();
    if (!auxiliar)
        auxiliar->setSiguiente(nuevo);
    cursor->setAnterior(nuevo);
    nuevo->setAnterior(auxiliar);
    nuevo->setSiguiente(cursor);
    tamanio++;
}

// Borar Elemento
template <typename Dato>
void Lista<Dato>::eliminarElemento(unsigned int posicion)
{
    if (posicion>1)
        avanzarCursor(posicion-1);
    else
        iniciarCursor();

    Nodo<Dato>* auxiliar=cursor;
    // Guardo el puntero al elemento anterior a borrar porque debo modificar su puntero siguiente
    avanzarCursor();
    // Ahora el cursor apunta al elemento que deseo borrar.
    // Si auxiliar no es el nulo se toma el siguiente del cursor y se lo asigna al siguiente de auxiliar
    // Si auxiliar es el nulo entonces debo cambiar el primero y apuntarlo al que antes era el segundo elemento
    if (!auxiliar)
        auxiliar->setSiguiente(cursor->getSiguiente);
    else
        setPrimero(cursor->getSiguiente);
    // Ya puedo borrar el elemento y liberar su memoria.
    delete cursor;
    // Vuelvo el cursor al elemento anterior al borrado
    setCursor(auxiliar);
    // Avanzo el cursor una vez mas para ir al proximo elemento.
    // Recordar que como yo modifique el primero en caso de que el auxiliar fuese el NULO, el siguiente paso nos lleva el que era el segundo elemento.
    avanzarCursor();
    // Si el cursor ahora no esta apuntando al vacio significa que tengo un elemento al cual debo cambiarle el puntero anterior
    if (!cursorVacio)
        cursor->setAnterior(auxiliar);
}

// Destructor
template <typename Dato>
Lista<Dato>::~Lista()
{
    while (!listaVacia)
        eliminarElemento(1);
}

#endif // LISTADE_H_INCLUDED
