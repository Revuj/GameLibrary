#ifndef DATA_H_
#define DATA_H_
#include <iostream>
#include <string>


class Data {

private:
	unsigned int dia, mes, ano;
public:
	/* construtor com valores por default
	 * @param d dia
	 * @param m mes
	 * @param a ano
	 *  */
	Data(unsigned int dia = 1, unsigned int mes = 1, unsigned int ano = 2000);
	Data(std::string data);

	/*
	 * overload do operador <= que compara duas data
	 * @param D1 data com que se compara o objeto atual
	 * return verdade se o objeto for  menor ou igual que D1
	 */

	 Data & setDia(const unsigned int dia);

	 Data & setMes(const unsigned int mes);

	 Data & setAno(const unsigned int ano);

	 unsigned int getDia() const;

	 unsigned int getMes() const;

	 unsigned int getAno() const;

	 /*
	  * Calcula a diferen�a de duas datas, em dias
	  * @param data data com que se compara o objeto atual
	  * return o valor calculado
	  */
	 unsigned int diferencaEntreDatas(const Data & data);

	 bool operator<=(const Data& D1) const;

	 bool operator<(const Data& D1) const;

	/*
	 * overload do operador == que compara duas data
	 * @param D1 data com que se compara o objeto atual
	 * return true se iguais senao falso
	 */
	 bool operator ==(const Data & D1) const;
};

std::ostream & operator <<(std::ostream & os, const Data & data);

#endif /* DATA_H_ */
