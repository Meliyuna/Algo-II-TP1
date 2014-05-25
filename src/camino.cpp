#include "camino.h"

using namespace std;

// ----- CaminoBifurcacion ----- //
CaminoBifurcacion::CaminoBifurcacion(string nombre, Esentido sentido){
    this->nombre=nombre;
    this->sentido=sentido;
}

string CaminoBifurcacion::get_nombre(){
    return this->nombre;
}

Esentido CaminoBifurcacion::get_sentido(){
    return this->sentido;
}

// ----- CaminoMochila ----- //
CaminoMochila::CaminoMochila(string item,Eaccion accion){
    this->item=item;
    this->accion=accion;
}

string CaminoMochila::get_item(){
    return this->item;
}

Eaccion CaminoMochila::get_accion(){
    return this->accion;
}

// ----- Camino ----- //
Camino::Camino(RGB color, Emovimiento movimiento,Esentido sentido,CaminoBifurcacion* bifurcacion ,CaminoMochila* mochila , std::string* unionNombre){
    this->color=color;
    this->movimiento=movimiento;
    this->sentido=sentido;
    this->bifurcacion=bifurcacion;
    this->mochila=mochila;
    this->unionNombre=unionNombre;
}
RGB Camino::get_color(){
    return this->color;
}

Emovimiento Camino::get_movimiento(){
    return this->movimiento;
}

Esentido Camino::get_sentido(){
    return this->sentido;
}

CaminoBifurcacion Camino::get_bifurcacion(){
    return CaminoBifurcacion(*this->bifurcacion);
}

CaminoMochila Camino::get_mochila(){
    return CaminoMochila(*this->mochila);
}

string Camino::get_unionNombre(){
    return string(*this->unionNombre);
}

bool Camino::has_mochila(){
    return this->mochila==NULL;
}

bool Camino::has_bifurcacion(){
    return this->bifurcacion==NULL;
}
