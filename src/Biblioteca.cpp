#include "Biblioteca.h"

void Biblioteca::adiciona_titulo(Titulo *T) {
	titulos.push_back(T);
}

bool Biblioteca::operator==(const Biblioteca B) {
	return this->titulos == B.titulos;
}

