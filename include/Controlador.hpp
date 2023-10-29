#pragma once
#include <Actualizable.hpp>
#include <curses.h>

class Controlador : public Actualizable
{
private:
    Dibujo *paletaJ1;
    Dibujo *paletaJ2;
    bool &ejecucion;

public:
    Controlador(Dibujo *jugador1, Dibujo *jugador2, bool &ejec) : paletaJ1(jugador1), paletaJ2(jugador2), ejecucion(ejec)
    {
    }
    ~Controlador();

    void Actualizar()
    {
        int tecla = getch();

        if (tecla == 'q')
        {
            ejecucion = false;
        }

        else if (tecla == 'w')
        {
            paletaJ1->SubirY(1);
        }

        else if (tecla == 's')
        {
            paletaJ1->BajarY(1);
        }

        else if (tecla == 'i')
        {
            paletaJ2->SubirY(1);
        }

        else if (tecla == 'k')
        {
            paletaJ2->BajarY(1);
        }
    }
};
