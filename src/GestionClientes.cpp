#include "GestionClientes.h"

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
}

bool GestionClientes::hayClientes() {
    return !terceraEdad.empty() || !discapacitados.empty() || !embarazadas.empty() || !normales.empty();
}
