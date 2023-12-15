#pragma once
#include <string>
using namespace std;
class Apunte
{
	private:
		string Titulo;
		string contenido;
		string fecha;
	public:
		Apunte(string Titulo, string contenido, string fecha);
		void settitulo(string titulo);
		void setcontenido(string contenido);
		void setfecha(string fecha);
		string gettitulo();
		string getcontenido();
		string getfecha();


};

