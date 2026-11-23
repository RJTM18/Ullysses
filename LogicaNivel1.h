
#pragma once

class Logica1
{
private:
    int PuntosVida;
    int MetrosLogrados;
    int contadorMovimientos;

public:
    Logica1(int vida, int MetrosLogrados)
    {
        this->PuntosVida = vida;
        this->MetrosLogrados = MetrosLogrados;
        contadorMovimientos = 0;
    }

    int getPuntosVida()
    {
        return PuntosVida;
    }

    int getMetrosLogrados()
    {
        return MetrosLogrados;
    }

    void PerderPuntosVida()
    {
        if (PuntosVida > 0)
            PuntosVida--;
    }

    bool PerdioNivel()
    {
        return PuntosVida <= 0;
    }

    bool GanoNivel()
    {
        return MetrosLogrados >= 400;
    }
    //aumentar los metros mediantes int metros
    void sumarMetros(int metros)
    {
        MetrosLogrados += metros;
    }
    //mediante un bool derecha aumentar el contador y si el contador es >5 se suma esos metros  a 5 metros
    void actualizarMetros(bool derecha)
    {
        if (derecha)
        {
            contadorMovimientos++;

            if (contadorMovimientos >= 5)
            {
                sumarMetros(5);
                contadorMovimientos = 0;
            }
        }
    }
    // en donde funciona que no pueda salirse del mapa o la longitud de ella
    int colisionY(int y, int altoPersonaje)
    {
        //esto es para calculare los 2 limites
        int limiteSuperior = 380;
        int limiteInferior = 960;

        if (y < limiteSuperior)
        {
            y = limiteSuperior;
        }

        if (y + altoPersonaje > limiteInferior)
        {
            y = limiteInferior - altoPersonaje;
        }

        return y;
    }

    //Ahora sirve para que el personaje no sea capaz de irse de largo del mapa
    int colisionX(int x, int anchoPersonaje)
    {
        int limiteIzquierda = 380; 
        int limiteDerecha = 800;
   //estos son las condiciones para que se mantenga en su limite
        if (x < limiteIzquierda)
        {
            x = limiteIzquierda;
        }

        if (x + anchoPersonaje > limiteDerecha)
        {
            x = limiteDerecha - anchoPersonaje;
        }

        return x;
    }
};
