#include <iostream>
#include "Titulo.h"
#include "Banco.h"
#include "Erro.h"
#include "Sistema.h"
#include <algorithm>

using namespace std;

int getOption(int min, int max){
	int opt;

	// Get the option
	std::cout << ">>> ";
	std::cin >> opt;

	// Check if not a number was entered
	if(std::cin.fail()){
		// Clear the cin error flags and the stream content, throw the error
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Clear the cin stream even if no error occured, to ensure the stream always stays clean
	std::cin.ignore(1000,'\n');

	// Check if the option is valid
	if(opt>=min && opt<=max)
		return opt;
	else
		throw (InputInvalido("Opcao Invalida!"));
}

void printWelcomeMenu(){
	unsigned int headerSize = 80;
	std::string welcomeMessage = "BIBLIOTECA DE JOGOS";

	// Escrever uma mensagem de bem-vindo
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl;
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl << std::endl;
	for (unsigned int i=0 ; i<(headerSize-welcomeMessage.size())/2 ; i++) { std::cout << ' '; }
	std::cout << welcomeMessage << std::endl << std::endl;
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl;
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl << std::endl;
}

void printHeader(const std::string &header){
	unsigned int headerSize = 80;
	unsigned int headerLeftSpaces = (headerSize - header.size()) / 2;

	// Give some space from previous menu print
	std::cout << "\n\n";

	// Draw the Menu Header
	for(unsigned int i=0 ; i<headerSize ; i++) { std::cout << "-"; }
	std::cout << std::endl;
	for(unsigned int i=0 ; i<headerLeftSpaces ; i++) { std::cout << " "; }
	std::cout << header << std::endl;
	for(unsigned int i=0 ; i<headerSize ; i++) { std::cout << "-"; }
	std::cout << std::endl << std::endl;
}

void printMainMenu(){
	// Draw the header
	printHeader("Biblioteca de jogos");

	// Draw the options
	std::cout << "1. Adicionar Utilizador" << std::endl;
	std::cout << "2. Ordenar Utilizadores" << std::endl;
	std::cout << "3. Pesquisar Utilizador" << std::endl;
	std::cout << "4. Adicionar Jogo" << std::endl;
	std::cout << "5. Ordenar Jogo" << std::endl;
	std::cout << "6. Pesquisar Jogo" << std::endl;
	std::cout << "7. Sair" << std::endl << std::endl;
}

void printOrdenacoMenu(){
	// Draw the header
	printHeader("Ordenar Utilizadores");

	// Draw the options
	std::cout << "1. Idade crescente" << std::endl;
	std::cout << "2. Nome crescente" << std::endl;
	std::cout << "3. Numero jogos crescente" << std::endl;
	std::cout << "4. Idade decrescente" << std::endl;
	std::cout << "5. Idade decrescente" << std::endl;
	std::cout << "6. Numero jogos decrescente" << std::endl;
	std::cout << "7. Sair" << std::endl << std::endl;
}

void printUserMenu(){
	// Draw the header
	printHeader("Menu Utilizador");

	// Draw the options
	std::cout << "1. Adicionar título" << std::endl;
	std::cout << "2. Adicionar cartao de credito" << std::endl;
	std::cout << "3. Verificar Saldo" << std::endl;
	std::cout << "4. Ordenar títulos" << std::endl;
	std::cout << "5. Jogar" << std::endl;
	std::cout << "6. Sair" << std::endl << std::endl;
}

void printOrdenaJogosMenu(){
	// Draw the header
	printHeader("Ordenar Titulos");

	// Draw the options
	std::cout << "1. ID crescente" << std::endl;
	std::cout << "2. ID decrescente" << std::endl;
	std::cout << "3. Data de lancamento crescente" << std::endl;
	std::cout << "4. Data de lancamento decrescente" << std::endl;
	std::cout << "5. Idade minima crescente" << std::endl;
	std::cout << "6. Idade mínima decrescente" << std::endl;
	std::cout << "7. Empresa ordem alfabetica crescente" << std::endl;
	std::cout << "8. Empresa ordem alfabetica decrescente" << std::endl;
	std::cout << "9. Sair" << std::endl << std::endl;
}

void adicionarUtilizador(Sistema &sistema){
	bool utilizadorAdicionado=false;
	while(!utilizadorAdicionado){
		utilizadorAdicionado=sistema.addUtilizador();
	}
}

void adicionarJogo(Sistema &sistema){
	bool tituloAdicionado=false;
	while(!tituloAdicionado){
		tituloAdicionado=sistema.addTitulo();
	}
}

void ordenaUtilizadores(Sistema& sistema){
	int opt;
	while(true){
		printOrdenacoMenu();

		try{
			opt = getOption(1,7);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			sistema.ordenarUtilizadores("idade",true);
		else if (opt == 2)
			sistema.ordenarUtilizadores("nome",true);
		else if (opt == 3)
			sistema.ordenarUtilizadores("jogos",true);
		else if (opt == 4)
			sistema.ordenarUtilizadores("idade",false);
		else if (opt == 5)
			sistema.ordenarUtilizadores("nome",false);
		else if (opt == 6)
			sistema.ordenarUtilizadores("jogos",false);
		else
			break;	// opt = 7, o utilizador quer sair
	}
}

void ordenaJogosUtilizador(Sistema &sistema,Utilizador& u){
	int opt;

	// Perguntar ao utilizador o que quer fazer at� este indicar que deseja sair
	while(true){
		printOrdenaJogosMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,9);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			sistema.ordenaTitulosUtilizador(u,"id",true);
		else if (opt == 2)
			sistema.ordenaTitulosUtilizador(u,"id",false);
		else if (opt == 3)
			sistema.ordenaTitulosUtilizador(u,"data",true);
		else if (opt == 4)
			sistema.ordenaTitulosUtilizador(u,"data",false);
		else if (opt == 5)
			sistema.ordenaTitulosUtilizador(u,"idade",true);
		else if (opt == 6)
			sistema.ordenaTitulosUtilizador(u,"idade",false);
		else if (opt == 7)
			sistema.ordenaTitulosUtilizador(u,"empresa",true);
		else if (opt == 8)
			sistema.ordenaTitulosUtilizador(u,"idade",false);
		else
			break;	// opt = 9, o utilizador quer sair
	}
}

void ordenaJogos(Sistema &sistema){
	int opt;

	// Perguntar ao utilizador o que quer fazer at� este indicar que deseja sair
	while(true){
		printOrdenaJogosMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,9);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			sistema.ordenaTitulos(,"id",true);
		else if (opt == 2)
			sistema.ordenaTitulos("id",false);
		else if (opt == 3)
			sistema.ordenaTitulos("data",true);
		else if (opt == 4)
			sistema.ordenaTitulos("data",false);
		else if (opt == 5)
			sistema.ordenaTitulos("idade",true);
		else if (opt == 6)
			sistema.ordenaTitulos("idade",false);
		else if (opt == 7)
			sistema.ordenaTitulos("empresa",true);
		else if (opt == 8)
			sistema.ordenaTitulos("idade",false);
		else
			break;	// opt = 9, o utilizador quer sair
	}
}

