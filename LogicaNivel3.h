#pragma once
#include "Molly.h"
#include "Boylan.h"
#include "PistaNivel3.h"

class LogicaNivel3 {
    Molly* molly;
    Boylan* boylan;
    PistaNivel3* pistas[3];
    int recuerdos, decisionesSi, tiempoTicks, calma;
    int proteccion, vozEspera, vozEfecto, boylanQuieto, usosVoz;
    int retoActivo, paso;
    bool victoria, derrota;

public:
    LogicaNivel3(int anchoMolly, int altoMolly, int anchoBoylan, int altoBoylan) {
        molly = new Molly(100, 490, anchoMolly, altoMolly);
        boylan = new Boylan(760, 320, anchoBoylan, altoBoylan);
        pistas[0] = new PistaNivel3(0, 245, 355);
        pistas[1] = new PistaNivel3(1, 535, 385);
        pistas[2] = new PistaNivel3(2, 845, 455);
        recuerdos = decisionesSi = 0;
        tiempoTicks = 4000; // 120 segundos
        calma = 3;
        proteccion = vozEspera = vozEfecto = boylanQuieto = 0;
        usosVoz = 2;
        retoActivo = -1;
        paso = 0;
        victoria = derrota = false;
    }
    ~LogicaNivel3() {
        delete molly; delete boylan;
        for (int i = 0; i < 3; i++) delete pistas[i];
    }
    void actualizar(Direccion tecla) {
        if (victoria || derrota || retoActivo >= 0) return;
        molly->mover(tecla, 1000, 640);
        if (proteccion > 0) proteccion--;
        if (vozEspera > 0) vozEspera--;
        if (vozEfecto > 0) vozEfecto--;
        if (boylanQuieto > 0) boylanQuieto--;
        if (boylanQuieto == 0) {
            if (recuerdos == 0) boylan->mover(Ninguno, 1000, 640);
            else boylan->perseguir(molly->getX(), molly->getY());
        }
        tiempoTicks--;
        if (tiempoTicks <= 0) { derrota = true; return; }

        if (recuerdos > 0 && proteccion == 0 &&
            molly->getRectangle().IntersectsWith(boylan->getRectangle())) {
            perderCalma();
            if (derrota) return;
            proteccion = 75;
            boylan->alejarse();
        }
        if (recuerdos == 3) {
            Rectangle puerta(45, 320, 95, 250);
            if (molly->getRectangle().IntersectsWith(puerta)) {
                victoria = true;
                return;
            }
        }
        if (retoActivo < 0) {
            for (int i = 0; i < 3; i++) {
                if (pistas[i]->estaRecogida()) continue;
                Rectangle zona = pistas[i]->getRectangle();
                zona.Inflate(10, 10);
                if (molly->getRectangle().IntersectsWith(zona)) {
                    retoActivo = i;
                    paso = 0;
                    return;
                }
            }
        }
    }
    void perderCalma() {
        calma--;
        if (calma <= 0) derrota = true;
    }
    // Una secuencia distinta para cada recuerdo.
    Direccion teclaEsperada(int numero) {
        const Direccion secuencias[3][4] = {
            { Arriba, Derecha, Abajo, Izquierda },
            { Izquierda, Arriba, Derecha, Abajo },
            { Derecha, Abajo, Izquierda, Arriba }
        };
        return secuencias[retoActivo][numero];
    }
    // 1: acierto parcial, 2: recuerdo completo, -1: error, -2: derrota.
    int probarTecla(Direccion tecla) {
        if (retoActivo < 0 || tecla == Ninguno) return 0;
        if (tecla != teclaEsperada(paso)) {
            perderCalma();
            paso = 0;
            return derrota ? -2 : -1;
        }
        paso++;
        if (paso < 4) return 1;
        pistas[retoActivo]->recoger();
        recuerdos++;
        retoActivo = -1;
        paso = 0;
        return 2;
    }
    bool usarVoz() {
        if (recuerdos == 0 || retoActivo >= 0 || vozEspera > 0 ||
            usosVoz == 0 || victoria || derrota)
            return false;
        boylan->alejarse();
        boylanQuieto = 65;
        vozEfecto = 24;
        vozEspera = 210;
        usosVoz--;
        return true;
    }
    void registrarDecision(bool respuestaSi) {
        if (respuestaSi) decisionesSi++;
    }
    void dibujar(Graphics^ g, Bitmap^ imagenMolly, Bitmap^ imagenBoylan,
                 Bitmap^ imagenPistas) {
        for (int i = 0; i < 3; i++) pistas[i]->dibujar(g, imagenPistas);
        boylan->dibujar(g, imagenBoylan);
        molly->dibujar(g, imagenMolly);
        if (vozEfecto > 0) {
            int x = molly->getX(), y = molly->getY();
            g->DrawEllipse(Pens::Gold, x - 26, y - 26, 140, 140);
        }
        if (recuerdos == 3) {
            g->DrawRectangle(Pens::Gold, 45, 320, 95, 250);
        }
    }
    int getRecuerdos() { return recuerdos; }
    int getTiempo() { return (tiempoTicks * 30 + 999) / 1000; }
    int getCalma() { return calma; }
    int getVozEspera() { return (vozEspera * 30 + 999) / 1000; }
    int getUsosVoz() { return usosVoz; }
    int getDecisionesSi() { return decisionesSi; }
    int getRetoActivo() { return retoActivo; }
    int getPaso() { return paso; }
    bool gano() { return victoria; }
    bool perdio() { return derrota; }
};
