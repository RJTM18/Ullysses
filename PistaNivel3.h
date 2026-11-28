#pragma once
#include "Sprite.h"

class PistaNivel3 {
    int tipo, x, y;
    bool recogida;
public:
    PistaNivel3(int tipo, int x, int y)
        : tipo(tipo), x(x), y(y), recogida(false) {}
    bool estaRecogida() { return recogida; }
    void recoger() { recogida = true; }
    Rectangle getRectangle() { return Rectangle(x, y, 58, 58); }
    void dibujar(Graphics^ g, Bitmap^ hoja) {
        if (recogida) return;
        int ancho = hoja->Width / 3;
        Rectangle origen(tipo * ancho, 0, ancho, hoja->Height);
        g->DrawImage(hoja, getRectangle(), origen, GraphicsUnit::Pixel);
    }
};
