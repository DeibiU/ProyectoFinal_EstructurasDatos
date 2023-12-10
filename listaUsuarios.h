#pragma once

#include "usuario.h"
class listaUsuarios
{
private:
	usuario* cab;
	int largo;

public:
	listaUsuarios();
	~listaUsuarios();

	usuario* getCab();
	int getLargo();

	void setCab(usuario*);
	void setLargo(int);

	/*UTILITARIOS */
	bool esVacia();
	usuario* dirUsuario(int);
	usuario* dirAnterior(int);
	usuario* dirUltimo();




	void agregarInicio(bool, int, string, string, string, int);
	void agregarFinal(bool, int, string, string, string, int);
	bool agregarAntesDe(bool, int, string, string, string, int, int);
	bool agregarDespuesDe(bool, int, string, string, string, int, int);

	bool eliminar(int);

	void eliminarTodos();

	void eliminarTodos(int dato);

	void desplegar();
};

