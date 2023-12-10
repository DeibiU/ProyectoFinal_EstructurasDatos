#include <stdlib.h>
#include <iostream>
#include "listaDobleCircular.h"

using namespace std;

listaDobleCircular::listaDobleCircular()
{
	this->cab = NULL;
	this->largo = 0;
}

listaDobleCircular::~listaDobleCircular()
{
}

nodoD* listaDobleCircular::getCab()
{
	return this->cab;
}

int listaDobleCircular::getLargo()
{
	return this->largo;
}

void listaDobleCircular::setCab(nodoD* ptr)
{
	this->cab = ptr;
}

void listaDobleCircular::setLargo(int n)
{
	this->largo = n;
}

bool listaDobleCircular::esVacia()
{
	return this->getLargo() == 0;
}

nodoD* listaDobleCircular::dirNodo(int pnum)	   
{ //Devolver la direcci�n donde se ubica pnum
	nodoD* aux = getCab();
	do {
		aux = aux->getSgte();
	} while ((aux != NULL) && (aux->getDato() != pnum));
	return aux;
}

nodoD* listaDobleCircular::dirAnterior(int pdato)
{
	nodoD* aux = dirNodo(pdato);
	if (aux != nullptr) {
		return aux->getAnte();
	}
	else {
		return nullptr;
	}
}

nodoD* listaDobleCircular::dirSiguiente(int pdato)
{
	nodoD* aux = dirNodo(pdato);
	if (aux != nullptr) {
		return aux->getSgte();
	}
	else {
		return nullptr;
	}
}

nodoD* listaDobleCircular::dirUltimo()
{
	nodoD* aux = getCab();

	if (aux != nullptr) {
		return aux->getAnte();	
	}
}

bool listaDobleCircular::eliminar(int pdato)
{
	bool eliminado = false;
	if (!esVacia()) {
		nodoD* aux = dirNodo(pdato); //Paso0 1. Encuentro el nodoa eliminar
		if (aux != nullptr) {
			//Paso 2. Reacomodo la lista sin el nuevo nodo
			if (getLargo() == 1) {
				setCab(nullptr);
			}
			else {
				aux->getAnte()->setSgte(aux->getSgte());
				aux->getSgte()->setAnte(aux->getAnte());
				if (aux == getCab())
					setCab(getCab()->getSgte());
			}
		//Paso 3. Borrar el aux y reajustar
			delete aux;
			setLargo(getLargo() - 1);
			eliminado = true;
		}
	}

	return eliminado;

}

void listaDobleCircular::desplegar() {
	
	if (esVacia()) {
		cout << "La lista esta vacia, no hay elementos a desplegar" << endl;
	}
	else {
		nodoD* aux = getCab();
		for (int i = 1; i <= getLargo(); i++) {
			cout << aux->getDato() << "-";
			aux = aux->getSgte();
		}
	}
}

void listaDobleCircular::agregarInicio(int pdato)
{
	//Paso 1. Crear el nodo
	nodoD* nuevo = new nodoD(pdato);
	//Paso 2. Enlazar el nuevo nodo a la lista
	if (esVacia()) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
	}
	else {
		nuevo->setSgte(getCab());
		nuevo->setAnte(getCab()->getAnte());

		//Paso 3. Reacomodar la lista con el nuevo nodo
		getCab()->getAnte()->setSgte(nuevo);
		getCab()->setAnte(nuevo);
	}
	
	setCab(nuevo);
	setLargo(getLargo() + 1);
}

void listaDobleCircular::agregarFinal(int pdato)
{
	//Paso 1. Crear el nodo
	nodoD* nuevo = new nodoD(pdato);
	if (esVacia()) {
		nuevo->setSgte(nuevo); 
		nuevo->setAnte(nuevo); 
	}
	else {
		nuevo->setSgte(getCab());	 
		nuevo->setAnte(getCab()->getAnte());   

		//Paso 3. Reacomodar la lista con el nuevo nodo
		getCab()->getAnte()->setSgte(nuevo);  
		getCab()->setAnte(nuevo);			  
	}

	setLargo(getLargo() + 1);

}

