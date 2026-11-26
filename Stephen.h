#pragma once
#include "Sprite.h"

class Stephen : public Sprite {
public:
	Stephen(int x, int y, int widthSpriteSheet, int heightSpriteSheet, int rows, int columns, int speed, double scale) :
		Sprite(x, y, widthSpriteSheet, heightSpriteSheet, rows, columns, speed, scale), 
		AcasoEstaMuerto(false), recibioImpactoPrevio(false),ticks(0) {};
	~Stephen() {};

	int getPuntosVida() { return puntosVida; }
	bool getAcasoEstaMuerto() { return AcasoEstaMuerto; }
	bool getRecibioImpactoPrevio() { return recibioImpactoPrevio; }
	void setPuntosVida(int puntosDeVida) { this->puntosVida = puntosDeVida; }

	//Esta función empieza a sumar solo si el jugador ha sido impactado previamente. 
	void sumarTicks() {
		ticks++;
		if (ticks >= 45) {
			ticks = 0;
			recibioImpactoPrevio = false;
		}
	};

	void fueImpactado() {
		// Solo hacer daño si NO está en período de invencibilidad
		if (!recibioImpactoPrevio) {
			recibioImpactoPrevio = true;			
			puntosVida--;
			ticks = 0;  // Reiniciar el contador desde 0
		}
	};

	void jugadorMuerto() { this->AcasoEstaMuerto = true; }

	void mover(Direccion tecla, int WidthScreen, int HeightScreen) override {		
		//movimiento
		dx = dy = 0;

		if (tecla == Derecha)	dx = 1;
		if (tecla == Izquierda) dx = -1;
		if (tecla == Arriba)	dy = -1;
		if (tecla == Abajo)		dy = 1;

		x += velocidad * dx;
		y += velocidad * dy;

		//tamaño del sprite modificado
		int anchoFrameModificado = (anchoFrame * escala);
		int altoFrameModificado = (altoFrame * escala);

		const int mitadAnchuraCalle = 500;

		//limites
		if (x < WidthScreen - mitadAnchuraCalle) x = WidthScreen - mitadAnchuraCalle;
		if (y < 0) y = 0;
		if (x > (WidthScreen + mitadAnchuraCalle) - anchoFrameModificado) x = (WidthScreen + mitadAnchuraCalle) - anchoFrameModificado;
		if (y > HeightScreen - altoFrameModificado) y = HeightScreen - altoFrameModificado;

		animar(tecla);
	};

	void animar(Direccion tecla) {
		if (tecla == Abajo)		indiceY = 0;
		if (tecla == Izquierda)	indiceY = 1;
		if (tecla == Derecha)	indiceY = 2;
		if (tecla == Arriba)	indiceY = 3;

		if (tecla != Ninguno) {
			indiceX++;
			if (indiceX >= columnas) indiceX = 0;
		}
		else { indiceX = 0; }
	};

private: 
	int puntosVida;
	int ticks;
	bool AcasoEstaMuerto; //determina si el jugador perdio todas sus vidas
	bool recibioImpactoPrevio; //determina si el jugador ha sido impactado previamente 

};
