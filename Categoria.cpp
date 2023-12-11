// Archivo categorias.cpp
#include "CategoriasTienda.h"

#include <iostream>

ListaCategorias::ListaCategorias() : cabeza(nullptr) {}

ListaCategorias::~ListaCategorias() {
    // Liberar la memoria de los nodos
    Nodo* actual = cabeza;
    if (actual == nullptr) {
        return;
    }

    do {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);
}

void ListaCategorias::registrarCategoria(const std::string& nombre) {
    Nodo* nuevoNodo = new Nodo(Categoria(nombre));

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    }
    else {
        Nodo* ultimo = cabeza->anterior;

        nuevoNodo->siguiente = cabeza;
        nuevoNodo->anterior = ultimo;

        cabeza->anterior = nuevoNodo;
        ultimo->siguiente = nuevoNodo;
    }
}

void ListaCategorias::removerCategoria(const std::string& nombre) {
    if (cabeza == nullptr) {
        std::cout << "La lista de categorías está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    do {
        if (actual->categoria.nombre == nombre) {
            if (actual == cabeza) {
                cabeza = actual->siguiente;
            }

            Nodo* siguiente = actual->siguiente;
            Nodo* anterior = actual->anterior;

            siguiente->anterior = anterior;
            anterior->siguiente = siguiente;

            delete actual;
            std::cout << "Categoría eliminada: " << nombre << std::endl;
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "Categoría no encontrada: " << nombre << std::endl;
}

void ListaCategorias::modificarCategoria(const std::string& nombre, const std::string& nuevoNombre) {
    if (cabeza == nullptr) {
        std::cout << "La lista de categorías está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;

    do {
        if (actual->categoria.nombre == nombre) {
            actual->categoria.nombre = nuevoNombre;
            std::cout << "Categoría modificada: " << nombre << " -> " << nuevoNombre << std::endl;
            return;
        }

        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "Categoría no encontrada: " << nombre << std::endl;
}

Categoria* ListaCategorias::consultarCategoria(const std::string& nombre) {
    if (cabeza == nullptr) {
        std::cout << "La lista de categorías está vacía." << std::endl;
        return nullptr;
    }

    Nodo* actual = cabeza;

    do {
        if (actual->categoria.nombre == nombre) {
            return &(actual->categoria);
        }

        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "Categoría no encontrada: " << nombre << std::endl;
    return nullptr;
}

void ListaCategorias::listarCategoriasAscendente() {
    if (cabeza == nullptr) {
        std::cout << "La lista de categorías está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;

    std::cout << "Categorías en forma ascendente:" << std::endl;
    do {
        std::cout << actual->categoria.nombre << std::endl;
        actual = actual->siguiente;
    } while (actual != cabeza);
}

void ListaCategorias::listarCategoriasDescendente() {
    if (cabeza == nullptr) {
        std::cout << "La lista de categorías está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza->anterior;

    std::cout << "Categorías en forma descendente:" << std::endl;
    do {
        std::cout << actual->categoria.nombre << std::endl;
        actual = actual->anterior;
    } while (actual != cabeza->anterior);
}

int main() {
    ListaCategorias listaCategorias;

    int opcion;
    do {
        std::cout << "\nMENU:\n";
        std::cout << "1. Registrar Categoría\n";
        std::cout << "2. Remover Categoría\n";
        std::cout << "3. Modificar Categoría\n";
        std::cout << "4. Consultar Categoría\n";
        std::cout << "5. Listar Categorías Ascendente\n";
        std::cout << "6. Listar Categorías Descendente\n";
        std::cout << "0. Salir\n";

        std::cout << "Ingrese la opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::string nombre;
            std::cout << "Ingrese el nombre de la categoría a registrar: ";
            std::cin >> nombre;
            listaCategorias.registrarCategoria(nombre);
            break;
        }
        case 2: {
            std::string nombre;
            std::cout << "Ingrese el nombre de la categoría a remover: ";
            std::cin >> nombre;
            listaCategorias.removerCategoria(nombre);
            break;
        }
        case 3: {
            std::string nombre, nuevoNombre;
            std::cout << "Ingrese el nombre de la categoría a modificar: ";
            std::cin >> nombre;
            std::cout << "Ingrese el nuevo nombre: ";
            std::cin >> nuevoNombre;
            listaCategorias.modificarCategoria(nombre, nuevoNombre);
            break;
        }
        case 4: {
            std::string nombre;
            std::cout << "Ingrese el nombre de la categoría a consultar: ";
            std::cin >> nombre;
            Categoria* categoria = listaCategorias.consultarCategoria(nombre);
            if (categoria != nullptr) {
                std::cout << "Categoría encontrada: " << categoria->nombre << std::endl;
            }
            break;
        }
        case 5: {
            listaCategorias.listarCategoriasAscendente();
            break;
        }
        case 6: {
            listaCategorias.listarCategoriasDescendente();
            break;
        }
        case 0:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
