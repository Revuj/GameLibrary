/*
 * Sistema.cpp
 *
 *  Created on: 21/11/2018
 *      Author: revuj
 */

#include "Sistema.h"
#include <algorithm>

unsigned int Sistema::nrMedioTitulos() {

	unsigned int nrTotalTitulos = 0;

	for (const auto & utilizador : this->jogadores) {
		nrTotalTitulos += utilizador.getBiblioteca().getTitulos().size();
	}

	double media = static_cast<double>(nrTotalTitulos) / this->jogadores.size();

	nrTotalTitulos = media + 0.5;

	return nrTotalTitulos;
}

float Sistema::custoMedioBiblioteca() {

	float custoTotal = 0;

	for (const auto & utilizador : this->jogadores) {
		custoTotal += utilizador.getGastos();
	}

	custoTotal /= this->jogadores.size(); /*cada utilizador tem uma biblioteca*/
	return custoTotal;
}

bool Sistema::validName(const std::string nome) {
	for (const auto & utilizador : this->jogadores) {
		if (utilizador.getNome() == nome)
			return false;
	}

	return true;

}

bool Sistema::validEmail(const std::string email) {
	for (const auto & utilizador : this->jogadores) {
		if (utilizador.getEmail() == email)
			return false;
	}

	return true;

}

void Sistema::addUtilizador() /*a incluir throws*/
{
	std::string nome;
	std::string email;
	std::string EMAILCHAR = "@";
	std::string idade;
	std::string morada;
	std::cout << "Creating a user...  \n";
	std::cout << "Enter a user name: ";
	getline(std::cin, nome);

	std::cout << "Checking if is a valid name... \n";
	if (validName(nome))
		std::cout << "Valid name";
	else
		std::cout << "Invalid Name, try again";

	std::cout << "Enter your email \n";
	getline(std::cin, email);
	if (email.find(EMAILCHAR) == std::string::npos)
		std::cout << "Invalid email it must contain '@' \n";
	if (validEmail(email))
		std::cout << "Email Valid \n";
	else
		std::cout << "Already exists email\n";

	std::cout << "Enter your age ";
	getline(std::cin, idade);
	std::cout << "Enter your address: ";
	getline(std::cin, morada);

	jogadores.push_back(Utilizador(nome, email, stoi(idade), morada));
	//std::sort(jogadores.begin(),jogadores.end(),userNameAscend);

	std::cout
			<< "Do you want to play online or do you prefer to play home? (home/online)?"
			<< std::endl;

}

void displayRank(std::vector<std::string> a)
{

	sort(a.begin(),a.end());
	std::vector<std::string> aux=a;
	unique (aux.begin(), aux.end());
	std::vector<int> co;
    for(size_t i=0;i<aux.size();i++)
    {
        co.push_back(count(a.begin(), a.end(), aux[i]));
    }

    for(size_t i=0;i<aux.size();i++){
		std::cout << i + 1 << ": " << aux.at(distance(co.begin(), max_element(co.begin(), co.end()))-1) << std::endl;
		co.erase(max_element(co.begin(), co.end()));
    }
}


void Sistema::rankingDeGeneros()
{
	std::vector<std::string> generos;

	for (auto const & utilizador : this->jogadores)
	{
		std::vector<Titulo*> titulos = utilizador.getBiblioteca().getTitulos();

		for (auto const & titulo : titulos)
		{
			std::vector<std::string> generosVector = titulo->getGeneros();

			for (auto const & genero : generosVector)
			{
				generos.push_back(genero);
			}
		}
	}

	displayRank(generos);
}

void Sistema::rankingDePlataformas()
{
	std::vector<std::string> plataformas;

	for (auto const & utilizador : this->jogadores)
	{
		plataformas.push_back(utilizador.PlataformaPreferida());
	}

	displayRank(plataformas);
}

void Sistema::rankingDeIdades()
{

	std::vector<std::string> faixasEtarias;

	for (auto const & utilizador : this->jogadores)
	{
		unsigned int idade = utilizador.getIdade();

		if (idade<= 10)
			faixasEtarias.push_back("0-10");
		else if (idade <= 20)
			faixasEtarias.push_back("11-20");
		else if (idade <= 30)
			faixasEtarias.push_back("21-30");
		else if (idade <= 40)
			faixasEtarias.push_back("31-40");
		else
			faixasEtarias.push_back("40+");
	}

	displayRank(faixasEtarias);
}

//void Sistema::rankingDeRentabilidades()
//{
//	map <string, unsigned int> rentabilidade;
//
//	for (auto const & utilizador : utilizadores)
//	{
//		map<Titulo*,vector<string>> titulos = utilizador.getBiblioteca().getBiblioteca();
//
//		for (auto const & titulo : titulos)
//		{
//			rentabilidade[titulo.first->getNome()] += titulo.first->getGastos();
//		}
//	}
//
//	displayRank(rentabilidade);
//}
