#pragma once
#include "Sprite.h"

class Leopold : public Sprite {
public:
	Leopold(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, double escala) :
		Sprite(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala) {
	};
	~Leopold() {};

	void mover(Direccion tecla, int AnchoPantallaSprite, int AltoPantallaSprite) override {
		//movimiento
		dx = dy = 0;

		if (tecla == Derecha)	dx = 1;
		if (tecla == Izquierda) dx = -1;
		if (tecla == Arriba)	dy = -1;
		if (tecla == Abajo)		dy = 1;

		x += velocidad * dx;
		y += velocidad * dy;

		//tamaño del sprite modificado
		int anchoFrameModificado = (anchoFrame * escala);
		int altoFrameModificado = (altoFrame * escala);

		//limites
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		if (x > AnchoPantallaSprite - anchoFrameModificado) x = AnchoPantallaSprite - anchoFrameModificado;
		if (y > AltoPantallaSprite - altoFrameModificado) y = AltoPantallaSprite - altoFrameModificado;

		Animar(tecla);
	};

	void Animar(Direccion tecla) {
		if (tecla == Abajo)		indiceY = 0;
		if (tecla == Izquierda) indiceY = 2;
		if (tecla == Derecha)	indiceY = 3;
		if (tecla == Arriba)	indiceY = 1;

		if (tecla != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		} else { indiceX = 0; }
	};

	

};
