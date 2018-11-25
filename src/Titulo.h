#ifndef TITULO_H_
#define TITULO_H_

#include <iostream>
#include <string>
#include <vector>
#include "Data.h"
#include "Utilizador.h"

/**
 * Titulo que foi declarado no Sistema
 */
class Titulo {
protected:
	static unsigned int IdUnico; /**< Variavel static para defenir o ID do titulo */
	unsigned int IdU;	/**< Identificador do titulo */
	std::string nome;/**< Nome do titulo */
	Data dataLancamento;/**< Data de lancamento do titulo */
	unsigned int idadeMinima;/**< Idade minima necessaria para se jogar o titulo */
	std::vector<std::string> generos;/**< Vetor com os genneros atribuidos ao titulo */
	std::string empresa; /**< Empresa que criou o titulo */
	std::string plataforma;/**< Plataforma do titulo */
	std::vector<float> historico_preco;/**< Historico de precos */
public:
	/**
	 * @brief Construtor da classe Titulo
	 * @param nome - Nome atribuido ao titulo
	 * @param idadeMinima - Idade minima atribuida ao titulo
	 * @param plataforma - Plataforma atribuida ao titulo
	 * @param preco - Preco base adicionado ao historico de precos
	 * @param generos - Generos atribuidos ao titulo
	 * @param empresa - Empresa atribuida ao titulo
	 * @param dataLancamenot - Data atribuida ao titulo
	 */
	Titulo(std::string nome, unsigned idadeMinima,
			std::string plataforma,float preco,
			std::vector<std::string> generos, std::string empresa,
			Data dataLancamento);

	/**
	 * @brief Destrutor da classe Titulo
	 */
	virtual ~Titulo();

	/**
	 * @brief Permite obter o nome do titulo 
	 * @return Retorna o nome do titulo
	 */
	std::string getNome() const;

	/**
	 * @brief Permite obter o identificador do titulo 
	 * @return Retorna o identificador do titulo
	 */
	unsigned int getIdU() const;

	/**
	 * @brief Permite obter a data de lancamento do titulo 
	 * @return Retorna a data de lancamento do titulo
	 */
	Data getDataLancamento() const;

	/**
	 * @brief Permite obter a idade minima do titulo 
	 * @return Retorna a idade minima do titulo
	 */
	unsigned int getIdadeMinima() const;

	/**
	 * @brief Permite obter os generos do titulo 
	 * @return Retorna um vetor com os generos do titulo
	 */
	std::vector<std::string> getGeneros() const;

	/**
	 * @brief Permite obter a empresa do titulo 
	 * @return Retorna a empresa do titulo
	 */
	std::string getEmpresa() const;

	/**
	 * @brief Permite obter a plataforma do titulo 
	 * @return Retorna a plataforma do titulo
	 */
	std::string getPlataforma() const;

	/**
	 * @brief Permite obter o preco atual do titulo 
	 * @return Retorna o preco atual do titulo
	 */
	float getPreco() const;

	/**
	 * @brief Permite obter o preco base do titulo 
	 * @return Retorna o preco base do titulo
	 */
	float getPrecoBase() const;

	/**
	 * @brief Permite obter o historico de precos do titulo 
	 * @return Retorna um vetor com todos os precos do titulo
	 */
	std::vector<float> getHistorialPreco() const;

	/**
	 * @brief Permite atualizar o historico de precos do titulo 
	 * @param precos - vetor com os precos para atribuir ao titulo
	 */
	void setHistoricoPreco(const std::vector<float>& precos);
	
	/**
	 * @brief Permite obter o desconto do titulo em percentagem 
	 * @return Retorna o desconto do titulo
	 */
	float getDesconto() const;

	/**
	 * @brief Método puramente virtual que permite obter o gastos num titulo. A implementação encontra-se nas classes derivadas: Home e Online
	 * @return Retorna os gastos no titulo consoante o seu tipo 
	 */
	virtual float getGastos() const = 0;

	/**
	 * @brief Adiciona um novo preco ao historico de precos
	 * @param preco - preco a adicionar ao historico de precos
	 */
	void setPreco(const float preco);

	/**
	 * @brief Permite obter o desconto do titulo em percentagem 
	 * @return Retorna o desconto do titulo
	 * @param os - Stream passada por referência para a qual será efetuada a escrita
	 */
	std::ostream & showTitulo(std::ostream & os) const;

	/**
	 * @brief Verifica se dois titulos sao iguais
	 * @param T - titulo com que se vai comparar o objeto atual
	 * @return true se forem iguais senao falso
	 */
	bool operator==(const Titulo * T);
};

class Home: public Titulo {

private:
	static const unsigned int precoAtualizacao; /* preco por download,*/
	std::vector<Data> dataDeAtualizacao; /* vetor com datas de atualizacoes, em que o seu tamanho da preco gasto em atualizacoes*/
public:

	/*
	 * construtor da classe Home que atua como construtor default para qualquer(quaisquer) parametro(s)
	 * vetor de datas vazio incialmente
	 */

	Home(std::string nome, int idadeMinima,
				std::string plataforma,float preco,
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
	 * show datas de atualizacao
	 */
	float getGastos() const;
};

std::ostream & operator <<(std::ostream & os, const Home & h); // a fazer

class Online: public Titulo {
private:
	/*valor por servico ou preco por subscricao*/
	bool subscricaoFixa; /*falso corresponde a subscricao variavel*/
	float precoSubscricao; /*preco da subscricao escolhida*/
	/* vetores abaixo com indice correspondente*/
	std::vector<Data> datasEmQueJogou; /*vetor incialmente vazio, datas podem repetir se para plataformas diferentes*/
	std::vector<unsigned int> minutosJogadosPorData; /*vetor incialmente vazio*/
	float horasTotais; /*no final arredonda para cima*/

public:
	/*
	 * construtor da classe Online que atua como construtor default para qualquer(quaisquer) parametro(s)
	 * vetores incialmente vazios
	 */
	Online(std::string nome, int idadeMinima,
				std::string plataforma,float preco,
				std::vector<std::string> generos, std::string empresa,
				Data dataLancamento, bool subs, float pSubscricao);

	std::vector<Data> getDatasJogo() const;

	std::vector<unsigned int> getMinutosJogo() const;

	void setMinutosJogo(std::vector<unsigned int>& minutosjogo);

	void setDatasJogo(std::vector<Data>& datasJogo);
	/*
	 * adiciona aos 3 vetores os habitos gaming de uma certa data, funcao a usar em adicionaEstatisticas
	 * @param D1 data em que jogou
	 * @param minutos tempo que jogou
	 * @param plataforma plataforma onde jogou
	 */
	void atualizaEstAux(const Data & D1, const size_t minutos);
	/*
	 * adicionar estaticas relativas aos habitos de gaming, atualiza os 3 ultimos vetores, cuja ordem � crucial e atualiza horas_totais
	 * @param D1 data em que jogou, podendo jogar mais que uma vez ao dia,na mesma plataforma ou nao
	 * @param minutos tempo que jogou
	 * @param plataforma plataforma onde jogou
	 */
	void adicionaEstatisticas(const Data & D1, const size_t minutos);
	/*
	 * devolve o numero de horas jogadas, arredondando para cima o membro estatico horas totais
	 */
	float getHorasTotais() const;

	/*
	 * devolve o booleano que indica se o jogo tem uma subscricao fixa ou variavel
	 */
	bool getSubscricao() const;

	/*
	 * devolve o preco por subscricao
	 */
	float getPrecoSubscricao() const;

	float getGastos() const;
};

std::ostream & operator <<(std::ostream & os, const Online & o);

#endif /* TITULO_H_ */
