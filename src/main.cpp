#include <iostream>
#include "Titulo.h"
#include "Banco.h"
#include "Erro.h"
#include "Sistema.h"
#include <algorithm>

int getOption(int min, int max) {
	int opt;

	// Get the option
	std::cout << ">>> ";
	std::cin >> opt;

	// Check if not a number was entered
	if (std::cin.fail()) {
		// Clear the cin error flags and the stream content, throw the error
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		throw(InputInvalido("Input Invalido!"));
	}

	// Clear the cin stream even if no error occured, to ensure the stream always stays clean
	std::cin.ignore(1000, '\n');

	// Check if the option is valid
	if (opt >= min && opt <= max)
		return opt;
	else
		throw(InputInvalido("Opcao Invalida!"));
}

void printWelcomeMenu() {
	unsigned int headerSize = 80;
	std::string welcomeMessage = "BIBLIOTECA DE JOGOS";

	// Escrever uma mensagem de bem-vindo
	for (unsigned int i = 0; i < headerSize; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < headerSize; i++) {
		std::cout << '-';
	}
	std::cout << std::endl << std::endl;
	for (unsigned int i = 0; i < (headerSize - welcomeMessage.size()) / 2;
			i++) {
		std::cout << ' ';
	}
	std::cout << welcomeMessage << std::endl << std::endl;
	for (unsigned int i = 0; i < headerSize; i++) {
		std::cout << '-';
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < headerSize; i++) {
		std::cout << '-';
	}
	std::cout << std::endl << std::endl;
}

void printMainMenu() {

	std::cout << "1. Visualizar Titulos" << std::endl;
	std::cout << "2. Adicionar Utilizador" << std::endl;
	std::cout << "3. Visualizar Utilizadores" << std::endl;
	std::cout << "4. Adicionar Jogo" << std::endl;
	std::cout << "5. Pesquisar Utilizador" << std::endl;
//	std::cout << "6. Pesquisar Jogo" << std::endl;
	std::cout << "7.Rankings e Estatisticas" << std::endl;
	std::cout << "8. Sair" << std::endl << std::endl;
}

void printDisplayUtilizadoresMenu() {

	// Draw the options
	std::cout << "1. Visualizacao simples" << std::endl;
	std::cout << "2. Idade crescente" << std::endl;
	std::cout << "3. Idade decrescente" << std::endl;
	std::cout << "4. Numero jogos crescente" << std::endl;
	std::cout << "5. Numero de jogos descresnte" << std::endl;
	std::cout << "6. Nome crescente" << std::endl;
	std::cout << "7. Nome Decrescente" << std::endl;
	std::cout << "8. Sair" << std::endl << std::endl;
}

void printUserMenu() {

	// Draw the options
	std::cout << "1. Adicionar titulo" << std::endl;
	std::cout << "2. Adicionar cartao de credito" << std::endl;
	std::cout << "3. Verificar Saldo" << std::endl;
	std::cout << "4. Jogar" << std::endl;
	std::cout << "5. Tempo Jogado" << std::endl;
	std::cout << "6. Sair" << std::endl;
}

void printDisplayTitulosMenu() {
	// Draw the options
	std::cout << "1. Visualizacao simples" << std::endl;
	std::cout << "2. Data de lancamento crescente" << std::endl;
	std::cout << "3. Data de lancamento decrescente" << std::endl;
	std::cout << "4. Idade minima crescente" << std::endl;
	std::cout << "5. Idade minima decrescente" << std::endl;
	std::cout << "6. Empresa ordem alfabetica crescente" << std::endl;
	std::cout << "7. Empresa ordem alfabetica decrescente" << std::endl;
	std::cout << "8. Sair" << std::endl << std::endl;
}

