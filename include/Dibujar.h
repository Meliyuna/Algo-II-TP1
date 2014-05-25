#ifndef DIBUJAR_H_
#define DIBUJAR_H_

#include "EasyBMP.h"
#include "VariablesGlobales.h"

class Dibujar {

public:

	 /* PRE:
	  	POS: inicializa las variables a sus valores por defecto:
	  		-tamaño de la imagen: 1x1 pixels
	  		-profundidad de imagen: 8
	  		-coordenada x: 0
	  		-coordenada y: 0
	  		-ancho del camino (unidad): 6x6 pixels
	  		-color del recorrido: BLANCO */
	Dibujar();

	/* PRE: (0,0)<(ancho,alto) (unidad,unidad)
	  		(conversion de unidad: (1,1) = (6pixels,6pixels)
	  							   (2,2) = (12pixels,12pixels) ...etc,
	   POS: modifica el tamaño de la imagen segun los valores especificados */
	void modificarTamanio(int ancho, int alto);

	/* PRE: (0,0)<(x,y)<=(ancho,alto)
	   POS: inicia un camino pintando del COLOR especificado en la posicion (x,y)
	   	   -(x,y) seran ahora el punto de referencia de los metodos restantes
	   	   -si no se espeficica COLOR, se usara por defecto NEGRO */
	void inicioDelCamino(int x, int y, tipoColor color);

	/* PRE: 0<longitud<=alto
	   POS: dibuja un tramo hacia el SUR de la longitud especificada*/
	void tramoHaciaElSur(int longitud);

	/* PRE: 0<longitud<=alto
	   POS: dibuja un tramo hacia el NORTE de la longitud especificada*/
	void tramoHaciaElNorte(int longitud);

	/* PRE: 0<longitud<=ancho
	   POS: dibuja un tramo hacia el OESTE de la longitud especificada*/
	void tramoHaciaElOeste(int longitud);

	/* PRE: 0<longitud<=ancho
	   POS: dibuja un tramo hacia el ESTE de la longitud especificada*/
	void tramoHaciaElEste(int longitud);

	/* PRE:
	   POS: dibuja una bifurcacion hacia el ESTE */
	void bifurcacionEste();

	/* PRE:
	   POS: dibuja una bifurcacion hacia el OESTE */
	void bifurcacionOeste();

	/* PRE:
	   POS: dibuja una bifurcacion hacia el NORTE */
	void bifurcacionNorte();

	/* PRE:
	   POS: dibuja una bifurcacion hacia el SUR */
	void bifurcacionSur();

	/* PRE:
	   POS: dibuja una union entre una bifurcacion ESTE y un camino del OESTE */
	void unionOeste();

	/* PRE:
	   POS: dibuja una union entre una bifurcacion OESTE y un camino del ESTE */
	void unionEste();

	/* PRE:
	   POS: dibuja una union entre una bifurcacion SUR y un camino del NORTE */
	void unionNorte();

	/* PRE:
	   POS: dibuja una union entre una bifurcacion NORTE y un camino del SUR */
	void unionSur();

	/* PRE:
	   POS: dibuja una marca del objeto Levantado en la posicion actual */
	void objetoLevantado();

	/* PRE:
	   POS: dibuja una marca del objeto Tirado en la posicion actual  */
	void objetoTirado();

	/* PRE:
	   POS: se guarda la imagen dibujada en la carpeta actual, donde se encuentra este codigo
	 	   -si no se dibujo ninguna imagen, guardara una imagen de 1x1 (pixels) en blanco */
	void guardarImagen();

private:

	BMP miImagen;
	int unidad;
	int x;
	int y;
	tipoColor miColor;
	bool primerPaso;

	/* PRE: METODO PRIVADO
	   POS: dibuja en el pixel de la posicion (i,j) con el color especificado */
	void pintarDe(tipoColor color, int i, int j);

	/* PRE:
	   POS: dibuja un tramo hacia el SUR de longitud 1*/
	void unoAbajo();

	/* PRE:
	   POS: dibuja un tramo hacia el NORTE de longitud 1*/
	void unoArriba();

	/* PRE:
	   POS: dibuja un tramo hacia el OESTE de longitud 1*/
	void unoIzquierda();

	/* PRE:
	   POS: dibuja un tramo hacia el ESTE de longitud 1*/
	void unoDerecha();

	void pintarParedVertical1();

	void pintarParedHorizontal1();

	void pintarParedVertical2();

	void pintarParedHorizontal2();

