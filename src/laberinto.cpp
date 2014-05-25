#include "Laberinto.h"
#include "Nodo.h"

Laberinto::Laberinto()
{
    this ->ancho=0;
    this ->largo=0;
}

bool Laberinto::buscarEnMochila (std::string nombre)
{
    //uso busqueda secuencial
   /* bool encontrado=false;

    std::string comparar;

    mochila->iniciarCursor();
    mochila->avanzarCursor();
    comparar=mochila->cursor->getDato();


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
    //dtor */
    return 0;
}
