#pragma once
#include "Sprite.h"
#include <cstdlib>

class AntiSemita : public Sprite
{
public:
    AntiSemita(int x, int y, int anchoSpriteSheet,
        int altoSpriteSheet, int filas, int columnas,
        int velocidad, double escala)
        : Sprite(x, y, anchoSpriteSheet, altoSpriteSheet,
            filas, columnas, velocidad, escala)
    {
        indiceX = 0;
        indiceY = 2;
    }

    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override {
        dx = -velocidad;
        dy = 0;

        x += dx;

        indiceX = (indiceX + 1) % columnas;
    }

    void reaparecer(int limiteAncho, int limiteAlto) {
        int anchoCarro = (int)(anchoFrame * escala);

        if (x + anchoCarro < 0) {
            x = limiteAncho + 100 + rand() % 500;
        }
    }


};

