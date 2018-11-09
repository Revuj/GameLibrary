#include "Biblioteca.h"
#include <algorithm>
#include "Titulo.h"

void Biblioteca::adicionaTitulo(Titulo * T,const std::vector<std::string>& plataforma) {
	if(titulos.find(T)==titulos.end())
		titulos[T]=plataforma;
	else {
		std::vector<std::string> p=titulos[T];
		p.insert(plataforma.end(),plataforma.begin(),plataforma.end());
		std::sort(p.begin(), p.end());
		p.erase(std::unique(p.begin(), p.end()), p.end());
		titulos[T]=p;
	}
}

std::vector<Titulo*> Biblioteca::getTitulos() const
{
	std::vector<Titulo*> games;
	for (auto& titulo : titulos)
		games.push_back(titulo.first);
	return games;
}

std::vector<std::string> Biblioteca::getPlataformas() const{
	std::vector<std::string> plataforma;
	for (auto& titulo : titulos)
		plataforma.insert(plataforma.end(),titulo.second.begin(),titulo.second.end());
	return plataforma;
}

std::map<Titulo*,std::vector<std::string>> Biblioteca::getBiblioteca() const
{
	return this->titulos;
}

bool Biblioteca::operator==(const Biblioteca B)
{
	return this->titulos==B.titulos;
}

float Biblioteca::custoTotal() const
{
    float custoTotal=0;

    for(const auto & titulopair : this->titulos)
        custoTotal += titulopair.first->getGastos(titulopair.second);

    return custoTotal;
}



