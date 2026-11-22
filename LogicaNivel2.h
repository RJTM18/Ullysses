#pragma once
//#include "LogicaGeneral.h"
#include "Stephen.h"

class LogicaNivel2 {
public:
	LogicaNivel2(int anchoPantalla, int altoPantalla) : anchoPantalla(anchoPantalla), altoPantalla(altoPantalla), stephen(nullptr) {};
	~LogicaNivel2() { delete stephen; };

	void crearStephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		stephen = new Stephen(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void dibujarStephen(Graphics^ g, Bitmap^ ImgStephen) {
		if (stephen == nullptr) return;
		stephen->dibujar(g, ImgStephen);
	};

	void moverStephen(Direccion tecla, int WidthScreen, int HeightScreen) {
		if (stephen == nullptr) return;
		stephen->mover(tecla, WidthScreen, HeightScreen);
	};

private:
	int anchoPantalla;
	int altoPantalla;

	Stephen* stephen;
};
