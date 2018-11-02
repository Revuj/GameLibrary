#include "Utilizador.h"
#include "Titulo.h"
#include <algorithm>
#include "Erro.h"
#include <vector>

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
	return (this->nome == U.nome) && (this->morada == U.morada)
			&& (this->idade == U.idade) && (this->email == U.email)
			&& (this->conjuntoTitulos == U.conjuntoTitulos)
			&& (this->cc == U.cc);
}


bool Utilizador::adicionaCartaoCredito(const CartaoCredito & C)
{
	/*se nao existe, acrescenta*/
	if( find(this->cc.begin(),this->cc.end(),C) != cc.end())
	{
		this->cc.push_back(C);
		return true;

	}
	else
		return false;
}


void Utilizador::AdicionaTitulo(Titulo * T,std::string plataforma, CartaoCredito & c)
{
/* comparar data de valdiade do cartao e a data atual(ver funcoes)*/

	//nao encontra esse titulo, se encontrar throw titulo ja existente
	if (find( this->conjuntoTitulos.getTitulos().begin(), this->conjuntoTitulos.getTitulos().begin(), T ) != this->conjuntoTitulos.getTitulos().end())
	{
		for (const auto & cartao : this->cc)
		{
			if (cartao == c)
			{
				if (cartao.getSaldo() >= T->getPrecoAtual(plataforma)) //ver se o saldo para comprar o titulo é suficiente
				{
					this->conjuntoTitulos.adicionaTitulo(T);
					c.removeQuantia(T->getPrecoAtual(plataforma)); //retira dinheiro do cartao
				}
				else
					throw SaldoInsuficiente(cartao.getSaldo());
			}
			else
				throw CartaoInexistente(c.getId());
		}
	}
	else
		throw TituloJaAdicionado(T->getNome());
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

std::vector<std::string> Utilizador::PlataformaPreferida() const {
	std::vector<Titulo *> titulos=conjuntoTitulos.getTitulos();
	std::vector<std::string> plataformas;
	for(auto i: titulos){
		std::map<std::string, std::vector<float>> p = i->getPrecosPlataforma();
		for (const auto &s : p)
		   plataformas.push_back(s.first);
	}

	std::map<std::string, int> m;

	for (size_t i = 0; i < plataformas.size(); i++)
	   {
	     std::map<std::string, int>::iterator it = m.find(plataformas[i]);

	      if (it == m.end())
	        m[plataformas[i]]= 1;

	      else
	        m[plataformas[i]] += 1;
	     }

	std::vector<std::string> plataformasPreferidas;
	int max=1;
	for(auto it=m.cbegin();it!=m.cend();it++){
		if (it ->second > max)
		    {
				plataformasPreferidas.clear();
		        max = it->second;
		        plataformasPreferidas.push_back(it->first);
		    }
		else if(it->second == max)
			plataformasPreferidas.push_back(it->first);
	}
	return plataformasPreferidas;
}
