#pragma once

class Actualizable
{
private:
public:
    Actualizable() {}
    virtual void Actualizar() = 0;
    ~Actualizable();
};
