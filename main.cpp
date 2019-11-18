
#include <iostream>
#include "Materia.h"
#include "Grupo.h"
using namespace std;

int main()
{
	// 1. Dar de alta 1 materia
	// 2. Dar de alta 1 grupo

	// MENU
	// a) Imprimir datos del grupo
	// b) Imprimir únicamente datos de materia del grupo
	// c) Dar de alta un profesor
	// d) Ordena lista profesores y muestra la lista ordenada
	// e) Cambiar materia en el grupo
	// e) Terminar

	string sNombreMateria, sDepartamento, sSalon, sProfesor;
	string * sPtrListaProfesores;
	int iClave;
	char cOpcion;

	cout << "REGISTRO DE MATERIA" << endl;
	cout << "Ingrese el nombre de la materia: ";
	cin >> sNombreMateria;
	cout << "Ingrese la clave: ";
	cin >> iClave;
	cout << "Ingrese el departamento: ";
	cin >> sDepartamento;

	cout << "REGISTRO DE GRUPO" << endl;
	cout << "Ingrese el profesor: ";
	cin >> sProfesor;
	cout << "Ingrese el salón: ";
	cin >> sSalon;

	Materia m(sNombreMateria, iClave, sDepartamento);
	Grupo g(m, sSalon, sProfesor);
	m = g.getMateria();
	m.agregaProfesor(sProfesor);
	g.setMateria(m);

	cOpcion = ' ';
	while (cOpcion != 'f')
	{
		cout << "MENU" << endl;
		cout << "a) Imprimir datos del grupo" << endl;
		cout << "b) Imprimir únicamente datos de materia del grupo" << endl;
		cout << "c) Dar de alta un profesor" << endl;
		cout << "d) Ordena lista profesores "
			 << "y muestra la lista ordenada" << endl;
		cout << "e) Cambiar materia en el grupo" << endl;
		cout << "f) Terminar" << endl;
		cout << "Ingrese una opcion: ";
		cin >> cOpcion;

		switch (cOpcion)
		{
			case 'a':
				g.toString();
				break;

			case 'b':
				g.getMateria().toString();
				break;

			case 'c':
				cout << "Ingrese el profesor: ";
				cin >> sProfesor;
				m = g.getMateria();
				if (m.agregaProfesor(sProfesor))
				{
					cout << "Se agrego al profesor con exito." << endl;
					g.setMateria(m);
				}
				else
				{
					cout << "Hubo un error agregando al profesor." << endl;
				}
				break;

			case 'd':
				m = g.getMateria();
				m.ordenaListaProfesores();
				g.setMateria(m);
				sPtrListaProfesores = m.getListaProfesores();
				for (int iX = 0; iX < m.getNumProfesores(); iX++)
				{
					cout << *(sPtrListaProfesores + iX) << endl;
				}
				break;

			case 'e':
				cout << "Ingrese el nombre de la materia: ";
				cin >> sNombreMateria;
				cout << "Ingrese la clave: ";
				cin >> iClave;
				cout << "Ingrese el departamento: ";
				cin >> sDepartamento;

				m.setNombre(sNombreMateria);
				m.setClave(iClave);
				m.setDepartamento(sDepartamento);
				g.setMateria(m);
				break;

			case 'f':
				break;

			default:
				cout << "Opcion invalida.";
				cout << "Ingrese una opcion (a-f): ";
				cin >> cOpcion;
			break;
		}
	}

	return 0;
}