#include "Apunte.h"

Apunte::Apunte(string Titulo, string contenido, string fecha)
{
	this->Titulo = Titulo;
	this->contenido = contenido;
	this->fecha = fecha;
}

void Apunte::settitulo(string titulo)
{
	this->Titulo = titulo;
}

void Apunte::setcontenido(string contenido)
{
	this->contenido = contenido;
}

void Apunte::setfecha(string fecha)
{
	this->fecha = fecha;
}

string Apunte::gettitulo()
{
	return this->Titulo;
}

string Apunte::getcontenido()
{
	return this->contenido;
}

string Apunte::getfecha()
{
	return this->fecha;
}
