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
            filas, columnas, velocidad, escala) {

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
        int anchoCarro = anchoFrame * escala;

        if (x + anchoCarro < 10)
        {
            x = limiteAncho;

            int carril = rand() % 3;

            int altoCarro = altoFrame * escala;
            int inicioPista = limiteAlto * 45 / 100;
            int espacio = limiteAlto - inicioPista;

            y = inicioPista + carril * espacio / 3 + (espacio / 3 - altoCarro) / 2;
        }
    }

    
};
