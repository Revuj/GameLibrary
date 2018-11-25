#include "Utilizador.h"
#include "Titulo.h"
#include <algorithm>
#include "Erro.h"
#include <vector>
#include "Banco.h"

/*
 * construtor utilizador que atua como um construtor default
 */

Utilizador::Utilizador(const std::string nome, const std::string email, const size_t idade, const std::string morada, const Biblioteca biblioteca) {
	this->nome = nome;
	this->email = email;
	this->idade = idade;
	this->morada = morada;
	this->conjuntoTitulos = biblioteca;
}

/*
 * funcoes "get" para aceder aos membro-dados do utilizaodor
 */
std::string Utilizador::getNome() const {
	return this->nome;
}

std::string Utilizador::getEmail() const {
	return this->email;
}

size_t Utilizador::getIdade() const {
	return this->idade;
}

std::string Utilizador::getMorada() const {
	return this->morada;
}

std::vector<CartaoCredito> Utilizador::getCc() const {
	return this->cc;
}

Biblioteca Utilizador::getBiblioteca() const {
	return this->conjuntoTitulos;
}


bool Utilizador::operator ==(const Utilizador & U) // a modificar, provavelmente

		{
	return (this->nome == U.nome) && (this->email == U.email);

}


bool Utilizador::adicionaCartaoCredito(const CartaoCredito & C)
{
	/*se nao existe, acrescenta*/
	if( find(this->cc.begin(),this->cc.end(),C) == cc.end())
	{
		this->cc.push_back(C);
		return true;

	}
	else
		throw(CartaoJaExistente("Cartao com id " + C.getId() + " ja existe."));
	return false;
}


void Utilizador::AdicionaTitulo(Titulo * T, CartaoCredito & c,bool comprar)
{
/* comparar data de valdiade do cartao e a data atual(ver funcoes)*/
	for (auto & cartao : this->cc)
	{
		if (cartao == c)
		{
			if (cartao.getSaldo() >= T->getPreco()) //ver se o saldo para comprar o titulo é suficiente
			{
				this->conjuntoTitulos.adicionaTitulo(T);
				cartao.removeQuantia(T->getPreco()); //retira dinheiro do cartao
				return;
			}
			else
				throw SaldoInsuficiente("Saldo insuficiente no cartao " +  c.getId() + ". Saldo: " + std::to_string(cartao.getSaldo()));
		}
	}
	throw CartaoInexistente(c.getId());



}

std::ostream & operator <<(std::ostream & os, const Utilizador & u)
{
	os << "Nome: " << u.getNome() << std::endl;
	os << "E-mail: " << u.getEmail() << std::endl;
	os << "Idade: " << u.getIdade() << std::endl;
	os << "Morada: " << u.getMorada() << std::endl;

	os << "Cartoes de Credito: " << std::endl;
	for (const auto & cartao : u.getCc())
	{
		os << cartao.getId() << std::endl;
	}

	os << "Jogos na Biblioteca: " << std::endl;
	for (const auto & titulo : u.getBiblioteca().getTitulos())
		{
			os << "->" << titulo->getNome() << std::endl;
		}
	return os;
}

std::string Utilizador::PlataformaPreferida() const {

	std::vector<std::string> plataformas;
	std::vector<Titulo*> titulos=conjuntoTitulos.getTitulos();

	for(size_t i=0;i<titulos.size();i++){
		plataformas.push_back(titulos.at(i)->getPlataforma());
	}

    int max=0;
    std::string mostvalue=plataformas[0];
    for(size_t i=0;i<plataformas.size();i++)
    {
        int co = std::count(plataformas.begin(), plataformas.end(), plataformas[i]);
        if(co > max)
        {       max = co;
                mostvalue = plataformas[i];
        }
    }
    return mostvalue;
}

float Utilizador::getGastos() const{
	float total=0;
	std::vector<Titulo*> titulos=conjuntoTitulos.getTitulos();
	for (auto titulo : titulos){
		total += titulo->getGastos();
		total += titulo->getPreco();
	}
	return total;
}
