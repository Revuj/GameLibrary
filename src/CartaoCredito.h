#ifndef SRC_CARTAOCREDITO_H_
#define SRC_CARTAOCREDITO_H_

#include "Data.h"


/**
 * Classe CartaoCredito utilizada na classe Utilizador
 */
class CartaoCredito {
private:
	float saldo;/**< Saldo do cartao de credito */
	Data dataDeValidade;/**< Data de validade do cartao */
	const std::string id;/**< Identificador do cartao */

public:
	/**
	 * @brief Construtor da classe Cartao de credito
	 * @param saldo - Saldo a atribuir ao cartao
	 * @param d1 - Data da validade do Cartao
	 * @param iD - Identificador a atribuir ao cartao
	 */
	CartaoCredito (const float saldo= 0,const Data& d1= Data(),const std::string iD=""); /* construtor que atua que tambem atua como construtor default*/
	
	/**
	 * @brief devolve o saldo do cartao
	 * @return Retorna o saldo do utilizador
	 */
	float getSaldo() const;

	/**
	 * @brief Devolve a data de validade do cartao
	 * @return Retorna a data de validade do cartao
	 */
	Data getDataDeValidade() const;

	/**
	 * @brief Devolve o id(string) do cartao de credito atual
	 * @return Retorna o identificador do cartao
	 */
	std::string getId()const;

	/**
	 * @brief Atualiza a data de validade para a data atual
	 */
	void atualizaDataDeValidade();

	/**
	 * @brief Overload do operador de igualdade
	 * @param C - cartao de credito a comparar com o objeto atual
	 * @return Retorna verdadeiro se os cartoes sao iguais
	 */
	bool operator==(const CartaoCredito &C) const ;
	
	/**
	 * @brief Adiciona uma quantia ao saldo do cartao
	 */
	void adicionaQuantia(float quantia);

	/**
	 * @brief Remove uma quantia ao saldo
	 */
	void removeQuantia(float quantia);
};

std::ostream & operator <<(std::ostream & os, const CartaoCredito & cartao);

#endif /* SRC_CARTAOCREDITO_H_ */
