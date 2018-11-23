#include "Titulo.h"
#include "Erro.h"
#include <algorithm>
#include <cmath>
#include <iostream>



 /*inicializacao de variaveis static*/
unsigned int Titulo::IdUnico = 1;
const unsigned int Home::precoAtualizacao=1;

 /*
  * construtor titulo
  */

//========================================================================================
//========================================================================================
Titulo::Titulo(std::string nome, int idadeMinima,
		std::string plataforma,float preco,
		std::vector<std::string> generos, std::string empresa,
		Data dataLancamento) {

	this->IdU = IdUnico++;
 	this->nome = nome;
 	this->idadeMinima = idadeMinima;
 	this->generos = generos;
 	this->empresa = empresa;
 	this->plataforma = plataforma;
 	this->historico_preco.push_back(preco);
 	this->dataLancamento = dataLancamento;

 }

Titulo::~Titulo() {}

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

 std::string Titulo::getPlataforma() const{
	 return this->plataforma;
 }

 float Titulo::getPreco() const {
  	return historico_preco.at(historico_preco.size()-1);
  }

 float Titulo::getPrecoBase() const{
	 return historico_preco.at(0);
 }

 std::vector<float> Titulo::getHistorialPreco() const{
	 return historico_preco;
 }

 float Titulo::getDesconto() const
 {
 	return ( 1- getPrecoBase() / getPreco() )*100; /*divisao do preco atual com o de lan�amento */
 }

 void Titulo::setHistoricoPreco(std::vector<float>& precos) const{
	 historico_preco=precos;
 }

 //========================================================================================
 //========================================================================================
 void Titulo::setPreco(const float preco) {
 	if (preco <= 0)
 		throw PrecoInvalido(preco);
 	else historico_preco.push_back(preco);
 }

 //========================================================================================
 //========================================================================================
 /*se o identificador unico for igual entao trata-se do mesmo titulo*/
 bool Titulo::operator==(const Titulo * T) {
 	return (this->IdU == T->IdU);
 }

 //========================================================================================
 //========================================================================================
 std::ostream & Titulo::showTitulo(std::ostream & os) const
 {
 	os << "Titulo: " << this->nome << std::endl;
 	os << "Id: " << this->IdU << "/n";
 	os << "Data de Lan�amento: " << this->dataLancamento << std::endl;
 	os << "Idade Minima: " << this->idadeMinima << "\n";

 	os << "Generos: ";
 	for (const auto & genero : this->generos)
 		os << genero << ";";

 	os << std::endl << "Preco de Aquisicao: " << std::endl;
 	os << getPreco()<<"\n";

 	os << std::endl << "Plataformas: " << std::endl;
 	os<<plataforma<<"\n";
 	return os;
 }

 /*
  * classe Home, derivada da Titulo
  */

 Home::Home(std::string nome, int idadeMinima,
			std::string plataforma,float preco,
			std::vector<std::string> generos, std::string empresa,
			Data dataLancamento) :
 		Titulo(nome, idadeMinima, plataforma,preco, generos, empresa,
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
	 os << h.getPrecoAtualizacao() << "�";
	 return os;
 }

 //========================================================================================
 //========================================================================================
 float Home::getGastos() const
 {
 	float total = dataDeAtualizacao.size()* this->precoAtualizacao;
 	return total;
 }

 //========================================================================================
 //========================================================================================
 Online::Online(std::string nome, int idadeMinima,
			std::string plataforma,float preco,
			std::vector<std::string> generos, std::string empresa,
			Data dataLancamento, bool subs, float pSubscricao) :
 		Titulo(nome, idadeMinima, plataforma,preco, generos, empresa,
 				dataLancamento) {
 	this->subscricaoFixa = subs;
 	this->precoSubscricao = pSubscricao;
	horasTotais=0;
 }

std::vector<Data> Online::getDatasJogo() const{
	return datasEmQueJogou;
}

std::vector<unsigned int> Online::getMinutosJogo() const{
	return minutosJogadosPorData;
}

void Online::setMinutosJogo(std::vector<unsigned int>& minutosjogo){
	minutosJogadosPorData=minutosjogo;
}

void Online::setDatasJogo(std::vector<Data>& datasJogo){
	datasEmQueJogou=datasJogo;
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
 void Online::atualizaEstAux(const Data & D1, const size_t minutos) {
 	this->datasEmQueJogou.push_back(D1);
 	this->minutosJogadosPorData.push_back(minutos);
 }

 //========================================================================================
 //========================================================================================
 void Online::adicionaEstaticas(const Data & D1, const size_t minutos) {

 	unsigned int indiceData = 0;

 	for (auto data : this->datasEmQueJogou) {
 		if (data == D1) {
 			this->minutosJogadosPorData[indiceData] += minutos; /*atualiza os minutos numa data*/
 			horasTotais += minutos / 60.0;
 			return;
 		}

 		indiceData++;
 	}

 	atualizaEstAux(D1, minutos);
 	horasTotais += minutos / 60.0;

 	return;
 }

 //========================================================================================
 //========================================================================================
 float Online::getHorasTotais() const
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
 float Online::getGastos() const
 {
	 float total=0;
	 if(subscricaoFixa)
		 total+=precoSubscricao;
	 else total += (precoSubscricao*horasTotais);

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
