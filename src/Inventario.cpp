#include "Inventario.h"
#include <iostream>
#include <fstream>
#include <sstream>

CategoriaNodo::CategoriaNodo(const string& categoria) 
    : categoria(categoria), subcategorias(new HashMap()), siguiente(nullptr) {}

CategoriaNodo::~CategoriaNodo() {
    delete subcategorias;
}

Inventario::Inventario() : cabeza(nullptr) {}   

Inventario::~Inventario() {
    CategoriaNodo* actual = cabeza;
    while (actual != nullptr) {
        CategoriaNodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

std::string Inventario::obtenerProximoId() {
    int maxId = 0;
    CategoriaNodo* actual = cabeza;
    while (actual != nullptr) {
        ListaEnlazada* productos = actual->subcategorias->obtenerTodosLosProductos();
        Nodo* nodo = productos->obtenerCabeza();
        while (nodo != nullptr) {
            int id = std::stoi(nodo->producto->getId());
            maxId = std::max(maxId, id);
            nodo = nodo->siguiente;
        }
        delete productos; // Liberar la memoria después de usarla
        actual = actual->siguiente;
    }
    return std::to_string(maxId + 1);
}

void Inventario::agregarProducto(Producto* producto) {
    if (producto->getId().empty()) {
        producto->setId(obtenerProximoId());
    }
    std::string categoria = producto->getCategoria();
    CategoriaNodo* actual = cabeza;
    CategoriaNodo* previo = nullptr;

    while (actual != nullptr && actual->categoria != categoria) {
        previo = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        actual = new CategoriaNodo(categoria);
        if (previo == nullptr) {
            cabeza = actual;
        } else {
            previo->siguiente = actual;
        }
    }
    actual->subcategorias->insert(producto);
}

Producto* Inventario::buscarProducto(const string& id) {
    CategoriaNodo* actual = cabeza;
    while (actual != nullptr) {
        Producto* producto = actual->subcategorias->search(id);
        if (producto != nullptr) {
            return producto;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void Inventario::mostrarInventario() {
    CategoriaNodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "Categoria: " << actual->categoria << endl;
        actual->subcategorias->display();
        actual = actual->siguiente;
    }
}

void Inventario::cargarProductosDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo : " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string id, categoria, subcategoria, nombre, precio, cantidad;
        getline(ss, id, ',');
        getline(ss, categoria, ',');
        getline(ss, subcategoria, ',');
        getline(ss, nombre, ',');
        getline(ss, precio, ',');
        getline(ss, cantidad, ',');

        // Convertir el precio y la cantidad a tipos numéricos
        double precioNum = stod(precio);
        int cantidadNum = stoi(cantidad);

        // Crear un nuevo producto y agregarlo al inventario
        Producto* producto = new Producto(id, categoria, subcategoria, nombre, precioNum, cantidadNum);
        agregarProducto(producto);
    }

    archivo.close();
}

void Inventario::actualizarArchivo(const string& nombreArchivo, Producto* productoModificado) {
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    ofstream archivoSalida("C:/Users/tapia/Downloads/C++/Taller_2_cpp/data/temp.txt"); // Archivo temporal para escribir los datos actualizados
    if (!archivoSalida.is_open()) {
        cerr << "No se pudo abrir el archivo temporal." << endl;
        archivoEntrada.close();
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        istringstream ss(linea);
        string id, categoria, subcategoria, nombre, precio, cantidad;
        getline(ss, id, ',');
        getline(ss, categoria, ',');
        getline(ss, subcategoria, ',');
        getline(ss, nombre, ',');
        getline(ss, precio, ',');
        getline(ss, cantidad, ',');

        // Si el ID del producto coincide con el que estamos buscando, actualizamos la cantidad
        if (id == productoModificado->getId()) {
            int nuevaCantidad = productoModificado->getCantidad();
            archivoSalida << id << ',' << categoria << ',' << subcategoria << ',' << nombre << ',' << precio << ',' << nuevaCantidad << endl;
        } else {
            archivoSalida << linea << endl;
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    // Reemplazar el archivo original con el archivo temporal
    if (rename("C:/Users/tapia/Downloads/C++/Taller_2_cpp/data/temp.txt", nombreArchivo.c_str()) != 0) {
        cerr << "Error al reemplazar el archivo." << endl;
    }
}

void Inventario::guardarProductoEnArchivo(const string& nombreArchivo, Producto* producto) {
    ofstream archivo(nombreArchivo, ios::app); // Abre el archivo en modo append
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    archivo << producto->getId() << ","
            << producto->getCategoria() << ","
            << producto->getSubCategoria() << ","
            << producto->getNombre() << ","
            << producto->getPrecio() << ","
            << producto->getCantidad() << endl;

    archivo.close();
}