#pragma once
#include "Junior.h"
#include "Debug.h"
#include <vector>

class Juego {
public:
	Juego(int anchoPantallaPixel, int altoPantallaPixel) : anchoPantalla(anchoPantallaPixel), altoPantalla(altoPantallaPixel) {};
	~Juego() { 
		delete junior; 
	};

	void crearJunior(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, int escala) { junior = new Junior(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala); }
	void dibujarJunior(Graphics^ g, Bitmap^ imgJunior) { junior->dibujar(g, imgJunior); }

	void moverJunior(Direccion tecla, int AnchoPantallaSprite, int AltoPantallaSprite) { 
		junior->mover(tecla, AnchoPantallaSprite, AltoPantallaSprite); 

	}


private:
	int anchoPantalla;
	int altoPantalla;

	Junior* junior;
	// std::vector<Debug*> debugs;
};

