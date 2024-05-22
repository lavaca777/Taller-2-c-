#pragma once
#include <string>
using namespace std;

class Cliente{
    private:
        string nombre;
        bool esTerceraEdad;
        bool esEmbarazada;
        bool esDiscapacitado;
        bool esNormal;
    public:

        Cliente(string nombre, bool esTerceraEdad, bool esEmbarazada, bool esDiscapacitado, bool esNormal);
        ~Cliente();

        string getNombre() const;
        bool getEsTerceraEdad() const;
        bool getEsEmbarazada() const;
        bool getEsDiscapacitado() const;
        bool getEsNormal() const;
};