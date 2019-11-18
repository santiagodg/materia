
#ifndef GRUPO_H
#define GRUPO_H

#include <iostream>
#include <string>
#include "Materia.h"
using namespace std;

class Grupo
{
	private:
		// Atributos
		Materia materia;
		string sSalon, sProfesor;

	public:
		// Constructor
		Grupo(Materia, string, string);

		// Getters
		Materia getMateria();
		string getSalon();
		string getProfesor();

		// Setters
		void setMateria(Materia);
		void setSalon(string);
		void setProfesor(string);

		// Métodos
		void toString();
};

Grupo::Grupo(Materia mat, string sS, string sP)
{
	materia = mat;
	sSalon = sS;
	sProfesor = sP;
}

Materia Grupo::getMateria()
{
	return materia;
}

string Grupo::getSalon()
{
	return sSalon;
}

string Grupo::getProfesor()
{
	return sProfesor;
}

void Grupo::setMateria(Materia mat)
{
	materia = mat;
}

void Grupo::setSalon(string sS)
{
	sSalon = sS;
}

void Grupo::setProfesor(string sP)
{
	sProfesor = sP;
}

void Grupo::toString()
{
	materia.toString();
	cout << "Profesor titular: " << sProfesor << endl;
	cout << "Salon: " << sSalon << endl;
}

#endif