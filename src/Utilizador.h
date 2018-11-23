#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include "CartaoCredito.h"
#include "Biblioteca.h"

/**
 * Utilizador que foi declarado no Sistema
 */
class Utilizador {

private:
	std::string nome;/**< Nome do utilizador */
	std::string email;/**< Email do utilizador */
	size_t idade;/**< Idade do utilizador */
	std::string morada;/**< Morada do utilizador */
	std::vector<CartaoCredito> cc;/**< Vetor com os cartoes de credito do utilizador */
	Biblioteca conjuntoTitulos;/**< Biblioteca com todos os Titulos do utilizador */

public:
	/**
	 * @brief Construtor da classe Utilizador
	 * @param nome - Nome atribuido ao utilizador
	 * @param email - Email atribuido ao utilizador
	 * @param idade - Idade atribuido ao utilizador
	 * @param morada - Morada atribuido ao utilizador
	 * @param b - Biblioteca atribuida ao utilizador
	 */
	Utilizador(const std::string nome = "", const std::string email = "", const size_t idade = 0, const std::string morada = "", const Biblioteca b=Biblioteca());

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
	size_t getIdade() const;
	
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
	 * @brief Overload do operador de igualdade para a classe Utilizador
	 * @param U - Utilizador a ser comparado
	 * @return Retorna verdadeiro se os utilizadores forem iguais, caso contrário retorna falso
	 */
	bool operator ==(const Utilizador & U);
	
	/**
	 * @brief Adiciona um cartao de credito caso este ainda nao exista
	 * @param C - cartao de credito
	 * @return Retorna verdadeiro se adicionar o cartao de credito, caso contrário retorna falso
	 */
	bool adicionaCartaoCredito(const CartaoCredito & C);

	/**
	 * @brief Adiciona um titulo ao utilizador 
	 * @param T - Titulo a acrescentar
	 * @param c - Cartao de credito para efutuar compra
 	 */
	void AdicionaTitulo(Titulo * T, CartaoCredito & c);

	/**
	 * @brief Calcula o preco total da biblioteca do utilizador
	 * @return Retorna o preco total da biblioteca
	 */
	float getGastos() const;

};

/**
* @brief Overload do operador de inserção para a classe Utilizador
* @param os - Stream passada por referência para a qual será efetuada a escrita
* @param u - Utilizador a ser enviado para a stream
* @return Retorna referência de stream de output
*/
std::ostream & operator <<(std::ostream & os, const Utilizador & u);

#endif /* UTILIZADOR_H_ */
