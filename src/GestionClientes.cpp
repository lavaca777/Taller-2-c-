#include "GestionClientes.h"
#include <iostream>
#include <fstream>
#include <sstream>

GestionClientes::~GestionClientes() {

    while (!terceraEdad.empty()) {
        delete terceraEdad.front();
        terceraEdad.pop();
    }
    while (!discapacitados.empty()) {
        delete discapacitados.front();
        discapacitados.pop();
    }
    while (!embarazadas.empty()) {
        delete embarazadas.front();
        embarazadas.pop();
    }
    while (!normales.empty()) {
        delete normales.front();
        normales.pop();
    }
}

void GestionClientes::agregarCliente(Cliente* cliente) {

    if (cliente->getEsTerceraEdad()) {
        terceraEdad.push(cliente);
        
    } else if (cliente->getEsDiscapacitado()) {
        discapacitados.push(cliente);

    } else if (cliente->getEsEmbarazada()) {
        embarazadas.push(cliente);

    } else if (cliente->getEsNormal()) {
        normales.push(cliente);
    }
}

Cliente* GestionClientes::siguienteCliente() {

    if (!terceraEdad.empty()) {
        Cliente* cliente = terceraEdad.front();
        terceraEdad.pop();
        return cliente;

    } else if (!discapacitados.empty()) {
        Cliente* cliente = discapacitados.front();
        discapacitados.pop();
        return cliente;

    } else if (!embarazadas.empty()) {
        Cliente* cliente = embarazadas.front();
        embarazadas.pop();
        return cliente;

    } else if (!normales.empty()) {
        Cliente* cliente = normales.front();
        normales.pop();
        return cliente;
    }
    return nullptr;
}

bool GestionClientes::hayClientes() {
    return !terceraEdad.empty() || !discapacitados.empty() || !embarazadas.empty() || !normales.empty();
}

void GestionClientes::guardarClientesEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    auto guardarCola = [&archivo](queue<Cliente*>& cola, const string& tipo) {
        queue<Cliente*> temp = cola;

        while (!temp.empty()) {
            Cliente* cliente = temp.front();
            archivo << cliente->getNombre() << "," << tipo << endl;
            temp.pop();
        }
    };

    guardarCola(terceraEdad, "TerceraEdad");
    guardarCola(discapacitados, "Discapacitado");
    guardarCola(embarazadas, "Embarazada");
    guardarCola(normales, "Normal");

    archivo.close();
}

void GestionClientes::cargarClientesDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        string nombre, tipo;
        getline(ss, nombre, ',');
        getline(ss, tipo, ',');

        Cliente* cliente = new Cliente(nombre);
        if (tipo == "TerceraEdad") {
            cliente->setTerceraEdad(true);
            agregarCliente(cliente);
        } else if (tipo == "Discapacitado") {
            cliente->setDiscapacitado(true);
            agregarCliente(cliente);
        } else if (tipo == "Embarazada") {
            cliente->setEmbarazada(true);
            agregarCliente(cliente);
        }
        else{ cliente->setNormal(true); agregarCliente(cliente);}  
    }
    archivo.close();
}