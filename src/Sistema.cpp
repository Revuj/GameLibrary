/*
 * Sistema.cpp
 *
 *  Created on: 21/11/2018
 *      Author: revuj
 */

#include "Sistema.h"
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Titulo.h"
#include <vector>


bool userNameAscend(Utilizador& user1,Utilizador& user2){
	return user1.getNome() < user2.getNome();
}

bool userNameDescend(Utilizador& user1,Utilizador& user2){
	return user1.getNome() > user2.getNome();
}

bool userAgeAscend(Utilizador& user1,Utilizador& user2){
	return user1.getIdade() < user2.getIdade();
}

bool userAgeDescend(Utilizador& user1,Utilizador& user2){
	return user1.getIdade() > user2.getIdade();
}
bool userNumberGamesAscend(Utilizador& user1,Utilizador& user2){
	return user1.getBiblioteca().getTitulos().size() < user2.getBiblioteca().getTitulos().size();
}
bool userNumberGamesDescend(Utilizador& user1,Utilizador& user2){
	return user1.getBiblioteca().getTitulos().size() > user2.getBiblioteca().getTitulos().size();
}




bool gameIdAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdU() < titulo2->getIdU();
}

bool gameIdDescend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdU() > titulo2->getIdU();
}

bool gameReleaseAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getDataLancamento() < titulo2->getDataLancamento();
}

bool gameReleaseDescend(Titulo* titulo1,Titulo* titulo2){
	return !(titulo1->getDataLancamento() <= titulo2->getDataLancamento());
}

bool gameAgeAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdadeMinima() < titulo2->getIdadeMinima();
}

bool gameAgeDescend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdadeMinima() > titulo2->getIdadeMinima();
}

bool gameDeveloperAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getEmpresa() < titulo2->getEmpresa();
}

bool gameDeveloperDescend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getEmpresa() > titulo2->getEmpresa();
}

bool cmpParJogoRentabilidade(const std::pair<std::string,float> & p1,const std::pair<std::string,float> & p2){
	return p1.second > p2.second;
}





Sistema::~Sistema(){
	for (auto titulo:titulos)
		delete titulo;
}

void Sistema::readFileUtilizadores(std::ifstream & f) {
	std::string nome, mail, idadeStr, localidade, titulo, cartao, dataCartao, idCartao;
	float saldo;
	unsigned int idade;
	std::stringstream tituloSs, cartaoSs;
	std::vector<CartaoCredito> cartoes;

	getline(f, nome);
	getline(f, mail);
	getline(f, idadeStr);
	getline(f, localidade);

	getline(f, cartao);

	while (cartao != "")
	{
		cartaoSs << cartao;
		std::cout << cartaoSs.str() << "oi" << std::endl;
		cartaoSs >> saldo >> dataCartao >> idCartao;
		cartoes.push_back(CartaoCredito(saldo, Data(dataCartao), idCartao));
		getline(f, cartao);
		cartaoSs.str(std::string());
		cartaoSs.clear();
	}

	std::cout << "im here" << std::endl;

	idade = std::stoul(idadeStr, NULL, 0);

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

		std::cout << tituloSs.str() << std::endl;

	//arranjar maneira para receber os generos!!!
		std::cout << tipoDeJogo << std::endl;
		if (tipoDeJogo == "Online")
		{
			Online *ptr;
			std::vector<Data> datasJogo;
			std::vector<unsigned int> minutosJogados;
			tituloSs >> nomeDoJogo >> idadeMinima >> plataforma >> empresa >> dataStr >> subscricao >> precoSubsStr;
			std::cout << "DataOnline: " << dataStr << std::endl;
			Data d (dataStr);

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco)
			{
				price_history.push_back(preco);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;

			while (tituloSs >> genero)
			{
				generos.push_back(genero);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

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
				{
					getline(f, titulo);
					tituloSs << titulo;
				while(tituloSs>>data>>minutos){
					datasJogo.push_back(Data(data));
					minutosJogados.push_back(minutos);
				}
				fim = true;
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
			tituloSs >> nomeDoJogo >> idadeMinima >> plataforma >> empresa >> dataStr;
			std::cout << "DataHome: " << dataStr << std::endl;
			Data d (dataStr);

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco)
			{
				price_history.push_back(preco);
			}
			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;
			std::cout << "Generoewdawe: " << tituloSs.str() << std::endl;
			while (tituloSs >> genero)
			{
				std::cout << genero << std::endl;
				generos.push_back(genero);
			}

			tituloSs.str(std::string());
			tituloSs.clear();


			ptr =  new Home(nomeDoJogo, idadeMinima, plataforma, preco, generos, empresa, d);
			std::string data;
			getline(f, titulo);
			tituloSs << titulo;

			while(tituloSs>>data){
				ptr->adicionaAtualizacao(Data(data));
			}

			std::cout << *ptr << std::endl;
			B.adicionaTitulo(ptr);
			ptr->setHistoricoPreco(price_history);
		}
		tituloSs.str(std::string());
		tituloSs.clear();

	}

	std::cout << nome << " " << mail << " " << idade << " " << localidade << std::endl;
	Utilizador U(nome, mail, idade, localidade, B);

	for (const auto & c : cartoes)
	{
		std::cout << "cartao: " << c.getId() << std::endl;
		U.adicionaCartaoCredito(c);
	}

	this->jogadores.push_back(U);

	std::cout << U << std::endl;


}

