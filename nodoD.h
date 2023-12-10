#pragma once
class nodoD
{
private:
	int dato;
	nodoD* sgte;
	nodoD* ante;

public:
	nodoD();
	nodoD(int);
	~nodoD();

	int getDato();
	nodoD* getSgte();
	nodoD* getAnte();

	void setDato(int);
	void setSgte(nodoD*);
	void setAnte(nodoD*);

};

