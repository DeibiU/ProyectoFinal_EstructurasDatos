// proyecto listas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
#include "listaSimple.h"
#include "listaDobleLineal.h"
#include "listaDobleCircular.h"
using namespace std;
void menu() {
    listaSimple* lista = new listaSimple();
    int opc = -1;
    int dato = 0;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU 1" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar al inicio" << endl;
        cout << "(2) Agregar al final " << endl;
        cout << "(3) Agregar antes de...  " << endl;
        cout << "(4) Agregar despues de...  " << endl;
        cout << "(5) Agregar ascendente...  " << endl;
        cout << "(6) Agregar descendente...  " << endl;
        cout << "(7) Remover un dato de la lista" << endl;
        cout << "(10) Desplegar la lista" << endl;
        cout << "(11) Eliminar todos los elementos dato" << endl;
        cout << "(13) Eliminar todos los datos consecutivos" << endl;
        cout << "(12) Agregar descendente..." << endl;
        cout << "(16) Completar Secuencia..." << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
        case 1: {
            cout << "Dato que desea agregar al inicio: ";
            cin >> dato;
            lista->agregarInicio(dato);
            break;
        }
        case 2: {
            cout << "Dato que desea agregar al final: ";
            cin >> dato;
            lista->agregarFinal(dato);
            break;
        }
        case 3: {
            int ref = 0;
            cout << "Dato de referencia en la lista?->";
            cin >> ref;
            cout << "Dato que desea agregar antes de " << ref << " ->";
            cin >> dato;
            if (lista->agregarAntesDe(dato, ref))
                cout << "Agregado correctamente" << endl;
            else
                cout << "No se pudo agregar" << endl;
            break;
        }

        case 5: {
            cout << "Dato que desea agregar al ascendente: ";
            cin >> dato;
            lista->agregarAscendente(dato);
            break;
        }

        case 7: {
            cout << "Dato que desea eliminar de la lista: ";
            cin >> dato;
            if (lista->eliminar(dato))
                cout << "El numero " << dato << " ha sido eliminado exitosamente" << endl;
            else
                cout << "El numero " << dato << " no está en la lista" << endl;

            break;
        }
        case 12:
            int numDescendente;
            cout << "Ingresar el valor" << endl;
            cin >> numDescendente;
            lista->agregarDescendente(numDescendente);
            break;
        case 11:
            cout << "Eliminando los elementos dato" << endl;
            cin >> dato;
            lista->eliminarTodos();
            break;
        case 13:
            cout << "Eliminando los repetidos consecutivos" << endl;
            cin >> dato;
            lista->eliminarRepetidosConsecutivos();
            break;
        case 10:
            cout << "Desplegando los valores de la lista" << endl;
            lista->desplegar();
            break;
        case 16:
            cout << "Completando la lista" << endl;
            lista->completarSecuencia();
            break;
        case 0:
            cout << "Finalizando el programa... ";
            break;
        default:
            cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }


}
void menu2() {
    listaDobleLineal* lista = new listaDobleLineal();
    int opc = -1;
    int dato = 0;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU 2" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar al inicio" << endl;
        cout << "(2) Agregar al final " << endl;
        cout << "(3) Agregar antes de...  " << endl;
        cout << "(4) Agregar despues de...  " << endl;
        cout << "(5) Agregar ascendente...  " << endl;
        cout << "(6) Agregar descendente...  " << endl;
        cout << "(7) Remover un dato de la lista" << endl;
        cout << "(10) Desplegar la lista" << endl;
        cout << "(11) Eliminar todos los elementos dato" << endl;
        cout << "(13) Eliminar todos los datos consecutivos" << endl;
        cout << "(12) Agregar descendente..." << endl;
        cout << "(16) Completar Secuencia..." << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
        case 1: {
            cout << "Dato que desea agregar al inicio: ";
            cin >> dato;
            lista->agregarInicio(dato);
            break;
        }
        case 2: {
            cout << "Dato que desea agregar al final: ";
            cin >> dato;
            lista->agregarFinal(dato);
            break;
        }
        case 3: {
            int ref = 0;
            cout << "Dato de referencia en la lista?->";
            cin >> ref;
            cout << "Dato que desea agregar antes de " << ref << " ->";
            cin >> dato;
            if (lista->agregarAntesDe(dato, ref))
                cout << "Agregado correctamente" << endl;
            else
                cout << "No se pudo agregar" << endl;
            break;
        }

        case 5: {
            cout << "Dato que desea agregar al ascendente: ";
            cin >> dato;
            lista->agregarAscendente(dato);
            break;
        }

        case 7: {
            cout << "Dato que desea eliminar de la lista: ";
            cin >> dato;
            if (lista->eliminar(dato))
                cout << "El numero " << dato << " ha sido eliminado exitosamente" << endl;
            else
                cout << "El numero " << dato << " no está en la lista" << endl;

            break;
        }
        case 12:
            int numDescendente;
            cout << "Ingresar el valor" << endl;
            cin >> numDescendente;
            lista->agregarDescendente(numDescendente);
            break;
        case 11:
            cout << "Eliminando los elementos dato" << endl;
            cin >> dato;
            lista->eliminarTodos();
            break;
        case 13:
            cout << "Eliminando los repetidos consecutivos" << endl;
            cin >> dato;
            lista->eliminarRepetidosConsecutivos();
            break;
        case 10:
            cout << "Desplegando los valores de la lista" << endl;
            lista->desplegar();
            break;
        case 16:
            cout << "Completando la lista" << endl;
            lista->completarSecuencia();
            break;
        case 0:
            cout << "Finalizando el programa... ";
            break;
        default:
            cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }


}
void menu3() {
    listaDobleCircular* lista = new listaDobleCircular();
    int opc = -1;
    int dato = 0;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU 3" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar al inicio" << endl;
        cout << "(2) Agregar al final " << endl;
        cout << "(3) Agregar antes de...  " << endl;
        cout << "(4) Agregar despues de...  " << endl;
        cout << "(5) Agregar ascendente...  " << endl;
        cout << "(6) Agregar descendente...  " << endl;
        cout << "(7) Remover un dato de la lista" << endl;
        cout << "(10) Desplegar la lista" << endl;
        cout << "(11) Eliminar todos los elementos dato" << endl;
        cout << "(13) Eliminar todos los datos consecutivos" << endl;
        cout << "(12) Agregar descendente..." << endl;
        cout << "(16) Completar Secuencia..." << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
        case 1: {
            cout << "Dato que desea agregar al inicio: ";
            cin >> dato;
            lista->agregarInicio(dato);
            break;
        }
        case 2: {
            cout << "Dato que desea agregar al final: ";
            cin >> dato;
            lista->agregarFinal(dato);
            break;
        }
        case 3: {
            int ref = 0;
            cout << "Dato de referencia en la lista?->";
            cin >> ref;
            cout << "Dato que desea agregar antes de " << ref << " ->";
            cin >> dato;
            if (lista->agregarAntesDe(dato, ref))
                cout << "Agregado correctamente" << endl;
            else
                cout << "No se pudo agregar" << endl;
            break;
        }

        case 5: {
            cout << "Dato que desea agregar al ascendente: ";
            cin >> dato;
            lista->agregarAscendente(dato);
            break;
        }

        case 7: {
            cout << "Dato que desea eliminar de la lista: ";
            cin >> dato;
            if (lista->eliminar(dato))
                cout << "El numero " << dato << " ha sido eliminado exitosamente" << endl;
            else
                cout << "El numero " << dato << " no está en la lista" << endl;

            break;
        }
        case 12:
            int numDescendente;
            cout << "Ingresar el valor" << endl;
            cin >> numDescendente;
            lista->agregarDescendente(numDescendente);
            break;
        case 11:
            cout << "Eliminando los elementos dato" << endl;
            cin >> dato;
            lista->eliminarTodos();
            break;
        case 13:
            cout << "Eliminando los repetidos consecutivos" << endl;
            cin >> dato;
            lista->eliminarRepetidosConsecutivos();
            break;
        case 10:
            cout << "Desplegando los valores de la lista" << endl;
            lista->desplegar();
            break;
        case 16:
            cout << "Completando la lista" << endl;
            lista->completarSecuencia();
            break;
        case 0:
            cout << "Finalizando el programa... ";
            break;
        default:
            cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }


}

int main()
{
    int opc = -1;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Lista simple" << endl;
        cout << "(2) Lista doble lineal " << endl;
        cout << "(3) Lista doble circular" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            menu();
            break;
        }
        case 2: {
            menu2();
            break;
        }
        case 3: {
            menu3();
            break;
        }
    }
}
