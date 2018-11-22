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

std::string lerFicheiroUtilizadores(){
	std::string ficheiroUtilizadores;
	std::cout << "\nIndique o nome do ficheiro de utilizadores: ";
	getline(std::cin, ficheiroUtilizadores);

	return ficheiroUtilizadores;
}

std::string lerFicheiroJogos(){
	std::string ficheiroJogos;
	std::cout << "\nIndique o nome do ficheiro de utilizadores: ";
	getline(std::cin, ficheiroJogos);

	return ficheiroJogos;
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
	std::cout << "4. Sair" << std::endl << std::endl;
}

void adicionarUtilizador(Sistema &sistema){
	bool utilizadorAdicionado=false;
	while(!utilizadorAdicionado){
		sistema.addUtilizador();
	}
}


int main() {
	printWelcomeMenu();
	std::string ficheiroUtilizadores,ficheiroJogos;
	ficheiroUtilizadores=lerFicheiroUtilizadores();
	ficheiroJogos=lerFicheiroJogos();
	Sistema sistema(ficheiroUtilizadores,ficheiroJogos);
	try{	// Ler info dos ficheiros e verificar que nao ha erros na sua abertura
		sistema.openFiles();
	}
	catch(FicheiroNaoEncontrado &e){
		std::cerr << e.getInfo();
		return 1;
	}

	int opt;

	// Perguntar ao utilizador o que quer fazer até este indicar que deseja sair
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

		else
			break;	// opt = 5, o utilizador quer sair
	}

    return 0;
}
