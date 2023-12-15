#include <iostream>
#include <fstream>
#include "Apunte.h"

#include "Curso.h"

using namespace std;
vector < Curso* > cursos;
int menu() {
    int opcion = 0;
    cout << "  ---MENU---\n1-Operaciones Curso\n2-Operaciones Apuntes \n3-Guardar Archivo\n4-Cargar archivo\n5-Salir\n\nIngrese la Opcion: ";
    cin >> opcion;
    while (opcion < 1 || opcion > 5) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << "  ---MENU---\n1-Operaciones Curso\n2-Operaciones Apuntes \n3-Guardar Archivo\n4-Cargar archivo\n5-sALIR\n\nIngrese la Opcion: ";
        cin >> opcion;
    }
    return opcion;
}
int submenu() {
    int opcion = 0;
    cout << " ---MENU---" << endl;
    cout << "1-Crear Curso\n2-Listar Cursos \n3-Eliminar Curso\n4-Salir\n\nIngrese la Opcion: ";
    cin >> opcion;
    while (opcion < 1 || opcion > 4) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << " ---MENU---" << endl;
        cout << "1-Crear Curso\n2-Listar Cursos \n3-Eliminar Curso\n4-Salir\n\nIngrese la Opcion: ";
        cin >> opcion;
    }
    return opcion;

}
int submenuapuntes() {

    int opcion = 0;
    cout << " ---MENU APUNTES---" << endl;
    cout << "1-Crear Apuntes\n2-Listar Apuntes \n3-Eliminar Apuntes\n4-Combinar Apuntes\n5.Salir\n\nIngrese la Opcion: ";
    cin >> opcion;
    while (opcion < 1 || opcion > 5) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << " ---MENU---" << endl;
        cout << "1-Crear Apuntes\n2-Listar Apuntes \n3-Eliminar Apuntes\n4-Combinar Apuntes\n5.Salir\n\nIngrese la Opcion: ";
        cin >> opcion;
    }
    return opcion;

}
void listarcursos() {

    for (int i = 0; i < cursos.size(); i++) {
        cout << i << "." << cursos[i]->getnombre() << endl;
    }
}
void operacionescurso() {
    //variables
    string nombredelcurso;

    int indice = 0;

    int submenusillo = submenu();
    while (submenusillo != 4) {
        switch (submenusillo) {
        case 1:
            cout << endl << "---CREAR CURSO---" << endl;
            cout << "Digite el nombre del curso: ";
            cin.ignore();
            getline(cin, nombredelcurso);
            cursos.push_back(new Curso(nombredelcurso));
            cout << endl << "Curso creado exitosamente" << endl;
            break;
        case 2:
            if (cursos.size() > 0) {
                listarcursos();
                cout << endl;
            }
            else {
                cout << "No hay cursos en el vector";
            }

            break;
        case 3:
            if (cursos.size() > 0) {
                listarcursos();
                cout << endl << endl << "Digite el indice de el curso a eliminar: ";
                cin >> indice;
                while (indice < 0 || indice > cursos.size() - 1) {
                    cout << endl << "Valor fuera de rango" << endl;
                    cout << "Digite el indice de el curso a eliminar: ";
                    cin >> indice;
                }
                cursos.erase(cursos.begin() + indice);
                cout << endl << "Curso eliminado exitosamente" << endl;
            }
            else {
                cout << "No hay cursos en el vector";
            }

            break;

        default:
            cout << endl << "Valor fuera de rango " << endl;
        }

        submenusillo = submenu();
    }

}
void listarapuntes() {
    cout <<endl<< "Cursos guardados" << endl;
    listarcursos();
    cout << endl<<"Ingrese la posicion del curso para poder listar los apuntes :";
    int posicion = 0;
    cin >> posicion;
    while (posicion<0||posicion>cursos.size()-1) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << endl << "Ingrese la posicion del curso para poder listar los apuntes :";
        cin >> posicion;
    }
    if (cursos[posicion]->tamvector()>0)
    {
        cout << "Apuntes guardados en el curso " << cursos[posicion]->getnombre() << endl;
        for (int i = 0; i < cursos[posicion]->tamvector(); i++)
        {
            cout << "Posicion " << i<<endl;
            cout << cursos[posicion]->getapunte(i)->tostring() << endl;;
        }
    }
    else {

        cout <<endl<< "El curso no tiene apuntes" << endl;
    }
    

}
void eliminarapuntes() {
    int posicionapuntes = 0;
    cout << endl << "Cursos guardados" << endl;
    listarcursos();
    cout << endl << "Ingrese la posicion del curso para poder listar los apuntes :";
    int posicion = 0;
    cin >> posicion;
    while (posicion<0 || posicion>cursos.size() - 1) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << endl << "Ingrese la posicion del curso para poder listar los apuntes :";
        cin >> posicion;
    }
    cout << "Apuntes guardados en el curso " << cursos[posicion]->getnombre() << endl;
    if (cursos[posicion]->tamvector()>0)
    {
        for (int i = 0; i < cursos[posicion]->tamvector(); i++)
        {
            cout << i << "." << cursos[posicion]->getapunte(i)->tostring() << endl;;
        }
        cout << endl << "Digite la posicion del apunte a eliminar: ";
        cin >> posicionapuntes;
        while (posicionapuntes<0 || posicionapuntes>cursos[posicion]->tamvector() - 1) {
            cout << endl << "Valor fuera de rango" << endl;
            cout << endl << "Digite la posicion del apunte a eliminar: ";
            cin >> posicionapuntes;
        }
        cursos[posicion]->eliminarapunte(posicionapuntes);
        cout << endl << "Apunte eliminado exitosamente" << endl;
    }
    else {

        cout << endl << "El curso no tiene apuntes" << endl;
    }
    
    
}
void combinarapuntes() {
    int posicion = 0;
    cout << "Cursos guardados " << endl;
    listarcursos();
    cout << endl << "Selecciona el curso(posicion): ";
    cin >> posicion;
    while (posicion<0||posicion>cursos.size()-1) {
        cout << endl << "Valor fuera de rango" << endl;
        cout << "Selecciona el curso(posicion): ";
        cin >> posicion;
    }
    int tam = cursos[posicion]->tamvector() ;
    
    if (tam>0)
    {
        cursos[posicion]->combinarDosApuntes(posicion);
        
    }
    else {
        cout << "No se puede combinar pq no tiene apuntes" << endl;

    }

}
void operacionesdeapuntes() {
    int submenus = submenuapuntes();
    int indice = 0;
    //variables
    string Titulo;
    string contenido;
    string fecha;
    while (submenus != 5) {
        switch (submenus) {
        case 1:
            if (cursos.size() > 0) {
                listarcursos();
                cout << endl << endl << "Ingrese la posicion del curso para agregar el apunte: ";
                cin >> indice;
                while (indice < 0 || indice > cursos.size() - 1) {
                    cout << endl << "Valor fuera de rango" << endl;
                    cout << endl << "Ingrese la posicion del curso para agregar el apunte: ";
                    cin >> indice;
                }
                cin.ignore();
                cout << endl << "Ingrese el titulo del apunte: ";
                getline(cin, Titulo);
                cout << endl << "Ingrese el contenido del apunte: ";
                getline(cin, contenido);
                cout << endl << "Ingrese la fecha del apunte: ";
                getline(cin, fecha);
                cursos[indice]->anadirapunte(new Apunte(Titulo, contenido, fecha));
                cout << endl << "Apunte guardado exitosamente" << endl;
            }
            else {
                cout << "No hay cursos en el vector";
            }
            break;
        case 2:
            if (cursos.size()>0)
            {
                listarapuntes();
            }
            else {
                cout << "No hay cursos disponibles" << endl;
            }
            break;
        case 3:
            if (cursos.size()>0)
            {
                eliminarapuntes();
            }
            else {
                cout << "No hay cursos disponibles" << endl;

            }
            break;
        case 4:
            if (cursos.size() >0)
            {
                combinarapuntes();
            }
            else {
                cout << "No hay suficientes cursos disponibles" << endl;

            }
            break;
        case 5:
            break;
        default:
            cout << "Valor fuera de rango" << endl;
            break;
        }
        submenus = submenuapuntes();
    }

}
void guardararchivo() {
    ofstream archivo("archivo.bin", ios::binary|ios::out);
    if (archivo.fail())
    {
        cout <<endl<< "Error al abrir el archivo " << endl;
    }
    else {
        for (size_t i = 0; i < cursos.size(); i++)
        {
            archivo.write((char*)(cursos[i]), sizeof(Curso));
        }
    }



}
void leerarchivo() {
    

}
int main() {
    int opcion = 3;
    while (opcion != 5) {
        opcion = menu();
        if (opcion == 1) {
            operacionescurso();
        }
        if (opcion == 2) {
            operacionesdeapuntes();
        }
        if (opcion==3)
        {
            guardararchivo();
        }
        if (opcion==4)
        {
            leerarchivo();
        }
    }
    for (int i = 0; i < cursos.size(); i++)
    {
        delete cursos[i];
    }
}