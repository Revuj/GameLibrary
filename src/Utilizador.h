#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
/*#include <vector>*/

#include "CartaoCredito.h"
#include "Biblioteca.h"

class Utilizador {

private:
	std::string nome;
	std::string email;
	size_t idade;
	std::string morada;
	std::vector<CartaoCredito> cc;
	Biblioteca conjuntoTitulos;

public:
	Utilizador(const std::string nome = "", const std::string email = "", /*construtor nao inclui cartoes de credito*/const size_t idade = 0, const std::string morada = "", const Biblioteca b =Biblioteca());
	std::string getNome() const;
	std::string getEmail() const;
	size_t getIdade() const;
	std::string getMorada() const;
	std::vector<CartaoCredito> getCc() const;
	Biblioteca getBiblioteca() const;
	bool operator ==(const Utilizador & U);
	/*
	 * adiciona um cartao de credito caso este ainda nao exista
	 * param C cartao de credito
	 * return true se foi inserido senao falso
	 */
	bool adicionaCartaoCredito(const CartaoCredito & C);

	/*
	 * ve se pode adicionar um titulo à biblioteca
	 * @param T titulo a acrescentar
	 * @param plataforma onde vamos comprar titulo
	 * return true ou false mediante se foi ou nao possivel adicionar um titulo
	 */
	void AdicionaTitulo(Titulo * T,std::string plataforma, CartaoCredito & c);

};

std::ostream & operator <<(std::ostream & os, const Utilizador & u);





#endif /* UTILIZADOR_H_ */