void Sistema::readUtilizadores() {

	unsigned int i = 1;

	while (true)
	{
	std::ifstream file;
	file.open("Utilizador" + std::to_string(i) + ".txt");
			 if (!file.fail())
			 {
				 readFileUtilizadores(file);
				 file.close();
				 i++;
			 }
			 else
				 break;
	}

}

void Sistema::saveUtilizadores() {

	for(unsigned int i=0;i< jogadores.size();i++)
	{
		std::cout << "oi" << std::endl;
		std::ofstream file("Utilizador" + std::to_string(i + 1) + ".txt");
		std::string nome=jogadores.at(i).getNome();
		std::string mail=jogadores.at(i).getEmail();
		unsigned int idade=jogadores.at(i).getIdade();
		std::string localidade=jogadores.at(i).getMorada();
		std::vector<CartaoCredito> cartoes = jogadores.at(i).getCc();

		file<<nome<<std::endl<<mail<<std::endl<<idade<<std::endl<<localidade<<std::endl;
		std::vector<Titulo*> titulos=jogadores.at(i).getBiblioteca().getTitulos();

		for (const auto & cartao : cartoes)
		{
			file << cartao.getSaldo() << " " << cartao.getDataDeValidade() << " " << cartao.getId() << std::endl;
		}

		file << std::endl;

		for(size_t i = 0; i < titulos.size(); i++)
		{
			std::cout << "ola" << std::endl;
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
				file<<tipoDeJogo<<" "<<nomeDoJogo<<" "<<idadeMinima<<" "<<plataforma<<" ";

				file<<empresa<<" "<<data<<" "<<subscricao<<" "<<precoSubs<<std::endl;
				for(unsigned int i = 0; i < preco.size(); i++)
				{
					if (i == preco.size() - 1)
						file << preco[i] << std::endl;
					else
						file<< preco[i] <<" ";
				}


				for(unsigned int i = 0; i < genero.size(); i++)
				{
					if (i == genero.size() - 1)
						file << genero[i] << std::endl;
					else
						file<< genero[i] <<" ";
				}

				for(unsigned int i = 0; i < datasJogo.size(); i++)
				{
					if (i == datasJogo.size() - 1)
						file << datasJogo[i] << " " << minutosJogados[i];
					else
						file << datasJogo[i] << " " << minutosJogados[i] << " ";
				}

				if (i != titulos.size() - 1)
					file << std::endl;
			}
			else {
				std::cout << "hello" << std::endl;
				Home* home=dynamic_cast<Home*>(titulos.at(i));
				std::string tipoDeJogo="Home";
				std::string nomeDoJogo=home->getNome();
				unsigned int idadeMinima=home->getIdadeMinima();
				std::string plataforma=home->getPlataforma();
				std::vector<float> preco = home->getHistorialPreco();
				std::vector<std::string> genero=home->getGeneros();
				std::string empresa=home->getEmpresa();
				Data data=home->getDataLancamento();
				std::vector<Data> datasAtualizacao=home->getDatas();
				file<<tipoDeJogo<<" "<<nomeDoJogo<<" "<<idadeMinima<<" "<<plataforma <<" " << empresa << " " << data << std::endl;
				for(unsigned int i = 0; i < preco.size(); i++)
				{
					if (i == preco.size() - 1)
						file << preco[i] << std::endl;
					else
						file<< preco[i] <<" ";
				}


				for(unsigned int i = 0; i < genero.size(); i++)
				{
					if (i == genero.size() - 1)
						file << genero[i] << std::endl;
					else
						file<< genero[i] <<" ";
				}

				for(unsigned int i = 0; i < datasAtualizacao.size(); i++)
				{
					if (i == datasAtualizacao.size() - 1)
						file << datasAtualizacao[i];
					else
						file<< datasAtualizacao[i] <<" ";
				}

				if (i != titulos.size() - 1)
					file << std::endl;

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

	bool validEmail=false;
	while(!validEmail){
		std::cout << "Enter your email \n";
		getline(std::cin, email);
		if (email.find(EMAILCHAR) == std::string::npos){
			std::cout << "Invalid email it must contain '@' \n";
		}
		else validEmail=true;
	}

	std::cout << "Enter your age ";
	getline(std::cin, idade);

	std::cout << "Enter your address: ";
	getline(std::cin, morada);

	jogadores.push_back(Utilizador(nome, email, std::stoul(idade, NULL, 0), morada));

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

Utilizador Sistema::pesquisaUtilizador(std::string nome, std::string email){
	for(const auto utilizador : this->jogadores) {
		if (utilizador.getEmail()==email && utilizador.getNome()==nome)
			return utilizador;
	}
	throw(UtilizadorInexistente("O utilizador de nome "+ nome+ " e email "+email+" nao existe"));
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

void Sistema::rankingDePlataformas() const
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
