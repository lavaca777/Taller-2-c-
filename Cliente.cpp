#include "Cliente.h"
using namespace std;

Cliente::Cliente (string nombre, bool esTerceraEdad, bool esEmbarazada, bool esDiscapacitado, bool esNormal){
    this -> nombre = nombre;
    this -> esTerceraEdad = esTerceraEdad;
    this -> esEmbarazada = esEmbarazada;
    this -> esDiscapacitado = esDiscapacitado;
    this -> esNormal = esNormal;
}
Cliente::~Cliente() {}

string Cliente::getNombre() const { return nombre; }
bool Cliente::getEsTerceraEdad() const { return esTerceraEdad; }
bool Cliente::getEsEmbarazada() const { return esEmbarazada; }
bool Cliente::getEsDiscapacitado() const { return esDiscapacitado; }
bool Cliente::getEsNormal() const { return esNormal; }