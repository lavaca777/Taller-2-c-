#include <iostream>
#include "Inventario.h"
#include "GestionClientes.h"
#include "Cliente.h"

using namespace std;

void Menu(GestionClientes* gestionClientes, Inventario* inv, string* archProductos);
void generarBoleta( Inventario* inventario, ListaEnlazada* productosComprados, string* archProductos);

int main() {
    GestionClientes gestionClientes;
    Inventario inv;
    string archProductos = "data/Productos.txt";
    string archClientes = "data/Clientes.txt";

    gestionClientes.cargarClientesDesdeArchivo(archClientes);
    inv.cargarProductosDesdeArchivo(archProductos);
    Menu(&gestionClientes, &inv, &archProductos);

}

void generarBoleta( Inventario* inventario, ListaEnlazada* productosComprados, string* archProductos) {
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
        inventario->actualizarArchivo(*archProductos, actual->producto);
    }
    
}

void Menu(GestionClientes* gestionClientes, Inventario* inv, string* archProductos){
    int opcion;
    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Ingresar cliente a la cola" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Agregar producto a bodega" << endl;
        cout << "4. Aumentar Stock" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:{
            int prioridad;
            string nombre;
            string rut;

            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "RUT: ";
            cin >> rut;

            Cliente* cliente = new Cliente(nombre, rut);
            
            cout << "\nElija la opcion mas prioritaria, siendo 1 la mas prioritaria y 4 la menos prioritaria" << endl;
            cout << "1. Es tercera edad" << endl;
            cout << "2. Es discapacitado" << endl;
            cout << "3. Es embarazada" << endl;
            cout << "4. Es normal" << endl;
            cout << "Seleccione una opcion: ";
            cin >> prioridad;
            
            switch (prioridad)
            {
            case 1: cliente->setTerceraEdad(true);
                break;
            case 2: cliente->setDiscapacitado(true);
                break;
            case 3: cliente->setEmbarazada(true);
                break;
            case 4: cliente->setNormal(true);
                break;
            
            default: cout << "\ningreso una opcion no valida" << endl;
                break;
            }

            gestionClientes->agregarCliente(cliente);
            break;
        }

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

                for (int j = 0; j < cant; j++){
                    productosC.insertar(producto);
                }

                producto->restarCantidad(cant);
                     
            }
            generarBoleta(inv, &productosC, archProductos);
            delete cliente;
            break;
        }
            
        case 3:{

            string categoria, subcategoria, nombre;
            double precio;
            int cantidad;

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
            
            Producto* producto = new Producto("", categoria, subcategoria, nombre, precio, cantidad);
            inv->agregarProducto(producto);
            inv->guardarProductoEnArchivo(*archProductos, producto);
            break;

        }

        case 4:{
            
            string id;
            int unidades;

            inv->mostrarInventario();

            cout << "ingrese el id del producto: " << endl;
            cin >> id;

            Producto* producto = inv->buscarProducto(id);
            if (producto == nullptr){ cout << "no se encontro el producto" << endl; continue;}

            cout << "Unidades a reponer: " << endl;
            cin >> unidades;

            producto->agregarCantidad(unidades);
            inv->actualizarArchivo(*archProductos, producto);
            break;
        }
            
        case 5: {
            gestionClientes->guardarClientesEnArchivo("data/Clientes.txt");
            cout << "\nSaliendo del sistema...." << endl;
            break;
        }

        default: 
            cout << "\nOpcion no valida." << endl;
            break;
        }

    } while (opcion != 5);
}