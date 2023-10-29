#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <curses.h>

using namespace std;

class Dibujo
{
private:
    int x;
    int y;
    fstream archivo;
    string recurso;

public:
    Dibujo(int x, int y, string recurso)
    {
        this->recurso = recurso;
        archivo.open("./data/" + this->recurso + ".txt");
        this->x = x;
        this->y = y;
    }

    Dibujo(string recurso)
    {
        Dibujo(0, 0, recurso);
    }

    void Mover(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void SubirY(int y)
    {
        this->y -= y;
    }

    void BajarY(int y)
    {
        this->y += y;
    }

    int ObtenerX() const
    {
        return x;
    }

    int ObtenerY() const
    {
        return y;
    }

    bool ColisionaConPaleta(Dibujo *paleta) const
    {
        int xPelota = ObtenerX();
        int yPelota = ObtenerY();
        int xPaleta = paleta->ObtenerX();
        int yPaleta = paleta->ObtenerY();

        int anchoPelota = 2;
        int altoPelota = 2;
        int anchoPaleta = 2;
        int altoPaleta = 5;

        bool colisionX = (xPelota + anchoPelota > xPaleta) && (xPelota < xPaleta + anchoPaleta);

        bool colisionY = (yPelota + altoPelota > yPaleta) && (yPelota < yPaleta + altoPaleta);

        return colisionX && colisionY;
    }

    bool ColisionaConParedSuperior() const
    {
        int yPelota = ObtenerY();

        int posicionParedSuperior = 0;

        return yPelota < posicionParedSuperior;
    }

    bool ColisionaConParedInferior() const
    {
        int yPelota = ObtenerY();

        int alturaPantalla = 25;

        return yPelota >= alturaPantalla;
    }

    bool FueraDePantalla() const
    {
        int xPelota = ObtenerX();
        int yPelota = ObtenerY();

        int anchoPantalla = 207;

        return xPelota < 0 || xPelota >= anchoPantalla;
    }

    void Dibujar()
    {

        string linea;
        move(this->y, this->x);

        while (getline(archivo, linea))
        {
            int y_linea = getcury(stdscr);
            mvaddstr(
                y_linea + 1,
                this->x,
                linea.c_str());
        }

        archivo.clear();
        archivo.seekg(0);
    }

    void Limpiar()
    {
        string linea;
        move(this->y, this->x);

        while (getline(archivo, linea))
        {
            int y_linea = getcury(stdscr);
            mvaddstr(
                y_linea + 1,
                this->x,
                " ");
        }

        archivo.clear();
        archivo.seekg(0);
    }

    ~Dibujo()
    {
        archivo.close();
    }
};