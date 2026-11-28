#pragma once
#include "Sprite.h"

class Boylan : public Sprite {
    int sentido;
public:
    Boylan(int x, int y, int ancho, int alto)
        : Sprite(x, y, ancho, alto, 1, 1, 1, 0.075), sentido(1) {
        setHitbox(0.20, 0.15, 0.60, 0.70);
    }
    void mover(Direccion tecla, int limiteAncho, int limiteAlto) override {
        x += sentido * velocidad;
        if (x >= 835) sentido = -1;
        if (x <= 730) sentido = 1;
    }

    void perseguir(int objetivoX, int objetivoY) {
        if (x < objetivoX - 10) x += 3;
        if (x > objetivoX + 10) x -= 3;
        if (y < objetivoY - 10) y += 3;
        if (y > objetivoY + 10) y -= 3;
    }

    void alejarse() {
        x = 850;
        y = 300;
    }
};