void adicionarUtilizador(Sistema &sistema) {

	std::string nome;
	std::string email;
	std::string idade;
	std::string morada;
	std::cout << "A criar utilizador...  \n";
	std::cout << "Insere um nome: ";
	getline(std::cin, nome);

	while (true) {
		try {
			sistema.isValidEmail(email);
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;
			continue;
		}
		break;
	}

	std::cout << "Insere a tua idade: ";
	getline(std::cin, idade);
	std::cout << "Insere o teu enderesso: ";
	getline(std::cin, morada);

	sistema.adicionaUtilizador(
			Utilizador(nome, email, std::stoul(idade, NULL, 0), morada));

	std::cout << "Utilizador guardado com sucesso!" << std::endl << std::endl;
	return;
}

std::string lerData(std::string data) {

	// Verificar se está no formato válido (DD/MM/AAAA)
	if (data.size() != 10)			// Verificar se a data tem o tamanho correto
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(2) != '/') || (data.at(5) != '/'))// Verificar se dia, mes e ano estao separados por um traco
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(0) < '0') || (data.at(0) > '9'))// Verificar se Dx é um digito
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(1) < '0') || (data.at(1) > '9'))// Verificar se xD é um digito
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(3) < '0') || (data.at(3) > '9'))// Verificar se Mx é um digito
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(4) < '0') || (data.at(4) > '9'))// Verificar se xM é um digito
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(6) < '0') || (data.at(6) > '9'))// Verificar se Axxx é um dígito
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(7) < '0') || (data.at(7) > '9'))// Verificar se xAxx é um dígito
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(8) < '0') || (data.at(8) > '9'))// Verificar se xxAx é um dígito
		throw(DataInvalida("Data Invalida!"));
	else if ((data.at(9) < '0') || (data.at(9) > '9'))// Verificar se xxxA é um dígito
		throw(DataInvalida("Data Invalida!"));

	// Verificar se a data segue os padrões normais de datas
	int dia = stoi(data.substr(0, 2));
	int mes = stoi(data.substr(3, 2));
	int ano = stoi(data.substr(6, 4));

	// Verificar se o mes esta dentro dos limites reais
	if (mes < 0 || mes > 12)
		throw(DataInvalida("Data Invalida!"));

	switch (mes) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:		// Meses com 31 dias
		if ((dia < 0) || (dia > 31))
			throw(DataInvalida("Data Incorreta!"));
		break;
	case 4:
	case 6:
	case 9:
	case 11:								// Meses com 30 dias
		if ((dia < 0) || (dia > 30))
			throw(DataInvalida("Data Incorreta!"));
		break;
	case 2:															// Fevereiro
		if ((dia < 0) || (dia > 29))
			throw(DataInvalida("Data Incorreta!"));
		else if ((dia == 29) && (ano % 4 != 0))	// Se o dia for 29 de Fevereiro e o ano não for bissexto -> erro
			throw(DataInvalida("Data Incorreta!"));
		break;
	}

	// Data válidade
	return data;
}

