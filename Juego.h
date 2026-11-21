#pragma once
#include "Debug.h"
#include <vector>
#include "Leopold.h"
#include "Carro.h"
#include <algorithm>
#include "LogicaNivel1.h"
using namespace std;
class Juego {
public:
	Juego(int anchoPantallaPixel, int altoPantallaPixel) : anchoPantalla(anchoPantallaPixel), altoPantalla(altoPantallaPixel) 
    {
        leopold = nullptr;
        logica = new Logica1(5, 0);
        protección = 0;
    };
	~Juego() { 
		delete leopold; 
        delete logica;

        for (Carro* c : carros)
        {
            delete c;
        }
	};

	void crearLeopold(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, double escala) { leopold = new Leopold(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala); }
    void crearCarro(int x, int y, int anchoSpriteSheet, int altoSpriteSheet, int columnas, int filas, int velocidad, double escala) { carros.push_back(new Carro(x, y, anchoSpriteSheet, altoSpriteSheet, filas, columnas, velocidad, escala)); }
   
    void moverCarros() 
    {
        
        for (Carro* c : carros)
        {
            c->mover(Ninguno, anchoPantalla, altoPantalla);
            c->reaparecer(anchoPantalla, altoPantalla);
        }
        
           
    }

    void dibujarCarros(Graphics^ g, Bitmap^ img) {
        for (Carro* c : carros)
            c->dibujar(g, img);
    }

    void moverLeopold(Direccion tecla, int ancho, int alto) 
    {
        leopold->mover(tecla, ancho, alto);
    }

    void dibujarLeopold(Graphics^ g, Bitmap^ img) {
        leopold->dibujar(g, img);
    }

    void verificarColisiones()
    {
        if (leopold == nullptr)
        {
            return;
        }

        if (protección > 0)
        {
            protección--;
            return;
        }

        for (Carro* c : carros)
        {
            if (leopold->getRectangle().IntersectsWith(c->getRectangle()))
            {
                logica->perderVida();
                protección = 10;
                break;
            }
        }

    }

    int getVida()
    {
        return logica->getVida();
    }

    int perdio()
    {
        return logica->perdio();
    }

    void dibujarColisiones(Graphics^ g)
    {
        if (leopold != nullptr)
        {
            g->DrawRectangle(Pens::Red, leopold->getRectangle());
        }

        for (Carro* c : carros)
        {
            g->DrawRectangle(Pens::Yellow, c->getRectangle());
        }
    }

    void aumentarMetros(int metros)
    {
        logica->sumarMetros(metros);
    }

    int metros()
    {
        return logica->getMetrosLogrados();
    }

    bool gano()
    {
        return logica->gano();
    }

    void actualizarMetros(Direccion tecla)
    {
        logica->actualizarMetros(tecla == Derecha);
    }

private:
	int anchoPantalla;
	int altoPantalla;
    int protección;
	Leopold* leopold;
	vector <Carro*> carros;
    Logica1* logica;

};

