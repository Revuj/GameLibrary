#ifndef SRC_CARTAOCREDITO_H_
#define SRC_CARTAOCREDITO_H_

/**
 * Classe CartaoCredito utilizada na classe utilizador
 */

#include "Data.h"



class CartaoCredito {
private:
	float saldo;
	Data dataDeValidade;
	const std::string id; /*string de numeros que identificam o cartao, membro dado nao mutavel*/

public:
	CartaoCredito (const float saldo= 0,const Data& d1= Data(),const std::string iD=""); /* construtor que atua que tambem atua como construtor default*/
	float getSaldo() const;
	Data getDataDeValidade() const;

	/*
	 * devolve o id(string) do cartao de credito atual
	 */
	std::string getId()const;

	void atualizaDataDeValidade();

	/*
	 * compara dois cartoes
	 * @param C cartao de credito a comparar com o objeto atual
	 * return true se iguais senao falso
	 */
	bool operator==(const CartaoCredito &C) const ;
	/*
	 * adiciona quantia ao saldo do Cart�o de Cr�dito
	 */
	void adicionaQuantia(float quantia);

	/*
	 * remove quantia ao saldo do Cart�o de Cr�dito
	 */
	void removeQuantia(float quantia);

};

std::ostream & operator <<(std::ostream & os, const CartaoCredito & cartao);

#endif /* SRC_CARTAOCREDITO_H_ */
