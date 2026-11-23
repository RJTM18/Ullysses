#pragma once
#include "Sprite.h"

class LogicaGeneral{
public:
	//La anchura y la altura de la pantalla donde se moverá el sprite
	LogicaGeneral(int anchoPantallaSprite, int altoPantallaSprite) :
		anchoPantallaSprite(anchoPantallaSprite), altoPantallaSprite(altoPantallaSprite) {};
	//virtual ~LogicaGeneral();

	//Cada nivel define cuántas vidas tendrá el protagonista. 
	virtual void setCantidadPuntosVida(int puntosDeVida) = 0;

	//Esta función activará la función de perder vida de cada personaje.
	virtual void impactoJugadorConEntidad() = 0;

protected:
	int anchoPantallaSprite; //ancho de pantalla donde se movera el sprite en cada nivel
	int altoPantallaSprite; //alto de pantalla donde se movera el sprite en cada nivel
};
