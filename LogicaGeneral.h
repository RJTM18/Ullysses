#pragma once
#include "Sprite.h"

class LogicaGeneral{
public:
	//La anchura y la altura de la pantalla donde se moverá el sprite
	LogicaGeneral(int anchoPantallaSprite, int altoPantallaSprite) :
		anchoPantallaSprite(anchoPantallaSprite), altoPantallaSprite(altoPantallaSprite) {};
	//virtual ~LogicaGeneral();



protected:
	int anchoPantallaSprite; //ancho de pantalla donde se movera el sprite en cada nivel
	int altoPantallaSprite; //alto de pantalla donde se movera el sprite en cada nivel
};
