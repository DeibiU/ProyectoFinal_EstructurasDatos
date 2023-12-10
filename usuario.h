#pragma once
#include <iostream>
#include <string>
using namespace std;

class usuario
{
private:
	bool perfil; // si es 1 es admin, si es 0 es cliente
	int cedula;
	string nombre;
	string apellido;
	string correo;
	int telefono;
	usuario* sgte;
public:
	usuario();
	usuario(bool, int, string, string, string, int);

	bool setPerfil();
	void setCedula(int);
	void setNombre(string);
	void setApellido(string);
	void setCorreo(string);
	void setTelefono(int);
	void setSgte(usuario*);
	bool getPerfil();
	int getCedula();
	string getNombre();
	string getApellido();
	string getCorreo();
	int getTelefono();
	usuario* getSgte();
};

