#include "Erro.h"

std::ostream & operator <<(std::ostream & os, const PrecoInvalido & preco) {
	os << "Tentativa de atualizar preco falhada: preco invalido = " << preco
			<< std::endl;
	os << "Preco devera ser maior que 0!" << std::endl;
	return os;
}

//========================================================================================
//========================================================================================

std::ostream & operator <<(std::ostream & os, const PlataformaNaoExistente & plataforma) {
	os << "Este titulo nao esta disponivel nesta plataforma: " << plataforma
			<< std::endl;
	os << "Devera escolher uma plataforma existente!" << std::endl;
	return os;
}

//========================================================================================
//========================================================================================

std::ostream & operator <<(std::ostream & os, const SaldoInsuficiente & saldo) {
	os << "O seu saldo é insuficiente. Tem um saldo de " << saldo.getSaldo() << "€" << std::endl;
	return os;
}

//========================================================================================
//========================================================================================

std::ostream & operator <<(std::ostream & os, const CartaoInexistente & cartao) {
	os << "O cartao com id " << cartao.getId() << "nao existe." << std::endl;
	os << "Por favor, tente outro cartao." << std::endl;
	return os;
}

//========================================================================================
//========================================================================================

std::ostream & operator <<(std::ostream & os, const TituloJaAdicionado & titulo) {
	os << titulo.getNome() << "ja pertence a sua lista de jogos." << std::endl;
	return os;
}




