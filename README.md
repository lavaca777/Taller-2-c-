# Sistema de Gestión de Inventario y Clientes para Farmacias

## Descripción

Este proyecto implementa un sistema de gestión de inventario y clientes para una farmacia. Permite gestionar productos en el inventario, atender clientes y generar boletas de compra. Está desarrollado en C++ y utiliza estructuras de datos como listas enlazadas y tablas hash para el almacenamiento y gestión de datos.

## Características

- **Gestión de Clientes**: Permite agregar clientes con diferentes niveles de prioridad (tercera edad, discapacitados, embarazadas, normales) y atenderlos en orden de prioridad.
- **Gestión de Inventario**: Permite agregar productos al inventario, aumentar el stock de productos existentes y buscar productos por ID.
- **Generación de Boletas**: Genera una boleta de compra detallada para los clientes atendidos y actualiza el inventario en un archivo de texto.

## Archivos

### Código Fuente

- `main.cpp`: Contiene la función principal del programa y el menú interactivo para gestionar el sistema.
- `Inventario.h` y `Inventario.cpp`: Declaración e implementación de la clase `Inventario`, que gestiona los productos.
- `ListaEnlazada.h` y `ListaEnlazada.cpp`: Declaración e implementación de la clase `ListaEnlazada` para gestionar listas enlazadas de productos.
- `HashMap.h` y `HashMap.cpp`: Declaración e implementación de la clase `HashMap` para la gestión de productos mediante tablas hash.
- `GestionClientes.h` y `GestionClientes.cpp`: Declaración e implementación de la clase `GestionClientes` para gestionar la cola de clientes.
- `Cliente.h` y `Cliente.cpp`: Declaración e implementación de la clase `Cliente`, que representa a un cliente.

### Archivos de Datos

- `clientes.txt`: Archivo de texto que almacena la información de los clientes.
- `productos.txt`: Archivo de texto que almacena la información de los productos en el inventario.

### Archivos de Ejemplo

#### `clientes.txt`

- pedropo,TerceraEdad
- juan,Discapacitado
- tiare,Embarazada
- inti,Normal

#### `productos.txt`

- 1,Medicina,Analgésicos,Paracetamol,5.0,50
- 2,Medicina,Analgésicos,Ibuprofeno,7.5,15
- 3,Medicina,Analgésicos,Aspirina,4.0,40
- 4,Medicina,Medicamentos de prescripción,Omeprazol,10.0,20
- 5,Medicina,Medicamentos de prescripción,Atorvastatina,15.0,25
- 6,Medicina,Medicamentos de prescripción,Losartán,12.0,30


## Compilación y Ejecución

1. **Compilar el código**:
    ```sh
    g++ -o farmacia main.cpp Inventario.cpp ListaEnlazada.cpp HashMap.cpp GestionClientes.cpp Cliente.cpp
    ```

2. **Ejecutar el programa**:
    ```sh
    ./farmacia
    ```

## Uso

1. **Menú Principal**:
    - `1. Ingresar cliente a la cola`: Permite agregar un cliente a la cola con una prioridad específica.
    - `2. Atender cliente`: Atiende al siguiente cliente en la cola y genera una boleta de compra.
    - `3. Agregar producto a bodega`: Permite agregar un nuevo producto al inventario.
    - `4. Aumentar Stock`: Permite aumentar el stock de un producto existente en el inventario.
    - `5. Salir`: Guarda los datos y cierra el programa.

2. **Atención de Clientes**:
    - Al seleccionar la opción `2`, se llama al siguiente cliente en la cola.
    - Se muestra el inventario y se permite al cliente seleccionar productos.
    - Se genera una boleta de compra y se actualiza el archivo de inventario.

## Contribución

Si deseas contribuir a este proyecto, por favor realiza un fork del repositorio y envía un pull request con tus cambios. Las mejoras y correcciones son bienvenidas.

## Licencia

Este proyecto está licenciado bajo la Licencia MIT. Ver el archivo `LICENSE` para más detalles.
