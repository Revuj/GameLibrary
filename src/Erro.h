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

std::ostream & operator <<(std::ostream & os, const PrecoInvalido & preco) {
	os << "Tentativa de atualizar preco falhada: preco invalido = " << preco
			<< std::endl;
	os << "Preco devera ser maior que 0!" << std::endl;
	return os;
}

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

std::ostream & operator <<(std::ostream & os,
		const PlataformaNaoExistente & plataforma) {
	os << "Este titulo nao esta disponivel nesta plataforma: " << plataforma
			<< std::endl;
	os << "Devera escolher uma plataforma existente!" << std::endl;
	return os;
}

//========================================================================================
//========================================================================================

#endif /* ERRO_H_ */
