#pragma once
#include <Dibujo.hpp>

using namespace std;

class Escenario
{
private:
    Dibujo *pelota;
    Dibujo *paletaJ1;
    Dibujo *paletaJ2;

    int velocidadPelotaX;
    int velocidadPelotaY;

public:
    Escenario(Dibujo *pelota, Dibujo *paletaJ1, Dibujo *paletaJ2)
        : pelota(pelota), paletaJ1(paletaJ1), paletaJ2(paletaJ2)
    {
        velocidadPelotaX = 1; 
        velocidadPelotaY = 1; 
    }

    void GestionarMovimientoPelota()
    {
        pelota->Mover(pelota->ObtenerX() + velocidadPelotaX, pelota->ObtenerY() + velocidadPelotaY);

        if (pelota->ColisionaConPaleta(paletaJ1) || pelota->ColisionaConPaleta(paletaJ2))
        {
            velocidadPelotaX *= -1; 
        }

        if (pelota->ColisionaConParedSuperior() || pelota->ColisionaConParedInferior())
        {
            velocidadPelotaY *= -1; 
        }

        if (pelota->FueraDePantalla())
        {
            // Determinar qué jugador anotó un punto y restablecer la posición de la pelota para el próximo saque
            // Actualizar los marcadores de puntos de los jugadores
        }
    }
};
