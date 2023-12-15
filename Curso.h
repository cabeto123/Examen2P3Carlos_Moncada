#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Apunte.h"
using namespace std;
class Curso
{
	private:
		string nombre;
		vector <Apunte*> apuntes;
	public:
		Curso();
		Curso(string nombre);
		void setnombre(string nombre);
		void anadirapunte(Apunte* a);
		void eliminarapunte(int indice);
		Apunte* getapunte(int indice);
		string getnombre();
		int tamvector();
		void combinarDosApuntes(int posicion);
		vector <Apunte*> getvectorapuntes();
		void escribirarchivo(ofstream archivo);
		void leerarchivo(ifstream archivo);
};

