#include <stdlib.h>
#include <iostream>

#include "listaSimple.h"
using namespace std;


listaSimple::listaSimple()
{
	this->cab = NULL;
	this->largo = 0;
}

listaSimple::~listaSimple()
{
}

nodoS* listaSimple::getCab()
{
	return this->cab;
}

int listaSimple::getLargo()
{
	return this->largo;
}

void listaSimple::setCab(nodoS* ptr)
{
	this->cab = ptr;
}

void listaSimple::setLargo(int n)
{
	this->largo = n;
}

bool listaSimple::esVacia()
{
	return this->getLargo() == 0;
}

nodoS* listaSimple::dirNodo(int pnum)
{ //Devolver la direcci�n donde se ubica pnum
	nodoS* aux = getCab();
	while ((aux != NULL) && (aux->getDato() != pnum)) {
		aux = aux->getSgte();
	}
	return aux;
}

nodoS* listaSimple::dirAnterior(int pnum)
{
	/*nodoS* aux = getCab();
	nodoS* previo = aux;

	while (aux != NULL) {
		previo = aux;
		if (aux->getDato() != pnum) {
			aux = aux->getSgte();
		}
	}
	return previo;*/

	nodoS* ant = NULL;

	if (!esVacia()) {
		ant = getCab();

		while ((ant != NULL) && (ant->getSgte() != NULL)) {

			if (ant->getSgte()->getDato() == pnum) {
				return ant;
			}
			else {
				ant = ant->getSgte();
			}
		}
		return NULL;
	}
	else {
		return NULL;
	}
}

nodoS* listaSimple::dirUltimo()
{
	nodoS* aux = getCab();

	while (aux != NULL && aux->getSgte() != NULL) {
		aux = aux->getSgte();
	}
	return aux;
}

void listaSimple::desplegar()
{
	nodoS* aux = getCab();  // aux toma el valor de la cabeza
	if (aux == NULL) {
		cout << "LA LISTA ESTA VACIA..." << endl;
	}
	else {
		cout << "ELEMENTOS EN LA LISTA:" << endl;
		while (aux != NULL) {
			cout << aux->getDato() << "->";
			aux = aux->getSgte();  //Que aux apunta al siguiente nodo.
		}
		cout << "//";
	}

}


void listaSimple::agregarInicio(int x)
{
	nodoS* nuevo = new nodoS(x); //Paso 1. Crear el nodo
	nuevo->setSgte(getCab());//Paso 2. Enlazar el nuevo nodo a la lista
	setCab(nuevo); //Paso 3. Reacomodar la lista con el nuevo nodo
	largo++;
}

void listaSimple::agregarFinal(int x)
{
	nodoS* nuevo = new nodoS(x);
	nodoS* ultimo = dirUltimo();
	ultimo->setSgte(nuevo);
	largo++;
}

bool listaSimple::agregarAntesDe(int x, int ref)
{//Agregar un nodo con el valor de x y lo voy a colocar antes del nodo
//	que contiene a ref
// Sino existe ref no lo agrega
	bool agregado = false;
	if (getCab() != NULL) {
		if (getCab()->getDato() == ref) {
			agregarInicio(x);
			agregado = true;
		}
		else {
			nodoS* ant = dirAnterior(ref);
			if (ant != NULL) {
				nodoS* nuevo = new nodoS(x); //Paso 1. Crear el nodo
				nuevo->setSgte(ant->getSgte()); //Paso 2. Enlazar el nuevo nodo a la lista
				ant->setSgte(nuevo); //Paso 3. Reacomodar la lista con el nuevo nodo
				largo++;
				agregado = true;
			}
		}

	}
	return agregado;
}

bool listaSimple::agregarAscendente(int pnum)
{ //Agregar en forma ascendente (de menor a mayor) en la lista, considerando que no
 // pueden darse valores repetidos
	bool agregado = false;
	bool repetido = false;
	if (esVacia() or pnum < getCab()->getDato()) {
		agregarInicio(pnum);
		agregado = true;
	}
	else {
		nodoS* ant = getCab();
		nodoS* aux = NULL;
		while (ant != NULL && !repetido && !agregado) {
			if (pnum == ant->getDato()) {
				repetido = true;
			}
			else {
				nodoS* aux = ant->getSgte();
				if (ant->getSgte() == NULL || pnum < aux->getDato()) {
					nodoS* nuevo = new nodoS(pnum);//Paso #1
					nuevo->setSgte(aux);//Paso #2
					ant->setSgte(nuevo); //Paso #3
					largo++;
					agregado = true;
				}
				else {
					ant = ant->getSgte();
				}
			}
		}
	}
	return agregado;
}

