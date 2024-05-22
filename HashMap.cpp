#include "HashMap.h"

HashMap::HashMap() {}

int HashMap::hashFunction(const string& key) const {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % TABLE_SIZE;
    }
    return hash;
}

void HashMap::insert(Producto* producto) {
    int hash = hashFunction(producto->getId());
    table[hash].insertar(producto);
}

Producto* HashMap::search(const string& key) {
    int hash = hashFunction(key);
    return table[hash].buscar(key);
}

void HashMap::remove(const string& key) {
    int hash = hashFunction(key);
    table[hash].eliminar(key);
}

void HashMap::display() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i].mostrar();
    }
}

Nodo* HashMap::obtenerTodosLosProductos() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Nodo* nodo = table[i].obtenerCabeza();
        if (nodo != nullptr) {
            return nodo;
        }
    }
    return nullptr;
}
