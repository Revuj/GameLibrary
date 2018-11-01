#ifndef SRC_CARTAOCREDITO_H_
#define SRC_CARTAOCREDITO_H_

/**
 * Classe CartaoCredito utilizada na classe utilizador
 */

#include "Data.h"



class CartaoCredito {
private:
	unsigned int saldo;
	Data dataDeValidade;
	const std::string id; /*string de numeros que identificam o cartao, membro dado nao mutavel*/

public:
	CartaoCredito (const unsigned int = 0,const Data& = Data(),const std::string=""); /* construtor que atua que tambem atua como construtor default*/
	unsigned int getSaldo() const;
	Data getDataDeValidade() const;

	/*
	 * devolve o id(string) do cartao de credito atual
	 */
	std::string getId()const;

	/*
	 * compara dois cartoes
	 * @param C cartao de credito a comparar com o objeto atual
	 * return true se iguais senao falso
	 */
	bool operator==(const CartaoCredito &C) const ;
	/*
	 * adiciona quantia ao saldo do Cartão de Crédito
	 */
	void adicionaQuantia(float quantia);

	/*
	 * remove quantia ao saldo do Cartão de Crédito
	 */
	void removeQuantia(float quantia);
};




#endif /* SRC_CARTAOCREDITO_H_ */
