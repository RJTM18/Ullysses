
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
};