void adicionarJogo(Sistema &sistema) {
	std::cout << "Adicionar um titulo \n";

	std::cout << std::endl << "Tipo de Titulo (Home, Online): ";
	std::string tipo;
	getline(std::cin, tipo);
	while (tipo != "Home" && tipo != "Online") {
		std::cout << "Introduza um tipo de titulo valido" << std::endl;
		getline(std::cin, tipo);
	}

	std::cout << std::endl << "Nome do titulo: ";
	std::string nome;
	getline(std::cin, nome);

	std::string data;
	while (true) {
		std::cout << "\nData de lancamento (Formato DD/MM/AAAA): ";
		getline(std::cin, data);
		try {
			lerData(data);
		} catch (DataInvalida &e) {
			std::cout << "\n" << e.getInfo() << std::endl
					<< "Introduza novamente" << std::endl;
			continue;
		}
		break;
	}

	std::cout << std::endl << "Preco do titulo: ";
	float preco;
	std::cin >> preco;
	// Verificar se foi introduzido um numero
	while (std::cin.fail() || std::cin.eof() || preco <= 0) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Preco Invalido! Introduza novamente." << std::endl;
		std::cout << std::endl << "Preco do titulo: ";
		std::cin >> preco;
	}

	// Limpar a stream mesmo que não tenha ocorrido qualquer erro, para garantir que está sempre limpa e vazia
	std::cin.ignore(1000, '\n');

	int idadeMinima;
	std::cout << std::endl << "Idade minima: ";
	std::cin >> idadeMinima;
	// Verificar se foi introduzido um numero
	while (std::cin.fail() || std::cin.eof() || idadeMinima <= 0) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Idade invalida! Introduza novamente." << std::endl;
		std::cout << std::endl << "Idade Minima: ";
		std::cin >> idadeMinima;
	}
	std::cin.ignore(1000, '\n');

	std::string plataforma;
	std::cout << std::endl << "Plataforma: ";
	getline(std::cin, plataforma);

	std::vector<std::string> generos;
	std::string genero;
	std::cout << std::endl
			<< "Generos (Introduza um genero de cada vez e introduza '.' quando terminar. Necessario pelo menos um genero!): ";
	while (genero[0] != '.' || (!generos.size())) {
		getline(std::cin, genero);
		if (genero[0] != '.') {
			generos.push_back(genero);
		}
	}

	std::cout << std::endl << "Empresa: ";
	std::string empresa;
	getline(std::cin, empresa);

	if (tipo == "Home") {
		Home *home = new Home(nome, idadeMinima, plataforma, preco, generos,
				empresa, Data(data));
		try {
			sistema.addTitulo(home);
		} catch (TituloJaAdicionado &e) {
			std::cout << e.getInfo();
		}

	} else if (tipo == "Online") {
		std::cout << std::endl << "Tipo de subscricao ( Variavel ou Fixa ): ";
		std::string tipoSubs;
		getline(std::cin, tipo);
		while (tipoSubs != "Variavel" && tipoSubs != "Fixa") {
			std::cout << "Introduza um tipo de subscricao valida" << std::endl;
			getline(std::cin, tipoSubs);
		}
		bool tipoSubscricao;
		if (tipoSubs == "Variavel") {
			tipoSubscricao = false;
		} else
			tipoSubscricao = true;
		float precoSubscricao;
		std::cout << std::endl << "Preco de Subscricao: ";
		std::cin >> precoSubscricao;
		// Verificar se foi introduzido um numero
		while (std::cin.fail() || std::cin.eof() || precoSubscricao <= 0) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Preco Invalido! Introduza novamente." << std::endl;
			std::cout << std::endl << "Preco de Subscricao: ";
			std::cin >> precoSubscricao;
		}

		std::cin.ignore(1000, '\n');
		Online *online = new Online(nome, idadeMinima, plataforma, preco,
				generos, empresa, Data(data), tipoSubscricao, precoSubscricao);
		try {
			sistema.addTitulo(online);
		} catch (TituloJaAdicionado &e) {
			std::cout << "\n" << e.getInfo();
		}
	}

	std::cout << "O titulo " << nome << " adicionado com sucesso!" << std::endl
			<< std::endl;
}

