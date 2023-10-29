#pragma once
#include <Dibujo.hpp>
#include <curses.h>

class Marco : public Dibujo
{
private:
public:
    Marco(){}
    ~Marco();
    void Dibujar()
    {
        box(stdscr, '#', '#');
    }
};
