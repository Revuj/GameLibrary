#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <iostream>
#include "data.h"
#include "biblioteca.h"


using namespace std;

class Utilizador {

private:
	string nome;
	string email;
	unsigned int idade;
	string morada;
	struct Cartao_credito {
		Data validade;
		size_t saldo;

	};

public:


};





#endif /* UTILIZADOR_H_ */
