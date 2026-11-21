#pragma once
#include "Debug.h"
#include <vector>
#include "Leopold.h"
class Juego {
public:
	Juego(int anchoPantallaPixel, int altoPantallaPixel) : anchoPantalla(anchoPantallaPixel), altoPantalla(altoPantallaPixel) {};
	~Juego() { 
		delete leopold; 
	};

	void crearLeopold(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, int escala) { leopold = new Leopold(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala); }
	void dibujarJunior(Graphics^ g, Bitmap^ imgJunior) { leopold->dibujar(g, imgJunior); }

	void moverJunior(Direccion tecla, int AnchoPantallaSprite, int AltoPantallaSprite) { 
		leopold->mover(tecla, AnchoPantallaSprite, AltoPantallaSprite); 

	}


private:
	int anchoPantalla;
	int altoPantalla;

	Leopold* leopold;
	// std::vector<Debug*> debugs;
};

