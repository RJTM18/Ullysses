#pragma once
#include "pch.h"
#include "Stephen.h"
#include "Policia.h"

class LogicaNivel2{
public:
	LogicaNivel2(int anchoPantalla, int altoPantalla) : anchoPantallaSprite(anchoPantalla), altoPantallaSprite(altoPantalla), stephen(nullptr) {};
	~LogicaNivel2() { 
		delete stephen; 
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) delete escuadronPolicias[i];
	};

	void setCantidadPuntosVida(int puntosDeVida) { stephen->setPuntosVida(puntosDeVida); }
	void impactoJugadorConEntidad() {
		stephen->fueImpactado();
		if (stephen->getAcasoEstaMuerto()) {

		};
	};

	void crearStephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		stephen = new Stephen(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void crearNuevoPolicia(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale,
		int siJugadorDerecha, int siJugadorIzquierda, int siJugadorArriba, int siJugadorAbajo) {
		Policia* nuevoPolicia = new Policia(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale,
			siJugadorDerecha, siJugadorIzquierda, siJugadorArriba, siJugadorAbajo);
		escuadronPolicias.push_back(nuevoPolicia);
	};

	void dibujarEntidades(Graphics^ g, Bitmap^ ImgStephen, Bitmap^ ImgPolicia) {
		if (stephen == nullptr || escuadronPolicias.empty()) return;

		stephen->dibujar(g, ImgStephen);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->dibujar(g, ImgPolicia);
	};

	void moverStephen(Direccion tecla, int WidthScreen, int HeightScreen) {
		if (stephen == nullptr) return;
		
		stephen->mover(tecla, WidthScreen, HeightScreen);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->mover(tecla, WidthScreen, HeightScreen);
	};

	void moverPolicias(Direccion dicJugador, int WidthScreen, int HeightScreen) {
		if (escuadronPolicias.empty()) return;
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->mover(dicJugador, WidthScreen, HeightScreen);
	};

private:
	int anchoPantallaSprite; //ancho de pantalla donde se movera el sprite en cada nivel
	int altoPantallaSprite; //alto de pantalla donde se movera el sprite en cada nivel

	Stephen* stephen;
	std::vector<Policia*> escuadronPolicias;
};
