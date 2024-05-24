#pragma once
#include "Nodo.h"
#include <iostream>

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada();
    void insertar(Producto* producto);
    Producto* buscar(const string& id);
    void eliminar(const string& id);
    void mostrar() const;
    Nodo* obtenerCabeza() const;
};
