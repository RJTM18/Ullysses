#pragma once
//Aquí, incluye los headers de los sprites a utilizar.
#include "Molly.h"

class LogicaNivel3{
public:
	LogicaNivel3(int anchoPantalla, int altoPantalla) : anchoPantallaSprite(anchoPantalla), altoPantallaSprite(altoPantalla), molly(nullptr) {};
	~LogicaNivel3() { delete molly; };

	//Cada nivel define cuántas vidas tendrá el protagonista. 
	void setCantidadPuntosVida(int puntosDeVida) { molly->setPuntosVida(puntosDeVida); }

	void crearMolly(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		molly = new Molly(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void dibujarMolly(Graphics^ g, Bitmap^ ImgStephen) {
		if (molly == nullptr) return;
		molly->dibujar(g, ImgStephen);
	};

	void moverMolly(Direccion tecla, int WidthScreen, int HeightScreen) {
		if (molly == nullptr) return;
		molly->mover(tecla, WidthScreen, HeightScreen);
	};

private:
	Molly* molly;

	int anchoPantallaSprite; //ancho de pantalla donde se movera el sprite en cada nivel
	int altoPantallaSprite; //alto de pantalla donde se movera el sprite en cada nivel
};