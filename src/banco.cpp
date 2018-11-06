#include "Erro.h"
#include "banco.h"
#include <time.h>
#include <algorithm>



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


}

void Banco::atualizaDataCartao(const CartaoCredito & C)
{
	if(!isDataValida(C))
		C.getDataDeValidade().setAno(C.getDataDeValidade().getAno()+3);
	else
	{
		if (C.getDataDeValidade().diferencaEntreDatas(this->getDataAtual()) <= 90)
			C.getDataDeValidade().setAno(C.getDataDeValidade().getAno()+3);
	}
}

void Banco::atualizaCartoesCredito()
{
	for(auto const  & cartao : this->CartoesDeCredito)
	{
		atualizaDataCartao(cartao);
	}
}


