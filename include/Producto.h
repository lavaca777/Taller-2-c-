#pragma once
#include <string>
using namespace std;

class Producto{
    private:
        string id;
        string categoria;
        string subCategoria;
        string nombre;
        double precio;
        int cantidad;

    public:
        Producto(string id, string categoria, string subCategoria, string nombre, double precio, int cantidad);

            string getId() const;
            void setId(const std::string& id);
            string getCategoria() const;
            string getSubCategoria() const;
            string getNombre() const;
            double getPrecio() const;
            int getCantidad() const;

            void restarCantidad(int cant);
            void agregarCantidad(int cant);
};