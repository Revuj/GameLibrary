#ifndef DATA_H_
#define DATA_H_
#include <iostream>
#include <string>

/**
 * Classe data utilizada nos titulos
 */
class Data {

private:
	unsigned int dia, mes, ano;
public:

	/**
	 * @brief Construtor da classe Data
	 * @param d - dia
	 * @param m - mes
	 * @param a - ano
	 */
	Data(unsigned int dia = 1, unsigned int mes = 1, unsigned int ano = 2000);

	/**
	 * @brief Construtor da classe Data com parametros diferentes
	 * @param data - string a ser tranformada em data
	 */
	Data(std::string data);

	/**
	 * @brief Altera o dia 
	 * @param dia - Valor a aplicar a dia
	 * @return Retorna referencia para Data para fazer chamadas de funcao em sequencia
	 */
	 Data & setDia(const unsigned int dia);

	/**
	 * @brief Altera o mes 
	 * @param mes - Valor a aplicar ao mes
	 * @return Retorna referencia para Data para fazer chamadas de funcao em sequencia
	 */
	 Data & setMes(const unsigned int mes);

	/**
	 * @brief Altera o dia 
	 * @param ano - Valor a aplicar a ano
	 * @return Retorna referencia para Data para fazer chamadas de funcao em sequencia
	 */
	 Data & setAno(const unsigned int ano);

	/**
	 * @brief Devolve o dia 
	 * @return Retorna o dia da data
	 */
	 unsigned int getDia() const;

	/**
	 * @brief Devolve o mes 
	 * @return Retorna o mes da data
	 */
	 unsigned int getMes() const;

	/**
	 * @brief Devolve o ano 
	 * @return Retorna o ano da data
	 */
	 unsigned int getAno() const;

	 /**
	 * @brief Calcula a diferen�a de duas datas, em dias
	 * @param data - data com que se compara o objeto atual
	 * @return Retorna a diferenca entre duas datas
	 */
	 unsigned int diferencaEntreDatas(const Data & data);

	/**
	 * @brief Overload do operador <= que compara duas data
	 * @param D1 - data com que se compara o objeto atual
	 * @return verdade se o objeto for  menor ou igual que D1
	 */
	 bool operator<=(const Data& D1) const;

	/**
	 * @brief Overload do operador < que compara duas data
	 * @param D1 - data com que se compara o objeto atual
	 * @return verdade se o objeto for  menor que D1
	 */
	 bool operator<(const Data& D1) const;

	/**
	 * @brief overload do operador == que compara duas data
	 * @param D1 - data com que se compara o objeto atual
	 * @return Retorna verdade se forem iguais
	 */
	 bool operator ==(const Data & D1) const;
};

std::ostream & operator <<(std::ostream & os, const Data & data);

#endif /* DATA_H_ */
