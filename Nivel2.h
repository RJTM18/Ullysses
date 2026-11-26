#pragma once
#include "pch.h"
#include "Stephen.h"
#include "Policia.h"

class Nivel2{
public:
	Nivel2(int anchoPantalla, int altoPantalla) : anchoPantallaSprite(anchoPantalla), altoPantallaSprite(altoPantalla), stephen(nullptr) {};
	~Nivel2() { 
		delete stephen; 
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) delete escuadronPolicias[i];
	};

	void crearStephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) {
		stephen = new Stephen(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale);
	};

	void crearNuevoPolicia(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale,
		ReaccionPolicia reaccionPoli) {
		Policia* nuevoPolicia = new Policia(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale, reaccionPoli);
		nuevoPolicia->setHitbox(0.38, 0.25, 0.28, 0.5);
		escuadronPolicias.push_back(nuevoPolicia);
	};

	void dibujarEntidades(Graphics^ g, Bitmap^ ImgStephen, Bitmap^ ImgPolicia) {
		if (stephen == nullptr || escuadronPolicias.empty()) return;

		stephen->dibujar(g, ImgStephen);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->dibujar(g, ImgPolicia);
	};

	void moverStephen(Direccion teclaPresionada, int WidthScreen, int HeightScreen) {
		if (stephen == nullptr) return;

		stephen->mover(teclaPresionada, WidthScreen, HeightScreen);
	};

	void moverPolicias(Direccion dicJugador, int WidthScreen, int HeightScreen) {
		if (escuadronPolicias.empty()) return;
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) escuadronPolicias[i]->mover(dicJugador, WidthScreen, HeightScreen);
	};

	void graficarCuadros(Graphics^ g) {
		stephen->dibujarRectangulo(g);
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) { escuadronPolicias[i]->dibujarRectangulo(g);		}
	};

	//colisiones
	//Sumar text tiene que sumar de 0 a 90 desde el momento que el jugador se impacta.
	//Mientras que el contador esté subiendo, este puede reiniciarse en el caso de que el jugador vuelva a pactar con una entidad.
	//En el caso de llegar a 90, se vuelve a cero y de ahí no se suman más.
	void impactoJugadorConEntidad() {
		if (stephen->getRecibioImpactoPrevio()) stephen->sumarTicks();
		
		for (int i = 0; i < (int)escuadronPolicias.size(); i++) {
			if (stephen->getRectangle().IntersectsWith(escuadronPolicias[i]->getRectangle())) {
				stephen->fueImpactado();
				if (stephen->getAcasoEstaMuerto()) {
					//juegoterminado()
				}
			}
		};
	};

	//El tick tiene que comenzar desde el impacto.

	void setStephenPuntosVida(int puntosDeVida) { stephen->setPuntosVida(puntosDeVida); }
	int getStephenPuntosVida() { return stephen->getPuntosVida(); }


private:
	int anchoPantallaSprite; //ancho de pantalla donde se movera el sprite en cada nivel
	int altoPantallaSprite; //alto de pantalla donde se movera el sprite en cada nivel

	Stephen* stephen;
	std::vector<Policia*> escuadronPolicias;

	//Un vector que contenga las direcciones
	std::vector<Direccion> Direcciones;
};
