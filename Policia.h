#pragma once
#include "Sprite.h"

class Policia : public Sprite {
public:
	Policia(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale,
		int siJugadorDerecha, int siJugadorIzquierda, int siJugadorArriba, int siJugadorAbajo) :
		Sprite(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale),
		siJugadorAbajo(siJugadorAbajo),
		siJugadorArriba(siJugadorArriba),
		siJugadorDerecha(siJugadorDerecha),
		siJugadorIzquierda(siJugadorIzquierda) {};
	~Policia() {};

	void mover(Direccion direccionPolicia, int WidthScreen, int HeightScreen) override {
		//movimiento
		dx = dy = 0;

		if (direccionPolicia == Derecha)	dx = 1;		//Policía va la izquierda.
		if (direccionPolicia == Izquierda)	dx = -1;	//Policía a la derecha.
		if (direccionPolicia == Arriba)		dy = -1;	//Policía abajo.
		if (direccionPolicia == Abajo)		dy = 1;		//policía arriba.

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

		animar(direccionPolicia);
	};

	void animar(Direccion direccionPolicia) {
		if (direccionPolicia == Arriba)		indiceY = 0;
		if (direccionPolicia == Abajo)		indiceY = 1;
		if (direccionPolicia == Derecha)	indiceY = 2;
		if (direccionPolicia == Izquierda)	indiceY = 3;

		if (direccionPolicia != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		}
		else { indiceX = 0; }
	};

private:
	int siJugadorDerecha;
	int siJugadorIzquierda;
	int siJugadorArriba;
	int siJugadorAbajo;
};
