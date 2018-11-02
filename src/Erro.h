#ifndef ERRO_H_
#define ERRO_H_

#include <iostream>

class PrecoInvalido {
private:
	float preco;
public:
	PrecoInvalido(float preco) {
		this->preco = preco;
	}
};

std::ostream & operator <<(std::ostream & os, const PrecoInvalido & preco);

//========================================================================================
//========================================================================================

class PlataformaNaoExistente {
private:
	std::string plataforma;
public:
	PlataformaNaoExistente(std::string plataforma) {
		this->plataforma = plataforma;
	}
};

std::ostream & operator <<(std::ostream & os, const PlataformaNaoExistente & plataforma);

//========================================================================================
//========================================================================================

class SaldoInsuficiente {
private:
	unsigned int saldo;
public:
	SaldoInsuficiente(unsigned int saldo) {
		this->saldo = saldo;
	}
	unsigned int getSaldo() const {
		return this->saldo;
	}
};

std::ostream & operator <<(std::ostream & os, const SaldoInsuficiente & saldo);

//========================================================================================
//========================================================================================

class CartaoInexistente {
private:
	std::string id;
public:
	CartaoInexistente(const std::string id) {
		this->id = id;
	}
	std::string getId() const {
		return this->id;
	}
};

std::ostream & operator <<(std::ostream & os, const CartaoInexistente & cartao);

//========================================================================================
//========================================================================================

class TituloJaAdicionado {
private:
	std::string nome;
public:
	TituloJaAdicionado(std::string nome) {
		this->nome = nome;
	}
	std::string getNome() const {
		return this->nome;
	}
};

std::ostream & operator <<(std::ostream & os, const TituloJaAdicionado & titulo);

//========================================================================================
//========================================================================================

class PlataformaJaExistente{
	std::string plataforma;
public:
	PlataformaJaExistente(std::string plataforma):plataforma(plataforma){}
	std::string getPlataforma() const {return plataforma;}
};

#endif /* ERRO_H_ */