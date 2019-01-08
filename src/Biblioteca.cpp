#include "Biblioteca.h"
#include <string>
#include "Titulo.h"

void Biblioteca::adicionaTitulo(Titulo * T) {
	for (size_t i = 0; i < titulos.size(); i++) {
		if (titulos[i]->getNome() == T->getNome() && titulos[i]->getNome() == T->getNome()) {
			throw TituloJaAdicionado("Jogo ja adicionado");
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


