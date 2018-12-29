
#include <iostream>
#include "Titulo.h"
#include "Banco.h"
#include "Erro.h"
#include "Empresa.h"
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
	std::cout << "4. Pesquisar Utilizador" << std::endl;
	std::cout << "5. Pesquisar Jogo" << std::endl;
	std::cout << "6. Rankings e Estatisticas" << std::endl;
	std::cout << "7. Adicionar Empresa" << std::endl;
	std::cout << "8. Pesquisar Empresa" << std::endl;
	std::cout << "9. Sair" << std::endl << std::endl;
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
	std::cout << "2. Adicionar titulo a whishlist" << std::endl;
	std::cout << "3. Comprar titulo na whishlist" << std::endl;
	std::cout << "4. Adicionar cartao de credito" << std::endl;
	std::cout << "5. Verificar Saldo" << std::endl;
	std::cout << "6. Jogar" << std::endl;
	std::cout << "7. Tempo Jogado" << std::endl;
	std::cout << "8. Sair" << std::endl;
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

void adicionarUtilizador(Sistema * sistema) {

	std::string nome;
	std::string email;
	std::string idade;
	std::string morada;
	std::cout << "A criar utilizador...  \n";
	std::cout << "Insere um nome: ";
	getline(std::cin, nome);

	while (true) {
		try {
			sistema->isValidEmail(email);
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;
			continue;
		}
		break;
	}

	std::cout << "Insere a tua idade: ";
	getline(std::cin, idade);
	getline(std::cin, morada);

	Utilizador *u = new Utilizador(nome, email, std::stoul(idade, NULL, 0), morada);
	sistema->adicionaUtilizador(u);

	std::cout << "Utilizador guardado com sucesso!" << std::endl << std::endl;
	return;
}

void lerData(std::string data) {

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
		else if ((dia == 29) && (ano % 4 != 0))
			throw(DataInvalida("Data Incorreta!"));
		break;
	}


	return ;
}

void adicionarJogo(Sistema * sistema, std::string nomeEmpresa) {
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

	if (tipo == "Home") {
		Home *home = new Home(nome, idadeMinima, plataforma, preco, generos,
				nomeEmpresa, Data(data));
		try {
			sistema->addTitulo(home,nomeEmpresa);
		} catch (TituloJaAdicionado &e) {
			std::cout << e.getInfo();
		}

	} else if (tipo == "Online") {
		std::cout << std::endl << "Tipo de subscricao ( Variavel ou Fixa ): ";
		std::string tipoSubs;
		getline(std::cin, tipoSubs);
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
				generos, nomeEmpresa, Data(data), tipoSubscricao, precoSubscricao);
		try {
			sistema->addTitulo(online,nomeEmpresa);
		} catch (TituloJaAdicionado &e) {
			std::cout << "\n" << e.getInfo();
		}
	}

	std::cout << "O titulo " << nome << " adicionado com sucesso!" << std::endl
			<< std::endl;
}

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void adicionarEmpresa(Sistema * sistema){
	std::string nome;
	std::string email;
	std::string numeroTelemovel;
	std::string nif;
	std::cout << "\nNome da empresa: ";
	getline(std::cin, nome);

	while (true) {
		try {
			sistema->isValidEmail(email);
		} catch (Erro &e) {
			std::cout << e.getInfo() << std::endl;
			continue;
		}
		break;
	}

	while(true){
		std::cout << "\nIntroduza o numero de telemovel: ";
		getline(std::cin, numeroTelemovel);
		if(is_digits(numeroTelemovel) && numeroTelemovel.size()==9){
			break;
		}
		if(numeroTelemovel.size()!=9){
			std::cout << "Introduza um numero com 9 digitos\n";
		}
		else std::cout << "O numero de telemovel so pode ter algarismos";
	}

	while(true){
		std::cout << "Introduza o NIF: ";
		getline(std::cin, nif);
		if(is_digits(nif) && nif.size()==9){
			break;
		}
		if(nif.size()!=9){
			std::cout << "Introduza um NIF com 9 digitos\n";
		}
		else std::cout << "O NIF so pode ter algarismos";
	}

	Empresa *empresa= new Empresa(nome,email,numeroTelemovel,nif);
	try{
		sistema->adicionaEmpresa(empresa);
	}
	catch(EmpresaJaAdicionada &e){
		std::cout << "\n" << e.getInfo();
	}
}

void displayUtilizadores(Sistema * sistema) {
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
			sistema->displayUtilizadores();
		else if (opt == 2)
			sistema->ordenaUtilizadores("idade", true);
		else if (opt == 3)
			sistema->ordenaUtilizadores("idade", false);
		else if (opt == 4)
			sistema->ordenaUtilizadores("jogos", true);
		else if (opt == 5)
			sistema->ordenaUtilizadores("jogos", false);
		else if (opt == 6)
			sistema->ordenaUtilizadores("nome", true);
		else if (opt == 7)
			sistema->ordenaUtilizadores("nome", false);
		else
			break;
	}
}

