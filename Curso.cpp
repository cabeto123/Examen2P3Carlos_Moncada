#include "Curso.h"

Curso::Curso(string nombre)
{
	this->nombre = nombre;
}

void Curso::setnombre(string nombre)
{
	this->nombre = nombre;
}

void Curso::anadirapunte(Apunte* a)
{
	apuntes.push_back(a);
}

Apunte* Curso::getapunte(int indice)
{
	return apuntes[indice];
}

string Curso::getnombre()
{
	return this->nombre;
}

void Curso::combinarDosApuntes()
{
}
