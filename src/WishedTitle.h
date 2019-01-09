#ifndef WISHEDTITLE_H_
#define WISHEDTITLE_H_

class Titulo;

class WishedTitle {
private:
	Titulo* titulo; /**< Titulo na wishlist */
	unsigned interesse; /**< Interesse no titulo, desde 1 a 10 */
	float probabilidadeCompra; /**< Probabilidade de comprar o titulo, entre 0 e 1 */
public:

	/**
	* @brief Construtor da classe WishedTitle
	* @param interesse - Interesse no titulo, desde 1 a 10
	* @param probabilidade - Probabilidade de comprar o titulo, entre 0 e 1
	* @param title - Apontador para um titulo pretendido pelo utilizador
	*/
	WishedTitle(unsigned interesse, float probabilidade, Titulo* title);

	/**
	* @brief Devolve o interesse no titulo
	* @return Retorna um valor entre 1 e 10 correspendente ao interesse no jogo
	*/
	unsigned getInteresse() const { return interesse; }

	/**
	* @brief Devolve a probabilidade de compra do titulo
	* @return Retorna um valor entre 0 e 1 correspondente a probabilidade de compra do jogo
	*/
	float getProbabilidadeCompra() const { return probabilidadeCompra; }

	/**
	* @brief Devolve o titulo
	* @return Retorna um apontador para o titulo
	*/
	Titulo * getTitulo() const { return titulo;  }

	/**
	* @brief Alterar a probabilidade de compra do titulo
	* @param probabilidade - Nova probabilidade de compra
	*/
	void setProbabilidadeCompra(float probabilidade);

	void setInteresse(int interesse) {this->interesse = interesse;}

	/**
	* @brief Compara dos objetos da classe WishedTitle
	* @param title - WishedTitle a ser comprado
	* @return Retorna booleano representado se um objeto tem menos prioridade que outro
	*/
	bool operator<(const WishedTitle &title) const;

	/**
	 * @brief Atualiza a probabilidade de compra do WishedTitle
	 */
	void atualizaProbabilidade(float saldo);
};

#endif /* WISHEDTITLE_H_ */

