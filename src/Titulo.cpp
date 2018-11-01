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

/*funcoes get para aceder aos membros-dado fora da classe*/
unsigned int Titulo::getIdU() const{
		return IdU;
}

std::string Titulo::getNome() const {
		return nome;
}

Data Titulo::getDataLancamento() const {
		return dataLancamento;
}

unsigned int Titulo::getIdadeMinima() const {
		return idadeMinima;
}

std::vector<std::string> Titulo::getGeneros() const {
		return generos;
}

std::string Titulo::getEmpresa() const {
		return empresa;
}

std::map<std::string, std::vector<float>> Titulo::getPrecosPlataforma() const {
		return precosPlataforma;
}

//========================================================================================
//========================================================================================
float Titulo::getPrecoTitulo(std::string plataforma) const
{


	for(auto const &precos : this->precosPlataforma)
		return precos.second.at(precos.second.size()-1); /*preco atual da plataforma*/

	throw PlataformaNaoExistente(plataforma);
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
float Titulo::getPrecoAtual(std::string plataforma) const {
	for (const auto & plat : precosPlataforma) {
		if (plat.first == plataforma)
			return plat.second[plat.second.size() - 1];
	}
	throw PlataformaNaoExistente(plataforma);
	return 0.0;
}

//========================================================================================
//========================================================================================
/*se o identificador unico for igual entao trata-se do mesmo titulo*/
bool Titulo::operator==(const Titulo & T) {
	return (this->IdU == T.IdU);
}

//========================================================================================
//========================================================================================
float Titulo::getDesconto(std::string plataforma)
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
std::ostream & operator <<(std::ostream & os, const Titulo & t) {
	os << "Titulo: " << t.getNome() << std::endl;
	os << "Id: " << t.getIdU() << std::endl;
	//os << "Data de Lançamento: " << t.getDataLancamento() << std::endl; <- dame erro
	os << "Idade Minima: " << t.getIdadeMinima() << std::endl;

	os << "Generos: ";
	for (const auto & generos : t.getGeneros())
		os << generos << ";";

	os << std::endl << "Preco de Aquisicao: " << std::endl;
	for (const auto & plat : t.getPrecosPlataforma()) {
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
void Home::showDatasAtualizacao() const
{
	for(const auto &datas : this->dataDeAtualizacao)
	{
		std::cout<<datas << "\n";
	}

}

//========================================================================================
//========================================================================================
unsigned int Home::getGastos() const
{
	return this->dataDeAtualizacao.size()* this->precoAtualizacao;
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
	this->Data_em_que_jogou.push_back(D1);
	this->minutos_jogados_por_data.push_back(minutos);
	this->plataformas.push_back(plataforma);
}

//========================================================================================
//========================================================================================
void Online::adicionaEstaticas(const Data & D1, const size_t minutos,
		const std::string plataforma) {

	unsigned int indiceData = 0;

	for (auto data : this->Data_em_que_jogou) {
		if (data == D1 && plataformas[indiceData] == plataforma) {
			this->minutos_jogados_por_data[indiceData] += minutos; /*atualiza os minutos numa data*/
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
unsigned int Online::getHorasTotais()
{
	if(horasTotais == (unsigned int)horasTotais) /*numero de horas e um inteiro*/
		return horasTotais;
	else
		return (horasTotais+1.0); /*arredonda para cima*/
}
