#pragma once
#include <string>
#include <vector>
#include "Apunte.h"
using namespace std;
class Curso
{
	private:
		string nombre;
		vector <Apunte*> apuntes;
	public:
		Curso(string nombre);
		void setnombre(string nombre);
		void anadirapunte(Apunte* a);
		void eliminarapunte(int indice);
		Apunte* getapunte(int indice);
		string getnombre();
		int tamvector();
		void combinarDosApuntes(int posicion);
};