bool listaSimple::agregarDescendente(int numD)
{
	bool numAgregado = false;
	if (esVacia() || numD> getCab()->getDato()) {
		agregarInicio(numD);
		numAgregado = true;
	}
	else {
		nodoS* ant = getCab();
		nodoS* current = nullptr;

		while (ant != nullptr && !numAgregado) {
			current = ant->getSgte();

			if (current == nullptr || numD>= current->getDato()) {
				
				if (current == nullptr || numD!= current->getDato()) {
					nodoS* nuevo = new nodoS(numD);
					nuevo->setSgte(current);
					ant->setSgte(nuevo);
					largo++;
					numAgregado = true;
				}
			}

			ant = ant->getSgte();
		}
	}

	return numAgregado ;
}

bool listaSimple::completarSecuencia()
{ //Agregar en forma ascendente (de menor a mayor) en la lista, considerando que no
 // pueden darse valores repetidos
	bool agregado = false;

	if (esVacia()) {
		agregado = true;
	}
	else {
		nodoS* aux = getCab();
		nodoS* ant = NULL;
		while (aux != NULL && aux->getSgte() != NULL) {
			int numero = aux->getDato()+1;
			nodoS* ant = aux->getSgte();
			if (aux->getSgte() == NULL || numero < ant->getDato()) {
				nodoS* nuevo = new nodoS(numero);//Paso #1
				nuevo->setSgte(ant);//Paso #2
				aux->setSgte(nuevo); //Paso #3
				largo++;
				aux = aux->getSgte();
				agregado = true;
			}
			else {
				aux = aux->getSgte();
			}

		}
	}
	return agregado;
}


bool listaSimple::eliminar(int pdato)
{
	bool eliminado = false;
	if (!esVacia()) {

		nodoS* aux;
		if (getCab()->getDato() == pdato) {
			aux = getCab();
			setCab(aux->getSgte());
			setLargo(getLargo() - 1);
			delete aux;
			eliminado = true;
		}
		else {
			nodoS* ant = dirAnterior(pdato);
			if (ant != NULL) {
				aux = ant->getSgte();
				ant->setSgte(aux->getSgte());
				setLargo(getLargo() - 1);
				delete aux;
				eliminado = true;
			}
		}
	}
	return eliminado;
}

void listaSimple::eliminarTodos()
{
	nodoS* aux = getCab();
	while (aux != NULL) {
		setCab(getCab()->getSgte());
		delete aux;
		aux = getCab();
	}
	setLargo(0);
}

int listaSimple::cantpares()
{
	nodoS* aux = listaSimple::getCab(); // aux toma el valor de la cabeza
	int pares = 0;

	while (aux != NULL) {
		int numero = aux->getDato();
		if (numero % 2 == 0) {
			pares++;
		}
		aux = aux->getSgte(); //Que aux apunta al siguiente nodo
	}
	return pares;
}

void listaSimple::eliminarTodos(int dato) {
	nodoS* actual = cab;
	nodoS* anterior = nullptr;

	while (actual != nullptr) {
		if (actual->getDato() == dato) {
			if (anterior == nullptr) {
				cab = actual->getSgte();
				delete actual;
				actual = cab;
			}
			else {
				nodoS* temp = actual->getSgte(); // Almacena el siguiente nodo
				anterior->setSgte(temp); // Asigna el siguiente nodo
				delete actual;
				actual = temp; // Avanza el puntero actual
			}
		}
		else {
			anterior = actual;
			actual = actual->getSgte();
		}
	}
}

void listaSimple::eliminarRepetidosConsecutivos() {
	nodoS* actual = cab;

	while (actual != nullptr && actual->getSgte() != nullptr) {
		if (actual->getDato() == actual->getSgte()->getDato()) {
			nodoS* temp = actual->getSgte();
			actual->setSgte(temp->getSgte()); // Asignar el siguiente nodo
			delete temp;
		}
		else {
			actual = actual->getSgte();
		}
	}
}

bool listaSimple::agregarDespuesDe(int x, int ref) 
{
    bool agregado = false;
    if (getCab() != NULL) {
        nodoS* ant = dirNodo(ref); 
        if (ant != NULL) {
            nodoS* nuevo = new nodoS(x); //Paso 1. Crear el nodo
            nuevo->setSgte(ant->getSgte()); //Paso 2. Enlazar el nuevo nodo a la lista
            ant->setSgte(nuevo); //Paso 3. Reacomodar la lista con el nuevo nodo
            largo++;
            agregado = true;
        }
    }
    return agregado;
    ;
}
