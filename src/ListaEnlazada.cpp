#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

void ListaEnlazada::insertar(Producto* producto) {
    Nodo* nuevoNodo = new Nodo(producto);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

Producto* ListaEnlazada::buscar(const string& id) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->producto->getId() == id) {
            return actual->producto;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaEnlazada::eliminar(const string& id) {
    Nodo* actual = cabeza;
    Nodo* previo = nullptr;

    while (actual != nullptr && actual->producto->getId() != id) {
        previo = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) return;

    if (previo == nullptr) {
        cabeza = actual->siguiente;
    } else {
        previo->siguiente = actual->siguiente;
    }
    delete actual;
}

void ListaEnlazada::mostrar() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "ID: " << actual->producto->getId()
                  << ", Nombre: " << actual->producto->getNombre()
                  << ", Categoria: " << actual->producto->getCategoria()
                  << ", Subcategoria: " << actual->producto->getSubCategoria()
                  << ", Precio: " << actual->producto->getPrecio()
                  << ", Cantidad: " << actual->producto->getCantidad() << endl;
        actual = actual->siguiente;
    }
}

Nodo* ListaEnlazada::obtenerCabeza() const {
    return cabeza;
}
