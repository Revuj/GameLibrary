#include "Biblioteca.h"
#include <string>

void Biblioteca::adicionaTitulo(Titulo * T) {
	for (size_t i = 0; i < titulos.size(); i++) {
		if (*titulos[i] == *T) {
			throw TituloJaAdicionado("Game already exist");
		}
	}
	titulos.push_back(T);
}

std::vector<Titulo*> Biblioteca::getTitulos() const
{
	return titulos;
}

bool Biblioteca::operator==(const Biblioteca B)
{
	return this->titulos==B.titulos;
}


