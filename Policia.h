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

	void mover(Direccion direccionJugador, int WidthScreen, int HeightScreen) override {
		Direccion dirreccionPolicia = Ninguno;
		//movimiento
		dx = dy = 0;

		if (direccionJugador == Derecha)	dx = siJugadorDerecha;	//Policía va la izquierda.
		if (direccionJugador == Izquierda)	dx = siJugadorIzquierda;//Policía a la derecha.
		if (direccionJugador == Arriba)		dy = siJugadorArriba;	//Policía abajo.
		if (direccionJugador == Abajo)		dy = siJugadorAbajo;	//policía arriba.

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

		animar(dirreccionPolicia);
	};

	void animar(Direccion dirreccionPolicia) {
		if (dirreccionPolicia == Arriba)		indiceY = 0;
		if (dirreccionPolicia == Abajo)		indiceY = 1;
		if (dirreccionPolicia == Derecha)	indiceY = 2;
		if (dirreccionPolicia == Izquierda)	indiceY = 3;

		if (dirreccionPolicia != Ninguno) {
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
