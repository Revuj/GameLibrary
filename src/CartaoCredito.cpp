#include "CartaoCredito.h"
#include "Erro.h"

/*
 * construtor
 */

CartaoCredito::CartaoCredito(const float saldo,const Data & d1,const std::string iD)
: id(iD) /* id deve ser diferente de todos os cartoes*/
{
	this->saldo=saldo;
	this->dataDeValidade = d1;

}

float CartaoCredito::getSaldo() const
{
	return this->saldo;
}


Data CartaoCredito::getDataDeValidade() const
{
	return this->dataDeValidade;
}

void CartaoCredito::atualizaDataDeValidade()
{
	this->dataDeValidade.setAno(this->dataDeValidade.getAno() + 3);
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

std::ostream & operator <<(std::ostream & os, const CartaoCredito & cartao)
{
	os << "Saldo: " << cartao.getSaldo() << std::endl;
	os << "Id: " << cartao.getId() << std::endl;
	os << "Data de Validade: " << cartao.getDataDeValidade() << std::endl;
	return os;
}


