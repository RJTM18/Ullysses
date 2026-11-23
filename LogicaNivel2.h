#pragma once
#include "pch.h"
#include "LogicaGeneral.h"
#include "Stephen.h"
#include "Policia.h"

class LogicaNivel2 : public LogicaGeneral{
public:
	LogicaNivel2(int anchoPantalla, int altoPantalla) : LogicaGeneral(anchoPantalla, altoPantalla), 
		stephen(nullptr) {};
	~LogicaNivel2() { 
		delete stephen; 
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) delete escuadronPolicias[i];
	};

	void setCantidadPuntosVida(int puntosDeVida) override { stephen->setPuntosVida(puntosDeVida); }
	void impactoJugadorConEntidad() {
		stephen->fueImpactado();
		if (stephen->getAcasoEstaMuerto()) {

		};
	};

	void crearStephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		stephen = new Stephen(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void crearNuevoPolicia(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		Policia* nuevoPolicia = new Policia(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
		escuadronPolicias.push_back(nuevoPolicia);
	};

	void dibujarEntidades(Graphics^ g, Bitmap^ ImgStephen, Bitmap^ ImgPolicia) {
		if (stephen == nullptr || escuadronPolicias.empty()) return;

		stephen->dibujar(g, ImgStephen);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->dibujar(g, ImgPolicia);
	};

	void moverStephen(Direccion tecla, int WidthScreen, int HeightScreen) {
		if (stephen == nullptr || escuadronPolicias.empty() ) return;
		
		stephen->mover(tecla, WidthScreen, HeightScreen);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->mover(tecla, WidthScreen, HeightScreen);
	};

private:
	Stephen* stephen;
	std::vector<Policia*> escuadronPolicias;
};
