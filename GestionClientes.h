#pragma once

#include "Cliente.h"
#include <queue>

class GestionClientes {
private:
    queue<Cliente*> terceraEdad;
    queue<Cliente*> discapacitados;
    queue<Cliente*> embarazadas;
    queue<Cliente*> normales;

public:
    ~GestionClientes();
    
    void agregarCliente(Cliente* cliente);
    Cliente* siguienteCliente();
    bool hayClientes();
};