#include "colaD.h"
using namespace std;

nodoS* colaD::getpFrente()
{
	return this->pFrente;
}

void colaD::setpFrente(nodoS* ptr)
{
	this->pFrente = ptr;
}

nodoS* colaD::getpFinal() {
	return this->pFinal;
}

void colaD::setpFinal(nodoS* ptr) {
	this->pFinal = ptr;
}

int colaD::getLargo()
{
	return this->largo;
}

void colaD::setLargo(int pLargo)
{
	this->largo = pLargo;
}


void colaD::encolar(int pDato)
{
	//Paso #1, Crear la cola
	nodoS* nuevo = new nodoS(pDato);

	if (this->largo == 0) {
		this->pFrente = nuevo;
		setLargo(getLargo() + 1);
	}
	else {
		pFinal->setSgte(nuevo);
	}
	this->pFinal = nuevo;
	setLargo(getLargo() + 1);
}

int colaD::desencolar() {
	if (this->largo == 0)
		return 0;
	else {
		//Paso 1
		nodoS* aux = this->pFrente;
		//Paso 2
		this->pFrente = pFrente->getSgte();
		//Paso 3
		delete aux;
		setLargo(getLargo() - 1);
	}
}

int colaD::frente()
{
	if (getLargo() == 0)
		return 0;
	else {
		return getpFrente()->getDato();
	}
}

int colaD::dFinal()
{
	if (getLargo() == 0)
		return 0;
	else {
		return getpFinal()->getDato();
	}
}

void colaD::desplegar()
{
	nodoS* aux = getpFrente();  // aux toma el valor de la cabeza
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