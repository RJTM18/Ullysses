#pragma once
#include "Sprite.h"

class Policia : public Sprite {
public:
	Policia(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) :
		Sprite(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale) {};
	~Policia() {};

	void mover(Direccion direccionJugador, int WidthScreen, int HeightScreen) override {
		//movimiento
		dx = dy = 0;

		if (direccionJugador == Derecha)	dx = -1; //Policía va la izquierda.
		if (direccionJugador == Izquierda)	dx = 1;	 //Policía a la derecha.
		if (direccionJugador == Arriba)		dy = 1;  //Policía abajo.
		if (direccionJugador == Abajo)		dy = -1; //policía arriba.

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

		animar(direccionJugador);
	};

	void animar(Direccion direccionJugador) {
		if (direccionJugador == Arriba)		indiceY = 0;
		if (direccionJugador == Abajo)		indiceY = 1;
		if (direccionJugador == Derecha)	indiceY = 2;
		if (direccionJugador == Izquierda)	indiceY = 3;

		if (direccionJugador != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		}
		else { indiceX = 0; }
	};
};