bool listaDobleCircular::agregarAntesDe(int x, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		if (getCab()->getDato() == ref) {
			agregarInicio(x);
			agregado = true;
		}
		else {
			nodoD* sig = dirSiguiente(ref);
			if (sig != NULL) {						//Aunque este If no sea realmente necesario, funciona para detectar una cola mal conectada.
				// Paso #1, crear el nodo
				nodoD* nuevo = new nodoD(x);
				// Paso #2, enlazar el nuevo nodo a la lista, guinde el nodo
				nuevo->setAnte(sig->getAnte());
				nuevo->setSgte(sig);
				// Paso #3, reacomodo la lista con el nuevo nodo
				sig->setAnte(nuevo);
				nodoD* ant = nuevo->getAnte();
				ant->setSgte(nuevo);
				largo++;
				agregado = true;
			}
		}

	}
	return agregado;
}

bool listaDobleCircular::agregarDespuesDe(int x, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		nodoD* ant = dirAnterior(ref);
		if (ant != NULL) {							//Aunque este If no sea realmente necesario, funciona para detectar una cola mal conectada
			// Paso #1, crear el nodo
			nodoD* nuevo = new nodoD(x);
			// Paso #2, enlazar el nuevo nodo a la lista, guinde el nodo
			nuevo->setSgte(ant->getSgte());
			nuevo->setAnte(ant);
			// Paso #3, reacomodo la lista con el nuevo nodo
			ant->setSgte(nuevo);
			nodoD* sig = nuevo->getSgte();
			sig->setAnte(nuevo);
			largo++;
			agregado = true;
		}
	}
	return agregado;

	return false;
}

bool listaDobleCircular::agregarAscendente(int pnum)
{ //Agregar en forma ascendente (de menor a mayor) en la lista, considerando que no
 // pueden darse valores repetidos
	bool agregado = false;
	bool repetido = false;
	if (esVacia() or pnum < getCab()->getDato()) {
		agregarInicio(pnum);
		agregado = true;
	}
	else {
		nodoD* ant = getCab();
		nodoD* aux = NULL;
		while (ant != NULL && !repetido && !agregado) {
			if (pnum == ant->getDato()) {
				repetido = true;
			}
			else {
				nodoD* aux = ant->getSgte();
				if (ant->getSgte() == NULL || pnum < aux->getDato()) {
					nodoD* nuevo = new nodoD(pnum);	
					nuevo->setSgte(aux);	 
					ant->setSgte(nuevo);	 
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
bool listaDobleCircular::agregarDescendente(int numD)
{
	bool numAgregado = false;
	if (esVacia() || numD> getCab()->getDato()) {
		agregarInicio(numD);
		numAgregado = true;
	}
	else {
		nodoD* ant = getCab();
		nodoD* current = nullptr;

		while (ant != nullptr && !numAgregado) {
			current = ant->getSgte();

			if (current == nullptr || numD>= current->getDato()) {
				
				if (current == nullptr || numD!= current->getDato()) {
					nodoD* nuevo = new nodoD(numD);
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

bool listaDobleCircular::completarSecuencia()
{ //Agregar en forma ascendente (de menor a mayor) en la lista, considerando que no
 // pueden darse valores repetidos
	bool agregado = false;

	if (esVacia()) {
		agregado = true;
	}
	else {
		nodoD* aux = getCab();
		nodoD* sig = NULL;
		nodoD* ant = NULL;
		while (aux != NULL && aux->getSgte() != getCab()) {
			int numero = aux->getDato() + 1;
			nodoD* sig = aux->getSgte();
			nodoD* ant = aux;
			if (aux->getSgte() == NULL || numero < sig->getDato()) {
				nodoD* nuevo = new nodoD(numero);//Paso #1
				nuevo->setSgte(sig);//Paso #2
				nuevo->setAnte(ant);
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

void listaDobleCircular::eliminarTodos()
{
	nodoD* aux = getCab();
	while (aux != NULL) {
		setCab(getCab()->getSgte());
		delete aux;
		aux = getCab();
	}
	setLargo(0);
}