
#pragma once

class Logica1
{
private:
    int vida;
    int MetrosLogrados;
    int contadorMovimientos;

public:
    Logica1(int vida, int MetrosLogrados)
    {
        this->vida = vida;
        this->MetrosLogrados = MetrosLogrados;
        contadorMovimientos = 0;
    }

    int getVida()
    {
        return vida;
    }

    int getMetrosLogrados()
    {
        return MetrosLogrados;
    }

    void perderVida()
    {
        if (vida > 0)
            vida--;
    }

    bool perdio()
    {
        return vida <= 0;
    }

    bool gano()
    {
        return MetrosLogrados >= 400;
    }

    void sumarMetros(int metros)
    {
        MetrosLogrados += metros;
    }

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
