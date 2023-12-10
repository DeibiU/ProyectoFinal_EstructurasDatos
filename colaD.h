#pragma once
#include "nodoS.h"

class colaD
{
private:
	nodoS* pFrente;
	nodoS* pFinal;
	int largo;

	nodoS* getpFrente();
	void setpFrente(nodoS*);

	nodoS* getpFinal();
	void setpFinal(nodoS*);

	int getLargo();
	void setLargo(int);

public:
	colaD();
	~colaD();

	void encolar(int);
	int desencolar();
	int frente();
	int dFinal();
	void desplegar();
	int largoC();
};

