#ifndef SRC_SISTEMA_H_
#define SRC_SISTEMA_H_

#include "Utilizador.h"
#include "Banco.h"
#include "Empresa.h"
#include <string>
#include <fstream>
#include <iomanip>

/* ------------------ Bibliotecas da segunda parte do trabalho ----*/

#include <set> // para usar bst


typedef std::set<Empresa*,EmpresasComp> BSTEmpresa;

/**
 * Classe que gere as contas dos utilizadores
 */
class Sistema {
private:
	std::vector <Utilizador *> jogadores; /**< Conjunto de utilizadores do sistema */
	std::vector <Titulo *> titulos; /**< Conjunto de titulos disponiveis */
	std::vector <std::string> plataformas; /**< Plataformas onde os titulos estao disponiveis */
	Banco banco; /**< Banco para gerir cartoes de credito no sistema */
	BSTEmpresa empresas; /**< Conjunto de empresas disponiveis */
public:
	/**
	 * @brief Construtor da class Sistema
	 */
	Sistema() {};

	/**
	 * @brief Destrutor da class Sistema
	 */
	~Sistema();

	/**
	 * @brief Le um utilizador de um ficheiro
	 * @param file - ficheiro onde esta contida a informacao sobre o utilizador
	 */
	void readFileUtilizadores(std::ifstream & file);

	/**
	 * @brief Invoca as funcoes necessarias para ler os utilizadores guardados nos ficheiros
	 */
	void readUtilizadores();

	/**
	 * @brief Guarda todos os utilizadores do sistema em ficheiros, criando novos, se necessario
	 */
	void saveUtilizadores() const;

	/**
	 * @brief Le os titulos de um ficheiro
	 * @param file - ficheiro onde esta contida a informacao de todos os titulos
	 */
	void readFileTitulos(std:: ifstream & file);

	/**
	 * @brief Invoca as funcoes necessarias para ler os titulos guardados nos ficheiros
	 */
	void readTitulos();

	/**
	 * @brief Guarda todos os titulos do sistema num ficheiro
	 */
	void saveTitulos() const;

	/**
	 * @brief Le as empresas de um ficheiro
	 *
	 * @param file - ficheiro onde esta contida a informacao de todas as empresas
	 */
	void readFileEmpresas(std::ifstream & file);

	/**
	 * @brief Invoca as funcoes necessarias para ler as empresas guardadas nos ficheiros
	 *
	 */
	void readEmpresas();

	/**
	 * @brief Guarda todas as empresas do sistema num ficheiro
	 *
	 */
	void saveEmpresas();

	/**
	 * @biref Verifica se o email ja existe
	 * @return Retorna true se o email nao existir, ainda
	 */
	bool validEmail(const std::string email) const;

	/**
	 * @brief Verifica se o email e valido sintaticamente e verifica a sua existencia, se necessario
	 * @param email - email a verificar
	 * @param checkafter - parametro que especifica a necessidade de verificar a existencia do email
	 */
	void isValidEmail(std::string & email,bool checkafter=false) const;

	/**
	 * @brief Simula o "jogar" de um utilizador, incrementando o tempo jogado e guardando uma data do dia em que jogou
	 * @param u - apontador para o utilizador a jogar
	 * @param t - apontador para o titulo a ser jogado
	 * @param minutos - minutos jogados pelo utilizador
	 */
	void utilizadorJogar(Utilizador *u, Titulo * t, unsigned int minutos);

	/**
	 * @brief Mostra o saldo de um utilizador do sistema
	 * @param u - apontador para o utilizador, cujo saldo vai ser verificado
	 */
	void saldoUtilizador(const Utilizador *u) const;

	/**
	 * @brief Mostra o tempo jogado por um utilizador
	 * @param u - apontador para o utiliziador, cujo tempo jogado vai ser verificado
	 */
	void tempoJogado(const Utilizador *u) const;

	/**
	 * @brief Adiciona um novo utilizador ao sistema
	 * @param u - apontador para o utilizador a ser adicionado
	 */
	void adicionaUtilizador(Utilizador *u);

	/**
	 * @brief Adiciona um novo titulo ao sistema
	 * @param titulo - apontador para o titulo a ser adicionado
	 */
	void addTitulo(Titulo *titulo,std::string empresa);

	/**
	 * @brief Adiciona uma nova empresa ao sistema
	 * @param empresa - apontador para a empresa a ser adicionada
	 */
	void adicionaEmpresa(Empresa *empresa);

	/**
	 * @brief Adiciona uma atualizacao a um titulo do sistema
	 * @param nome - nome do titulo que vai ter uma atualizacao
	 * @param plataforma - plataforma do titulo
	 * @param data - data da atualizacao
	 */
	void adicionaAtualizacao(std::string nome,std::string plataforma,Data data);

