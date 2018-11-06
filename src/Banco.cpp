#include "Erro.h"
#include <time.h>
#include <algorithm>
#include "Banco.h"
#include "iomanip"



Banco::Banco() {
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	unsigned int dia= aTime->tm_mday;
	unsigned int mes = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	unsigned int ano = aTime->tm_year + 1900;

	this->atual.setDia(dia).setMes(mes).setAno(ano);
}

Banco::~Banco() {

}


Data Banco::getDataAtual() const
{
	return this->atual;
}

std::vector<CartaoCredito> Banco::getCartoesCredito() const
{
	return this->CartoesDeCredito;
}

bool Banco::isDataValida(const CartaoCredito & C) const
{
		if (atual <= C.getDataDeValidade())
			return true;
		else
			return false;
}

/*execoes a implementar*/
void Banco::adicionaCartaoCredito(const CartaoCredito & C)
{
	/*ve se ja existe cartao de credito*/
	if (find(this->CartoesDeCredito.begin(),this->CartoesDeCredito.end(),C) != this->CartoesDeCredito.end())
		throw CartaoJaExistente(C.getId());

	if(!isDataValida(C))
		throw CartaoInvalido(C.getId());

	this->CartoesDeCredito.push_back(C);
}

void Banco::adicionaCartoesCredito(const std::vector <CartaoCredito> & cartoes)
{
	for (auto const & cartao : cartoes)
	{
		adicionaCartaoCredito(cartao);
	}
}

void Banco::atualizaCartao(CartaoCredito & C)
{
	if(!isDataValida(C))
		C.atualizaDataDeValidade();
	else
	{
		if (C.getDataDeValidade().diferencaEntreDatas(this->getDataAtual()) <= 90)
			C.atualizaDataDeValidade();
	}
}

void Banco::atualizaCartoesCredito()
{
	for(auto & cartao : this->CartoesDeCredito)
	{
		atualizaCartao(cartao);
	}
}

#include <iostream>
std::ostream & operator <<(std::ostream & os, const Banco & banco)
{
	unsigned int counter = 0;

	for (const auto & cartao : banco.getCartoesCredito())
	{

		if (counter % 3 == 0)
		{
			os << std::endl << "Cartao " << counter + 1 << ": " <<  cartao.getId();
		}
		else
			os << std::setw(15) << "Cartao " << counter + 1 << ": " <<  cartao.getId();

		counter++;
	}
	return os;
}

