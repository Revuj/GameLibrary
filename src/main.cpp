#include <iostream>

#include "Titulo.h"

using namespace std;

int main() {

	Utilizador u1, u2;
	Biblioteca B;

	CartaoCredito c;

	//////////
	//JOGO 1//
	//////////

	vector<string> generos1 = { "Luta", "Acao", "RPG" };

	std::map<std::string, std::vector<float>> precosPlataforma1;

	vector<float> precosNintendo = { 60, 50, 45 };
	precosPlataforma1["Nintendo"] = precosNintendo;

	vector<float> precosPlayStation = { 60, 50 };
	precosPlataforma1["PlayStation"] = precosPlayStation;

	Data d1(31, 10, 2018);

	Titulo t1("testeGame", 5, precosPlataforma1, generos1, "Square Enix", d1);

	cout << t1;

	return 0;
}

