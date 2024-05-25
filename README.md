# Sistema de Gestión de Farmacia

Este es un proyecto de gestión de inventario y atención de clientes para una farmacia, desarrollado en C++. Permite a los usuarios gestionar productos en el inventario y atender a clientes en una cola prioritaria, generando boletas de compra y actualizando el inventario en tiempo real.

## Funcionalidades

- **Gestión de Inventario**: Permite agregar, buscar, y mostrar productos en el inventario.
- **Atención de Clientes**: Maneja una cola prioritaria de clientes según su condición (tercera edad, discapacitado, embarazada, normal).
- **Generación de Boletas**: Genera boletas de compra para los clientes atendidos, detallando los productos comprados y el total a pagar.
- **Actualización de Inventario**: Actualiza el inventario en el archivo de productos después de cada compra.

## Descripción de los Objetos Principales

Durante el inicio del programa, se crean varios objetos fundamentales para el funcionamiento de la aplicación. A continuación, se detallan estos objetos:

### 1. Inventario (`Inventario`)

La clase `Inventario` gestiona todas las operaciones relacionadas con los productos de la farmacia. Algunas de las funciones clave incluyen:

- **Agregar Producto**: Agrega un nuevo producto al inventario.
- **Buscar Producto**: Busca un producto por su ID en el inventario.
- **Mostrar Inventario**: Muestra todos los productos disponibles en el inventario.
- **Cargar Productos desde Archivo**: Carga productos desde un archivo de texto.
- **Actualizar Archivo**: Actualiza el archivo de productos después de modificaciones.

### 2. Producto (`Producto`)

La clase `Producto` representa un producto en el inventario. Cada objeto `Producto` tiene atributos como ID, categoría, subcategoría, nombre, precio y cantidad. Entre las funciones importantes de la clase `Producto` se incluyen:

- **Restar Cantidad**: Resta una cantidad específica del stock del producto.
- **Agregar Cantidad**: Agrega una cantidad específica al stock del producto.

### 3. Cliente (`Cliente`)

La clase `Cliente` representa a un cliente en la cola de atención. Cada objeto `Cliente` tiene atributos como nombre y una prioridad basada en su condición (tercera edad, discapacitado, embarazada, normal).

### 4. Gestión de Clientes (`GestionClientes`)

La clase `GestionClientes` maneja la cola de clientes, permitiendo agregar clientes con prioridad y atenderlos en orden de prioridad. Las funciones importantes incluyen:

- **Agregar Cliente**: Agrega un cliente a la cola con una prioridad específica.
- **Siguiente Cliente**: Devuelve el siguiente cliente en la cola para ser atendido.

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
    g++ -o farmacia main.cpp Inventario.cpp Producto.cpp ListaEnlazada.cpp HashMap.cpp GestionClientes.cpp Cliente.cpp
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

## Equipo de Trabajo

- **Inti Bautista Santibáñez Walker**
  - **RUT**: 21.275.258-4
  - **Correo**: inti.santibanez@alumnos.ucn.cl

- **Carlos Andres Tapia Paredes**
  - **RUT**: 21.458.544-8
  - **Correo**: carlos.tapia03@alumnos.ucn.cl
