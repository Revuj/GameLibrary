#include "CartaoCredito.h"
#include "Erro.h"

/*
 * construtor
 */

CartaoCredito::CartaoCredito(const unsigned int saldo,const Data & d1,const std::string iD)
: id(iD) /* id deve ser diferente de todos os cartoes*/
{
	this->saldo=saldo;
	this->dataDeValidade = d1;

}

unsigned int CartaoCredito::getSaldo() const
{
	return this->saldo;
}


Data CartaoCredito:: getDataDeValidade() const
{
	return this->dataDeValidade;
}

std::string CartaoCredito::getId() const
{
	return this->id;
}

bool CartaoCredito::operator==(const CartaoCredito &C) const
{
	return (this->id== C.id);

}

void CartaoCredito::adicionaQuantia(float quantia)
{
	this->saldo += quantia;
}

void CartaoCredito::removeQuantia(float quantia)
{
	if (this->saldo - quantia >= 0)
		this->saldo -= quantia;
	else throw SaldoInsuficiente(this->saldo);
}


