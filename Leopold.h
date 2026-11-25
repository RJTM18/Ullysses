#pragma once
#include "Sprite.h"
class Leopold : public Sprite {
public:
	Leopold(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, double escala) :
		Sprite(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala) {
		setHitbox(0.46, 0.20, 0.10, 0.25);
	};
	~Leopold() {};

	void mover(Direccion tecla, int, int) override {
		dx = dy = 0;
		if (tecla == Derecha)   dx = 1;
		if (tecla == Izquierda) dx = -1;
		if (tecla == Arriba)    dy = -1;
		if (tecla == Abajo)     dy = 1;

		x += velocidad * dx;
		y += velocidad * dy;
		Animar(tecla);
	};

	int getAnchoEscalado() { return (int)(anchoFrame * escala); }
	int getAltoEscalado() { return (int)(altoFrame * escala); }

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
