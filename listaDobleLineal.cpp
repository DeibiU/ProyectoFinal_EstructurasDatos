#include <stdlib.h>
#include <iostream>
#include "listaDobleLineal.h"
using namespace std;



listaDobleLineal::listaDobleLineal()
{
	this->cab = NULL;
	this->largo = 0;
}

listaDobleLineal::~listaDobleLineal()
{
}

nodoD* listaDobleLineal::getCab()
{
	return this->cab;
}

int listaDobleLineal::getLargo()
{
	return this->largo;
}

void listaDobleLineal::setCab(nodoD* ptr)
{
	this->cab = ptr;
}

void listaDobleLineal::setLargo(int n)
{
	this->largo = n;
}

bool listaDobleLineal::esVacia()
{
	return this->getLargo() == 0;
}

nodoD* listaDobleLineal::dirNodo(int pnum)
{ //Devolver la direcci�n donde se ubica pnum
	nodoD* aux = getCab();
	while ((aux != NULL) && (aux->getDato() != pnum)) {
		aux = aux->getSgte();
	}
	return aux;
}

nodoD* listaDobleLineal::dirAnterior(int pdato)
{
	nodoD* aux = dirNodo(pdato);
	if (aux != nullptr) {
		return aux->getAnte();
	}
	else {
		return nullptr;
	}
}

nodoD* listaDobleLineal::dirSiguiente(int pdato)
{
	nodoD* aux = dirNodo(pdato);
	if (aux != nullptr) {
		return aux->getSgte();
	}
	else {
		return nullptr;
	}
}

nodoD* listaDobleLineal::dirUltimo()
{
	nodoD* aux = getCab();

	while (aux != NULL && aux->getSgte() != NULL) {
		aux = aux->getSgte();
	}
	return aux;
}
bool listaDobleLineal::eliminar(int pdato)
{
    nodoD* aux = dirNodo(pdato);
    bool resultado = false;
    if (aux != nullptr) {
        if (aux->getAnte() == nullptr && aux->getSgte() == nullptr) {
            setCab(nullptr);
        }
        else if (aux->getAnte() == nullptr) {
            aux->getSgte()->setAnte(nullptr);
            setCab(aux->getSgte());
        }
        else if (aux->getSgte() == nullptr) {
            aux->getAnte()->setSgte(nullptr);
        }
        else {
            aux->getSgte()->setAnte(aux->getAnte());
            aux->getAnte()->setSgte(aux->getSgte());
        }
        delete aux;
        resultado = true;
        setLargo(getLargo() - 1);
    }
    return resultado;
}

void listaDobleLineal::agregarFinal(int x)
{
	nodoD* nuevo = new nodoD(x);
	nodoD* ultimo = dirUltimo();
	ultimo->setSgte(nuevo);
	largo++;
}

void listaDobleLineal::agregarInicio(int pdato)
{
	nodoD* nuevo = new nodoD(pdato);

	if (!esVacia()) {
		nuevo->setSgte(getCab());
		getCab()->setAnte(nuevo);
	}
	setCab(nuevo);
	setLargo(getLargo() + 1);
}

bool listaDobleLineal::agregarAntesDe(int x, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		if (getCab()->getDato() == ref) {
			agregarInicio(x);
			agregado = true;
		}
		else {
			nodoD* sig = dirSiguiente(ref);
			if (sig != NULL) {
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

	return false;
}

bool listaDobleLineal::agregarDespuesDe(int x, int ref)
{
	//Buscar el nodo de pdato
	// Paso #1, crear el nodo
	// Paso #2, enlazar el nuevo nodo a la lista, guinde el nodo
	// Paso #3, reacomodo la lista con el nuevo nodo

	//Explorar como se codifica...
	bool agregado = false;
	if (getCab() != NULL) {
		/*if (getCab()->getDato() == ref) {
			agregarInicio(x);
			agregado = true;
		}
		else {*/
			nodoD* ant = dirAnterior(ref);
			if (ant != NULL) {
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
		//}
		
	}
	return agregado;

	return false;
}

bool listaDobleLineal::agregarAscendente(int pnum)
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
					nodoD* nuevo = new nodoD(pnum);//Paso #1	
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
bool listaDobleLineal::agregarDescendente(int numD)
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

void listaDobleLineal::desplegar()	
{
	nodoD* aux = getCab();  // aux toma el valor de la cabeza
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

bool listaDobleLineal::completarSecuencia()
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
		while (aux != NULL && aux->getSgte() != NULL) {
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

void listaDobleLineal::eliminarTodos()
{
	nodoD* aux = getCab();
	while (aux != NULL) {
		setCab(getCab()->getSgte());
		delete aux;
		aux = getCab();
	}
	setLargo(0);
}

int listaDobleLineal::cantpares()
{
	nodoD* aux = listaDobleLineal::getCab(); // aux toma el valor de la cabeza
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