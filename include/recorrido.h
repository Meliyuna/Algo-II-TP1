#ifndef RECORRIDO_H_INCLUDED
#define RECORRIDO_H_INCLUDED
#include "lista.h"

typedef struct {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
}RGB;


class Recorrido{
    private:
        Lista <char>* caminos1;
        Lista <char>* bifurcaciones1;
        int cantBifurcaciones;
        int cantUniRecorridas;
        int cantGiros;
        RGB color;

    public:

        //PRE
        //POST: inicializa los punteros en NULL, las cantidades en cero y el color en (0;0;0)
        Recorrido();
        //PRE
        //POST:
        ~Recorrido();

        //PRE
        //POST:Agrega un nodo Bifurcacion en el camino y en la lista de bifurcaciones y que ademas sume uno al this->cantidadBifurcaciones
        void agregarBifurcacion();
        //PRE
        //POST: Setea el color del recorrido que esta trazando.

/***LOS SIGUIENTES METODOS TIENE QUE SER CORREGIDOS*/
        void setColor(char);
        //PRE
        //POST:
        void agregarGiro();
        //PRE
        //POST:
        void avanzar ();
        //PRE
        //POST:
        void leventarElemento();
        //PRE
        //POST:
        void tirarElemento();

};


#endif // RECORRIDO_H_INCLUDED
