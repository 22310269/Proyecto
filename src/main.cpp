#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <Controlador.hpp>
#include <Escenario.hpp>
#include <curses.h>
#include <unistd.h>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    Ventana ventanaMenu;
    Ventana ventanaJuego;
    bool ejecucionJuego = true;

    Dibujo *logo = new Dibujo(68, 5, "paddle_logo");
    Dibujo *letras = new Dibujo(60, 20, "pong_letras");
    Dibujo *paletaJ1 = new Dibujo(6, 1, "paddle");
    Dibujo *paletaJ2 = new Dibujo(167, 1, "paddle");
    Dibujo *pelota = new Dibujo(80, 45, "pelota");

    list<Dibujo *> dibujosJuego;
    dibujosJuego.push_back(paletaJ1);
    dibujosJuego.push_back(paletaJ2);
    dibujosJuego.push_back(pelota);

    list<Dibujo *> dibujosMenu;
    dibujosMenu.push_back(logo);
    dibujosMenu.push_back(letras);

    list<Actualizable *> actualizables;
    Controlador *control = new Controlador(paletaJ1, paletaJ2, ejecucionJuego);
    actualizables.push_back(control);

    Escenario escenario(pelota, paletaJ1, paletaJ2);

    ventanaMenu.Dibujar(dibujosMenu);
    timeout(3000);

    while (ejecucionJuego)
    {
        ventanaJuego.Actualizar(actualizables);
       escenario.GestionarMovimientoPelota();
        ventanaJuego.Dibujar(dibujosJuego);
    }

    return 0;
}