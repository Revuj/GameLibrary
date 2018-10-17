

#ifndef TITULOS_H_
#define TITULOS_H_

#include <string>
#include <vector>


using std::string;
using std::vector;


class Titulo {

private:
	string nome;
	float preco_aquisicao;
	// data lançamentos
	int idade_minima, idade_maxima;
	string plataforma;
	string genero;
	string empresa;
	vector<int> historial_preco;// primeiro valor = preco atual

public:
	Titulo(string="",float=0,int=0,int=0,string="",string="",string="");
	void set_preco(float); // mudar preco e acrescentar valor ao vetor


};



#endif /* TITULOS_H_ */

