#pragma once
#include "ListaEnlazada.h"
#include <string>

class HashMap {
private:
    static const int TABLE_SIZE = 10;
    ListaEnlazada table[TABLE_SIZE];

    int hashFunction(const string& key) const;

public:
    HashMap();
    void insert(Producto* producto);
    Producto* search(const string& key);
    void remove(const string& key);
    void display() const;
    Nodo* obtenerTodosLosProductos() const;

};
