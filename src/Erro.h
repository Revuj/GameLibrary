#ifndef ERRO_H_
#define ERRO_H_

#include <iostream>

/**
 * Classe Erro utilizada para tratamento de excecoes no decorrer do programa.
 */
class Erro {
private:
	const std::string info;		/**< Informacao do erro que ocorreu aquando uma excecao */
public:
	/**
	 * @brief Construtor da classe Erro
	 * @param info - Descricao do tipo de erro que aconteceu aquando o lancamento de uma excecao
	 */
	Erro(const std::string &info) : info(info) {}

	/**
	 * @brief Permite obter a descricao do Erro
	 * @return Retorna a descricao do Erro
	 */
	const std::string getInfo() const { return info; }
};

//========================================================================================
//========================================================================================

/**
 * Classe utilizada para lancar excecoes do tipo Data Invalida
 */
class DataInvalida : public Erro {
public:
	/**
	 * @brief Construtor da classe DataInvalida
	 */
	DataInvalida(const std::string &info) : Erro(info) { }
};

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
//========================================================================================

class TituloInexistente : public Erro {
public:
	/**
	 * @brief Construtor da classe TituloInexistente
	 */
	TituloInexistente(const std::string &info) : Erro(info) { }
};


//========================================================================================
//=======================================================================================

class InputInvalido : public Erro {
public:
	/**
	 * @brief Construtor da classe InputInvalido
	 */
	InputInvalido(const std::string &info) : Erro(info) { }
};

//========================================================================================
//=======================================================================================

class UtilizadorInexistente : public Erro {
public:
	/**
	 * @brief Construtor da classe InputInvalido
	 */
	UtilizadorInexistente(const std::string &info) : Erro(info) { }
};

//========================================================================================
//=======================================================================================

class ErroEmail: public Erro {
public:
    /**
     * @brief Construtor da classe UtilizadorInexistente
     */
    ErroEmail(const std::string &info) : Erro(info) { }
};

//========================================================================================
//=======================================================================================

class EmpresaInexistente : public Erro {
public:
	/**
	 * @brief Construtor da classe InputInvalido
	 */
	EmpresaInexistente(const std::string &info) : Erro(info) { }
};

class EmpresaJaAdicionada : public Erro {
public:
	/**
	 * @brief Construtor da classe InputInvalido
	 */
	EmpresaJaAdicionada(const std::string &info) : Erro(info) { }
};

#endif /* ERRO_H_ */
