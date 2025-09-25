#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Constante para el tamaño máximo del inventario
const int MAX_PRODUCTOS = 100;

// Arreglos paralelos para almacenar la información de los productos
int codigos[MAX_PRODUCTOS];           // Códigos únicos de productos
string nombres[MAX_PRODUCTOS];        // Nombres de los productos
int cantidades[MAX_PRODUCTOS];        // Cantidad en stock
float precios[MAX_PRODUCTOS];         // Precios unitarios

int totalProductos = 0;               // Contador de productos actuales

// Función para inicializar datos de ejemplo
void inicializarDatos() {
    // Producto 1: Martillo de bola
    codigos[0] = 101;
    nombres[0] = "Martillo de bola";
    cantidades[0] = 50;
    precios[0] = 15.50;
    
    // Producto 2: Destornillador
    codigos[1] = 102;
    nombres[1] = "Destornillador";
    cantidades[1] = 120;
    precios[1] = 8.75;
    
    // Producto 3: Cinta métrica
    codigos[2] = 103;
    nombres[2] = "Cinta métrica";
    cantidades[2] = 75;
    precios[2] = 20.00;
    
    // Producto 4: Llave inglesa
    codigos[3] = 104;
    nombres[3] = "Llave inglesa";
    cantidades[3] = 45;
    precios[3] = 25.99;
    
    // Producto 5: Taladro inalámbrico
    codigos[4] = 105;
    nombres[4] = "Taladro inalámbrico";
    cantidades[4] = 10;
    precios[4] = 120.00;
    
    totalProductos = 5; // Actualizamos el contador
}

// Función para buscar un producto por código y devolver su índice
int buscarProducto(int codigo) {
    // Recorremos todos los productos registrados
    for (int i = 0; i < totalProductos; i++) {
        if (codigos[i] == codigo) {
            return i; // Retornamos el índice si encontramos el código
        }
    }
    return -1; // Retornamos -1 si no encontramos el producto
}

// Función para consultar un producto específico
void consultarProducto() {
    int codigo;
    cout << "\nIngrese el código del producto a consultar: ";
    cin >> codigo;
    
    // Verificamos si la entrada es válida
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Debe ingresar un número válido.\n";
        return;
    }
    
    int indice = buscarProducto(codigo);
    
    if (indice != -1) {
        // Si encontramos el producto, mostramos su información
        cout << "\nInformación del Producto:\n";
        cout << "Código: " << codigos[indice] << endl;
        cout << "Nombre: " << nombres[indice] << endl;
        cout << "Cantidad en stock: " << cantidades[indice] << endl;
        cout << "Precio unitario: $" << fixed << setprecision(2) << precios[indice] << endl;
    } else {
        // Si no encontramos el producto, mostramos error
        cout << "Error: No se encontró un producto con el código " << codigo << endl;
    }
}

// Función para actualizar el inventario de un producto
void actualizarInventario() {
    int codigo, cantidad;
    
    cout << "\nIngrese el código del producto: ";
    cin >> codigo;
    
    // Verificamos entrada válida para código
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Debe ingresar un código numérico válido.\n";
        return;
    }
    
    int indice = buscarProducto(codigo);
    
    if (indice == -1) {
        cout << "Error: No se encontró un producto con el código " << codigo << endl;
        return;
    }
    
    cout << "Producto encontrado: " << nombres[indice] << endl;
    cout << "Stock actual: " << cantidades[indice] << endl;
    cout << "Ingrese la cantidad a agregar (use números negativos para restar): ";
    cin >> cantidad;
    
    // Verificamos entrada válida para cantidad
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Debe ingresar una cantidad numérica válida.\n";
        return;
    }
    
    // Calculamos la nueva cantidad
    int nuevaCantidad = cantidades[indice] + cantidad;
    
    // Verificamos que no sea negativa
    if (nuevaCantidad < 0) {
        cout << "Error: La cantidad en stock no puede ser negativa.\n";
        cout << "Stock actual: " << cantidades[indice] << ", cantidad solicitada: " << cantidad << endl;
        return;
    }
    
    // Actualizamos el stock
    cantidades[indice] = nuevaCantidad;
    cout << "Inventario actualizado exitosamente.\n";
    cout << "Nuevo stock para " << nombres[indice] << ": " << cantidades[indice] << endl;
}

// Función para generar reporte completo del inventario
void generarReporte() {
    cout << "\n--- Reporte de Inventario ---\n";
    cout << left << setw(10) << "Código" << " | " 
         << setw(20) << "Nombre" << " | " 
         << setw(8) << "Stock" << " | " 
         << "Precio" << endl;
    cout << "-------------------------------------------------------------\n";
    
    // Recorremos todos los productos y los mostramos
    for (int i = 0; i < totalProductos; i++) {
        cout << left << setw(10) << codigos[i] << " | "
             << setw(20) << nombres[i] << " | "
             << setw(8) << cantidades[i] << " | "
             << "$" << fixed << setprecision(2) << precios[i] << endl;
    }
    
    cout << "-------------------------------------------------------------\n";
    cout << "Total de productos en inventario: " << totalProductos << endl;
    cout << "--- Fin del Reporte ---\n";
}

// Función para encontrar el producto más caro
void encontrarProductoMasCaro() {
    if (totalProductos == 0) {
        cout << "No hay productos en el inventario.\n";
        return;
    }
    
    // Inicializamos con el primer producto
    int indiceMasCaro = 0;
    float precioMasCaro = precios[0];
    
    // Comparamos con el resto de productos
    for (int i = 1; i < totalProductos; i++) {
        if (precios[i] > precioMasCaro) {
            precioMasCaro = precios[i];
            indiceMasCaro = i;
        }
    }
    
    cout << "\nEl producto más caro es: " << nombres[indiceMasCaro] 
         << " con un precio de $" << fixed << setprecision(2) << precioMasCaro << endl;
}

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n--- Menú Principal ---\n";
    cout << "Seleccione una opción:\n";
    cout << "1. Consultar un producto\n";
    cout << "2. Actualizar inventario\n";
    cout << "3. Generar reporte completo\n";
    cout << "4. Encontrar el producto más caro\n";
    cout << "5. Salir\n";
    cout << "\nOpción seleccionada: ";
}

// Función principal del programa
int main() {
    // Inicializamos los datos de ejemplo
    inicializarDatos();
    
    cout << "--- Bienvenido al Sistema de Inventario de \"El Martillo\" ---\n";
    
    int opcion;
    bool continuar = true;
    
    // Bucle principal del programa
    while (continuar) {
        mostrarMenu();
        cin >> opcion;
        
        // Verificamos si la entrada es válida
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Debe ingresar un número válido.\n";
            continue;
        }
        
        // Procesamos la opción seleccionada
        switch (opcion) {
            case 1:
                consultarProducto();
                break;
            case 2:
                actualizarInventario();
                break;
            case 3:
                generarReporte();
                break;
            case 4:
                encontrarProductoMasCaro();
                break;
            case 5:
                cout << "\n¡Gracias por usar el Sistema de Inventario de \"El Martillo\"!\n";
                cout << "¡Hasta luego!\n";
                continuar = false;
                break;
            default:
                cout << "Opción inválida. Por favor seleccione una opción del 1 al 5.\n";
                break;
        }
        
        // Pausa para que el usuario pueda leer la salida
        if (continuar) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}