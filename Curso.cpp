#include "Curso.h"
#include <iostream>
#include <string>
using namespace std;
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

void Curso::eliminarapunte(int indice)
{
	apuntes.erase(apuntes.begin() + indice);
}

Apunte* Curso::getapunte(int indice)
{
	return apuntes[indice];
}

string Curso::getnombre()
{
	return this->nombre;
}

int Curso::tamvector()
{
	return apuntes.size();
}

void Curso::combinarDosApuntes(int posicion)
{
    for (int i = 0; i < apuntes.size(); i++)
    {
        cout << i << " " << apuntes[i]->tostring() << endl;
    }
    int primerapunte = 0;
    int segundoapunte = 0;
    cout << endl << "Selecciona el primer apunte: ";
    cin >> primerapunte;
    while (primerapunte<0 || primerapunte>apuntes.size() - 1) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << "Selecciona el primer apunte: ";
        cin >> primerapunte;
    }
    cout << endl << "Selecciona el segundo apunte: ";
    cin >> segundoapunte;
    while (segundoapunte<0 || segundoapunte>apuntes.size() - 1) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << "Selecciona el segundo apunte: ";
        cin >> segundoapunte;
    }
    string tituloo =apuntes[primerapunte]->gettitulo() + " + " + apuntes[segundoapunte]->gettitulo();
    string contenidpo = apuntes[primerapunte]->getcontenido() + " + " + apuntes[segundoapunte]->getcontenido();
    string nuevafecha = "";
    cin.ignore();
    cout <<endl<< "Digite la nueva fecha ";
    getline(cin, nuevafecha);
    if (segundoapunte==0)
    {
        apuntes.erase(apuntes.begin() + segundoapunte);
        apuntes.erase(apuntes.begin() + (primerapunte-1));
    }
    else if (primerapunte==0)
    {

        apuntes.erase(apuntes.begin() + primerapunte);
        apuntes.erase(apuntes.begin() + (segundoapunte - 1));
    }
    else {
        apuntes.erase(apuntes.begin() + (segundoapunte ));
        apuntes.erase(apuntes.begin() + (primerapunte-1));
    }
    apuntes.push_back(new Apunte(tituloo, contenidpo, nuevafecha));

}


