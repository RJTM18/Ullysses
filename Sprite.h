#pragma once
using namespace System::Drawing;

enum Direccion { Ninguno, Abajo, Izquierda, Derecha, Arriba };

class Sprite {
protected:
	int x, y;                  
	int dx, dy;         
	int velocidad;

	int anchoSpriteSheet, altoSpriteSheet; 
	int anchoFrame, altoFrame;
	int filas, columnas;       
	int indiceX, indiceY;      
	             
	double escala;

public:
	Sprite(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int filas, int columnas, int velocidad, double escala) {
		this->x = x;
		this->y = y;
		this->anchoSpriteSheet = anchoSpriteSheet;
		this->altoSpriteSheet = altoSpriteSheet;
		this->anchoFrame = (int)(anchoSpriteSheet / columnas);
		this->altoFrame = (int)(altoSpriteSheet / filas);
		this->filas = filas;
		this->columnas = columnas;
		this->velocidad = velocidad;
		this->escala = escala;
		dx = 0;
		dy = 0;
		indiceX = 0;
		indiceY = 0;
	}

	virtual ~Sprite() {}

	virtual void mover(Direccion tecla, int limiteAnchoPantalla, int limiteAltoPantalla) = 0;

	void dibujar(Graphics^ g, Bitmap^ imagen)	{
		Rectangle recorte (indiceX * anchoFrame, indiceY * altoFrame, anchoFrame, altoFrame);
		Rectangle destino (x, y, (int)(anchoFrame * escala), (int)(altoFrame * escala));
		g->DrawImage(imagen, destino, recorte, GraphicsUnit::Pixel);
	}

	//HAMP Explica: rectangulo de colision: empieza a 1/5 del dibujo y mide 3/5 de ancho y de alto, asi no cuenta el aire alrededor del personaje
	Rectangle getRectangle()
	{
		int ancho = (int)(anchoFrame * escala);
		int alto = (int)(altoFrame * escala);

		return Rectangle(
			x + ancho / 4,
			y + alto / 4,
			ancho * 2/4,
			alto * 2/4
		);
	}
	//HAMP Explica: TEMPORAL (solo para entender): dibuja el rectangulo de colision como un borde rojo. Luego se retira
	void dibujarRectangulo(Graphics^ g) { g->DrawRectangle(Pens::Red, getRectangle()); }

	int getX() { return x; }
	int getY() { return y; }
	int getIndiceX() { return indiceX; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};