void ordenaJogosUtilizador(Sistema * sistema, Utilizador* u) {
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
			titulos = sistema->ordenaTitulosUtilizador(u, "id", true);
		else if (opt == 2)
			titulos = sistema->ordenaTitulosUtilizador(u, "id", false);
		else if (opt == 3)
			titulos = sistema->ordenaTitulosUtilizador(u, "data", true);
		else if (opt == 4)
			titulos = sistema->ordenaTitulosUtilizador(u, "data", false);
		else if (opt == 5)
			titulos = sistema->ordenaTitulosUtilizador(u, "idade", true);
		else if (opt == 6)
			titulos = sistema->ordenaTitulosUtilizador(u, "idade", false);
		else if (opt == 7)
			titulos = sistema->ordenaTitulosUtilizador(u, "empresa", true);
		else if (opt == 8)
			titulos = sistema->ordenaTitulosUtilizador(u, "empresa", false);
		else
			break;	// opt = 9, o utilizador quer sair

		for (const auto & titulo : titulos)
			std::cout << titulo->getNome() << std::endl;
	}
}

void displayTitulos(Sistema * sistema) {
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
			sistema->displayTitulos();
		else if (opt == 2)
			sistema->ordenaTitulos("data", true);
		else if (opt == 3)
			sistema->ordenaTitulos("data", false);
		else if (opt == 4)
			sistema->ordenaTitulos("idade", true);
		else if (opt == 5)
			sistema->ordenaTitulos("idade", false);
		else if (opt == 6)
			sistema->ordenaTitulos("empresa", true);
		else if (opt == 7)
			sistema->ordenaTitulos("empresa", false);
		else if (opt == 8)
			return;
	}

}

