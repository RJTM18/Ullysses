#pragma once
#include "Sprite.h"
#include <cstdlib>

class Carro : public Sprite 
{
public:
    Carro(int x, int y, int anchoSpriteSheet,
        int altoSpriteSheet, int filas, int columnas,
        int velocidad, double escala)
        : Sprite(x, y, anchoSpriteSheet, altoSpriteSheet,
            filas, columnas, velocidad, escala) 
    {
        indiceX = 0;
        indiceY = 2;
        setHitbox(0.10, 0.20, 0.78, 0.50);
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
            x = limiteAncho + 300 + rand() % 900;
        }
    }

    
};
