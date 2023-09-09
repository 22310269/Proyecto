#include <iostream>
#include <Mascota.hpp>
#include <Jugador.hpp>
#include <Campo.hpp>
#include <Paleta.hpp>
#include <Pelota.hpp>
#include <Puntaje.hpp>

int main(int argc, char const *argv[])
{
    std::cout << "Juego de mascotas" << std::endl;

    Mascota m1("Firulais");
    m1.Jugar();
    m1.Jugar();
    m1.Jugar();

    std::cout << m1.DecirNombre() << " tiene " << m1.DecirHambre() << " de hambre." << std::endl;

    m1.Comer(5);

    return 0;
}