#include "Laberinto.h"
#include "Nodo.h"

Lista<Mochila.h>* mochila;

Laberinto::Laberinto()
{
    //ctor
}

bool Laberinto::buscarEnMochila (string nombre)
{
    //uso busqueda secuencial
    int encontrado=0;

    string comparar=mochila->primero->getNombre;
    while ((mochila->tieneSiguiente())&&(!encontrado))
    {
        if (comparar!=nombre)
        {
            mochila->avanzarCursor();
            comparar=mochila->cursor->getNombre();
        }
        else
            encontrado++;
    }
    return encontrado;
}

Laberinto::~Laberinto()
{
    //dtor
}
