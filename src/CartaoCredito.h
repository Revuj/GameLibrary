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

public:
	CartaoCredito (unsigned int = 0,const Data& = Data()); /* construtor que atua que tambem atua como construtor default*/
	unsigned int getSaldo();
	Data getDataDeValidade();

	/*
	 * compara dois cartoes
	 * @param C cartao de credito a comparar com o objeto atual
	 * return true se iguais senao falso
	 */
	bool operator==(CartaoCredito C);
};




#endif /* SRC_CARTAOCREDITO_H_ */
