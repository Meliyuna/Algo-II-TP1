#ifndef RECORRIDO_H_INCLUDED
#define RECORRIDO_H_INCLUDED

#include "lista.h"

class Recorrido{
    private:
        Lista <char>* Caminos1;
        Lista <char>* Bifurcaciones1;
        int cantBifurcaciones;
        int cantUniRecorridas;
        int cantGiros;
        int color[3];

    public:

        //PRE
        //POST:
        Recorrido();
        //PRE
        //POST:
        ~Recorrido();

        //PRE
        //POST:Agrega un nodo Bifurcacion en el camino y en la lista de bifurcaciones y que ademas sume uno al this->cantidadBifurcaciones
        void agregarBifurcacion();
        //PRE
        //POST:
        void agregarGiro();
        //PRE
        //POST: Setea el color del recorrido que esta trazando.
        void setColor();
        //PRE
        //POST:
        void avanzar ();
        //PRE
        //POST:
        void retroceder();
        //PRE
        //POST:
        void leventarElemento();
        //PRE
        //POST:
        void tirarElemento();

};


#endif // RECORRIDO_H_INCLUDED
