#pragma once

#include "nodoS.h"
class listaSimple
{
private:
	nodoS* cab;
	int largo;

public:
	listaSimple();
	~listaSimple();

	nodoS* getCab();
	int getLargo();

	void setCab(nodoS*);
	void setLargo(int);

	/*UTILITARIOS */
	bool esVacia();
	nodoS* dirNodo(int);
	nodoS* dirAnterior(int);
	nodoS* dirUltimo();




	void agregarInicio(int);
	void agregarFinal(int);//Laboratorio #1
	bool agregarAntesDe(int, int);
	bool agregarDespuesDe(int, int);//Laboratorio #1
	bool agregarAscendente(int);
	bool agregarDescendente(int); //Laboratorio #1
	bool completarSecuencia();

	bool eliminar(int);

	void eliminarTodos();

	int cantpares();

	void eliminarTodos(int dato);

	void desplegar();

	void eliminarRepetidosConsecutivos();

};

