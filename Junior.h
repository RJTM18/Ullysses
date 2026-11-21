#pragma once
#include "Sprite.h"

class Junior : public Sprite {
public:
	Junior(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, int escala) :
		Sprite(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala) {
	};
	~Junior() {};

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

			//Limites
			if (x < 0) x = 0;
			if (y < 0) y = 0;
			if (x > AnchoPantallaSprite - anchoFrame) x = AnchoPantallaSprite - anchoFrame;
			if (y > AltoPantallaSprite - altoFrame) y = AltoPantallaSprite - altoFrame;

			Animar(tecla);
		}
	};

	void Animar(Direccion tecla) {
		if (tecla == Abajo)		indiceY = 0; 
		if (tecla == Izquierda) indiceY = 1;
		if (tecla == Derecha)	indiceY = 2;
		if (tecla == Arriba)	indiceY = 3;

		if (tecla != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		}
		else { indiceX = 0; }
	};

	void lanzarDebug() {
		if (estaLanzando) return;
		estaLanzando = true;
	}

private:
	Direccion tecla;
	bool estaLanzando;

};
