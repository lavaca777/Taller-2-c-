#pragma once
#include "HashMap.h"
#include <string>

class CategoriaNodo {
public:
    string categoria;
    HashMap* subcategorias;
    CategoriaNodo* siguiente;

    CategoriaNodo(const string& categoria);
    ~CategoriaNodo();
};

class Inventario {
private:
    CategoriaNodo* cabeza;

public:
    Inventario();
    ~Inventario();
    void agregarProducto(Producto* producto);
    Producto* buscarProducto(const string& id);
    void mostrarInventario();
    int contarSubcategorias(const string& categoria);
    void cargarProductosDesdeArchivo(const string& nombreArchivo);
    void actualizarArchivo(const string& nombreArchivo, Producto* productoModificado);
    void guardarProductoEnArchivo(const std::string& nombreArchivo, Producto* producto);
};
