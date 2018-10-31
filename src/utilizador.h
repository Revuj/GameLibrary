

#ifndef SRC_UTILIZADOR_H_
#define SRC_UTILIZADOR_H_


#include "biblioteca.h"
#include "CartaoCredito.h"
#include <string>



class Utilizador {

private:
	std::string nome;
	std::string email;
	size_t idade;
	std::string morada;
	CartaoCredito cc;
	Biblioteca conjuntoTitulos;

public:
	Utilizador(const std::string nome="",const std::string email="",const size_t idade=0,const std::string morada="",const CartaoCredito cc=CartaoCredito(), const Biblioteca b=Biblioteca());
	std::string getNome();
	std::string getEmail();
	size_t getIdade();
	std::string getMorada();
	CartaoCredito getCc();
	Biblioteca getBiblioteca();
	bool operator == (const Utilizador & U);


};





#endif /* SRC_UTILIZADOR_H_ */
