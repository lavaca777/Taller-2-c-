#pragma once
#include <string>
using namespace std;

class Cliente{
    private:
        string nombre;
        bool terceraEdad = false;
        bool discapacitado = false;
        bool embarazada = false;
        bool normal = false;
    public:

        Cliente(string nombre);
        ~Cliente();

        string getNombre() const;

        bool getEsTerceraEdad() const;
        void setTerceraEdad(bool terceraEdad);
        
        bool getEsDiscapacitado() const;
        void setDiscapacitado(bool discapacitado);
        
        bool getEsEmbarazada() const;
        void setEmbarazada(bool embarazada);

        bool getEsNormal() const;
        void setNormal(bool normal);
        
        string getTipo() const;
};