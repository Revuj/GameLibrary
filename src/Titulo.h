#ifndef TITULO_H_
#define TITULO_H_

#include <iostream>
#include <string>
#include <vector>
#include "Data.h"
#include "Utilizador.h"

//segunda parte
#include <queue>

#include <unordered_set>


/* ------------------------------------------------*/

struct UtilizadorPtr{
	int operator()(const Utilizador * u1) const {
		unsigned long hash = 5381;
		for (char c : u1->getEmail()) {
			if (c != '@' && c!= '.' )
				hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		}
	    return hash;
	}

	bool operator() (const Utilizador * u1, const Utilizador * u2) const {
		return u1->getEmail() == u2->getEmail();
	}
};

typedef std::unordered_set<Utilizador*,UtilizadorPtr,UtilizadorPtr> UserHashTable;

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
	std::string empresa;
	std::string plataforma;/**< Plataforma do titulo */
	std::vector<float> historico_preco;/**< Historico de precos */
	unsigned int numeroAnuncios; /** < Numero de anuncios */
	unsigned int numeroCliques /** < Numero de cliques */;
	UserHashTable asleepUsers;
public:
	/**
	 * @brief Construtor da classe Titulo
	 * @param nome - Nome atribuido ao titulo
	 * @param idadeMinima - Idade minima atribuida ao titulo
	 * @param plataforma - Plataforma atribuida ao titulo
	 * @param preco - Preco base adicionado ao historico de precos
	 * @param generos - Generos atribuidos ao titulo
	 * @param empresa - Empresa atribuida ao titulo
	 * @param dataLancamento - Data atribuida ao titulo
	 */
	Titulo(std::string nome, unsigned idadeMinima,
			std::string plataforma,float preco,
			std::vector<std::string> generos, std::string empresa,
			Data dataLancamento, unsigned int numero, unsigned int cliques);

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
	 * @brief Permite obter o numero de anuncios
	 * @return Retorna o numero de anuncios
	 */
	unsigned int getAnuncios() const;

	/**
	 * @brief Permite obter o numero de cliques
	 * @return Retorna o numero de cliques
	 */
	unsigned int getCliques() const;

	/**
	 * @brief Adiciona um novo preco ao historico de precos
	 * @param preco - preco a adicionar ao historico de precos
	 */
	void setPreco(const float preco);

	/**
	 * @brief Adiciona um numero de anuncios
	 * @param numero - numero de anuncios
	 */
	void adicionaAnuncios(unsigned int numero);

	/**
	 * @brief Adiciona um numero de cliques
	 * @param numero - numero de cliques
	 */
	void adicionaCliques(unsigned int numero);

	void adicionaUserHashTable(Utilizador *u);

	void removeUserHashTable(Utilizador* u);

	void printAsleepUsers();

	void clearAsleepUsers() { this->asleepUsers.clear() ;}

	UserHashTable getSleepUsers() { return this->asleepUsers; }

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


/**
 * Home derivada de Titulo
 */
class Home: public Titulo {

private:
	static const unsigned int precoAtualizacao; /**< preco por download*/
	std::vector<Data> dataDeAtualizacao; /**< vetor com datas de atualizacoes */
public:

	/**
	 * @brief construtor da classe Home
	 * @param nome - Nome atribuido ao titulo
	 * @param idadeMinima - Idade minima atribuida ao titulo
	 * @param plataforma - Plataforma atribuida ao titulo
	 * @param preco - Preco base adicionado ao historico de precos
	 * @param generos - Generos atribuidos ao titulo
	 * @param empresa - Empresa atribuida ao titulo
	 * @param dataLancamento - Data atribuida ao titulo
	 */
	Home(std::string nome, int idadeMinima,
				std::string plataforma,float preco,
				std::vector<std::string> generos, std::string empresa,
				Data dataLancamento, unsigned int numero, unsigned int cliques);

	/**
	 * @brief Adiciona uma data ao vetor data_de_atualizacao
	 * @param D - data em que houve uma atualizacao
	 * @return Retorna verdade ou falso se for possivel adicionar ao vetor a data
	 */
	bool adicionaAtualizacao(const Data & D);

