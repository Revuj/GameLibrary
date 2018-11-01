#include "Biblioteca.h"


void Biblioteca::adicionaTitulo(Titulo * T) {
	titulos.push_back(T);
}

std::vector<Titulo*> Biblioteca::getTitulos() const
{
	return this->titulos;
}


bool Biblioteca::operator==(const Biblioteca B)
{
	return this->titulos==B.titulos;
}





