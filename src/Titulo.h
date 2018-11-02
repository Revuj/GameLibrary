#ifndef TITULO_H_
#define TITULO_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Data.h"
#include "Utilizador.h"

class Titulo {

private:
	static unsigned int IdUnico; /*começa em 1 */
	unsigned int IdU;
	std::string nome;
	Data dataLancamento;
	unsigned int idadeMinima;
	std::vector<std::string> generos;
	std::string empresa; /*empresa que criou*/
	std::string plataforma;
	float price;
	std::vector<float> price_history;
public:

	/*construtores*/
	Titulo();
	Titulo(std::string nome, int idadeMinima, std::string plataforma, float price,
			std::vector<std::string> generos, std::string empresa,
			Data dataLancamento);

	/*funcoes para aceder aos membros dado*/
	unsigned int getIdU() const;

	std::string getNome() const;

	Data getDataLancamento() const;

	unsigned int getIdadeMinima() const;

	std::vector<std::string> getGeneros() const;

	std::string getEmpresa() const;

	std::string getPlataforma() const {return plataforma;}

	float getPrice() const;
	
	std::vector<float> getPriceHistory() const;

	/*
	 * atualiza o preco 
	 * @param preco preco atual
	 * return true ou false mediante o valor passado (false se menor ou igual a 0)
	 */
	void atualizaPreco(const float preco);

	/*
	 * verifica se dois titulos sao iguais
	 * @param T titulo com que se vai comparar o objeto atual
	 * return true se forem iguais senao falso
	 */
	bool operator==(const Titulo & T);

	/*
	 * calcula o desconto,comparando o preco de lancamento(o mais elevado) com o atual
	 * @param plataforma especifica a plataforma onde queremos calcular o desconto
	 * return um numero do tipo float no dentro do intervalo [0,100[ , lança excecao se plataforma nao existe
	 */
	float getDesconto(std::string plataforma);

};

/*
 * mostra no ecra o Titulo e os respetivos atributos
 */
std::ostream & operator <<(std::ostream & os, const Titulo & t);

class Home: public Titulo {

private:
	const unsigned int precoAtualizacao = 1; /* preco por download,*/
	std::vector<Data> dataDeAtualizacao; /* vetor com datas de atualizacoes, em que o seu tamanho da preco gasto em atualizacoes*/
public:

	/*
	 * construtor da classe Home que atua como construtor default para qualquer(quaisquer) parametro(s)
	 * vetor de datas vazio incialmente
	 */

	Home(std::string nome, int idadeMinima, std::string plataforma, float price,
			std::vector<std::string> generos, std::string empresa,
			Data dataLancamento);

	/*
	 * funcao adiciona uma data ao vetor data_de_atualizacao, assumindo que ha no maximo uma por dia
	 * @param D data em que houve uma atualizacao
	 * return verdade ou falso se for possivel adicionar ao vetor a data
	 */
	bool adicionaAtualizacao(const Data & D);

	/*
	 * devolve o membro dato precoatualizacao
	 */
	unsigned int getPrecoAtualizacao() const;

	/*
	 * devolve membro dado vetor de datas
	 */
	std::vector<Data> getDatas() const;

	/*
	 * devolve o gasto total em atualizacoes
	 */
	unsigned int getGastos() const;

	/*
	 * show datas de atualizacao
	 */
	void showDatasAtualizacao() const;
};



class Online: public Titulo {
private:
	std::vector<Utilizador> utilizadores; /*vetor incialmente vazio*/
	/*valor por servico ou preco por subscricao*/
	bool subscricaoFixa; /*falso corresponde a subscricao variavel*/
	float precoSubscricao; /*preco da subscricao escolhida*/
	/* vetores abaixo com indice correspondente*/
	std::vector<Data> Data_em_que_jogou; /*vetor incialmente vazio, datas podem repetir se para plataformas diferentes*/
	std::vector<size_t> minutos_jogados_por_data; /*vetor incialmente vazio*/
	std::vector<std::string> plataformas;  /*vetor incialmente vazio*/
	static float horasTotais; /*no final arredonda para cima*/

public:

	/*
	 * construtor da classe Online que atua como construtor default para qualquer(quaisquer) parametro(s)
	 * vetores incialmente vazios
	 */
	Online(std::string nome, int idadeMinima,std::string plataforma,float price,
			std::vector<std::string> generos, std::string empresa,
			Data dataLancamento, bool subs, size_t pSubscricao);

	/*
	 * adiciona um utilizador caso ele nao exista
	 * @param U utilizador a adicionar
	 * return true se foi possivel adiciona-lo
	 */
	bool adicionaUtilizador(const Utilizador &U);

	/*
	 * adiciona aos 3 vetores os habitos gaming de uma certa data, funcao a usar em adicionaEstatisticas
	 * @param D1 data em que jogou
	 * @param minutos tempo que jogou
	 * @param plataforma plataforma onde jogou
	 */
	void atualizaEstAux(const Data & D1, const size_t minutos,
			const std::string plataforma);

	/*
	 * adicionar estaticas relativas aos habitos de gaming, atualiza os 3 ultimos vetores, cuja ordem é crucial e atualiza horas_totais
	 * @param D1 data em que jogou, podendo jogar mais que uma vez ao dia,na mesma plataforma ou nao
	 * @param minutos tempo que jogou
	 * @param plataforma plataforma onde jogou
	 */
	void adicionaEstaticas(const Data & D1, const size_t minutos,
			const std::string plataforma);
	/*
	 * devolve o numero de horas jogadas, arredondando para cima o membro estatico horas totais
	 */
	unsigned int getHorasTotais();

};

#endif /* TITULO_H_ */
