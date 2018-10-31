#include "utilizador.h"


/*
 * construtor utilizador que atua como um construtor default
 */

Utilizador::Utilizador(const std::string nome,const std::string email,const size_t idade,const std::string morada,const CartaoCredito cc, const Biblioteca biblioteca)
{
this->nome=nome;
this->email=email;
this->idade=idade;
this->morada=morada;
this->cc=cc;
this->conjuntoTitulos=biblioteca;
}

/*
 * funcoes "get" para aceder aos membro-dados do utilizaodor
 */
	std::string Utilizador::getNome()
	{
		return this->nome;
	}

	std::string Utilizador::getEmail()
	{
		return this->email;
	}

	size_t Utilizador::getIdade()
	{
		return this->idade;
	}

	std::string Utilizador::getMorada()
	{
		return this->morada;
	}

	CartaoCredito Utilizador::getCc()
	{
		return this->cc;
	}

	Biblioteca Utilizador::getBiblioteca()
	{
		return this->conjuntoTitulos;
	}

	bool Utilizador::operator == (const Utilizador & U) // a modificar, provavelmente

	{
		return (this->nome==U.nome) && (this->morada==U.morada) && (this->idade==U.idade) && (this->email==U.email)
				&& (this->conjuntoTitulos==U.conjuntoTitulos) && (this->cc==U.cc);
	}




