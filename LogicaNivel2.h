#pragma once
#include "Stephen.h"

class Nivel_2 {
public:
	Nivel_2(int anchoPantalla, int altoPantalla) : widthScreen(anchoPantalla), heightScreen(altoPantalla) {};
	~Nivel_2() { delete stephen; };

	void crearStephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		stephen = new Stephen(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	}
	void dibujarStephen(Graphics^ g, Bitmap^ ImgStephen) { stephen->dibujar(g, ImgStephen); }
	void moverStephen(Direccion tecla, int WidthScreen, int HeightScreen) { stephen->mover(tecla, WidthScreen, HeightScreen); }

private:
	int widthScreen;
	int heightScreen;

	Stephen* stephen;
};
