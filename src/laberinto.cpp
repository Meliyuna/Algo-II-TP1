#include "Laberinto.h"
#include "Lista.h"
#include "Mochila.h"

Lista<Mochila.h>* mochila;

Laberinto::Laberinto()
{
    //ctor
}

bool Laberinto::buscarEnMochila (string nombre)
{
    //uso busqueda secuencial
    int encontrado=0;

    string comparar=mochila->primero->getNombreElemento();
    while ((!(mochila->cursorVacio()))&&(!encontrado))
    {
        if (comparar!=nombre)
        {
            mochila->avanzarCursor();
            comparar=mochila->cursor->getNombreElemento();
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
