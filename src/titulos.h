#ifndef TITULOS_H_
#define TITULOS_H_



#include "utilizador.h"
#include "data.h"

#include <string>
#include <vector>
//#include <map>




class Titulo {

private:
	static unsigned int IdUnico; /*começa em 1 */
	unsigned int IdU;
	std::string nome;
	float precoAquisicao;
	Data dataLancamento;
	int idadeMinima, idadeMaxima;
	std::string plataforma;
	std::string genero;
	std::string empresa; /*empresa que criou*/
	std::vector<float> historial_preco;// primeiro valor = preco atual
	//std::map<std::string,std::vector<float>>historial_;  /* para cada plataforma guarda um conjunto de precos(( sujeito a alteracoes))*/

public:
	Titulo(std::string="",float=0,int=0,int=0,std::string="",std::string="",std::string="");

	/*
	 * adiciona o preco ao vetor caso seja um valor positivo
	 * @param preco preco atual
	 * return true ou false mediante o valor passado (false se menor ou igual a 0)
	 */
		bool addPrice(const float preco);

		/*
		 * devolve o preco atual do jogo
		 */

		float getPrecoAtual();

		/*
		 * verifica se dois titulos sao iguais
		 * @param T titulo com que se vai comparar o objeto atual
		 * return true se forem iguais senao falso
		 */
		bool operator== (const Titulo & T);

};


class Home: public Titulo {

private:
	const unsigned int preco_atualizacao = 1;	/* preco por download,*/
	std::vector<Data> data_de_atualizacao; /* vetor com datas de atualizacoes, em que o seu tamanho da preco gasto em atualizacoes*/
public:

	/*
	 * construtor da classe Home que atua como construtor default para qualquer(quaisquer) parametro(s)
	 * vetor de datas vazio incialmente
	 */

	Home(std::string="",float=0,int=0,int=0,std::string="",std::string="",std::string="");


	/*
	 * funcao adiciona uma data ao vetor data_de_atualizacao, assumindo que ha no maximo uma por dia
	 * @param D data em que houve uma atualizacao
	 * return verdade ou falso se for possivel adicionar ao vetor a data
	 */
	bool adicionaAtualizacao(const Data & D);

};

class Online: public Titulo {
private:
	std::vector <Utilizador> utilizadores;	/*vetor incialmente vazio*/
	/*valor por servico ou preco por subscricao*/
	bool subscricaoFixa; /*falso corresponde a subscricao variavel*/
	float precoSubscricao; /*preco da subscricao escolhida*/
	/* vetores abaixo com indice correspondente*/
	std::vector <Data> Data_em_que_jogou;   /*vetor incialmente vazio, datas podem repetir se para plataformas diferentes*/
	std::vector <size_t> minutos_jogados_por_data;	/*vetor incialmente vazio*/
	std::vector<std::string> plataformas;	/*vetor incialmente vazio*/
	static float horas_totais;	/*no final arredonda para cima*/


public:

	/*
	* construtor da classe Online que atua como construtor default para qualquer(quaisquer) parametro(s)
	* vetores incialmente vazios
	*/
	Online(std::string n,float pa,int ii,int ifi,std::string p,std::string g,std::string e, bool subs, size_t pSubscricao);

	/*
	 * adiciona um utilizador caso ele nao exista
	 * @param U utilizador a adicionar
	 * return true se foi possivel adiciona-lo
	 */
	bool adicionaUtilizador(const Utilizador &U);


	/*
	 * adiciona aos 3 vetores os habitos gaming de uma certa data, funcao a usar em adicionaEstatisticas
	 * @param D1 data em que jogou
	 * @param minutos tempo que jogou
	 * @param plataforma plataforma onde jogou
	 */
	void atualizaEstAux(const Data & D1,const size_t minutos, const std::string plataforma);

	/*
	 * adicionar estaticas relativas aos habitos de gaming, atualiza os 3 ultimos vetores, cuja ordem é crucial e atualiza horas_totais
	 * @param D1 data em que jogou, podendo jogar mais que uma vez ao dia,na mesma plataforma ou nao
	 * @param minutos tempo que jogou
	 * @param plataforma plataforma onde jogou
	 */
	void adicionaEstaticas(const Data & D1,const size_t minutos, const std::string plataforma);



};




#endif /* TITULOS_H_ */

