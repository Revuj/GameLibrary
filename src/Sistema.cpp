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
#include <sstream>

Sistema::~Sistema(){
	for (auto titulo:titulos) 
		delete titulo;
}

void Sistema::readFileUtilizadores(std::ifstream & f) {
	std::string nome, mail, idadeStr, localidade, titulo;
	unsigned int idade;
	std::stringstream tituloSs;

	getline(f, nome);
	getline(f, mail);
	getline(f, idadeStr);
	getline(f, localidade);

	idade = std::stoul(idadeStr);

	Biblioteca B;
	while (!f.eof()) 
	{
		std::string tipoDeJogo;
		std::string nomeDoJogo;
		float idadeMinima;
		std::string plataforma;
		float preco;
		std::string genero=".";
		std::string empresa;
		std::string dataStr;
		std::vector<std::string> generos;
		std::vector<float>price_history;
		std::string subscricao;
		std::string precoSubsStr;

		getline(f, titulo);

		tituloSs << titulo;

		tituloSs >> tipoDeJogo;

		tituloSs.str(std::string());

	//arranjar maneira para receber os generos!!!
		if (tipoDeJogo == "Online")
		{
			Online *ptr;
			std::vector<Data> datasJogo;
			std::vector<unsigned int> minutosJogados;
			tituloSs >> tipoDeJogo >> nomeDoJogo >> idadeMinima >> plataforma >> empresa >> dataStr >> subscricao >> precoSubsStr;

			Data d (dataStr);

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco) 
			{
				price_history.push_back(preco);
			}

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> genero) 
			{
				generos.push_back(genero);
			}

			unsigned int precoSubs = std::stof(precoSubsStr);
			if (subscricao == "fixa")
				ptr =  new Online(nomeDoJogo, idadeMinima, plataforma, 0, generos, empresa, d, true, precoSubs);
			else
				ptr =  new Online(nomeDoJogo, idadeMinima, plataforma, 0, generos, empresa, d, false, precoSubs);
			
			bool fim=false;
			std::string data;
			unsigned int minutos;
			while(true){
				if(fim) break;
				
				else 
				if(tituloSs>>data>>minutos){
					getline(f, titulo);
					tituloSs << titulo;
					datasJogo.push_back(Data(data));
					minutosJogados.push_back(minutos);
				}
			}
			ptr->setHistoricoPreco(price_history);
			ptr->setDatasJogo(datasJogo);
			ptr->setMinutosJogo(minutosJogados);
			B.adicionaTitulo(ptr);
		}
		else
		{
			Home *ptr;
			tituloSs >> tipoDeJogo >> nomeDoJogo >> idadeMinima >> plataforma >>  empresa >> dataStr;
			
			Data d (dataStr);

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco) 
			{
				price_history.push_back(preco);
			}

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> genero)
			{
				generos.push_back(genero);
			}

			ptr =  new Home(nomeDoJogo, idadeMinima, plataforma, preco, generos, empresa, d);
			std::string data;
			while(tituloSs>>data){
				ptr->adicionaAtualizacao(Data(data));
			}
			B.adicionaTitulo(ptr);
		}

	}

	Utilizador U(nome, mail, idade, localidade, B);
	std::cout << U << std::endl;

	this->jogadores.push_back(U);
}

void Sistema::readUtilizadores() {

	for(int i=1;i<2;i++)
	{
	std::ifstream file;
	file.open("Utilizador" + std::to_string(i) + ".txt");
			 if (!file.fail())
			 {
				 readFileUtilizadores(file);
				 file.close();
			 }
			 //else
				 //throw
	}

}

