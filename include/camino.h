#ifndef CAMINO_H_INCLUDED
#define CAMINO_H_INCLUDED
#include <string>

enum Esentido{N, S, E, O};
enum Emovimiento {A, R, U};
enum Eaccion {L,T};

typedef struct {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
}RGB;

class CaminoBifurcacion {
    private:
        std::string nombre;
        Esentido sentido;

    public:
        CaminoBifurcacion(std::string, Esentido);
        std::string get_nombre();
        Esentido get_sentido();
};

class CaminoMochila {
    private:
        std::string item;
        Eaccion  accion;

    public:
        CaminoMochila(std::string, Eaccion);
        std::string get_item();
        Eaccion get_accion();
};

class Camino{
    private:
        RGB color;
        Emovimiento movimiento;
        Esentido sentido;
        CaminoBifurcacion* bifurcacion;
        CaminoMochila* mochila;
        std::string* unionNombre;

    public:
        Camino(RGB color, Emovimiento,Esentido,CaminoBifurcacion*,CaminoMochila*, std::string*);
        RGB get_color();
        Emovimiento get_movimiento();
        Esentido get_sentido();
        CaminoBifurcacion get_bifurcacion();
        CaminoMochila get_mochila();
        std::string get_unionNombre();
        bool has_bifurcacion();
        bool has_mochila();

};
#endif // CAMINO_H_INCLUDED