	/**
	 * @brief Mostra os utilizadores de forma ordenada
	 * @param tipo - especifica o modo como queremos ordenar os utilizadores
	 * @param ascend - especifica se a ordem deve ser crescente ou decrescente
	 */
	void ordenaUtilizadores(std::string tipo,bool ascend);

	/**
	 * @brief Mostra os titulos de forma ordenada
	 * @param tipo - especifica o modo como queremos ordenar os titulos
	 * @param ascend - especifica se a ordem deve ser crescente ou decrescente
	 */
	void ordenaTitulos(std::string tipo, bool ascend);

	/**
	 * @brief Pesquisa um utilizador
	 * @param nome - nome do utilizador a ser pesquisado
	 * @param email - email do utilizador a ser pesquisado
	 * @return Retorna um apontador para o utilizador, quando este se encontra no sistema
	 */
	Utilizador* pesquisaUtilizador(std::string nome, std::string email);

	/**
	 * @brief Pesquisa um titulo
	 * @param nome - nome do titulo a ser pesquisado
	 * @param email - email do titulo a ser pesquisado
	 * @return Retorna um apontador para o titulo, quando este se encontra no sistema
	 */
	Titulo* pesquisaJogo(std::string nome,std::string plataforma) const;

	/**
	 * @brief Pesquisa uma empresa
	 * @param nome - nome da empresa a ser pesquisada
	 * @param nif - nif da empresa a ser pesquisada
	 * @return Retorna um apontador para a empresa, quando esta se encontra no sistema
	 */
	Empresa* pesquisaEmpresa(std::string nome,std::string nif) const;

	/**
	 * @brief Ordena os titulos de um utilizador
	 * @param u - apontador para o utilizador cujos titulos vao ser ordenados
	 * @param ascend - especifica se a ordem deve ser crescente ou decrescente
	 */
	std::vector<Titulo*> ordenaTitulosUtilizador(const Utilizador *u, std::string criterio,bool ascend) const;

	/**
	 * @brief Numero medio de titulos nas bibliotecas dos utilizadores do sistema
	 * @return Retorna o numero medio de titulos
	 */
	unsigned int nrMedioTitulos() const;

	/**
	 * @brief Custo meido de uma biblioteca
	 * @return Retorna o custe medio das bibliotecas dos utilizadores do sistema
	 */
	float custoMedioBiblioteca() const;

	/**
	 * @brief Mostra o ranking de popularidade de generos
	 */
	void rankingDeGeneros() const;

	/**
	 * @brief Mostra o ranking de popularidade de plataformas
	 */
	void rankingDePlataformas() const;

	/**
	 * @brief Mostra o ranking de popularidade de idades
	 */
	void rankingDeIdades() const;

	/**
	 * @brief Mostra o ranking de titulos por rentabilidade
	 */
	void rankingDeRentabilidades() const;

	/**
	 * @brief Devolve os utilizadores do sistema
	 * @return Retorna um vetor de apontadores para os utilizadores do sistema
	 */
	std::vector <Utilizador*> getJogadores() const;

	/**
	 * @brief Mostra os utilizadores do sistema
	 */
	void displayUtilizadores() const;

	/**
	 * @brief Devolve os titulos do sistema
	 * @return Retorna um vetor de apontadores para os titulos do sistema
	 */
	std::vector <Titulo *> getTitulos() const;

	/**
	 * @brief Mostra os titulos do sistema
	 */
	void displayTitulos() const;

	/**
	 * @brief Mostra no ecra as empresas consoante o conteudo de s
	 *
	 * @param s - string que define o que sera mostrado no ecra
	 */
	void displayEmpresas(std::string s) const;

	/**
	 * @brief Devolve as plataformas do sistema
	 * @return Retorna um vetor de plataformas do sistema
	 */
	std::vector <std::string> getPlataformas() const;

	/**
	 * @brief Devolve o banco do sistema
	 * @return Retorna o Banco do sstema
	 */
	Banco getBanco() const;

	/**
	 * @brief Verifica se a data de um cartao de credito e valida
	 */
	void dataValida( CartaoCredito & D) const;

	/**
	 * @brief Atualiza os utilizadores adormecidos de todos os utilizadores
	 *
	 */
	void atualizaAsleepUsers();

	/**
	 * @brief Remove os utilizadores adormecidos dos titulos para uma dada plataforma
	 *
	 * @param plataforma - string que define a plataforma para o qual s�o removidos os utilizaores adormecidos
	 * @param u - utilizador a remover
	 */
	void removeAsleepUsers(std::string plataforma,Utilizador *u);

	/**
	 * @brief Mostra no ecra os utilizadores adormecidos consoante o conteudo da string s
	 *
	 * @param s - string que define quais utilizadores adormecidos mostrar
	 */
	void displayAsleepUsers(std::string s);
};




#endif /* SRC_SISTEMA_H_ */
