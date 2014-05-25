#ifndef LABERINTO_H_H
#define LABERINTO_H_H


<<<<<<< HEAD
class Laberinto
=======
class Laberinto.h
>>>>>>> b11056e6e2d624e62a04c7fce3ec505bc0022c12
{
    public:
        //Constructor
        //PRE
        //POST
        Laberinto.h();

        //Actualizar Coordenadas
        //PRE
        //POST
        void actualizarCoordenadas();

        //Lectura
        //PRE: Lee un archivo de texto, determinado por el usuario
        //POST: Guarda la informacion en "Camino" o "Mochila"  segun corresponda
        void lectura();

        //Buscar en Mochila
        //PRE: Recibe un parametro para buscar en "Mochila"
        //POST: Indica si el elemento se encuentra o no
        bool buscarEnMochila(string nombre);

        //Destructor
        //PRE
        //POST
        virtual ~Laberinto.h();

    private:
        int ancho;
        int largo;
        Lista<*Tda Recorridos>* recorrido;
        Lista<*Tda Mochila>* mochila;
};

#endif // LABERINTO_H_H