	/**
	 * @brief Devolve o preco por atualizacao
	 * @return Retorna o membro dato precoatualizacao
	 */
	unsigned int getPrecoAtualizacao() const;

	/**
	 * @brief Devolve membro dado vetor de datas
	 * @return Retorna vetor de datas de atualizacao
	 */
	std::vector<Data> getDatas() const;

	/**
	 * @brief Devolve os gastos associados as atualizacoes
	 * @return Retorna os gastos
	 */
	float getGastos() const;
};

std::ostream & operator <<(std::ostream & os, const Home & h); // a fazer

/**
 * Online derivada de Titulo
 */
class Online: public Titulo {
private:
	bool subscricaoFixa; /**<falso corresponde a subscricao variavel*/
	float precoSubscricao; /**<preco da subscricao escolhida*/
	std::vector<Data> datasEmQueJogou; /**<vetor das datas em que o utilizador jogou*/
	std::vector<unsigned int> minutosJogadosPorData; /**<vetor com minutos jogados num dia*/
	float horasTotais; /**<horas totais jogadas*/

public:
	/**
	 * @brief construtor da classe Online
	 * @param nome - Nome atribuido ao titulo
	 * @param idadeMinima - Idade minima atribuida ao titulo
	 * @param plataforma - Plataforma atribuida ao titulo
	 * @param preco - Preco base adicionado ao historico de precos
	 * @param generos - Generos atribuidos ao titulo
	 * @param empresa - Empresa atribuida ao titulo
	 * @param dataLancamento - Data atribuida ao titulo
	 * @param subs - Subscricao fixa ou variavel
	 * @param - Preco da subscricao escolhida
	 */
	Online(std::string nome, int idadeMinima,
				std::string plataforma,float preco,
				std::vector<std::string> generos, std::string empresa,
				Data dataLancamento, unsigned int numero, unsigned int cliques , bool subs, float pSubscricao);

	/**
	 * @brief Devolve as datas jogadas
	 * @return Vetor com datas jogadas
	 */
	std::vector<Data> getDatasJogo() const;

	/**
	 * @brief Devolve os minutos jogados por data
	 * @return Vetor com minutos jogados por data
	 */
	std::vector<unsigned int> getMinutosJogo() const;

	/**
	 * @brief Altera os minutos jogados por data
	 * @param minutosjogo - Vetor com minutos jogados por data
	 */
	void setMinutosJogo(std::vector<unsigned int>& minutosjogo);

	/**
	 * @brief Altera as datas jogadas
	 * @param datasJogo - Vetor com datas jogadas
	 */
	void setDatasJogo(std::vector<Data>& datasJogo);
	
	/**
	 * @brief Adiciona aos 3 vetores os habitos gaming de uma certa data, funcao a usar em adicionaEstatisticas
	 * @param D1 - data em que jogou
	 * @param minutos - tempo que jogou
	 */
	void atualizaEstAux(const Data & D1, const size_t minutos);
	
	/**
	 * @brief Adicionar estaticas relativas aos habitos de gaming, atualiza os 3 ultimos vetores, cuja ordem � crucial e atualiza horas_totais
	 * @param D1 - data em que jogou, podendo jogar mais que uma vez ao dia,na mesma plataforma ou nao
	 * @param minutos - tempo que jogou
	 */
	void adicionaEstatisticas(const Data & D1, const size_t minutos);
	
	/**
	 * @brief Devolve o numero de horas jogadas, arredondando para cima o membro estatico horas totais
	 * @return Retorna o numero de horas totais
	 */
	float getHorasTotais() const;

	/**
	 * @brief Devolve o booleano que indica se o jogo tem uma subscricao fixa ou variavel
	 * @return Retorna boolenao consoante o tipo de subscricao
	 */
	bool getSubscricao() const;

	/**
	 * @brief Devolve o preco por subscricao
	 * @return Retorna o preco de subscricao
	 */
	float getPrecoSubscricao() const;

	/**
	 * @brief Devolve os gastos associadas a subscricao
	 * @return Retorna os gastos
	 */
	float getGastos() const;
};

std::ostream & operator <<(std::ostream & os, const Online & o);

#endif /* TITULO_H_ */