void displayUtilizadores(Sistema& sistema) {
	int opt;
	while (true) {
		printDisplayUtilizadoresMenu();

		try {
			opt = getOption(1, 8);
		} catch (InputInvalido &e) {
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			sistema.displayUtilizadores();
		else if (opt == 2)
			sistema.ordenaUtilizadores("idade", true);
		else if (opt == 3)
			sistema.ordenaUtilizadores("idade", false);
		else if (opt == 4)
			sistema.ordenaUtilizadores("jogos", true);
		else if (opt == 5)
			sistema.ordenaUtilizadores("jogos", false);
		else if (opt == 6)
			sistema.ordenaUtilizadores("nome", true);
		else if (opt == 7)
			sistema.ordenaUtilizadores("nome", false);
		else
			break;
	}
}

void ordenaJogosUtilizador(Sistema &sistema, Utilizador& u) {
	int opt;
	std::vector<Titulo *> titulos;

	// Perguntar ao utilizador o que quer fazer atï¿½ este indicar que deseja sair
	while (true) {
		printDisplayTitulosMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try {
			opt = getOption(1, 9);
		} catch (InputInvalido &e) {
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			titulos = sistema.ordenaTitulosUtilizador(u, "id", true);
		else if (opt == 2)
			titulos = sistema.ordenaTitulosUtilizador(u, "id", false);
		else if (opt == 3)
			titulos = sistema.ordenaTitulosUtilizador(u, "data", true);
		else if (opt == 4)
			titulos = sistema.ordenaTitulosUtilizador(u, "data", false);
		else if (opt == 5)
			titulos = sistema.ordenaTitulosUtilizador(u, "idade", true);
		else if (opt == 6)
			titulos = sistema.ordenaTitulosUtilizador(u, "idade", false);
		else if (opt == 7)
			titulos = sistema.ordenaTitulosUtilizador(u, "empresa", true);
		else if (opt == 8)
			titulos = sistema.ordenaTitulosUtilizador(u, "empresa", false);
		else
			break;	// opt = 9, o utilizador quer sair

		for (const auto & titulo : titulos)
			std::cout << titulo->getNome() << std::endl;
	}
}

void displayTitulos(Sistema &sistema) {
	int opt;

	// Perguntar ao utilizador o que quer fazer atï¿½ este indicar que deseja sair
	while (true) {
		printDisplayTitulosMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try {
			opt = getOption(1, 9);
		} catch (InputInvalido &e) {
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			sistema.displayTitulos();
		else if (opt == 2)
			sistema.ordenaTitulos("data", true);
		else if (opt == 3)
			sistema.ordenaTitulos("data", false);
		else if (opt == 4)
			sistema.ordenaTitulos("idade", true);
		else if (opt == 5)
			sistema.ordenaTitulos("idade", false);
		else if (opt == 6)
			sistema.ordenaTitulos("empresa", true);
		else if (opt == 7)
			sistema.ordenaTitulos("empresa", false);
		else if (opt == 8)
			return;
	}
}

void escolheTitulo(Sistema &sistema, Utilizador &u) {
	std::string titulo;
	std::string plataforma;
	std::string s;
	Titulo * t;

	while (true) {
		std::cout << "Insira o nome do titulo" << std::endl;
		getline(std::cin, titulo);
		std::cout << "Insira a plataforma" << std::endl;
		getline(std::cin, plataforma);

		try {
			t = sistema.pesquisaJogo(titulo, plataforma);
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;
			std::cout
					<< "Deseja desistir da procura('s' para sair/ outro para continuar)?"
					<< std::endl;
			getline(std::cin, s);
			if (s == "s")
				return;

			continue;
		}
		break;
	}

	for (auto & cartao : u.getCc()) {
		try {
			u.AdicionaTitulo(t, cartao);
			sistema.dataValida(cartao);
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;
			continue;
		}
		std::cout << "Adicionou o titulo " << titulo
				<< " a biblioteca do utilizador, removendo " << t->getPreco()
				<< " euros ao cartao " << cartao.getId() << std::endl;
		break;
	}

}

void escolheCc(Sistema &sistema, Utilizador &u) {
	std::string id;
	std::string saldo;
	std::string s;

	while (true) {
		try {
			std::cout << "Insira o id do cartao:" << std::endl;
			getline(std::cin, id);

			std::cout << "Insira o saldo a depositar:" << std::endl;
			getline(std::cin, saldo);

			CartaoCredito c(std::stof(saldo), sistema.getBanco().getDataAtual(),
					id);
			c.atualizaDataDeValidade();
			u.adicionaCartaoCredito(c);
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;

			std::cout
					<< "Deseja desistir da insercao('s' para sair/ outro para continuar)?"
					<< std::endl;
			getline(std::cin, s);
			if (s == "s")
				return;
			continue;
		}
		break;
	}

	std::cout << "O cartao com id " << id << " foi adicionado com sucesso."
			<< std::endl;

}

void utilizadorJoga(Sistema &sistema, Utilizador &u) {
	std::string titulo;
	std::string plataforma;
	std::string s;
	Titulo * t;

	while (true) {
		std::cout << "Insira o nome do titulo" << std::endl;
		getline(std::cin, titulo);
		std::cout << "Insira a plataforma" << std::endl;
		getline(std::cin, plataforma);

		try {
			t = sistema.pesquisaJogo(titulo, plataforma);

			if (dynamic_cast<Online *>(t) == NULL) {
				std::cout << "Nao e um titulo online!" << std::endl;

				std::cout
						<< "Deseja desistir da procura('s' para sair/ outro para continuar)?"
						<< std::endl;
				getline(std::cin, s);
				if (s == "s")
					return;

				continue;
			}
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;
			std::cout
					<< "Deseja desistir da procura('s' para sair/ outro para continuar)?"
					<< std::endl;
			getline(std::cin, s);
			if (s == "s")
				return;

			continue;
		}
		break;
	}

	std::cout << "Numero de minutos a jogar:" << std::endl;
	int n;
	std::cin >> n;
	if (!std::cin) // or if(cin.fail())
	{
		// user didn't input a number
		std::cin.clear(); // reset failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		std::cout << "Numero de horas a jogar:" << std::endl;
	}
	sistema.utilizadorJogar(u, t, n);
	std::cout << "O utilizador jogou durante " << n << " minutos." << std::endl;
}

void menuUtilizador(Sistema &sistema, Utilizador& u) {
	int opt;

	while (true) {
		printUserMenu();

		try {
			opt = getOption(1, 6);
		} catch (InputInvalido &e) {
			std::cout << "\n" << e.getInfo();
			continue;
		}

		if (opt == 1)
			escolheTitulo(sistema, u);
		else if (opt == 2)
			escolheCc(sistema, u);
		else if (opt == 3)
			sistema.saldoUtilizador(u);
		else if (opt == 4)
			utilizadorJoga(sistema, u);
		else if (opt == 5)
			sistema.tempoJogado(u);
		else
			break;	// opt = 5, o utilizador quer sair
	}

}

void pesquisarUtilizador(Sistema &sistema) {

	std::string nome;
	std::cout << "Insere o nome de um utilizador" << std::endl;
	getline(std::cin, nome);
	std::string email;
	Utilizador u;
	std::string s;

	while (true) {

		while (true) {
			try {
				sistema.isValidEmail(email, true);
			} catch (Erro &e) {
				std::cout << e.getInfo() << std::endl;
				continue;
			}
			break;
		}

		try {
			u = sistema.pesquisaUtilizador(nome, email);
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;
			std::cout
					<< "Deseja desistir da procura('s' para sair/ outro para continuar)?"
					<< std::endl;
			getline(std::cin, s);
			if (s == "s")
				return;

			std::cout << "Insere o nome de um utilizador" << std::endl;
			getline(std::cin, nome);
			continue;
		}
		break;
	}
	menuUtilizador(sistema, u);
}

//
//void pesquisarJogo(Sistema &sistema) {
//	int ID;
//	std::cout << std::endl << "ID do titulo ( Introduza 0 se nao souber o ID ): ";
//	std::cin >> ID;
//	// Verificar se foi introduzido um numero
//	while (std::cin.fail() || std::cin.eof() || ID < 0) {
//		std::cin.clear();
//		std::cin.ignore(1000, '\n');
//		std::cout << "ID invalido! Introduza novamente." << std::endl;
//		std::cout << std::endl << "ID do titulo ( Introduza 0 se nao souber o ID ): ";
//		std::cin >> ID;
//	}
//	std::cin.ignore(1000, '\n');
//
//	std::string nome;
//	std::string plataforma;
//	std::string empresa;
//	if (ID == 0) {
//		std::cout << std::endl << "Nome do titulo: ";
//		std::string nome;
//		getline(std::cin, nome);
//
//		std::string plataforma;
//		std::cout << std::endl << "Plataforma: ";
//		std::getline(std::cin, plataforma);
//
//		std::cout << std::endl << "Empresa: ";
//		std::string empresa;
//		getline(std::cin, empresa);
//
//		try {
//			sistema.pesquisaJogo(nome, plataforma, empresa, 0);
//		} catch (TituloInexistente &e) {
//			std::cout << "\n" << e.getInfo();
//		}
//	}
//
//	try {
//		sistema.pesquisaJogo("", "", "", ID);
//	} catch (TituloInexistente &e) {
//		std::cout << "\n" << e.getInfo();
//	}
//
//}

void printRankingMenu()
{
	// Draw the options
	std::cout << "1. Ranking de Generos" << std::endl;
	std::cout << "2. Ranking de Idades" << std::endl;
	std::cout << "3. ranking de plataformas" << std::endl;
	std::cout << "4. Ranking de rentabilidade" << std::endl;
	std::cout << "5. Custo medio das bibliotecas" << std::endl;
	std::cout << "6. Numero medio de titulos das bibliotecas" << std::endl;
	std::cout << "7. Sair" << std::endl;
}

void displayRankings(Sistema &sistema) {
	int opt;

	while (true) {
		printRankingMenu();

		try {
			opt = getOption(1, 7);
		} catch (InputInvalido &e) {
			std::cout << "\n" << e.getInfo();
			continue;
		}

		if (opt == 1)
			sistema.rankingDeGeneros();
		else if (opt == 2)
			sistema.rankingDeIdades();
		else if (opt == 3)
			sistema.rankingDePlataformas();
		else if (opt == 4)
			sistema.rankingDeRentabilidades();
		else if (opt == 5)
			sistema.custoMedioBiblioteca();
		else if (opt==6)
			sistema.nrMedioTitulos();
		else
			break;	// opt = 7, o utilizador quer sair
	}

}
int main() {
	printWelcomeMenu();
	Sistema sistema;

	sistema.readUtilizadores();
	sistema.readTitulos();


	int opt;

	// Perguntar ao utilizador o que quer fazer atï¿½ este indicar que deseja sair
	while (true) {
		printMainMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try {
			opt = getOption(1, 8);
		} catch (InputInvalido &e) {
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			displayTitulos(sistema);
		else if (opt == 2)
			adicionarUtilizador(sistema);
		else if (opt == 3)
			displayUtilizadores(sistema);
		else if (opt == 4)
			adicionarJogo(sistema);
		else if (opt == 5)
			pesquisarUtilizador(sistema);
//		else if (opt == 6)
//			pesquisarJogo(sistema);
		else if (opt == 7)
			displayRankings(sistema);
		else {
			std::cout << "Adeus!" << std::endl;
			return 0;
		}
	}
	sistema.saveUtilizadores();
	sistema.saveTitulos();

	return 0;
}

#include <iomanip>
std::string Sistema:: displayTitulosPorTipo() const
{
	std::vector<Titulo*> onlines;
	std::vector <Titulo*> homes;

	for(const auto & titulo: this->titulos) {
		if (dynamic_cast<Online*>(titulo) != NULL)
			homes.push_back(titulo);
		else
			homes.push_back(titulo);
	}

	unsigned int numero = std::max(onlines.size(),homes.size());
	std::stringstream resultado;
	resultado<< "Titulos: "<<std::endl;
	resultado <<"Online"<<std::setw(10)<<"Home"<<std::endl;

	for(unsigned int i=0; i< numero ;i++)
	{
		if(i < onlines.size())
			resultado << onlines[i]->getNome();
		resultado << std::setw(10);
		if(i < homes.size())
			resultado << homes[i]->getNome();
		resultado << std::endl;
	}
	return resultado.str();
}
