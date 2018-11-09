#include "Titulo.h"
#include "Erro.h"
#include <algorithm>
#include <cmath>
#include <iostream>



 /*inicializacao de variaveis static*/
unsigned int Titulo::IdUnico = 1;
float Online::horasTotais = 0;

 /*
  * construtor titulo
  */

//========================================================================================
//========================================================================================
Titulo::Titulo(std::string nome, int idadeMinima,
 		std::map<std::string, std::vector<float>> precosPlataforma,
 		std::vector<std::string> generos, std::string empresa,
 		Data dataLancamento) {

	this->IdU = IdUnico++;
 	this->nome = nome;
 	this->idadeMinima = idadeMinima;
 	this->generos = generos;
 	this->empresa = empresa;
 	this->precosPlataforma = precosPlataforma;
 	this->dataLancamento = dataLancamento;

 }

//========================================================================================
//========================================================================================
Titulo::~Titulo()
{
}
 //========================================================================================
 //========================================================================================

 /*funcoes get para aceder aos membros-dado fora da classe*/
std::string Titulo::getNome() const {
 		return this->nome;
 }

unsigned int Titulo::getIdU() const{
 		return this->IdU;
 }

 Data Titulo::getDataLancamento() const {
		return this->dataLancamento;
}

 unsigned int Titulo::getIdadeMinima() const {
		return this->idadeMinima;
}

 std::vector<std::string> Titulo::getGeneros() const {
		return this->generos;
}

 std::string Titulo::getEmpresa() const {
		return this->empresa;
}

 std::map<std::string, std::vector<float>> Titulo::getPrecosPlataforma() const
 {
	 return this->precosPlataforma;
 }

 float Titulo::getPrecoAtual(std::string plataforma) const {
  	for (const auto & plat : precosPlataforma) {
  		if (plat.first == plataforma)
  			return plat.second[plat.second.size() - 1];
  	}
  	throw PlataformaNaoExistente(plataforma);
  	return 0.0;
  }

 float Titulo::getDesconto(std::string plataforma) const
 {
 	for(auto const & precos : this->precosPlataforma)
 	{
 		if(precos.first == plataforma)
 			return ( 1- (precos.second.at(precos.second.size()-1)) / precos.second.at(0) )*100; /*divisao do preco atual com o de lançamento */

 	}
 	throw PlataformaNaoExistente(plataforma); /*plataforma inexistente*/
 }

 //========================================================================================
 //========================================================================================
 void Titulo::atualizaPreco(const float preco) {
 	if (preco <= 0)
 		throw PrecoInvalido(preco);
 	else {
 		for (auto & plataforma : precosPlataforma) {
 			plataforma.second.push_back(preco);
 		}
 	}
 }

 //========================================================================================
 //========================================================================================
 void Titulo::atualizaPrecoNaPlataforma(const float preco,
 		std::string plataforma) {
 	if (preco <= 0)
 		throw PrecoInvalido(preco);
 	else {
 		for (auto & plat : precosPlataforma) {
 			if (plat.first == plataforma)
 				plat.second.push_back(preco);
 			return;
 		}
 		throw PlataformaNaoExistente(plataforma);
	}
}

//========================================================================================
//========================================================================================
 void Titulo::adicionaPlataforma(const float preco, std::string plataforma){
	if(precosPlataforma.find(plataforma)!=precosPlataforma.end())
		throw (PlataformaJaExistente(plataforma));
	std::vector<float> price;
	price.push_back(preco);
	precosPlataforma[plataforma]=price;
}
 //========================================================================================
