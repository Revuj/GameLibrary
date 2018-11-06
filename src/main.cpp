#include <iostream>

#include "Titulo.h"
#include "Banco.h"
#include "Erro.h"
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


	Online t1("testeGame", 5, precosPlataforma1, generos1, "Square Enix", d1,true,1);


	//////////
	//JOGO 2//
	//////////
	Home t2 ("testeGame2", 10, precosPlataforma1, generos1, "Capcom", d1);
	t2.adicionaAtualizacao(d1);
	t2.adicionaAtualizacao(d1); //nao e adicionada


	vector<string> plataformas={"Nintendo","PlayStation"};


	cout << t1;
	cout << t1.getDesconto("Nintendo") << "%"<<endl; //preco mais caro esta em ultimo, preco de lancamento

	Online t3 ("testeGame", 5, precosPlataforma1, generos1, "Square Enix", d1,true,10);
	t3.adicionaEstaticas(d1,70,"Nintendo");
	t3.adicionaEstaticas(d1,30,"PlayStation");
	t3.adicionaEstaticas(d1,21,"Nintendo"); //arredonda para tres horas
	cout<<"horas totais: "<<t3.getHorasTotais()<<endl;


	cout << endl << endl << endl;

	Biblioteca b1;

	b1.adicionaTitulo(&t1,plataformas);
	b1.adicionaTitulo(&t2,plataformas);

	CartaoCredito c1(100, d3, "1234");

	Utilizador u1("Rafa", "oioi@yolo.com", 19, "Rua do Salgueiral, 293", b1);

	u1.adicionaCartaoCredito(c1);

	cout << "gastos:";
	cout << u1.getGastos()<<"€"<<endl;
	t2.adicionaAtualizacao(d2);
	cout << "gastos:";
	cout << u1.getGastos()<<"€"<<endl;
	cout << "datas de atualizacao"<<endl;
	t2.showDatasAtualizacao();

	cout << u1 << endl;

	cout << "Difference between date 2 and date 1: ";
	cout << d2.diferencaEntreDatas(d1) << endl;
	cout << "Difference between date 2 and date 3: ";
	cout << d2.diferencaEntreDatas(d3) << endl;

	Data d4(30,12,2018);
	Data d5(2, 5, 2021);
	Data d6(3, 10, 2022);

	CartaoCredito c2(50, d4, "2345");
	CartaoCredito c3(70, d5, "3456");
	CartaoCredito c4(500, d6, "4568");

	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;

	vector<CartaoCredito> cartoes1 = {c1, c2, c3};

	Banco banco1;

	try
	{
		banco1.adicionaCartoesCredito(cartoes1);
	}
	catch(CartaoJaExistente & error)
	{
		cout << error << endl;
	}
	catch(CartaoInvalido & error)
	{
		cout << error << endl;
	}

	banco1.adicionaCartaoCredito(c4);

	banco1.atualizaCartao(c2);

	cout << c2 << endl;

	cout << banco1 << endl;

	return 0;
}
