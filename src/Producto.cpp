#include "Producto.h"
using namespace std;

Producto::Producto (string id, string categoria, string subCategoria, string nombre, double precio, int cantidad){

    this -> id = id;
    this -> categoria = categoria;
    this -> subCategoria = subCategoria;
    this -> nombre = nombre;
    this -> precio = precio;
    this -> cantidad = cantidad;

} 

//geters
string Producto::getId()const{return id;}
string Producto::getCategoria()const{return categoria;}
string Producto::getSubCategoria()const{return subCategoria;}
string Producto::getNombre()const{return nombre;}
double Producto::getPrecio()const{return precio;}
int Producto::getCantidad()const{return cantidad;}

void Producto::setId(const string& id) {this->id = id; }

void Producto::restarCantidad(int cant){cantidad = cantidad - cant;}
void Producto::agregarCantidad(int cant){cantidad = cantidad + cant;}