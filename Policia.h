#pragma once
#include "Sprite.h"

struct ReaccionPolicia {
	Direccion siJugadorDerecha;
	Direccion siJugadorIzquierda;
	Direccion siJugadorArriba;
	Direccion siJugadorAbajo;

	//Si el jugador toma una dirección, ¿qué dirección tomará el policía?
	ReaccionPolicia(Direccion der, Direccion izq, Direccion arr, Direccion aba)
		: siJugadorDerecha(der), siJugadorIzquierda(izq),
		siJugadorArriba(arr), siJugadorAbajo(aba) {
	}
};

class Policia : public Sprite {
public:
	Policia(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale,
		ReaccionPolicia reaccion) :
		Sprite(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale), 
		reaccionPolicia(reaccion) {};
	~Policia() {};

	void mover(Direccion direccionJugador, int WidthScreen, int HeightScreen) override {
		Direccion direccionPolicia = Ninguno;
		
		//direccion de respuesta
		if (direccionJugador == Derecha)	direccionPolicia = reaccionPolicia.siJugadorDerecha;	//Policía va la izquierda.
		if (direccionJugador == Izquierda)	direccionPolicia = reaccionPolicia.siJugadorIzquierda;	//Policía a la derecha.
		if (direccionJugador == Arriba)		direccionPolicia = reaccionPolicia.siJugadorArriba;	//Policía abajo.
		if (direccionJugador == Abajo)		direccionPolicia = reaccionPolicia.siJugadorAbajo;		//policía arriba.

		//movimiento
		dx = dy = 0;
		if (direccionPolicia == Derecha)   dx = 1;
		if (direccionPolicia == Izquierda) dx = -1;
		if (direccionPolicia == Arriba)    dy = -1;
		if (direccionPolicia == Abajo)     dy = 1;
		
		x += velocidad * dx;
		y += velocidad * dy;

		//tamaño del sprite modificado
		int anchoFrameModificado = (anchoFrame * escala);
		int altoFrameModificado = (altoFrame * escala);

		//mitad de la anchura de la calle
		const int mitadAnchuraCalle = 500;

		//limites
		if (x < WidthScreen - mitadAnchuraCalle) x = WidthScreen - mitadAnchuraCalle;
		if (y < 0) y = 0;
		if (x > (WidthScreen + mitadAnchuraCalle ) - anchoFrameModificado) x = (WidthScreen + mitadAnchuraCalle) - anchoFrameModificado;
		if (y > HeightScreen - altoFrameModificado) y = HeightScreen - altoFrameModificado;

		animar(direccionPolicia);
	};

	void animar(Direccion dirreccionPolicia) {
		if (dirreccionPolicia == Arriba)	indiceY = 0;
		if (dirreccionPolicia == Abajo)		indiceY = 1;
		if (dirreccionPolicia == Izquierda)	indiceY = 2;
		if (dirreccionPolicia == Derecha)	indiceY = 3;

		if (dirreccionPolicia != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		}
		else { indiceX = 0; }
	};

private:
	ReaccionPolicia reaccionPolicia;
};
