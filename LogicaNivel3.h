#pragma once
#include "LogicaGeneral.h"
//Aquí, incluye los headers de los sprites a utilizar.
#include "Molly.h"

class LogicaNivel3 : public LogicaGeneral {
public:
	LogicaNivel3(int anchoPantalla, int altoPantalla) : LogicaGeneral(anchoPantalla, altoPantalla), molly(nullptr) {};
	~LogicaNivel3() { delete molly; };

	void setCantidadPuntosVida(int puntosDeVida) override { molly->setPuntosVida(puntosDeVida); }

	void crearStephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		molly = new Molly(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void dibujarStephen(Graphics^ g, Bitmap^ ImgStephen) {
		if (molly == nullptr) return;
		molly->dibujar(g, ImgStephen);
	};

	void moverStephen(Direccion tecla, int WidthScreen, int HeightScreen) {
		if (molly == nullptr) return;
		molly->mover(tecla, WidthScreen, HeightScreen);
	};

private:
	Molly* molly;
};