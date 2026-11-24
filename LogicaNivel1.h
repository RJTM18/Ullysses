#pragma once
#include <vector>
#include "Leopold.h"
#include "Carro.h"
#include "AntiSemita.h"

class Logica1
{
private:
    int PuntosVida;
    int MetrosLogrados;
    int contadorMovimientos;
    int proteccion;

    int anchoPantalla, altoPantalla;
    Leopold* leopold;
    std::vector<Carro*> carros;
    std::vector<AntiSemita*> antisemita;

public:
    Logica1(int vida, int metros, int anchoPantalla, int altoPantalla)
        : PuntosVida(vida), MetrosLogrados(metros), contadorMovimientos(0), proteccion(0),
        anchoPantalla(anchoPantalla), altoPantalla(altoPantalla), leopold(nullptr) {
    }

    ~Logica1() {
        delete leopold;
        for (Carro* c : carros) delete c;
        for (AntiSemita* a : antisemita) delete a;
    }

    // ---------- creación ----------
    void crearLeopold(int x, int y, int anchoSS, int altoSS, int columnas, int filas, int velocidad, double escala) {
        leopold = new Leopold(x, y, anchoSS, altoSS, columnas, filas, velocidad, escala);
    }
    void crearCarro(int x, int y, int anchoSS, int altoSS, int columnas, int filas, int velocidad, double escala) {
        carros.push_back(new Carro(x, y, anchoSS, altoSS, filas, columnas, velocidad, escala));
    }
    void crearAntisemita(int x, int y, int anchoSS, int altoSS, int columnas, int filas, int velocidad, double escala) {
        antisemita.push_back(new AntiSemita(x, y, anchoSS, altoSS, filas, columnas, velocidad, escala));
    }

    //espacio donde se moverán
    void moverLeopold(Direccion tecla, int ancho, int alto) {
        if (leopold == nullptr) return;
        leopold->mover(tecla, ancho, alto);
        leopold->setX(colisionX(leopold->getX(), leopold->getAnchoEscalado()));
        leopold->setY(colisionY(leopold->getY(), leopold->getAltoEscalado()));
    }
    void moverCarros() {
        for (Carro* c : carros) {
            c->mover(Ninguno, anchoPantalla, altoPantalla);
            c->reaparecer(anchoPantalla, altoPantalla);
        }
    }
    void moverAntisemita() {
        for (AntiSemita* a : antisemita) {
            a->mover(Ninguno, anchoPantalla, altoPantalla);
            a->reaparecer(anchoPantalla, altoPantalla);
        }
    }

    //en donde se dibuja todo del primer nivel
    void dibujarLeopold(Graphics^ g, Bitmap^ img) { if (leopold) leopold->dibujar(g, img); }
    void dibujarCarros(Graphics^ g, Bitmap^ img) { for (Carro* c : carros) c->dibujar(g, img); }
    void dibujarAntisemita(Graphics^ g, Bitmap^ img) { for (AntiSemita* a : antisemita) a->dibujar(g, img); }
    void dibujarColisiones(Graphics^ g) {
        if (leopold) g->DrawRectangle(Pens::Red, leopold->getRectangle());
        for (Carro* c : carros) g->DrawRectangle(Pens::Yellow, c->getRectangle());
        for (AntiSemita* a : antisemita) g->DrawRectangle(Pens::Blue, a->getRectangle());
    }

    //aqui son las colisiones de enemigos y poder detectarlo
    void verificarColisiones() {
        if (leopold == nullptr) return;
        if (proteccion > 0) { proteccion--; return; }

        for (Carro* c : carros)
            if (leopold->getRectangle().IntersectsWith(c->getRectangle())) {
                PerderPuntosVida(); proteccion = 10; return;
            }
        for (AntiSemita* a : antisemita)
            if (leopold->getRectangle().IntersectsWith(a->getRectangle())) {
                PerderPuntosVida(); proteccion = 10; return;
            }
    }

   //Este sería el estado del nivel
    int  getVida() { return PuntosVida; }
    int  metros() { return MetrosLogrados; }
    bool perdio() { return PuntosVida <= 0; }
    bool gano() { return MetrosLogrados >= 400; }
    void PerderPuntosVida() { if (PuntosVida > 0) PuntosVida--; }
    void sumarMetros(int m) { MetrosLogrados += m; }

    void actualizarMetros(Direccion tecla) {
        if (tecla == Derecha) {
            contadorMovimientos++;
            if (contadorMovimientos >= 5) { sumarMetros(5); contadorMovimientos = 0; }
        }
    }

    // ---------- límites del mapa ----------
    int colisionY(int y, int alto) {
        int sup = 380, inf = 960;
        if (y < sup) y = sup;
        if (y + alto > inf) y = inf - alto;
        return y;
    }
    int colisionX(int x, int ancho) {
        int izq = 380, der = 800;
        if (x < izq) x = izq;
        if (x + ancho > der) x = der - ancho;
        return x;
    }
};