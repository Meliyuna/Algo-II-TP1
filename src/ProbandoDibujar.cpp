
#include <iostream>
#include "Dibujar.h"
#include "VariablesGlobales.h"
using namespace std;

int probando() {


	// se crea el objeto Dibujar, yo le puse de nonbre dibujar x'D

	Dibujar dibujar;

	// 1) lo primero que debemos hacer es asignar un tamaño a la imagen

	dibujar.modificarTamanio(50,50);

	// 2) empezamos un recorrido indicando la posicion y el color del mismo

	dibujar.inicioDelCamino(1,3,AZUL);

	// 3) voy dibujando el camino haciendo uso de todos los metodos para verificar
	//	  su funcionamiento x'D

	dibujar.tramoHaciaElSur(2);
	dibujar.tramoHaciaElEste(1);
	dibujar.tramoHaciaElSur(5);
	dibujar.bifurcacionEste();
	dibujar.tramoHaciaElSur(5);
	dibujar.tramoHaciaElEste(2);
	dibujar.tramoHaciaElNorte(10);
	dibujar.tramoHaciaElEste(10);
	dibujar.bifurcacionNorte();
	dibujar.tramoHaciaElEste(2);
	dibujar.bifurcacionSur();
	dibujar.tramoHaciaElEste(8);

	// 4) finalmente empiezo otro camino ahora de distinto color en otra posicion

	dibujar.inicioDelCamino(1,20,ROJO);

	// 5) RECORDAR que ahora estos metodos tendran como referencia a las nuevas coordenadas
	//	  que le acabo de pasar en el paso 4.

	dibujar.tramoHaciaElEste(20);
	dibujar.tramoHaciaElSur(9);
	dibujar.objetoLevantado();
	dibujar.tramoHaciaElSur(9);
	dibujar.bifurcacionOeste();
	dibujar.tramoHaciaElSur(2);
	dibujar.tramoHaciaElOeste(5);
	dibujar.tramoHaciaElNorte(2);
	dibujar.tramoHaciaElEste(3);

	dibujar.inicioDelCamino(49,1,VERDE);
	dibujar.tramoHaciaElOeste(10);
	dibujar.tramoHaciaElSur(9);
	dibujar.tramoHaciaElEste(4);
	dibujar.objetoTirado();
	dibujar.tramoHaciaElEste(5);
	dibujar.tramoHaciaElNorte(7);
	dibujar.tramoHaciaElOeste(7);
	dibujar.tramoHaciaElSur(2);
	dibujar.objetoLevantado();
	dibujar.tramoHaciaElSur(3);
	dibujar.tramoHaciaElEste(5);
	dibujar.tramoHaciaElNorte(3);
	dibujar.tramoHaciaElOeste(3);
	dibujar.tramoHaciaElSur(1);

	dibujar.inicioDelCamino(16,10,ROJO);
	dibujar.tramoHaciaElNorte(6);
	dibujar.unionNorte();

	// 6) finalmente guardo la imagen =)

	dibujar.guardarImagen();

	cout<<"HECHO!";

    return 0;
}
