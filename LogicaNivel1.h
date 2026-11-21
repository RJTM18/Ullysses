#pragma once
#include "Juego.h"
#include <algorithm>
#include <vector>
class Logica1
{
private:
	int vida;
	int MetrosLogrados;
public:
	Logica1(int vida, int MetrosLogrados)
	{
		this->vida = vida;
		this->MetrosLogrados = MetrosLogrados;
	}
	int getVida()
	{
		return vida;
	}

	int getMetrosLogrados()
	{
		return MetrosLogrados;
	}

	void perderVida()
	{
		if (vida > 0)
		{
			vida--;
		}
	}

	bool perdio()
	{
		return vida <= 0;
	}

	bool gano()
	{
		return MetrosLogrados >= 400;
	}

	void sumarMetros(int metros)
	{
		MetrosLogrados += metros;
	}
};