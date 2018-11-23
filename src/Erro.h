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

class PlataformaJaExistente{
	std::string plataforma;
public:
	PlataformaJaExistente(std::string plataforma) {
		this->plataforma = plataforma;
	}
	std::string getPlataforma() const {
		return this->plataforma;}
};

std::ostream & operator <<(std::ostream & os, const PlataformaJaExistente & plataforma);
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

class CartaoJaExistente {
private:
	std::string id;
public:
	CartaoJaExistente(const std::string id) {
		this->id = id;
	}
	std::string getId() const {
		return this->id;
	}
};

std::ostream & operator <<(std::ostream & os, const CartaoJaExistente & cartao);

//========================================================================================
//========================================================================================

class CartaoInvalido {
private:
	std::string id;
public:
	CartaoInvalido(const std::string id) {
		this->id = id;
	}
	std::string getId() const {
		return this->id;
	}
};

std::ostream & operator <<(std::ostream & os, const CartaoInvalido & cartao);

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
//=======================================================================================

/**
 * Classe utilizada para lan�ar exce��es do tipo Input Inv�lido
 */
class InputInvalido{
private:
	const std::string info;
public:
	/**
	 * @brief Construtor da classe InputInvalido
	 */
	InputInvalido(const std::string &info) :info(info) { }

	const std::string getInfo() const { return info; } 
};


#endif /* ERRO_H_ */