void menuUtilizador(Sistema &sistema,Utilizador& u){
	int opt;

	// Perguntar ao utilizador o que quer fazer at� este indicar que deseja sair
	while(true){
		printUserMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,5);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			sistema.adicionaTituloUtilizador(u);
		else if (opt == 2)
			sistema.adicionaCC(u);
		else if (opt == 3)
			cout<<sistema.saldoUtilizador(u)<<endl;
		else if (opt == 4)
			ordenaJogosUtilizador(sistema,u);
		else if	(opt == 5)
			sistema.utilizadorJogar(u);
		else
			break;	// opt = 6, o utilizador quer sair
	}

}

void pesquisaUtilizador(Sistema &sistema){
	string nome;
	cout << "Enter a user name: ";
	getline(std::cin, nome);
	string email;
	std::string EMAILCHAR = "@";
	bool validEmail=false;
	while(!validEmail){
		std::cout << "Enter your email \n";
		getline(std::cin, email);
		if (email.find(EMAILCHAR) == std::string::npos){
			std::cout << "Invalid email it must contain '@' \n";
		}
		else validEmail=true;
	}
	Utilizador u=sistema.pesquisaUtilizador(nome,email);
	menuUtilizador(sistema,u);
}

void pesquisarJogo(Sistema &sistema){
	string nome;
	cout << "Enter a name: ";
	getline(std::cin, nome);
	sistema.pesquisaJogo(nome);
}

int main() {
	printWelcomeMenu();
	Sistema sistema;

	int opt;

	// Perguntar ao utilizador o que quer fazer at� este indicar que deseja sair
	while(true){
		printMainMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,4);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			adicionarUtilizador(sistema);
		else if (opt == 2)
			ordenaUtilizadores(sistema);
		else if (opt == 3)
			pesquisaUtilizador(sistema);
		else if (opt == 4)
			adicionarJogo(sistema);
		else if (opt == 5)
			ordenaJogos(sistema);
		else if (opt == 6)
			pesquisarJogo(sistema);
		else
			break;	// opt = 7, o utilizador quer sair
	}

    return 0;
}