	void pintarInicioDelCamino(tipoColor color);

};

Dibujar::Dibujar(){

	miImagen.SetBitDepth(8);
	unidad=6;
	x=0;
	y=0;
	miColor=BLANCO;
	primerPaso=false;
}

void Dibujar::modificarTamanio(int ancho, int alto){

	ancho=((ancho)*unidad)+4;
	alto=((alto)*unidad)+4;
	miImagen.SetSize(ancho,alto);
}

void Dibujar::tramoHaciaElSur(int longitud){

	for(int i=1;i<=longitud;i++){
		unoAbajo();
	}
}

void Dibujar::tramoHaciaElNorte(int longitud){

	for(int i=1;i<=longitud;i++){
		unoArriba();
	}
}

void Dibujar::tramoHaciaElOeste(int longitud){

	for(int i=1;i<=longitud;i++){
		unoIzquierda();
	}
}

void Dibujar::tramoHaciaElEste(int longitud){

	for(int i=1;i<=longitud;i++){
		unoDerecha();
	}
}

void Dibujar::guardarImagen(){

	miImagen.WriteToFile("imagen.bmp");
}

void Dibujar::inicioDelCamino(int posX, int posY, tipoColor color=NEGRO){

	x=(posX*unidad)-unidad+2;
    y=(posY*unidad)-unidad+2;

    pintarInicioDelCamino(color);

    miColor=color;
}

void Dibujar::pintarInicioDelCamino(tipoColor color){

    for (int i=x;i<(x+unidad);i++){
    	for (int j=y;j<(y+unidad);j++){
    		pintarDe(color,i,j);
    	}
    }

	for (int i=x+1;i<x+4;i++){
		pintarDe(AMARILLO,i,y+1);
		pintarDe(AMARILLO,i,y+4);
	}

	for (int j=y+2;j<y+5;j++){
		pintarDe(AMARILLO,x+2,j);
	}


    for (int j=y;j<(y+unidad);j++){
    	pintarDe(GRIS,x,j);
    	pintarDe(GRIS,x+unidad-1,j);
    }

    for (int i=x;i<(x+unidad);i++){
    	pintarDe(GRIS,i,y);
    	pintarDe(GRIS,i,y+unidad-1);
    }

    primerPaso=true;
}

void Dibujar::objetoTirado(){

	for (int i=x+1;i<(x+unidad-1);i++){
		for (int j=y+1;j<(y+unidad-1);j++){
			pintarDe(NEGRO,i,j);
		}
	}
}

void Dibujar::objetoLevantado(){

	for (int i=x+1;i<(x+unidad-1);i++){
		for (int j=y+1;j<(y+unidad-1);j++){
			pintarDe(NEGRO,i,j);
		}
	}

	for (int i=x+2;i<(x+unidad-2);i++){
		for (int j=y+2;j<(y+unidad-2);j++){
			pintarDe(BLANCO,i,j);
		}
	}
}
void Dibujar::unionOeste(){

	for (int j=y+1;j<(y+unidad-1);j++){
		pintarDe(miColor,x,j);
	}
}

void Dibujar::unionEste(){

	for (int j=y+1;j<(y+unidad-1);j++){
		pintarDe(miColor,x+unidad-1,j);
	}
}

void Dibujar::unionNorte(){

	for (int i=x+1;i<(x+unidad-1);i++){
		pintarDe(miColor,i,y);
	}
}

void Dibujar::unionSur(){

	for (int i=x+1;i<(x+unidad-1);i++){
		pintarDe(miColor,i,y+unidad-1);
	}
}


void Dibujar::bifurcacionEste(){

	for (int j=y+1;j<(y+unidad-1);j++){
		pintarDe(miColor,x+unidad-1,j);
	}

	pintarDe(GRIS,x+unidad,y);
	pintarDe(GRIS,x+unidad,y+unidad-1);
}

void Dibujar::bifurcacionOeste(){

	for (int j=y+1;j<(y+unidad-1);j++){
		pintarDe(miColor,x,j);
	}

	pintarDe(GRIS,x-1,y);
	pintarDe(GRIS,x-1,y+unidad-1);
}

void Dibujar::bifurcacionNorte(){

	for (int i=x+1;i<(x+unidad-1);i++){
		pintarDe(miColor,i,y);
	}

	pintarDe(GRIS,x,y-1);
	pintarDe(GRIS,x+unidad-1,y-1);
}

