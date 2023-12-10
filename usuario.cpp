#include "usuario.h"

usuario::usuario()
{
	this->cedula = 0;
	this->nombre = " ";
	this->apellido = " ";
	this->correo = " ";
	this->telefono = 0;
	this->sgte = NULL;
}

usuario::usuario(bool perfil, int pCedula, string pNombre, string pApellido, string pCorreo, int pTelefono)
{
	this->perfil = perfil;
	this->cedula = pCedula;
	this->nombre = pNombre;
	this->apellido = pApellido;
	this->correo = pCorreo;
	this->telefono = pTelefono;
	this->sgte = NULL;
}

void usuario::setCedula(int pCedula)
{
	this->cedula = pCedula;
}

void usuario::setNombre(string pNombre)
{
	this->nombre = pNombre;
}

void usuario::setApellido(string pApellido)
{
	this->apellido = pApellido;
}

void usuario::setCorreo(string pCorreo)
{
	this->correo = pCorreo;
}

void usuario::setTelefono(int pTelefono)
{
	this->telefono = pTelefono;
}

void usuario::setSgte(usuario* ptr)
{
	this->sgte = ptr;
}

int usuario::getCedula()
{
	return this->cedula;
}

string usuario::getNombre()
{
	return this->nombre;
}

string usuario::getApellido()
{
	return this->apellido;
}

string usuario::getCorreo()
{
	return this->correo;
}

int usuario::getTelefono()
{
	return this->telefono;
}

usuario* usuario::getSgte()
{
	return this->sgte;
}