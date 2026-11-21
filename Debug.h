#pragma once
#include "Sprite.h"

class Debug : public Sprite{
public:
	Debug(Direccion tecla, int anchoScreenPixel, int altoScreenPixel, int AnchoSheet, int AltoSheet, int columns, int rows, int velocidad, int scale) :
		Sprite(x, y, anchoScreenPixel, altoScreenPixel, rows, columns, velocidad, scale) {
		//HAMP Explica: cada direccion tiene su dx, dy y su giro
		if (tecla == Derecha)	{ dx = 1; }
		if (tecla == Abajo)		{ dy = 1; }
		if (tecla == Izquierda) { dx = -1; }
		if (tecla == Arriba)	{ dy = -1; }
	};
	~Debug();

	void mover(Direccion tecla, int anchoScreenPixel, int altoScreenPixel) override	{
		x += dx * velocidad;
		y += dy * velocidad;

		//HAMP Explica: cuadros de vuelo 1, 2, 3 y vuelve a 1
		indiceX++;
		if (indiceX >= columnas) indiceX = 0;
	}
	
	bool ImpactoConLimite(int anchoScreenPixel, int altoScreenPixel) {
		return x < -anchoFrame || y < -altoFrame || x > anchoScreenPixel || y > altoScreenPixel;
	}

	void dibujarBola(Graphics^ g, Bitmap^ imagen) {
		Rectangle origen = Rectangle(indiceX * anchoFrame, indiceY * altoFrame, anchoFrame, altoFrame);

		//HAMP Explica: se mueve el origen al centro de la bola, se gira, se pinta y se deshace el giro
		g->TranslateTransform((float)(x + anchoFrame / 2), (float)(y + anchoFrame / 2));
		g->DrawImage(imagen, Rectangle(-anchoFrame / 2, -altoFrame / 2, anchoFrame, altoFrame), origen, GraphicsUnit::Pixel);
		g->ResetTransform();
	}

private:
};
