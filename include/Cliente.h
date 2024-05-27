#pragma once
#include <string>
using namespace std;

class Cliente{
    private:
        string nombre;
        string rut;
        bool terceraEdad = false;
        bool discapacitado = false;
        bool embarazada = false;
        bool normal = false;
    public:

        Cliente(string nombre, string rut);
        ~Cliente();

        string getNombre() const;
        string getRut() const;

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