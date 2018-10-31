
#include "CartaoCredito.h"

/*
 * construtor
 */

CartaoCredito::CartaoCredito(unsigned int saldo,const Data & d1)
{
	this->saldo=saldo;
	this->dataDeValidade = d1;
}

unsigned int CartaoCredito::getSaldo()
{
	return this->saldo;
}


Data CartaoCredito:: getDataDeValidade()
{
	return this->dataDeValidade;
}

bool CartaoCredito::operator==(CartaoCredito C)
{
	return (this->saldo=C.saldo) && (this->dataDeValidade==C.dataDeValidade);

}