void escolheTitulo(Sistema * sistema, Utilizador *u) {
	std::string titulo;
	std::string plataforma;
	std::string s;

	while (true) {
		std::cout << "Insira o nome do titulo" << std::endl;
		getline(std::cin, titulo);
		std::cout << "Insira a plataforma" << std::endl;
		getline(std::cin, plataforma);

		try {
			Titulo * t = sistema->pesquisaJogo(titulo, plataforma);

			for (auto & cartao : u->getCc()) {
				try {
					u->AdicionaTitulo(t, cartao);
					sistema->dataValida(cartao);
				} catch (Erro &e) {
					std::cout << e.getInfo() << std::endl;
					continue;
				}
				std::cout << "Adicionou o titulo " << titulo
						<< " a biblioteca do utilizador, removendo " << t->getPreco()
						<< " euros ao cartao " << cartao.getId() << std::endl;
				break;
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
}

void adiconaWishlist(Sistema *sistema, Utilizador *u){
	std::string titulo;
	std::string plataforma;
	std::string s;

	while (true) {
		std::cout << "Insira o nome do titulo" << std::endl;
		getline(std::cin, titulo);
		std::cout << "Insira a plataforma" << std::endl;
		getline(std::cin, plataforma);

		try {
			Titulo * t = sistema->pesquisaJogo(titulo, plataforma);
			unsigned interesse = getOption(1,10);
			float probabilidade = interesse/10;
			u->adicionaWishList(t,interesse,probabilidade);

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
}

void compraTituloWhisList(Sistema *sistema, Utilizador *u){
	std::string titulo;
	std::string plataforma;
	std::string s;

	while (true) {
		std::cout << "Insira o nome do titulo" << std::endl;
		getline(std::cin, titulo);
		std::cout << "Insira a plataforma" << std::endl;
		getline(std::cin, plataforma);

		try {
			Titulo * t = sistema->pesquisaJogo(titulo, plataforma);
			u->removeWishList(t);

			for (auto & cartao : u->getCc()) {
				try {
					u->AdicionaTitulo(t, cartao);
					sistema->dataValida(cartao);
				} catch (Erro &e) {
					std::cout << e.getInfo() << std::endl;
					continue;
				}
				std::cout << "Adicionou o titulo " << titulo
					<< " a biblioteca do utilizador, removendo " << t->getPreco()
					<< " euros ao cartao " << cartao.getId() << std::endl;
				break;
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
}

void escolheCc(Sistema * sistema, Utilizador *u) {
	std::string id;
	std::string saldo;
	std::string s;

	while (true) {
		try {
			std::cout << "Insira o id do cartao:" << std::endl;
			getline(std::cin, id);

			std::cout << "Insira o saldo a depositar:" << std::endl;
			getline(std::cin, saldo);

			CartaoCredito c(std::stof(saldo), sistema->getBanco().getDataAtual(),	id);
			c.atualizaDataDeValidade();
			u->adicionaCartaoCredito(c);
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

	std::cout << "O cartao foi adicionado com sucesso."
			<< std::endl;

}

void utilizadorJoga(Sistema * sistema, Utilizador *u) {
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
			t = sistema->pesquisaJogo(titulo, plataforma);

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
	sistema->utilizadorJogar(u, t, n);
	std::cout << "O utilizador jogou durante " << n << " minutos." << std::endl;
}

void menuUtilizador(Sistema * sistema, Utilizador* u) {
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
		if (opt == 2)
			adiconaWishlist(sistema,u);
		if (opt == 3)
			compraTituloWhisList(sistema, u);
		else if (opt == 4)
			escolheCc(sistema, u);
		else if (opt == 5)
			sistema->saldoUtilizador(u);
		else if (opt == 6)
			utilizadorJoga(sistema, u);
		else if (opt == 7)
			sistema->tempoJogado(u);
		else
			break;	// opt = 5, o utilizador quer sair
	}

}

void pesquisarUtilizador(Sistema * sistema) {

	std::string nome;
	std::cout << "Insere o nome de um utilizador" << std::endl;
	getline(std::cin, nome);
	std::string email;
	std::string s;

	while (true) {

		while (true) {
			try {
				sistema->isValidEmail(email, true);
			} catch (Erro &e) {
				std::cout << e.getInfo() << std::endl;
				continue;
			}
			break;
		}

		try {
			Utilizador *u = sistema->pesquisaUtilizador(nome, email);
			menuUtilizador(sistema, u);
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
}


void pesquisarJogo(Sistema * sistema) {
	std::string nome;
	std::string plataforma;


	std::cout << std::endl << "Nome do titulo: ";
	getline(std::cin, nome);

	std::cout << std::endl << "Plataforma: ";
	std::getline(std::cin, plataforma);

	try {
		Titulo *t = sistema->pesquisaJogo(nome,plataforma);


		std::string atual;

			Home * H = dynamic_cast<Home *>(t);
			if(H!=NULL) {
			std::cout << "Deseja adicionar uma atualizacao (dia atual) ('s' para processar uma atualizacao /outro para nao adicionar "<<std::endl;
			getline(std::cin,atual);
			if(atual == "s") {
				H->adicionaAtualizacao(sistema->getBanco().getDataAtual());
				sistema->adicionaAtualizacao(nome,plataforma,sistema->getBanco().getDataAtual());
				std::cout << "Atualizacao bem sucedida para o respetivo titulo"<<std::endl;

				std::cout <<"Atualizacoes existentes do titulo home"<<std::endl;
				for(const auto &datas: H->getDatas())
					std::cout << datas <<std::endl;
			}

			}
	} catch (TituloInexistente &e) {
		std::cout << "\n" << e.getInfo();
		return;
	}
}

void pesquisarEmpresa(Sistema * sistema){
	std::string nome;
	std::string nif;


	std::cout << std::endl << "Nome da empresa: ";
	getline(std::cin, nome);

	while(true){
		std::cout << "Introduza o NIF: ";
		getline(std::cin, nif);
		if(is_digits(nif) && nif.size()==9){
			break;
		}
		if(nif.size()!=9){
			std::cout << "Introduza um NIF com 9 digitos\n";
		}
		else std::cout << "O NIF so pode ter algarismos";
	}

	try {
		Empresa *empresa=sistema->pesquisaEmpresa(nome,nif);
		if(empresa!=NULL){
			std::string atual;
			std::cout << "Deseja adicionar um titulo ('s' para adicionar um titulo /outro para nao adicionar "<<std::endl;
			getline(std::cin,atual);

			if(atual == "s") {
				adicionarJogo(sistema,nome);
			}
		}
	} catch (EmpresaInexistente &e) {
		std::cout << "\n" << e.getInfo();
		return;
	}

}

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

void displayRankings(Sistema * sistema) {
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
			sistema->rankingDeGeneros();
		else if (opt == 2)
			sistema->rankingDeIdades();
		else if (opt == 3)
			sistema->rankingDePlataformas();
		else if (opt == 4)
			sistema->rankingDeRentabilidades();
		else if (opt == 5)
			std::cout << "Custo: " << sistema->custoMedioBiblioteca() << std::endl;
		else if (opt==6)
			std::cout << "Numero medio de titulos: " << sistema->nrMedioTitulos() << std::endl;
		else
			break;	// opt = 7, o utilizador quer sair
	}

}
int main() {
	printWelcomeMenu();
	Sistema * sistema = new Sistema;

	sistema->readUtilizadores();
	sistema->readTitulos();


	int opt;

	// Perguntar ao utilizador o que quer fazer atï¿½ este indicar que deseja sair
	while (true) {
		printMainMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try {
			opt = getOption(1, 10);
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
			pesquisarUtilizador(sistema);
		else if (opt == 5)
			pesquisarJogo(sistema);
		else if (opt == 6)
			displayRankings(sistema);
		else if (opt == 7)
			adicionarEmpresa(sistema);
		else if (opt == 8)
			pesquisarEmpresa(sistema);
		else {
			std::cout << "Adeus!" << std::endl;
			break;
		}
	}


	sistema->saveUtilizadores();
	sistema->saveTitulos();



	return 0;
}
