#pragma once
class Puntuacion
{
private:
	int puntos;
public:
	Puntuacion()
	{
		puntos = 0;
	}

	void sumarPuntos(int cantidad)
	{
		puntos += cantidad;
	}

	int getPuntos()
	{
		return puntos;
	}
};