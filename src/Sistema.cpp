/*
 * Sistema.cpp
 *
 *  Created on: 21/11/2018
 *      Author: revuj
 */

#include "Sistema.h"
#include "Utilizador.h"
#include <algorithm>
#include <utility>
#include <iostream>


void Sistema::readFile(std::ifstream & f) {
	std::string nome, mail, idade, localidade, titulo;
	std::stringstream tituloSs;

	getline(f, nome);
	getline(f, mail);
	getline(f, localidade);

	Biblioteca B;
	while (!f.eof())
	{
		std::string tipoDeJogo;
		std::string nomeDoJogo;
		std::string idadeMinimaStr;
		std::string plataforma;
		std::string precoStr;
		std::string genero;
		std::string empresa;
		std::string dataStr;
		std::string genero;
		std::vector<std::string> generos;
		std::string subscricao;
		std::string precoSubsStr;

		getline(f, titulo);

		tituloSs << titulo;

		tituloSs >> tipoDeJogo >> nomeDoJogo >> idadeMinimaStr >> plataforma >> precoStr >> genero >> empresa >> dataStr;

		unsigned int idadeMinima = std::stoul(idadeMinimaStr);
		float preco = std::stof(precoStr);

		Data d(dataStr);

		if (tipoDeJogo == "Online")
		{

			tituloSs >> tipoDeJogo >> nomeDoJogo >> idadeMinimaStr >> plataforma >> precoStr >>  empresa >> dataStr >> subscricao >> precoSubsStr;

			while (genero != "*")
			{
				tituloSs >> genero;
				generos.push_back(genero);
			}

			unsigned int precoSubs = std::stof(precoSubsStr);
			if (subscricao == "fixa")
				Online * t(nomeDoJogo, idadeMinima, plataforma, preco, generos, empresa, d, true, precoSubs);
			else
				Online * t(nomeDoJogo, idadeMinima, plataforma, preco, generos, empresa, f, true, precoSubs);

		}
		else
		{
			tituloSs >> tipoDeJogo >> nomeDoJogo >> idadeMinimaStr >> plataforma >> precoStr >>  empresa >> dataStr;

			while (genero != "*")
			{
				tituloSs >> genero;
				generos.push_back(genero);
			}

			Home * t(nomeDoJogo, idadeMinima, plataforma, preco, generos, empresa, d);
		}

		B.adicionaTitulo(t);
	}

	Utilizador U(nome, mail, idade, localidade, B);
	this->jogadores.push_back(U);
}

void Sistema::readUtilizadores() {

	for(int i=1;i<4;i++)
	{
	std::ifstream file;
	file.open("Utilizador" + std::to_string(i) + ".txt");
			 if (!file.fail())
			 {
				 readFile(file);
				 file.close();
			 }
			 else
			 printf ("Could not open the file\n");
	}

}

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

bool Sistema::addUtilizador() /*a incluir throws*/
{
	std::string nome;
	std::string email;
	std::string EMAILCHAR = "@";
	std::string idade;
	std::string morada;
	bool utilizadorCriado=false;
		std::cout << "Creating a user...  \n";
		std::cout << "Enter a user name: ";
		getline(std::cin, nome);
 		std::cout << "Checking if is a valid name... \n";
		if (validName(nome))
			std::cout << "Valid name\n";
		else{
			std::cout << "Invalid Name, try again";
			return false;
		}
 		std::cout << "Enter your email \n";
		getline(std::cin, email);
		if (email.find(EMAILCHAR) == std::string::npos){
			std::cout << "Invalid email it must contain '@' \n";
			return false;
		}
		if (validEmail(email))
			std::cout << "Email Valid \n";
		else{
			std::cout << "Already exists email\n";
			return false;
		}
 		std::cout << "Enter your age ";
		getline(std::cin, idade);
 		std::cout << "Enter your address: ";
		getline(std::cin, morada);
 		jogadores.push_back(Utilizador(nome, email, stoi(idade), morada));
		//std::sort(jogadores.begin(),jogadores.end(),userNameAscend);
 		return true;


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

int findPair(const std::vector<std::pair<std::string, float>> & rentabilidade, std::string nome)
{
	unsigned int comprimento=rentabilidade.size();
	for(unsigned int par = 0;par < comprimento; par++) {
		if (rentabilidade[par].first==nome) {
			return par;
		}
	}
	return -1;
}

void Sistema::rankingDeRentabilidades()
{

	std::vector<std::pair<std::string, float>> rentabilidade;
	int pos ;


	for (auto const & utilizador : this->jogadores)
	{
		std::vector<Titulo*> titulos = utilizador.getBiblioteca().getTitulos();

		for (auto const & titulo : titulos)
		{
			pos=findPair(rentabilidade, titulo->getNome());
			if (pos == -1)
			{
				rentabilidade.push_back(std::make_pair(titulo->getNome(), titulo->getGastos()));
			}
			else
			{
				rentabilidade[pos].second += titulo->getGastos();
			}
		}
	}

	sort(rentabilidade.begin(),rentabilidade.end(),cmpParJogoRentabilidade);

	for (auto const & titulo : rentabilidade)
	{
		std::cout << titulo.first<< ": "<<titulo.second<<std::endl;
	}
}
