
#ifndef MATERIA_H
#define MATERIA_H

#include <iostream>
#include <string>
using namespace std;

class Materia
{
	private:
		// Atributos
		string sNombre, sDepartamento;
		int iClave, iNumProfesores;
		string sListaProfesores[20];

	public:
		// Constructor
		Materia();
		Materia(string, int, string);

		// Getters
		string getNombre();
		int getClave();
		string getDepartamento();
		string * getListaProfesores();
		int getNumProfesores();

		// Setters
		void setNombre(string);
		void setClave(int);
		void setDepartamento(string);

		// Métodos
		void toString();
		bool agregaProfesor(string);
		void ordenaListaProfesores();
};

Materia::Materia()
{
	sNombre = "N/A";
	iClave = 0;
	sDepartamento = "N/A";
	iNumProfesores = 0;
}

Materia::Materia(string sN, int iC, string sD)
{
	sNombre = sN;
	iClave = iC;
	sDepartamento = sD;
	iNumProfesores = 0;
}

string Materia::getNombre()
{
	return sNombre;
}

int Materia::getClave()
{
	return iClave;
}

string Materia::getDepartamento()
{
	return sDepartamento;
}

string * Materia::getListaProfesores()
{
	return sListaProfesores;
}

int Materia::getNumProfesores()
{
	return iNumProfesores;
}

void Materia::setNombre(string sN)
{
	sNombre = sN;
}

void Materia::setClave(int iC)
{
	iClave = iC;
}

void Materia::setDepartamento(string sD)
{
	sDepartamento = sD;
}

void Materia::toString()
{
	cout << "Nombre: " << sNombre << endl;
	cout << "Clave: " << iClave << endl;
	cout << "Departamento: " << sDepartamento << endl;
	cout << "Numero de profesores: " << iNumProfesores << endl;
	for (int iX = 0; iX < iNumProfesores; iX++)
	{
		cout << sListaProfesores[iX] << endl;
	}

}

bool Materia::agregaProfesor(string sProfe)
{
	if (iNumProfesores == 20)
	{
		return false;
	}
	else
	{
		sListaProfesores[iNumProfesores] = sProfe;
		iNumProfesores++;
		return true;
	}
}

void Materia::ordenaListaProfesores()
{
	string sMin = "ZZZ";
	string sTemp;
	for (int iX = 0; iX < iNumProfesores; iX++)
	{
		for (int iY = iX; iY < iNumProfesores; iY++)
		{
			if (sListaProfesores[iY] < sListaProfesores[iX])
			{
				sTemp =	sListaProfesores[iX];
				sListaProfesores[iX] = sListaProfesores[iY];
				sListaProfesores[iY] = sTemp;
			}
		}
	}
}

#endif