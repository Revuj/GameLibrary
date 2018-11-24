#ifndef ERRO_H_
#define ERRO_H_

#include <iostream>

/**
 * Classe Erro utilizada para tratamento de exceções no decorrer do programa.
 */
class Erro {
private:
	const std::string info;		/**< Informação do erro que ocorreu aquando uma exceção */
public:
	/**
	 * @brief Construtor da classe Erro
	 * @param info - Descrição do tipo de erro que aconteceu aquando o lancamento de uma exceção
	 */
	Erro(const std::string &info) : info(info) {}

	/**
	 * @brief Permite obter a descrição do Erro
	 * @return Retorna a descrição do Erro
	 */
	const std::string getInfo() const { return info; }
};

//========================================================================================
//========================================================================================

/**
 * Classe utilizada para lançar exceções do tipo Data Inválida
 */
//class DataInvalida : public Erro {
//public:
//	/**
//	 * @brief Construtor da classe DataInvalida
//	 */
//	DataInvalida(const std::string &info) : Erro(info) { }
//};

//========================================================================================
//========================================================================================

class PrecoInvalido:public Erro {
public:
	/**
	 * @brief Construtor da classe PrecoInvalido
	 */
	PrecoInvalido(const std::string &info) : Erro(info) { }
};

//========================================================================================
//========================================================================================

class PlataformaNaoExistente:public Erro {
public:
	/**
	 * @brief Construtor da classe PlataformaNaoExistente
	 */
	PlataformaNaoExistente(const std::string &info) : Erro(info) { }
};

//========================================================================================
//========================================================================================

class PlataformaJaExistente : public Erro{
public:
	/**
	 * @brief Construtor da classe PlataformaJaExistente
	 */
	PlataformaJaExistente(const std::string &info) : Erro(info) { }
};

//========================================================================================
//========================================================================================

class SaldoInsuficiente : public Erro{
public:
	/**
	 * @brief Construtor da classe SaldoInsuficiente
	 */
	SaldoInsuficiente(const std::string &info) : Erro(info) { }
};

//========================================================================================
//========================================================================================

class CartaoInexistente : public Erro {
public:
	/**
	 * @brief Construtor da classe CartaoInexistente
	 */
	CartaoInexistente(const std::string &info) : Erro(info) { }
};

//========================================================================================
//========================================================================================

class CartaoJaExistente : public Erro {
public:
	/**
	 * @brief Construtor da classe CartaoJaExistente
	 */
	CartaoJaExistente(const std::string &info) : Erro(info) { }
};

//========================================================================================
//========================================================================================

class CartaoInvalido : public Erro {
public:
	/**
	 * @brief Construtor da classe CartaoInvalido
	 */
	CartaoInvalido(const std::string &info) : Erro(info) { }
};

//========================================================================================
//========================================================================================

class TituloJaAdicionado : public Erro {
public:
	/**
	 * @brief Construtor da classe TituloJaAdicionado
	 */
	TituloJaAdicionado(const std::string &info) : Erro(info) { }
};

//========================================================================================
//=======================================================================================

/**
 * Classe utilizada para lan�ar exce��es do tipo Input Inv�lido
 */
class InputInvalido : public Erro {
public:
	/**
	 * @brief Construtor da classe InputInvalido
	 */
	InputInvalido(const std::string &info) : Erro(info) { }
};

#endif /* ERRO_H_ */