//========================================================================================
 void Titulo::removePlataforma(const float preco, std::string plataforma){
	std::map<std::string,std::vector<float>>::iterator it=precosPlataforma.find(plataforma);
	if(it==precosPlataforma.end())
		throw (PlataformaNaoExistente(plataforma));
	else precosPlataforma.erase (it);
}
 //========================================================================================
 //========================================================================================
 /*se o identificador unico for igual entao trata-se do mesmo titulo*/
 bool Titulo::operator==(const Titulo & T) {
 	return (this->IdU == T.IdU);
 }


 //========================================================================================
 //========================================================================================
 std::ostream & Titulo::showTitulo(std::ostream & os) const
 {

 	os << "Titulo: " << this->nome << std::endl;
 	os << "Id: " << this->IdU << "/n";
 	os << "Data de Lançamento: " << this->dataLancamento << std::endl;
 	os << "Idade Minima: " << this->idadeMinima << "\n";

 	os << "Generos: ";
 	for (const auto & genero : this->generos)
 		os << genero << ";";

 	os << std::endl << "Preco de Aquisicao: " << std::endl;
 	for (const auto & plat : this->precosPlataforma) {
 		os << "-> " << plat.first << ": " << plat.second[plat.second.size() - 1]
 				<< std::endl;
 	}
 	return os;
 }

 /*
  * classe Home, derivada da Titulo
  */

 Home::Home(std::string nome, int idadeMinima,
 		std::map<std::string, std::vector<float>> precosPlataforma,
 		std::vector<std::string> generos, std::string empresa,
 		Data dataLancamento) :
 		Titulo(nome, idadeMinima, precosPlataforma, generos, empresa,
 				dataLancamento) {

 }

 //========================================================================================
 //========================================================================================
 bool Home::adicionaAtualizacao(const Data & D) {

 	if (find(this->dataDeAtualizacao.begin(), this->dataDeAtualizacao.end(),
 			D) != this->dataDeAtualizacao.end())
 		return false;
 	else {
 		this->dataDeAtualizacao.push_back(D);
 		return true;
 	}

 }

 //========================================================================================
 //========================================================================================
 unsigned int Home::getPrecoAtualizacao() const
 {
 	return this->precoAtualizacao;
 }

 //========================================================================================
 //========================================================================================
 std::vector<Data>Home::getDatas() const
 {
 	return this->dataDeAtualizacao;
 }

 //========================================================================================
 //========================================================================================
 std::ostream & operator <<(std::ostream & os, const Home & h) {
	 h.showTitulo(os);

	 os << "Datas de atualizacao: " << std::endl;

	 for (const auto & data : h.getDatas())
	 {
		 os << data << "; ";
	 }

	 os << std::endl << "Preco por atualizacao: ";
	 os << h.getPrecoAtualizacao() << "€";
	 return os;
 }

 //========================================================================================
 //========================================================================================
 float Home::getGastos(const std::vector<std::string>& plataformas) const
 {
 	float total = dataDeAtualizacao.size()* this->precoAtualizacao;
	 for(auto i: plataformas)
		 total+=getPrecoAtual(i);
 	return total;
 }

 //========================================================================================
 //========================================================================================
 Online::Online(std::string nome, int idadeMinima,
 		std::map<std::string, std::vector<float>> precosPlataforma,
 		std::vector<std::string> generos, std::string empresa,
 		Data dataLancamento, bool subs, size_t pSubscricao) :
 		Titulo(nome, idadeMinima, precosPlataforma, generos, empresa,
 				dataLancamento) {
 	this->subscricaoFixa = subs;
 	this->precoSubscricao = pSubscricao;
 }

 //========================================================================================
 //========================================================================================
 bool Online::adicionaUtilizador(const Utilizador &U) {
 	if (find(this->utilizadores.begin(), this->utilizadores.end(), U)
 			!= this->utilizadores.end())
 		return false;
 	else {
 		this->utilizadores.push_back(U);
 		return true;
 	}
 }

 //========================================================================================
 //========================================================================================
 void Online::atualizaEstAux(const Data & D1, const size_t minutos,
 		const std::string plataforma) {
 	this->datasEmQueJogou.push_back(D1);
 	this->minutosJogadosPorData.push_back(minutos);
 	this->plataformas.push_back(plataforma);
 }

 //========================================================================================
 //========================================================================================
 void Online::adicionaEstaticas(const Data & D1, const size_t minutos,
 		const std::string plataforma) {

 	unsigned int indiceData = 0;

 	for (auto data : this->datasEmQueJogou) {
 		if (data == D1 && plataformas[indiceData] == plataforma) {
 			this->minutosJogadosPorData[indiceData] += minutos; /*atualiza os minutos numa data*/
 			horasTotais += minutos / 60.0;
 			return;
 		}

 		indiceData++;
 	}

 	/*se plataforma e/ou data forem diferentes adiciona uma nova estatistica*/
 	atualizaEstAux(D1, minutos, plataforma);
 	horasTotais += minutos / 60.0;

 	return;
 }

 //========================================================================================
 //========================================================================================
 unsigned int Online::getHorasTotais() const
 {
 	if(horasTotais == (unsigned int)horasTotais) /*numero de horas e um inteiro*/
		return horasTotais;
	else
		return (horasTotais+1.0); /*arredonda para cima*/
}

 //========================================================================================
 //========================================================================================
 bool Online::getSubscricao() const
 {
	 return this->subscricaoFixa;
 }

 //========================================================================================
 //========================================================================================
 float Online::getPrecoSubscricao() const
 {
	 return this->precoSubscricao;
 }
 //========================================================================================
 //========================================================================================

 float Online::getGastos(const std::vector<std::string>& plataformas) const
 {
	 float total=0;
	 if(subscricaoFixa)
		 total+=precoSubscricao;
	 else total += (precoSubscricao*horasTotais);
	 for(auto i: plataformas)
		 total+=getPrecoAtual(i);
	 return total;
 }
 //========================================================================================
 //========================================================================================
 std::ostream & operator <<(std::ostream & os, const Online & o) {
	 o.showTitulo(os);
	 os << std::endl;


	 if (o.getSubscricao() == true)
		 os << "Subscricao Fixa" << std::endl;
	 else
		 os << "Subscricao Variavel" << std::endl;

	 os << "Preco da Subscricao: ";
	 os << o.getPrecoSubscricao();

	 return os;
 }

