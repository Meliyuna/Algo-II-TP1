#include "Mochila.h"

// Constructor
Mochila::Mochila()
{
    this->nombreElemento='0';
    this->cantidad=0;
}

// Modificar Nombre
void Mochila::setNombreElemento(std::string nombre)
{
    this->nombreElemento=nombre;
}

// Obtener Nombre
std::string Mochila::getNombreElemento()
{
    return nombreElemento;
}

// Obtener Cantidad
int Mochila::getCantidad()
{
    return cantidad;
}

// Sumar Cantidad
void Mochila::sumarCantidad()
{
    this->cantidad++;
}

// Restar Cantidad
void Mochila::restarCantidad()
{
    this->cantidad--;
}

// Destructor
Mochila::~Mochila()
{
    // �Que miras? ... �Te gusto? ... ;)
}
