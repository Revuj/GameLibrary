#include "Titulo.h"
#include "Erro.h"
#include <algorithm>
#include <cmath>
#include<string>
#include <iostream>
#include "WishedTitle.h"


 /*inicializacao de variaveis static*/
unsigned int Titulo::IdUnico = 1;
const unsigned int Home::precoAtualizacao=1;

 /*
  * construtor titulo
  */

//========================================================================================
//========================================================================================
Titulo::Titulo(std::string nome, unsigned idadeMinima,
		std::string plataforma,float preco,
		std::vector<std::string> generos, std::string empresa,
		Data dataLancamento, unsigned int numero, unsigned int cliques) {

	this->IdU = IdUnico++;
 	this->nome = nome;
 	this->idadeMinima = idadeMinima;
 	this->generos = generos;
 	this->empresa = empresa;
 	this->plataforma = plataforma;
 	this->historico_preco.push_back(preco);
 	this->dataLancamento = dataLancamento;
 	this->numeroAnuncios = numero;
 	this->numeroCliques = cliques;

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

 unsigned int Titulo::getAnuncios() const {
	 return this->numeroAnuncios;
 }

 unsigned int Titulo::getCliques() const {
	 return this->numeroCliques;
 }

 float Titulo::getPrecoBase() const{
	 return historico_preco.at(0);
 }

 std::vector<float> Titulo::getHistorialPreco() const{
	 return historico_preco;
 }

 float Titulo::getDesconto() const
 {
 	return abs(( 1- getPreco() / getPrecoBase() )*100); /*divisao do preco atual com o de lan�amento */
 }

 void Titulo::setHistoricoPreco(const std::vector<float>& precos) {
	 historico_preco=precos;
 }

 //========================================================================================
 //========================================================================================
 void Titulo::setPreco(const float preco) {
 	if (preco <= 0 || preco>=historico_preco[historico_preco.size()-1])
 		throw PrecoInvalido(std::to_string(preco));
 	else historico_preco.push_back(preco);
 }


 void Titulo::adicionaAnuncios(unsigned int numero) {
	 this->numeroAnuncios += numero;
 }

 void Titulo::adicionaCliques(unsigned int numero) {
	 this->numeroCliques += numero;
 }

 void Titulo::adicionaUserHashTable(Utilizador *u){
	 if(u->getMonthsLastBuy() <= 3)
		 return;
	 std::priority_queue<WishedTitle> wish = u->getWishList();
	 while(!wish.empty()){
		 auto it = this->asleepUsers.find(u);
		 std::cout << wish.top().getProbabilidadeCompra() << std::endl;
		 if(it == asleepUsers.end() && wish.top().getTitulo()->getNome() == this->nome && wish.top().getTitulo()->getPlataforma() == this->plataforma && wish.top().getProbabilidadeCompra()>0.6){
			std::cout << u->getNome() << std::endl;
			 asleepUsers.insert(u);
		 }
		 wish.pop();
	 }
 }

void Titulo::removeUserHashTable(Utilizador* u){
	auto it = this->asleepUsers.find(u);
	if(it != asleepUsers.end()){
		asleepUsers.erase(u);
		std::cout << "Utilizador removido da tabela da lista de utilizadores adormecidos do titulo "<<this->nome<<std::endl;
	}
}

void Titulo::printAsleepUsers(){
	for(auto it: this->asleepUsers){
		std::cout << (*it)<< std::endl;
	}
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
			Data dataLancamento, unsigned int numero, unsigned int cliques) :
 		Titulo(nome, idadeMinima, plataforma,preco, generos, empresa,
 				dataLancamento, numero, cliques) {

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
			Data dataLancamento, unsigned int numero, unsigned int cliques, bool subs, float pSubscricao) :
 		Titulo(nome, idadeMinima, plataforma,preco, generos, empresa,
 				dataLancamento, numero, cliques) {
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
 void Online::atualizaEstAux(const Data & D1, const size_t minutos) {
 	this->datasEmQueJogou.push_back(D1);
 	this->minutosJogadosPorData.push_back(minutos);
 }

 //========================================================================================
 //========================================================================================
 void Online::adicionaEstatisticas(const Data & D1, const size_t minutos) {

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
