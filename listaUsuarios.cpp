#include <stdlib.h>
#include <iostream>

#include "listaUsuarios.h"
using namespace std;

listaUsuarios::listaUsuarios()
{
	this->cab = NULL;
	this->largo = 0;
}

listaUsuarios::~listaUsuarios()
{
}

usuario* listaUsuarios::getCab()
{
	return this->cab;
}

int listaUsuarios::getLargo()
{
	return this->largo;
}

void listaUsuarios::setCab(usuario* ptr)
{
	this->cab = ptr;
}

void listaUsuarios::setLargo(int n)
{
	this->largo = n;
}

bool listaUsuarios::esVacia()
{
	return this->getLargo() == 0;
}

usuario* listaUsuarios::dirUsuario(int pCedula)
{
	usuario* aux = getCab();
	while ((aux != NULL) && (aux->getCedula() != pCedula)) {
		aux = aux->getSgte();
	}
	return aux;
}

usuario* listaUsuarios::dirAnterior(int pnum)
{
	usuario* ant = NULL;

	if (!esVacia()) {
		ant = getCab();

		while ((ant != NULL) && (ant->getSgte() != NULL)) {

			if (ant->getSgte()->getCedula() == pnum) {
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

usuario* listaUsuarios::dirUltimo()
{
	usuario* aux = getCab();

	while (aux != NULL && aux->getSgte() != NULL) {
		aux = aux->getSgte();
	}
	return aux;
}

void listaUsuarios::desplegar()
{
	usuario* aux = getCab();
	if (aux == NULL) {
		cout << "AUN NO HAY USUARIOS..." << endl;
	}
	else {
		cout << "USUARIOS EN LA LISTA:" << endl;
		cout << "-----Administradores-----" << endl;
		while (aux != NULL) {
			if (aux->getPerfil()) {
				cout << aux->getCedula() << " - " << aux->getNombre() << " " << aux->getApellido() << std::endl;
				aux = aux->getSgte();
			}
			else {
				aux = aux->getSgte();
			}
		}
		cout << "-----Clientes-----" << endl;
		while (aux != NULL) {
			if (!aux->getPerfil()) {
				cout << aux->getCedula() << " - " << aux->getNombre() << " " << aux->getApellido() << std::endl;
				aux = aux->getSgte();
			}
			else {
				aux = aux->getSgte();
			}
		}
		cout << "//";
	}

}

void listaUsuarios::agregarInicio(bool perfil, int pCedula, string pNombre, string pApellido, string pCorreo, int pTelefono)
{
	usuario* nuevo = new usuario(perfil, pCedula, pNombre, pApellido, pCorreo, pTelefono);
	nuevo->setSgte(getCab());
	setCab(nuevo);
	largo++;
}

void listaUsuarios::agregarFinal(bool perfil, int pCedula, string pNombre, string pApellido, string pCorreo, int pTelefono)
{
	usuario* nuevo = new usuario(perfil, pCedula, pNombre, pApellido, pCorreo, pTelefono);
	usuario* ultimo = dirUltimo();
	ultimo->setSgte(nuevo);
	largo++;
}

bool listaUsuarios::agregarAntesDe(bool perfil, int pCedula, string pNombre, string pApellido, string pCorreo, int pTelefono, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		if (getCab()->getCedula() == ref) {
			agregarInicio(perfil, pCedula, pNombre, pApellido, pCorreo, pTelefono);
			agregado = true;
		}
		else {
			usuario* ant = dirAnterior(ref);
			if (ant != NULL) {
				usuario* nuevo = new usuario(perfil, pCedula, pNombre, pApellido, pCorreo, pTelefono);
				nuevo->setSgte(ant->getSgte());
				ant->setSgte(nuevo);
				largo++;
				agregado = true;
			}
		}

	}
	return agregado;
}

bool listaUsuarios::agregarDespuesDe(bool perfil, int pCedula, string pNombre, string pApellido, string pCorreo, int pTelefono, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		usuario* ant = dirUsuario(ref);
		if (ant != NULL) {
			usuario* nuevo = new usuario(perfil, pCedula, pNombre, pApellido, pCorreo, pTelefono);
			nuevo->setSgte(ant->getSgte());
			ant->setSgte(nuevo);
			largo++;
			agregado = true;
		}
	}
	return agregado;
	;
}

bool listaUsuarios::eliminar(int pCedula)
{
	bool eliminado = false;
	if (!esVacia()) {

		usuario* aux;
		if (getCab()->getCedula() == pCedula) {
			aux = getCab();
			setCab(aux->getSgte());
			setLargo(getLargo() - 1);
			delete aux;
			eliminado = true;
		}
		else {
			usuario* ant = dirAnterior(pCedula);
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

void listaUsuarios::eliminarTodos()
{
	usuario* aux = getCab();
	while (aux != NULL) {
		setCab(getCab()->getSgte());
		delete aux;
		aux = getCab();
	}
	setLargo(0);
}

void listaUsuarios::eliminarTodos(int pCedula) {
	usuario* actual = cab;
	usuario* anterior = nullptr;

	while (actual != nullptr) {
		if (actual->getCedula() == pCedula) {
			if (anterior == nullptr) {
				cab = actual->getSgte();
				delete actual;
				actual = cab;
			}
			else {
				usuario* temp = actual->getSgte();
				anterior->setSgte(temp); // Asigna el siguiente nodo
				delete actual;
				actual = temp;
			}
		}
		else {
			anterior = actual;
			actual = actual->getSgte();
		}
	}
}