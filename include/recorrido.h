#ifndef RECORRIDO_H_INCLUDED
#define RECORRIDO_H_INCLUDED
#include "camino.h"
#include "lista.h"


class Recorrido{
    private:
        Lista <char>* caminos1;
        Lista <char>* bifurcaciones1;
        int cantBifurcaciones;
        int cantUniRecorridas;
        int cantGiros;
        RGB color;
        //PRE
        //POST:Agrega un nodo Bifurcacion en el camino y en la lista de bifurcaciones y que ademas sume uno al this->cantidadBifurcaciones
        void agregarBifurcacion();
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

    public:

        //PRE
        //POST: inicializa los punteros en NULL, las cantidades en cero y el color en (0;0;0)
        Recorrido();
        //PRE
        //POST:
        ~Recorrido();
        //PRE
        //POST: Setea el color del recorrido que esta trazando.
        void setColor(RGB colorCamino);
        //PRE: Se agrega el comando para que determine si crea el camino en memoria
        //POST:
        void agregarCamino(std::string comando);

/***LOS SIGUIENTES METODOS TIENE QUE SER CORREGIDOS*/

};


#endif // RECORRIDO_H_INCLUDED
