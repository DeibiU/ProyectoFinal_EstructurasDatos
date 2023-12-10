#pragma once
#include "nodoD.h"

class listaDobleCircular
{
private:
	nodoD* cab;
	int largo;

public:
	listaDobleCircular();
	~listaDobleCircular();

	nodoD* getCab();
	int getLargo();

	void setCab(nodoD*);
	void setLargo(int);

	/*UTILITARIOS */
	bool esVacia();
	nodoD* dirNodo(int);
	nodoD* dirAnterior(int);
	nodoD* dirSiguiente(int);
	nodoD* dirUltimo();




	void agregarInicio(int);
	void agregarFinal(int);
	bool agregarAntesDe(int, int);
	bool agregarDespuesDe(int, int);
	bool agregarAscendente(int);
	bool agregarOrdenadoDescendente(int dato); /*Agrega en forma ordenada descendente el dato en la lista, considerar que no se realizan
	inserciones de datos repetidos.Devuelve true si lo agreg� exitosamente.*/

	bool completarSecuencia();/*Considere una lista ordenada ascendentemente, modifique la lista para que incluya los
		valores que hacen falta para completar la secuencia iniciando con el primer valor de la lista y finalizando con el
		�ltimo valor de la lista.Ejemplo Si la lista es igual a 4 - 7 - 10. Deber� modificar la lista para que la lista sea igual a 4 - 5 - 6 -
		7 - 8 - 9 - 10. Es decir se agregaron los valores 5, 6, 8, 9. Esto se debe realizar en un O(n) y es modificadora.*/

	bool eliminar(int);

	void eliminarTodos();

	void eliminarTodos(int dato); //Elimina de la lista todos los elementos iguales a dato. Esto se debe realizar en un O(n)	y es modificadora.

	int cantpares();

	void desplegar();

	void eliminarRepetidosConsecutivos();/*Elimina de la lista los elementos repetidos.Considere que la lista no est�
		ordenada, pero s� los mismos valores est�n consecutivos.Esto se debe realizar en un O(n) y es modificadora.Ejemplo
		si la lista es igual a 30 - 12 - 12 - 12 - 5 - 5 - 5 el resultado ser�a 30 - 12 - 5*/
};

