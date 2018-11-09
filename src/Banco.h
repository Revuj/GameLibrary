#ifndef SRC_BANCO_H_
#define SRC_BANCO_H_

#include "CartaoCredito.h"
#include <vector>

/*tirar a funcao data atual de data e colocar aqui*/
/*
 * quando um cartao de um utilizador for removido, remove lo aqui na mesma
 * nao deixar remover se so tiver um cartao e lancar excecao
 */


/*classe banco armazena na sua base de dados todos os cartoes e serve para fazer a verificacao da sua validade */
class Banco
{
	std::vector<CartaoCredito> CartoesDeCredito;
	Data atual;

public:


	Banco(); /*construtor*/
	~Banco(); /*destrutor*/

	void setDataAtual(); /*onde e feito o set do dia de hoje, atualiza a data a cada compilacao*/

	/*
	 * chamar esta funcao depois de setData que incializa o objeto com a data da ultima compilacao
	 *
	 */
	Data getDataAtual() const;

	std::vector<CartaoCredito> getCartoesCredito() const;


	/*
	 * ve se esta dentro da data de validade
	 * @param cartao de credito a comparar a data
	 * return true se valida senao falsa
	 */
	bool isDataValida(const CartaoCredito & cartao) const ;


	/*deve ser chamada sempre antes de associar um cartao de credito a uma pessoa para garantir que esta disponivel e dentro da validade*/
	void adicionaCartaoCredito(const CartaoCredito &);

	/*
	 * remove e adiciona quantia estao na classe cartaocredito mas poderiam ser aplicadas aqui(ja aplicada na claase cartacredito)?
	 */

	/*
	 * a funcao transferir dinheiro entre cartoes de credito deve ser feita no mesmo sitio das funcoes que adicionam quantia e remove?
	 * so pode ser transferido se existir mais que um cartao (pode lancar excecao)
	 */

	void adicionaCartoesCredito(const std::vector <CartaoCredito> & cartoes);

	/*
	 * atualiza a data de um cartao de credito, adicionando mais 3 anos de validade
	 * atualiza se esta fora da validade ou se faltam ate 90 dias ate ao fim do prazo
	 * @param cartao de credito a atualizar
	 */
	void atualizaCartao(CartaoCredito & cartao);

	/*
	 * atualiza todos os cartoes do sistema, que tem data invalida ou que a sua validade termina dentro de 30 diasss
	 */
	void atualizaCartoesCredito();

};

std::ostream & operator <<(std::ostream & os, const Banco & banco);


#endif /* SRC_BANCO_H_ */
