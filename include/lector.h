#ifndef LECTOR_H_INCLUDED
#define LECTOR_H_INCLUDED
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "camino.h"

class Lector{
    private:
        std::ifstream archivo;
    public:
        Lector(std::string);
        std::vector<std::list<Camino*> >* CargarCaminos ();
};

#endif // LECTOR_H_INCLUDED
