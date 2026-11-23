#pragma once
#include "Sprite.h"

class Molly : public Sprite {
public:
	Molly(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) :
		Sprite(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale) {};
	~Molly() {};

	int getPuntosVida() { return puntosVida; }

	void setPuntosVida(int puntosDeVida) { this->puntosVida = puntosDeVida; }

	void mover(Direccion tecla, int WidthScreen, int HeightScreen) override {
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
		if (x > WidthScreen - anchoFrameModificado) x = WidthScreen - anchoFrameModificado;
		if (y > HeightScreen - altoFrameModificado) y = HeightScreen - altoFrameModificado;

		animar(tecla);
	};

	void animar(Direccion tecla) {
		if (tecla == Abajo)		indiceY = 0;
		if (tecla == Izquierda)	indiceY = 1;
		if (tecla == Derecha)	indiceY = 2;
		if (tecla == Arriba)	indiceY = 3;

		if (tecla != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		}
		else { indiceX = 0; }
	};

private:
	int puntosVida;
};
