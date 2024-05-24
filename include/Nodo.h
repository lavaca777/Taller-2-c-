#pragma once
#include "Producto.h"

class Nodo {
public:
    Producto* producto;
    Nodo* siguiente;

    Nodo(Producto* producto);
};
