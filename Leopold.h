#pragma once
#include "Sprite.h"

class Leopold : public Sprite {
public:
	Leopold(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, double escala) :
		Sprite(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala) {
	};
	~Leopold() {};
	void mover(Direccion tecla, int AnchoPantallaSprite, int AltoPantallaSprite) override {
		//HAMP Explica: PASO 1 - si hay flecha, dx y dy dicen hacia donde ir y se avanza velocidad pixeles
		if (tecla != Ninguno) {
			dx = 0;
			dy = 0;

			if (tecla == Arriba)	dy = -1;
			if (tecla == Abajo)		dy = 1;
			if (tecla == Izquierda) dx = -1;
			if (tecla == Derecha)	dx = 1;

			x += dx * velocidad;
			y += dy * velocidad;

			
			int anchoPersonaje = (int)(anchoFrame * escala);
			int altoPersonaje = (int)(altoFrame * escala);
			
			//Aqui es donde se puede utilizar el límite del personaje hecho
			int limiteIzquierdo = 0;
			int limiteDerecho = 1000;

			//aqui es la cantidad pero en el eje y
			int limiteSuperior = 300;
			int limiteInferior = 1200;

             //aqui es donde se aplican los límites del personaje para que no se salga del mapa
			
			//en x
			if (x < limiteIzquierdo)
				x = limiteIzquierdo;

			if (x > limiteDerecho - anchoPersonaje)
				x = limiteDerecho - anchoPersonaje;

			//en y
			if (y < limiteSuperior)
				y = limiteSuperior;

			if (y > limiteInferior - altoPersonaje)
				y = limiteInferior - altoPersonaje;

			if (x < 0) x = 0;
			if (y < 0) y = 0;

			if (x > AnchoPantallaSprite - anchoPersonaje)
				x = AnchoPantallaSprite - anchoPersonaje;

			if (y > AltoPantallaSprite - altoPersonaje)
				y = AltoPantallaSprite - altoPersonaje;
			Animar(tecla);
		}
	};
	//esto sirve para que pueda realizar la animación siguendo los indices 4x4
	void Animar(Direccion tecla) {
		if (tecla == Abajo)		indiceY = 0;
		if (tecla == Izquierda) indiceY = 2;
		if (tecla == Derecha)	indiceY = 3;
		if (tecla == Arriba)	indiceY = 1;

		if (tecla != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		}
		else { indiceX = 0; }
	};

	

};
