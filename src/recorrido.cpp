#include "recorrido.h"

//Contructor
Recorrido::Recorrido(){
    caminos1 = NULL;
    bifurcaciones1 = NULL;
    cantBifurcaciones = 0;
    cantGiros = 0;
    cantUniRecorridas = 0;
    color.Blue=0;
    color.Green=0;
    color.Red=0;
}
//Selecciona el color del recorrido
void Recorrido::setColor(RGB colorCamino){
    color.Blue = colorCamino.Blue;
    color.Red  = colorCamino.Red;
    color.Green= colorCamino.Green;

}

void Recorrido::agregarCamino(string comando){

    switch comando[0]{
        case G:
                break;
        case A:
                break;
        case R:
                break;

    }


}


