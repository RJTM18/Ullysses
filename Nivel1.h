#pragma once
#include <vector>
#include "Leopold.h"
#include "Carro.h"
#include "AntiSemita.h"
using namespace std;
class Nivel1
{
private:
    //punto interno de leopold, su confianza
    int NivelConfianza;

    int MetrosLogrados;
    int contadorMovimientos;
    int proteccion;
    bool ConversacionRealizada;
    bool ConversacionRealizada2;
    int anchoPantalla, altoPantalla;
    Leopold* leopold;
    vector<Carro*> carros;
    vector<AntiSemita*> antisemita;

public:
    Nivel1(int NivelConfianza, int metros, int anchoPantalla, int altoPantalla)
        : NivelConfianza(NivelConfianza),
        MetrosLogrados(metros),
        contadorMovimientos(0),
        proteccion(0),
        ConversacionRealizada(false),
        anchoPantalla(anchoPantalla),
        altoPantalla(altoPantalla),
        ConversacionRealizada2(false),
        leopold(nullptr) {
    }

    ~Nivel1() {
        delete leopold;
        for (Carro* c : carros) delete c;
        for (AntiSemita* a : antisemita) delete a;
    }

   
    void crearLeopold(int x, int y, int anchoSS, int altoSS, int columnas, int filas, int velocidad, double escala) {
        leopold = new Leopold(x, y, anchoSS, altoSS, columnas, filas, velocidad, escala);
    }
    void crearCarro(int x, int y, int anchoSS, int altoSS, int columnas, int filas, int velocidad, double escala) {
        carros.push_back(new Carro(x, y, anchoSS, altoSS, filas, columnas, velocidad, escala));
    }
    void crearAntisemita(int x, int y, int anchoSS, int altoSS, int columnas, int filas, int velocidad, double escala) {
        antisemita.push_back(new AntiSemita(x, y, anchoSS, altoSS, filas, columnas, velocidad, escala));
    }

 
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
                PerderNivelConfianza(); proteccion = 10; return;
            }
        for (AntiSemita* a : antisemita)
            if (leopold->getRectangle().IntersectsWith(a->getRectangle())) {
                PerderNivelConfianza(); proteccion = 10; return;
            }
    }

   //Este sería el estado del nivel
    int  getConfianza() { return NivelConfianza; }
    int  metros() { return MetrosLogrados; }
    bool perdio() { return NivelConfianza <= 0; }
    bool gano() { return MetrosLogrados >= 600; }
    void PerderNivelConfianza(int cantidad = 10) {
        NivelConfianza -= cantidad;
        if (NivelConfianza < 0) NivelConfianza = 0;
    }
    void sumarMetros(int m) { MetrosLogrados += m; }

    void actualizarMetros(Direccion tecla) {
        if (tecla == Derecha) {
            contadorMovimientos++;
            if (contadorMovimientos >= 5) { sumarMetros(5); contadorMovimientos = 0; }
        }
    }

    // Limites del mapa
    int colisionX(int x, int ancho) {
        int izquierda = 380;
        int derecha = 800;

        if (x < izquierda)
            return izquierda;

        if (x + ancho > derecha)
            return derecha - ancho;

        return x;
    }

    // Limites verticales del jugador
    int colisionY(int y, int alto) {
        int superior = 430;
        int inferior = 960;

        if (y < superior)
            return superior;

        if (y + alto > inferior)
            return inferior - alto;

        return y;
    }

    //accion para conversar cuando llegue a los 200 metros
    bool conversar()
    {
        return MetrosLogrados >= 200 &&
            ConversacionRealizada == false &&
            !perdio();
    }

    bool conversar2()
    {
        return MetrosLogrados >= 450 &&
            ConversacionRealizada2 == false &&
            !perdio();
    }
    //cuando se acaba
    void finalizarConversacion()
    {
        ConversacionRealizada = true;
    }

    void finalizarConversacion2()
    {
        ConversacionRealizada2 = true;
    }
    //cuando las respuestas de nuestras acciones le bajan o suben el nivel de confianza
    void aplicarRespuesta(int respuesta) {
        //utilizando switch
        switch (respuesta) 
        {
      //para las 3 opciones
        case 1:
            PerderNivelConfianza(10);
            break;

        case 2:
            break;

        case 3:
            NivelConfianza += 15;

            if (NivelConfianza > 100)
                NivelConfianza = 100;

            break;
        }


    }

    void aplicarRespuesta2(int respuesta) {
        //utilizando switch
        switch (respuesta)
        {
            //para las 3 opciones
        case 1:
            PerderNivelConfianza(10);
            break;

        case 2:
            break;

        case 3:
            NivelConfianza += 15;

            if (NivelConfianza > 100)
                NivelConfianza = 100;

            break;
        }
    }

    int calcularPuntaje() {
        return metros() + getConfianza() * 10;
    }
   
};