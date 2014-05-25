#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "lector.h"
#include "camino.h"
using namespace std;

Lector::Lector(string path){
    this->archivo.open(path.c_str(), ifstream::in);
}
vector<list<Camino*> >* Lector::CargarCaminos (){
    vector<list<Camino*> >* caminos = new vector<list<Camino*> >();
    string sentido;

    for (string line; getline(this->archivo, line); )
    {
        string accion = line.substr(0,line.find(" "));

    }
}
