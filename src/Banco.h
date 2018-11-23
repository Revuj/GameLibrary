#ifndef SRC_BANCO_H_
#define SRC_BANCO_H_

#include "CartaoCredito.h"
#include <vector>

/**
 * Banco que contem os cartoes de credito dos utilizadores.
 */
class Banco
{
	std::vector<CartaoCredito> CartoesDeCredito; /**< vector que contem os cartoes de credito*/
	Data atual; /**< data atual */

public:

	/**
	 * @brief Construtor da classe Banco
	 */
	Banco();

	/**
	 * @brief Destrutor da class Banco
	 */

	~Banco();

	/**
	 * @brief atualiza a data, para a data atual
	 */
	void setDataAtual();

	/**
	 * @brief devolve a data atual
	 *
	 */
	Data getDataAtual() const;

	/**
	 * @brief Permite obter os cartoes de credito dos utilizadores
	 * @return Retorna o vetor de cartoes de credito
	 */
	std::vector<CartaoCredito> getCartoesCredito() const;


	/**
	 * @brief Verifica se uma data e valida
	 * @param cartao - cartao de credito cuja data vai ser verificada
	 * @return retorna true se a data for valida, ou false de outra forma
	 */
	bool isDataValida(const CartaoCredito & cartao) const ;


	/**
	 * @brief Adiciona um cartao de credito ao banco
	 * @param cartao - cartao de credito a adicionar
	 */
	void adicionaCartaoCredito(const CartaoCredito & cartao);


	/**
	 * @brief Adiciona um vector de cartoes de credito ao banco
	 * @param cartoes - vector de cartoes de credito a adicionar ao banco
	 */
	void adicionaCartoesCredito(const std::vector <CartaoCredito> & cartoes);

	/**
	 * @brief Atualiza a data de um cartao de credito, adicionando mais 3 anos de validade, se esta fora da validade ou se faltam ate 90 dias ate ao fim do prazo
	 * @param cartao - cartao de credito a atualizar
	 */
	void atualizaCartao(CartaoCredito & cartao);

	/**
	 * @brief Atualiza todos os cartoes do sistema
	 */
	void atualizaCartoesCredito();

};

std::ostream & operator <<(std::ostream & os, const Banco & banco);



#endif /* SRC_BANCO_H_ */
