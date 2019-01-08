#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include <vector>
#include <string>
#include "Erro.h"
class Titulo;

/**
 * Bibloteca que foi declarado no Utilizador
 */
class Biblioteca {

	std::vector<Titulo*> titulos;/**< Vetor de titulos da biblioteca */
public:
	/**
	 * @brief Adicona um titulo a biblioteca
	 * @param T - Titulo a adicionar 
	 */
	void adicionaTitulo(Titulo * T);

	/**
	 * @brief Devolve o vetor de titulos
	 * @return Retorna vetor de titulos da biblioteca
	 */
	std::vector<Titulo*> getTitulos() const;

	/**
	 * @brief Overload do operador de igualdade
	 * @param B - Biblioteca a ser comparada
	 */
	bool operator==(const Biblioteca B);
};

#endif /* SRC_BIBLIOTECA_H_ */