void Dibujar::bifurcacionSur(){

	for (int i=x+1;i<(x+unidad-1);i++){
		pintarDe(miColor,i,y+unidad-1);
	}

	pintarDe(GRIS,x,y+unidad);
	pintarDe(GRIS,x+unidad-1,y+unidad);
}

void Dibujar::pintarParedVertical1(){

    for (int j=y-1;j<(y+unidad);j++){
    	pintarDe(GRIS,x,j);
    	pintarDe(GRIS,x+unidad-1,j);
    }

    for (int i=x;i<(x+unidad);i++){
    	pintarDe(GRIS,i,y+unidad-1);
    }

}

void Dibujar::pintarParedVertical2(){

	for (int j=(y-unidad);j<y+1;j++){
		pintarDe(GRIS,x,j);
		pintarDe(GRIS,x+unidad-1,j);
	}

	for (int i=x;i<(x+unidad);i++){
		pintarDe(GRIS,i,y-unidad);
	}
}

void Dibujar::pintarParedHorizontal1(){

	for (int i=x-1;i<(x+unidad);i++){
		pintarDe(GRIS,i,y);
		pintarDe(GRIS,i,y+unidad-1);
	}

	for (int j=y;j<(y+unidad);j++){
		pintarDe(GRIS,x+unidad-1,j);
	}
}

void Dibujar::pintarParedHorizontal2(){

	for (int i=(x-unidad);i<x+1;i++){
		pintarDe(GRIS,i,y);
		pintarDe(GRIS,i,y+unidad-1);
	}

	for (int j=y;j<(y+unidad);j++){
		pintarDe(GRIS,x-unidad,j);
	}
}

void Dibujar::unoDerecha(){

	if (primerPaso){

		primerPaso=false;

	}else{

		x+=unidad;

		for (int i=x-1;i<(x+unidad);i++){
			for (int j=y;j<(y+unidad);j++){
				pintarDe(miColor,i,j);
			}
		}

		pintarParedHorizontal1();
	}
}

void Dibujar::unoAbajo(){

	if (primerPaso){

		primerPaso=false;

	}else{

		y+=unidad;

		for (int i=x;i<(x+unidad);i++){
			for (int j=y-1;j<(y+unidad);j++){
				pintarDe(miColor,i,j);
			}
		}

		pintarParedVertical1();
	}
}


void Dibujar::unoIzquierda(){

	if (primerPaso){

		primerPaso=false;

	}else{

		for (int i=(x-unidad);i<x+1;i++){
			for (int j=y;j<(y+unidad);j++){
				pintarDe(miColor,i,j);
			}
		}

		pintarParedHorizontal2();

		x-=unidad;
	}
}

void Dibujar::unoArriba(){
    if(primerPaso){

    	primerPaso=false;

    }else{

    	for (int i=x;i<(x+unidad);i++){
    		for (int j=(y-unidad);j<y+1;j++){
    			pintarDe(miColor,i,j);
    		}
    	}

    	pintarParedVertical2();

    	y-=unidad;
    }
}

void Dibujar::pintarDe(tipoColor color, int i, int j){

    switch(color){

    case ROJO:

    	miImagen(i,j)->Red=150;
    	miImagen(i,j)->Green=0;
    	miImagen(i,j)->Blue=0;

    break;

    case VERDE:

    	miImagen(i,j)->Red=53;
    	miImagen(i,j)->Green=94;
    	miImagen(i,j)->Blue=59;

    break;

    case AZUL:

    	miImagen(i,j)->Red=0;
    	miImagen(i,j)->Green=0;
    	miImagen(i,j)->Blue=255;

    break;

    case GRIS:

    	miImagen(i,j)->Red=50;
    	miImagen(i,j)->Green=50;
    	miImagen(i,j)->Blue=50;

    break;

    case AMARILLO:

    	miImagen(i,j)->Red=253;
    	miImagen(i,j)->Green=233;
    	miImagen(i,j)->Blue=16;

    break;

    case NARANJA:

    	miImagen(i,j)->Red=204;
    	miImagen(i,j)->Green=119;
    	miImagen(i,j)->Blue=34;

    break;

    case NEGRO:

    	miImagen(i,j)->Red=0;
    	miImagen(i,j)->Green=0;
    	miImagen(i,j)->Blue=0;

    break;

    case BLANCO:

    	miImagen(i,j)->Red=255;
    	miImagen(i,j)->Green=255;
    	miImagen(i,j)->Blue=255;

    break;
    }
}



#endif /* DIBUJAR_H_ */
