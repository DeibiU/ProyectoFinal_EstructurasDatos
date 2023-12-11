// Archivo categorias.h
#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <iostream>
#include <string>

struct Categoria {
    std::string nombre;

    Categoria(const std::string& nombre) : nombre(nombre) {}
};

class ListaCategorias {
private:
    struct Nodo {
        Categoria categoria;
        Nodo* siguiente;
        Nodo* anterior;

        Nodo(const Categoria& cat) : categoria(cat), siguiente(nullptr), anterior(nullptr) {}
    };

    Nodo* cabeza;

public:
    ListaCategorias();
    ~ListaCategorias();

    void registrarCategoria(const std::string& nombre);
    void removerCategoria(const std::string& nombre);
    void modificarCategoria(const std::string& nombre, const std::string& nuevoNombre);
    Categoria* consultarCategoria(const std::string& nombre);
    void listarCategoriasAscendente();
    void listarCategoriasDescendente();
};

#endif // CATEGORIAS_H
