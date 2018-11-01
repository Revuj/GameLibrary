#include <iostream>

#include "Titulo.h"

using namespace std;

int main() {


	Data d1(31, 10, 2018);

	Data d2(1,11,2018);

	Data d3(20, 10, 2024);


	//////////
	//JOGO 1//
	//////////

	vector<string> generos1 = { "Luta", "Acao", "RPG" };

	std::map<std::string, std::vector<float>> precosPlataforma1;

	vector<float> precosNintendo = { 60, 50, 40 }; /*preco mais antigo tem de ser o mais caro, preco de lancamento*/
	precosPlataforma1["Nintendo"] = precosNintendo;

	vector<float> precosPlayStation = {60 ,40, 50 };
	precosPlataforma1["PlayStation"] = precosPlayStation;


	cout << d2.getDataAtual()<<endl;/*data atual*/

	Titulo t1("testeGame", 5, precosPlataforma1, generos1, "Square Enix", d1);


	//////////
	//JOGO 2//
	//////////
	Home t2 ("testeGame2", 10, precosPlataforma1, generos1, "Capcom", d1);
	t2.adicionaAtualizacao(d1);
	t2.adicionaAtualizacao(d1); /*nao e adicionada*/




	cout << "gastos:";
	cout << t2.getGastos()<<"€"<<endl;
	t2.adicionaAtualizacao(d2);
	cout << "gastos:";
	cout << t2.getGastos()<<"€"<<endl;
	cout << "datas de atualizacao"<<endl;
	t2.showDatasAtualizacao();




	cout << t1;
	cout << t1.getDesconto("Nintendo") << "%"<<endl; /*preco mais caro esta em ultimo, preco de lancamento*/

	Online t3 ("testeGame", 5, precosPlataforma1, generos1, "Square Enix", d1,true,10);
	t3.adicionaEstaticas(d1,70,"Nintendo");
	t3.adicionaEstaticas(d1,30,"PlayStation");
	t3.adicionaEstaticas(d1,21,"Nintendo"); /*arredonda para tres horas*/
	cout<<"horas totais: "<<t3.getHorasTotais()<<endl;


	cout << endl << endl << endl;

	Biblioteca b1;

	b1.adicionaTitulo(&t1);
	b1.adicionaTitulo(&t2);

	CartaoCredito c1(100, d3, "1234");

	Utilizador u1("Rafa", "oioi@yolo.com", 19, "Rua do Salgueiral, 293", b1);

	u1.adicionaCartaoCredito(c1);

	cout << u1 << endl;



	return 0;
}


