#pragma once
using namespace System::Drawing;

enum Direccion { Abajo, Izquierda, Derecha, Arriba, Ninguno };

class Sprite {
protected:
	int x, y;                  
	int dx, dy;         
	int velocidad;

	int anchoSpriteSheet, altoSpriteSheet; 
	int anchoFrame, altoFrame;
	int filas, columnas;       
	int indiceX, indiceY;      
	             
	int escala;

public:
	Sprite(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int filas, int columnas, int velocidad, int escala) {
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

	// Cada hijo define como se mueve
	virtual void mover(Direccion tecla, int limiteAncho, int limiteAlto) = 0;

	//Bitmap^ imagen => Sprite que es un conjunto de Frames (cuadros) que se recortan y se dibujan en el panel
	//Graphics^ g => lienzo donde se dibuja el sprite
	void dibujar(Graphics^ g, Bitmap^ imagen)	{
		//HAMP Explica: origen = cuadro que se recorta, destino = donde se pinta
		Rectangle recorte = Rectangle(indiceX * anchoFrame, indiceY * altoFrame, anchoFrame, altoFrame);
		Rectangle destino = Rectangle(x, y, (int)(anchoFrame * escala), (int)(altoFrame * escala));
		g->DrawImage(imagen, destino, recorte, GraphicsUnit::Pixel);
	}
















	//HAMP Explica: rectangulo de colision: empieza a 1/5 del dibujo y mide 3/5 de ancho y de alto, asi no cuenta el aire alrededor del personaje
	Rectangle getRectangle()
	{
		return Rectangle(x + anchoSpriteSheet / 5, y + altoSpriteSheet / 5, anchoSpriteSheet * 3 / 5, altoSpriteSheet * 3 / 5);
	}

	//HAMP Explica: TEMPORAL (solo para entender): dibuja el rectangulo de colision como un borde rojo. Luego se retira
	void dibujarRectangulo(Graphics^ g)
	{
		g->DrawRectangle(Pens::Red, getRectangle());
	}

	int getX() { return x; }
	int getY() { return y; }
	int getIndiceX() { return indiceX; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};
