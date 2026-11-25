#pragma once
//Aquí, incluye los headers de los sprites a utilizar.
#include "Molly.h"
#include "Pesadilla.h"

class LogicaNivel3 {
public:
	LogicaNivel3(int anchoPantalla, int altoPantalla)
		: anchoPantallaSprite(anchoPantalla), altoPantallaSprite(altoPantalla),
		molly(nullptr), pesadilla(nullptr) {
	};

	~LogicaNivel3() {
		delete molly;
		delete pesadilla;
	};

	//Cada nivel define cuántas vidas tendrá el protagonista. 
	void setCantidadPuntosVida(int puntosDeVida) { molly->setPuntosVida(puntosDeVida); }

	void crearMolly(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		molly = new Molly(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	//Crea al antagonista del nivel 3 (monstruo que se mueve en la parte superior)
	void crearPesadilla(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		pesadilla = new Pesadilla(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void dibujarMolly(Graphics^ g, Bitmap^ ImgStephen) {
		if (molly == nullptr) return;
		molly->dibujar(g, ImgStephen);
	};

	void dibujarPesadilla(Graphics^ g, Bitmap^ ImgPesadilla) {
		if (pesadilla == nullptr) return;
		pesadilla->dibujar(g, ImgPesadilla);
	};

	void moverMolly(Direccion tecla, int WidthScreen, int HeightScreen) {
		if (molly == nullptr) return;
		molly->mover(tecla, WidthScreen, HeightScreen);
	};

	//Mueve a la Pesadilla de izquierda a derecha y viceversa dentro del ancho de pantalla
	void moverPesadilla() {
		if (pesadilla == nullptr) return;
		pesadilla->mover(Ninguno, anchoPantallaSprite, altoPantallaSprite);
	};

	//Getters útiles por si el Form necesita leer posiciones
	Pesadilla* getPesadilla() { return pesadilla; }
	Molly* getMolly() { return molly; }

private:
	Molly* molly;
	Pesadilla* pesadilla;

	int anchoPantallaSprite; //ancho de pantalla donde se movera el sprite en cada nivel
	int altoPantallaSprite; //alto de pantalla donde se movera el sprite en cada nivel
};


//Aquí, incluye los headers de los sprites a utilizar.
/*#include "Molly.h"

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

*/