void Sistema::saveUtilizadores() {

	for(int i=0;i<jogadores.size();i++)
	{
		std::ofstream file("Utilizador" + std::to_string(i++) + ".txt");
		std::string nome=jogadores.at(i).getNome();
		std::string mail=jogadores.at(i).getEmail();
		unsigned int idade=jogadores.at(i).getIdade();
		std::string localidade=jogadores.at(i).getMorada();
		file<<nome<<std::endl<<mail<<std::endl<<idade<<std::endl<<localidade<<std::endl;
		std::vector<Titulo*> titulos=jogadores.at(i).getBiblioteca().getTitulos();
		for(size_t i = 0; i < titulos.size(); i++)
		{
			Online* online=dynamic_cast<Online*>(titulos.at(i));
			if(online != NULL){
				std::string tipoDeJogo="Online";
				std::string nomeDoJogo=online->getNome();
				unsigned int idadeMinima=online->getIdadeMinima();
				std::string plataforma=online->getPlataforma();
				std::vector<float> preco = online->getHistorialPreco();
				std::vector<std::string> genero=online->getGeneros();
				std::string empresa=online->getEmpresa();
				Data data=online->getDataLancamento();
				std::string subscricao;
				if(online->getSubscricao())
					subscricao="fixa";
				else subscricao="variavel";
				float precoSubs=online->getPrecoSubscricao();
				std::vector<Data> datasJogo=online->getDatasJogo();
				std::vector<unsigned int> minutosJogados=online->getMinutosJogo();
				float horastotais=online->getHorasTotais();
				file<<tipoDeJogo<<" "<<nome<<" "<<idadeMinima<<" "<<plataforma<<" ";

				file<<empresa<<" "<<data<<" "<<subscricao<<" "<<precoSubs<<std::endl;
				for(const auto &i:preco)
				{
					file<<i<<" ";
				}
				file<<std::endl;
				for(const auto &i:genero)
				{
					file<<i<<" ";
				}
				file<<std::endl;
				unsigned int sizeDataJogo=datasJogo.size();
				for(unsigned int i=0;i<sizeDataJogo;i++){
					file<<datasJogo[i]<<" "<<minutosJogados[i]<<std::endl;
				}
				file<<horastotais;
			}
			else {
				Home* home=dynamic_cast<Home*>(titulos.at(i));
				std::string tipoDeJogo="Home";
				std::string nomeDoJogo=online->getNome();
				unsigned int idadeMinima=online->getIdadeMinima();
				std::string plataforma=online->getPlataforma();
				std::vector<float> preco = online->getHistorialPreco();
				std::vector<std::string> genero=online->getGeneros();
				std::string empresa=online->getEmpresa();
				Data data=online->getDataLancamento();
				std::vector<Data> datasAtualizacao=home->getDatas();
				file<<tipoDeJogo<<" "<<nome<<" "<<idadeMinima<<" "<<plataforma<<" ( ";
				for(const auto &i:preco)
				{
					file<<i<<" ";
				}

				file<<") "<<empresa<<" "<<data<<std::endl;
				for(const auto &i:genero)
				{
					file<<i<<" ";
				}
				file<<"*"<<std::endl;
				for(const auto &i: datasAtualizacao){
					file<<i<<" ";
				}
				file<<std::endl;
			}
		}
		
		file.close();
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

	jogadores.push_back(Utilizador(nome, email, stoul(idade, NULL, 0), morada));

	return true;

}

bool Sistema::ordenarUtilizadores(std::string tipo,bool ascend){
	if(tipo=="idade"){
		if(ascend)
			std::sort(jogadores.begin(),jogadores.end(),userAgeAscend);
		else std::sort(jogadores.begin(),jogadores.end(),userAgeDescend);
	}

	if(tipo=="nome"){
		if(ascend)
			std::sort(jogadores.begin(),jogadores.end(),userNameAscend);
		else std::sort(jogadores.begin(),jogadores.end(),userNameDescend);
	}
	if(tipo=="jogos"){
		if(ascend)
			std::sort(jogadores.begin(),jogadores.end(),userNumberGamesAscend);
		else std::sort(jogadores.begin(),jogadores.end(),userNumberGamesDescend);
	}
	return true;
}

Utilizador Sistema::pesquisaUtilizador(std::string nome){
	auto it=jogadores.end();
	//it=std::find(jogadores.begin(),jogadores.end())
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

std::vector <Utilizador> Sistema::getJogadores()
{
	return this->jogadores;
}

std::vector <Titulo *> Sistema::getTitulos()
{
	return this->titulos;
}

std::vector <std::string> Sistema::getPlataformas()
{
	return this->plataformas;
}
