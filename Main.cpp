#include <iostream>
#include "Inventario.h"
#include "GestionClientes.h"
#include "GestionVentas.h"
#include "Cliente.h"

using namespace std;

void generarBoleta( Inventario* inventario, ListaEnlazada* productosComprados) {
    cout << "\n-- Boleta de Compra --" << endl;

    cout << "\nDetalles de la Compra" << endl;
    double total = 0.0;
    Nodo* actual = productosComprados->obtenerCabeza();
    while (actual != nullptr) {
        Producto* producto = actual->producto;
        cout << "Nombre: " << producto->getNombre() << ", Precio: " << producto->getPrecio() << endl;
        total += producto->getPrecio();
        actual = actual->siguiente;
    }

    cout << "\nTotal a Pagar: " << total << endl;
    cout << "Gracias por su compra! " << endl;
    for (Nodo* actual = productosComprados->obtenerCabeza(); actual != nullptr; actual = actual->siguiente) {
        inventario->actualizarArchivo("productos.txt", actual->producto);
    }
    delete productosComprados;

}

void Menu(GestionClientes* gestionClientes, Inventario* inv){
    int opcion;
    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Ingresar cliente a la cola" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Agregar producto a bodega" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:{
            int prioridad;
            string nombre;
            bool esTerceraEdad = false, esEmbarazada = false, esDiscapacitado = false, esNormal = false;
            cout << "Nombre: " << endl;
            cin >> nombre;
            
            cout << "Elija la opcion mas prioritaria, siendo 1 la mas prioritaria y 4 la menos" << endl;
            cout << "1. Es tercera edad" << endl;
            cout << "2. Es embarazada" << endl;
            cout << "3. Es discapacitado" << endl;
            cout << "4. Es normal" << endl;
            cout << "Seleccione una opcion: ";
            cin >> prioridad;
            
            switch (prioridad)
            {
            case 1: esTerceraEdad = true;
                break;
            case 2: esEmbarazada = true;
                break;
            case 3: esDiscapacitado = true;
                break;
            case 4: esNormal = true;
                break;
            
            default: cout << "\ningreso una opcion no valida" << endl;
                break;
            }

            Cliente* cliente = new Cliente(nombre, esTerceraEdad, esEmbarazada, esDiscapacitado, esNormal);
            gestionClientes->agregarCliente(cliente);
            break;

        }
            break;

        case 2:{
            if (!gestionClientes->hayClientes()){ cout << "\nNo hay clientes en la fila " << endl; break;}
            
            ListaEnlazada productosC;
            Cliente* cliente = gestionClientes->siguienteCliente();
            int cantP = 0; //cantidad de productos a comprar
            cout << "Se llama a " << cliente->getNombre() << endl;
            cout << "Numero de Productos a comprar: " << endl;
            cin >> cantP; //cantidad de productos

            inv->mostrarInventario();

            for (int i = 0; i < cantP;i ++){
                string idProducto;
                int cant;

                cout << "Ingrese el id del producto: " << endl;
                cin >> idProducto;
                cout << "Cantidad: " << endl;
                cin >> cant;

                Producto* producto = inv->buscarProducto(idProducto);
                if (producto == nullptr) {cout << "Producto no encontrado" << endl; continue;}
                if (producto->getCantidad() < cant) {cout << "No hay stock suficiente para la cantidad pedida" << endl; continue;}

                for (int j = 0; i < cant; i++){
                    productosC.insertar(producto);
                }

                producto->restarCantidad(cant);
                
                
            }
            generarBoleta(inv, &productosC);

        }
            break;

        case 3:{

            string id, categoria, subcategoria, nombre;
            double precio;
            int cantidad;
            cout << "ID: ";
            cin >> id;
            cout << "Categoria: ";
            cin >> categoria;
            cout << "Subcategoria: ";
            cin >> subcategoria;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Precio: ";
            cin >> precio;
            cout << "Cantidad: ";
            cin >> cantidad;
            Producto* producto = new Producto(id, categoria, subcategoria, nombre, precio, cantidad);
            inv->agregarProducto(producto);
            break;

        }
            break;

        case 4: cout << "\nSaliendo del sistema...." << endl;
            break;
        
        default: cout << "\nOpcion no valida." << endl;
            break;
        }

    } while (opcion != 4);
}

int main() {
    GestionClientes gestionClientes;
    Inventario inv;
    inv.cargarProductosDesdeArchivo("C:/Users/tapia/Downloads/C++/0) taller 2/data/productos.txt");
    Menu(&gestionClientes, &inv);

}