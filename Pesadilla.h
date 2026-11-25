#pragma once
#include "Sprite.h"

class Pesadilla : public Sprite
{
public:
	Pesadilla(int x, int y, int anchoSpriteSheet, int altoSpriteSheet,
		int filas, int columnas, int velocidad, double escala)
		: Sprite(x, y, anchoSpriteSheet, altoSpriteSheet,
			filas, columnas, velocidad, escala)
	{
		direccionX = 1;       // empieza desplazándose a la derecha
		indiceX = 0;
		indiceY = 0;
		setHitbox(0.15, 0.15, 0.15, 0.15);
	};

	~Pesadilla() {};

	//Movimiento horizontal con rebote en los bordes del panel
	void mover(Direccion tecla, int limiteAncho, int limiteAlto) override {
		dx = velocidad * direccionX;
		dy = 0;

		x += dx;

		int anchoEscalado = (int)(anchoFrame * escala);

		//Rebote en el borde derecho
		if (x + anchoEscalado >= limiteAncho) {
			x = limiteAncho - anchoEscalado;
			direccionX = -1;
		}
		//Rebote en el borde izquierdo
		if (x <= 0) {
			x = 0;
			direccionX = 1;
		}

		//Animación simple (si el sheet tiene más columnas, se irán alternando)
		indiceX = (indiceX + 1) % columnas;
	};

	int getDireccionX() const { return direccionX; }

private:
	int direccionX; // +1 = derecha, -1 = izquierda
};;