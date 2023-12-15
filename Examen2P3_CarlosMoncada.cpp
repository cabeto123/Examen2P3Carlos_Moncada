#include <iostream>
#include "Apunte.h"
#include "Curso.h"
using namespace std;
vector<Curso*> cursos;
int menu() {
	int opcion = 0;
	cout << "  ---MENU---\n1-Operaciones Curso\n2-Operaciones Apuntes \n3-Guardar Archivo\n4-Cargar archivo\n\nIngrese la Opcion: " ;
	cin >> opcion;
	while (opcion<1||opcion>4) {
		cout << endl<<"Valor fuera de rango"<<endl;
		cout << "  ---MENU---\n1-Operaciones Curso\n2-Operaciones Apuntes \n3-Guardar Archivo\n4-Cargar archivo\n\nIngrese la Opcion: ";
		cin >> opcion;
	}
	return opcion;
}
int submenu() {
	int opcion = 0;
	cout << " ---MENU---" << endl;
	cout << "1-Crear Curso\n2-Listar Cursos \n3-Eliminar Curso\n\nIngrese la Opcion: ";
	cin >> opcion;
	while (opcion < 1 || opcion>4) {
		cout << endl << "Valor fuera de rango" << endl;
		cout << " ---MENU---" << endl;
		cout << "1-Crear Curso\n2-Listar Cursos \n3-Eliminar Curso\n\nIngrese la Opcion: ";
		cin >> opcion;
	}
	return opcion;

}
void listarcursos() {

	for (int i = 0; i < cursos.size(); i++)
	{
		cout << i << "." << cursos[i]->getnombre() << endl;
	}
}
void operacionescurso() {
	//variables
	string nombredelcurso;
	string Titulo;
	string contenido;
	string fecha;
	int indice = 0;

	int submenusillo = submenu();
	switch (submenusillo)
	{
	case 1:	cout <<endl<< "---CREAR CURSO---" << endl;
			cout << "Digite el nombre del curso: ";
			cin >> nombredelcurso;
			cursos.push_back(new Curso(nombredelcurso));
			cout <<endl<< "Curso creado exitosamente"<<endl;
			break;
	case 2:
		if (cursos.size()>0)
	    {
			listarcursos();
		}
		else {
			cout << "No hay cursos en el vector";
		}
		
		break;
	case 3:
		if (cursos.size() > 0)
		{
			listarcursos();
			cout << endl << endl << "Digite el indice de el curso a eliminar: ";
			cin >> indice;
			while (indice<0||indice>cursos.size() - 1) {
				cout <<endl<< "Valor fuera de rango" << endl;
				cout  << "Digite el indice de el curso a eliminar: ";
				cin >> indice;
			}
			cursos.erase(cursos.begin() + indice);
		}
		else {
			cout << "No hay cursos en el vector";
		}



	default:
		cout << endl << "Valor fuera de rango " << endl;
	}
	



}
int main()
{
	int opcion = 3;
	while (opcion!=4) {
		opcion = menu();
		if (opcion==1)
		{
			operacionescurso();
		}


	}
}
