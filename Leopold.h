#pragma once
#include "Sprite.h"
#include "LogicaNivel1.h"
class Leopold : public Sprite {
public:
	Leopold(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, double escala) :
		Sprite(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala) {
		setHitbox(0.46, 0.20, 0.10, 0.40);
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

		//este es el tamaño del sprite pero ya modificado
		int anchoFrameModificado = (anchoFrame * escala);
		int altoFrameModificado = (altoFrame * escala);

		//limites
		Logica1 logica(3, 0);

		x = logica.colisionX(x, anchoFrameModificado);
		y = logica.colisionY(y, altoFrameModificado);
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
