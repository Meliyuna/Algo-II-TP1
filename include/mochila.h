#ifndef MOCHILA_H_INCLUDED
#define MOCHILA_H_INCLUDED
class Mochila
{
private:
    // Revisar si no necesita accion.
    string nombreElemento;
    // No puede levantar mas de un elemento
    unsigned int cantidad;
public:
    // Constructor
    // Pre: Ninguna
    // Post: Crea un objeto Mochila asignando como nombre '0' y cantidad nula.
    Mochila();

    // Modificar Nombre
    // Pre: Objeto Creado
    // Post: Modifica el Nombre del Elemento.
    void setNombreElemento(string nombre);

    // Obtener Nombre
    // Pre: Objeto Creado
    // Post: Devuelve el Nombre del Elemento
    string getNombreElemento();

    // Obtener Cantidad
    // Pre: Objeto Creado
    // Post: Devuelve la cantidad del elemento
    int getCantidad();

    // Restar Cantidad
    // Pre: Objeto Creado. La cantidad no puede ser cero.
    // Post: Modifica la cantidad restando 1.
    void restarCantidad();

    // Sumar Cantidad
    // Pre: Objeto Creado.
    // Post: Modifica la cantidad restando 1.
    void sumarCantidad();

    // Destructor
    // Pre: Objeto Creado
    // Post: No hace nada
    ~Mochila();
};
#endif // MOCHILA_H_INCLUDED
