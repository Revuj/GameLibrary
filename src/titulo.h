#ifndef TITULO_H_
#define TITULO_H_


#include <string>
#include <vector>


using namespace std;

#include "utilizador.h"




class Titulo { // abstrata?

private:
	string nome;
	float preco_aquisicao;
	Data data_lancamento;
	int idade_minima, idade_maxima;
	string plataforma;
	string genero;
	string empresa;
	vector<int> historial_preco;// primeiro valor = preco atual

public:
	Titulo(string="",float=0,int=0,int=0,string="",string="",string="");
	void set_preco(float); // mudar preco e acrescentar valor ao vetor


};


class Home: public Titulo {

private:
	Data data_de_atualizacao;
public:
	Home();

};

class Online: public Titulo {
private:
	vector <Utilizador> utilizadores;
	size_t valor_por_servico;
	size_t preco_subscricao;
	// vetores abaixo com indice correspondente
	vector <Data> Data_em_que_jogou;
	vector <size_t> minutos_jogados_por_data;
	vector<string> plataformas;
 //	static size_t horas_totais;

public:
	Online();

};




#endif /* TITULO_H_ */

