#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <queue>
#include "CartaoCredito.h"
#include "Biblioteca.h"
#include "WishedTitle.h"

class Titulo;

/**
 * Utilizador que foi declarado no Sistema
 */
class Utilizador {

private:
	std::string nome;/**< Nome do utilizador */
	std::string email;/**< Email do utilizador */
	unsigned idade;/**< Idade do utilizador */
	std::string morada;/**< Morada do utilizador */
	std::vector<CartaoCredito> cc;/**< Vetor com os cartoes de credito do utilizador */
	Biblioteca conjuntoTitulos;/**< Biblioteca com todos os Titulos do utilizador */

	/*segunda parte do trabalho*/
	std::priority_queue<WishedTitle> wishlist; /**< Wishlist do utilizador  */
	Data ultimaCompra; /** < Data da ultima compra do utilizador */
public:
	/**
	 * @brief Construtor da classe Utilizador
	 * @param nome - Nome atribuido ao utilizador
	 * @param email - Email atribuido ao utilizador
	 * @param idade - Idade atribuido ao utilizador
	 * @param morada - Morada atribuido ao utilizador
	 * @param b - Biblioteca atribuida ao utilizador
	 */
	Utilizador(const std::string nome = "", const std::string email = "", const unsigned idade = 0, const std::string morada = "", const Biblioteca b=Biblioteca());

	/**
	 * @brief Permite obter o nome do utilizador 
	 * @return Retorna o nome do utilizador
	 */
	std::string getNome() const;
	
	/**
	 * @brief Permite obter o email do utilizador 
	 * @return Retorna o email do utilizador
	 */
	std::string getEmail() const;
	
	/**
	 * @brief Permite obter a idade do utilizador
	 * @return Retorna a idade do utilizador 
	 */
	unsigned getIdade() const;
	
	/**
	 * @brief Permite obter a morada do utilizador
	 * @return Retorna string com morada do utilizador
	 */
	std::string getMorada() const;

	/**
	 * @brief Permite obter o vetor de cartoes de credito do utilizador 
	 * @return Retorna o vetor de cartoes de credito do utilizador
	 */
	std::vector<CartaoCredito> getCc() const;

	/**
	 * @brief Permite obter a biblioteca do utilizador 
	 * @return Retorna a biblioteca do utilizador
	 */
	Biblioteca getBiblioteca() const;

	/**
	 * @brief Devolve a diferenca entre a data atual e a data da ultima compra
	 * @return Retorna a diferenca entre a data atual e a data da ultima compra
	 */
	unsigned getMonthsLastBuy();


	/**
	 * @brief Devolve a data da ultima compra
	 * @return Retorna a data da ultima compra
	 */
	Data getDataUltimaCompra(){ return this->ultimaCompra; }

	/**
	 * @brief Altera a data da ultima compra
	 * @param data - data nova, da ultima compra
	 */
	void setDataUltimaCompra(std::string data){this->ultimaCompra=Data(data);}

	/**
	 * @brief Overload do operador de igualdade para a classe Utilizador
	 * @param U - Utilizador a ser comparado
	 * @return Retorna verdadeiro se os utilizadores forem iguais, caso contr�rio retorna falso
	 */
	bool operator ==(const Utilizador & U);
	
	/**
	 * @brief Adiciona um cartao de credito caso este ainda nao exista
	 * @param C - cartao de credito
	 * @return Retorna verdadeiro se adicionar o cartao de credito, caso contr�rio retorna falso
	 */
	bool adicionaCartaoCredito(const CartaoCredito & C);

	/**
	 * @brief Adiciona um titulo ao utilizador 
	 * @param T - Titulo a acrescentar
	 * @param c - Cartao de credito para efutuar compra
 	 */
	void AdicionaTitulo(Titulo * T, CartaoCredito & c,bool comprar=false);

	/**
	 * @brief Adiciona um novo titulo a wishlist
	 * @param titulo - apontador para o titulo a adicionar
	 * @param interesse - interesse que o utilizador revela pelo titulo a adicionar
	 */
	void adicionaWishList(Titulo* titulo,unsigned interesse);

	/**
	 * @brief Devolve a wishlist do utilizador
	 * @return Retorna a wishlist do utilizador
	 */
	std::priority_queue<WishedTitle> getWishList();

	/**
	 * @brief Remove um titulo da wishlist
	 * @param titulo - apontador para o titulo a remover
	 * @return Retorna true no caso do titulo existir e for removido, false de outra forma
	 */
	bool removeWishList(Titulo *titulo);

	/**
	 * @brief Devolve o primeiro titulo da wishlist com uma probabilidade minima
	 * @param minProbabilidade - probabilidade minima a considerar na pesquisa de um titulo
	 * @return Retorna um WishedTitle com probabilidade de compra superior a probabilidade minima
	 */
	WishedTitle getGamesWishList(float minProbabilidade);

	/**
	 * @brief Calcula o preco total da biblioteca do utilizador
	 * @return Retorna o preco total da biblioteca
	 */
	float getGastos() const;

	/**
	 * @brief mostra no ecra as publicidades ao utilizador
	 */
	void printPublicidade();

	/**
	 * @brief Atualiza o interesse, num titulo
	 * @param t - apontador para o titulo a mudar o interesse
	 * @param interesse - novo interesse no titulo
	 */
	void atualizaInteresse(Titulo* t, unsigned int interesse);

	/**
	 * @brief Atualiza as probabilidades de compra para todos os titulos
	 */
	void atualizaProbabilidades();
};

std::ostream & operator <<(std::ostream & os, const Utilizador & u);

#endif /* UTILIZADOR_H_ */
