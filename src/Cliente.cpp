#include "Cliente.h"
using namespace std;

Cliente::Cliente (string nombre, string rut){
    this -> nombre = nombre;
    this -> rut = rut;
}
Cliente::~Cliente() {}

string Cliente::getNombre() const { return nombre; }
string Cliente::getRut() const { return rut; }
bool Cliente::getEsTerceraEdad() const { return terceraEdad; }
bool Cliente::getEsEmbarazada() const { return embarazada; }
bool Cliente::getEsDiscapacitado() const { return discapacitado; }
bool Cliente::getEsNormal() const { return normal; }

void Cliente::setTerceraEdad(bool terceraEdad) { this->terceraEdad = terceraEdad; }
void Cliente::setDiscapacitado(bool discapacitado) { this->discapacitado = discapacitado;}
void Cliente::setEmbarazada(bool embarazada) { this->embarazada = embarazada;}
void Cliente::setNormal(bool normal) { this->normal = normal;}