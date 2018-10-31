#include "Titulo.h"

#include <algorithm>
#include <iostream>
#include "Erro.h"

/*inicializacao de variaveis static*/
unsigned int Titulo::IdUnico = 1;
float Online::horas_totais = 0;

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

std::ostream & operator <<(std::ostream & os, const Titulo & t) {
	os << "Titulo: " << t.getNome() << std::endl;
	os << "Id: " << t.getIdU() << std::endl;
	os << "Data de Lançamento: " << t.getDataLancamento() << std::endl;
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

	if (find(this->data_de_atualizacao.begin(), this->data_de_atualizacao.end(),
			D) != this->data_de_atualizacao.end())
		return false;
	else {
		this->data_de_atualizacao.push_back(D);
		return true;
	}

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
			horas_totais += minutos / 60;
			return;
		}

		indiceData++;
	}

	/*se plataforma e/ou data forem diferentes adiciona uma nova estatistica*/
	atualizaEstAux(D1, minutos, plataforma);
	horas_totais += minutos / 60;

	return;
}

