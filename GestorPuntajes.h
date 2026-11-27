#pragma once
#include <fstream>
#include <vector>
#include "Puntuacion.h"
using namespace std;
//creamos la clase la guardar las puntuaciones
class GestorPuntajes {
private:
    Puntuacion* puntuacion;

public:
    GestorPuntajes() {}

    bool guardarPuntaje(int puntaje) {
        //abrir el archivo de las puntuaciones
        ofstream archivo("FILES/SCORES.bin",
            ios::binary | ios::app);
        //esto es si el archivo no esta abierto devuelve falso
        if (!archivo.is_open())
            return false;

        archivo.write((char*)&puntaje, sizeof(int));
        return archivo.good();
    }
    //un vector para almacenar mas puntajes
    vector<int> leerPuntajes() {
        vector<int> puntajes;

        ifstream archivo("FILES/SCORES.bin", ios::binary);

        int puntaje;

        while (archivo.read((char*)&puntaje, sizeof(int))) {
            puntajes.push_back(puntaje);
        }

        return puntajes;
    }
};