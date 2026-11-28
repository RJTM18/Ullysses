#pragma once
#include "Sprite.h"

class Molly : public Sprite {
    int pasos;
public:
    Molly(int x, int y, int ancho, int alto)
        : Sprite(x, y, ancho, alto, 4, 4, 5, 0.28), pasos(0) {
        setHitbox(0.25, 0.12, 0.50, 0.75);
    }
    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override {
        dx = dy = 0;
        if (tecla == Abajo) { dy = 1; indiceY = 0; }
        if (tecla == Izquierda) { dx = -1; indiceY = 1; }
        if (tecla == Derecha) { dx = 1; indiceY = 2; }
        if (tecla == Arriba) { dy = -1; indiceY = 3; }
        x += dx * velocidad; y += dy * velocidad;
        int anchoDibujo = (int)(anchoFrame * escala);
        int altoDibujo = (int)(altoFrame * escala);
        if (x < 45) x = 45;
        if (x > limiteAncho - anchoDibujo - 45) x = limiteAncho - anchoDibujo - 45;
        if (y < 220) y = 220;
        if (y > limiteAlto - altoDibujo - 15) y = limiteAlto - altoDibujo - 15;
        if (tecla == Ninguno) { indiceX = 0; pasos = 0; }
        else { pasos++; if (pasos % 4 == 0) indiceX = (indiceX + 1) % columnas; }
    }
};
