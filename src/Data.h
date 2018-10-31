#ifndef DATA_H_
#define DATA_H_
#include <iostream>

class Data {

private:
	unsigned int dia, mes, ano;

public:
	/* construtor com valores por default
	 * @param d dia
	 * @param m mes
	 * @param a ano
	 *  */
	Data(int d = 1, int m = 1, int a = 2000);

	/*
	 * overload do operador <= que compara duas data
	 * @param D1 data com que se compara o objeto atual
	 * return verdade se o objeto for  menor ou igual que D1
	 */
	bool operator<=(const Data& D1);

	/*
	 * overload do operador == que compara duas data
	 * @param D1 data com que se compara o objeto atual
	 * return true se iguais senao falso
	 */
	bool operator ==(const Data & D1);

	unsigned int getDia() const {
		return dia;
	}
	;
	unsigned int getMes() const {
		return mes;
	}
	;
	unsigned int getAno() const {
		return ano;
	}
	;
};

std::ostream & operator <<(std::ostream & os, const Data & data);

#endif /* DATA_H_ */
