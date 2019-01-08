#include "Sistema.h"
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Titulo.h"
#include <vector>
#include <cctype>
#include <cstring>

bool userNameAscend(Utilizador* user1, Utilizador* user2) {
	return user1->getNome() < user2->getNome();
}

bool userNameDescend(Utilizador* user1, Utilizador* user2) {
	return user1->getNome() > user2->getNome();
}

bool userAgeAscend(Utilizador* user1, Utilizador* user2) {
	return user1->getIdade() < user2->getIdade();
}

bool userAgeDescend(Utilizador* user1, Utilizador* user2) {
	return user1->getIdade() > user2->getIdade();
}
bool userNumberGamesAscend(Utilizador* user1, Utilizador* user2) {
	return user1->getBiblioteca().getTitulos().size()
			< user2->getBiblioteca().getTitulos().size();
}
bool userNumberGamesDescend(Utilizador* user1, Utilizador* user2) {
	return user1->getBiblioteca().getTitulos().size()
			> user2->getBiblioteca().getTitulos().size();
}

bool gameIdAscend(Titulo* titulo1, Titulo* titulo2) {
	return titulo1->getIdU() < titulo2->getIdU();
}

bool gameIdDescend(Titulo* titulo1, Titulo* titulo2) {
	return titulo1->getIdU() > titulo2->getIdU();
}

bool gameReleaseAscend(Titulo* titulo1, Titulo* titulo2) {
	return titulo1->getDataLancamento() < titulo2->getDataLancamento();
}

bool gameReleaseDescend(Titulo* titulo1, Titulo* titulo2) {
	return !(titulo1->getDataLancamento() <= titulo2->getDataLancamento());
}

bool gameAgeAscend(Titulo* titulo1, Titulo* titulo2) {
	return titulo1->getIdadeMinima() < titulo2->getIdadeMinima();
}

bool gameAgeDescend(Titulo* titulo1, Titulo* titulo2) {
	return titulo1->getIdadeMinima() > titulo2->getIdadeMinima();
}

bool gameDeveloperAscend(Titulo* titulo1, Titulo* titulo2) {
	return titulo1->getEmpresa() < titulo2->getEmpresa();
}

bool gameDeveloperDescend(Titulo* titulo1, Titulo* titulo2) {
	return !(titulo1->getEmpresa() < titulo2->getEmpresa());
}

bool cmpParJogoRentabilidade(const std::pair<std::string, float> & p1,
		const std::pair<std::string, float> & p2) {
	return p1.second > p2.second;
}

Sistema::~Sistema() {
	for (auto titulo : titulos)
		delete titulo;
}

void Sistema::readFileUtilizadores(std::ifstream & f) {
	std::string nome, mail, idadeStr, numeroAnunciosStr, numeroCliquesStr, localidade, titulo, cartao, dataCartao,
			idCartao;
	float saldo;
	unsigned int idade, numeroAnuncios, numeroCliques;
	std::stringstream tituloSs, cartaoSs;
	std::vector<CartaoCredito> cartoes;

	getline(f, nome);
	getline(f, mail);
	getline(f, idadeStr);
	getline(f, localidade);

	getline(f, cartao);

	while (cartao != "") {
		cartaoSs << cartao;
		cartaoSs >> saldo >> dataCartao >> idCartao;
		cartoes.push_back(CartaoCredito(saldo, Data(dataCartao), idCartao));
		getline(f, cartao);
		cartaoSs.str(std::string());
		cartaoSs.clear();
	}

	banco.adicionaCartoesCredito(cartoes);

	idade = std::stoul(idadeStr, NULL, 0);

	Biblioteca B;
	while (!f.eof()) {
		std::string tipoDeJogo;
		std::string nomeDoJogo;
		float idadeMinima;
		std::string plataforma;
		float preco;
		std::string genero = ".";
		std::string empresa;
		std::string dataStr;
		std::vector<std::string> generos;
		std::vector<float> price_history;
		std::string subscricao;
		std::string precoSubsStr;

		getline(f, titulo);

		tituloSs << titulo;

		tituloSs >> tipoDeJogo;

		if (tipoDeJogo == "Online") {
			Online *ptr;
			std::vector<Data> datasJogo;
			std::vector<unsigned int> minutosJogados;
			tituloSs >> nomeDoJogo >> idadeMinima >> plataforma >> empresa
					>> dataStr >> subscricao >> precoSubsStr;

			Data d(dataStr);

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco) {
				price_history.push_back(preco);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;

			while (tituloSs >> genero) {
				generos.push_back(genero);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, numeroAnunciosStr);
			numeroAnuncios = std::stoul(numeroAnunciosStr, nullptr, 0);

			getline(f, numeroCliquesStr);
			numeroCliques = std::stoul(numeroCliquesStr, nullptr, 0);

			unsigned int precoSubs = std::stof(precoSubsStr);
			if (subscricao == "fixa")
				ptr = new Online(nomeDoJogo, idadeMinima, plataforma, 0,
						generos, empresa, d, numeroAnuncios, numeroCliques, true, precoSubs);
			else
				ptr = new Online(nomeDoJogo, idadeMinima, plataforma, 0,
						generos, empresa, d, numeroAnuncios, numeroCliques, false, precoSubs);

			bool fim = false;
			std::string data;
			unsigned int minutos;
			while (true) {
				if (fim)
					break;

				else {
					getline(f, titulo);
					tituloSs << titulo;
					while (tituloSs >> data >> minutos) {
						datasJogo.push_back(Data(data));
						minutosJogados.push_back(minutos);
					}
					fim = true;
				}
			}
			ptr->setHistoricoPreco(price_history);
			ptr->setDatasJogo(datasJogo);
			ptr->setMinutosJogo(minutosJogados);
			B.adicionaTitulo(ptr);
		} else {
			Home *ptr;
			tituloSs >> nomeDoJogo >> idadeMinima >> plataforma >> empresa
					>> dataStr;

			Data d(dataStr);

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco) {
				price_history.push_back(preco);
			}
			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;

			while (tituloSs >> genero) {
				generos.push_back(genero);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, numeroAnunciosStr);
			numeroAnuncios = std::stoul(numeroAnunciosStr, nullptr, 0);

			getline(f, numeroCliquesStr);
			numeroCliques = std::stoul(numeroCliquesStr, nullptr, 0);

			ptr = new Home(nomeDoJogo, idadeMinima, plataforma, preco, generos,
					empresa, d, numeroAnuncios, numeroCliques);
			std::string data;
			getline(f, titulo);
			tituloSs << titulo;

			while (tituloSs >> data) {
				ptr->adicionaAtualizacao(Data(data));
			}

			B.adicionaTitulo(ptr);
			ptr->setHistoricoPreco(price_history);
		}
		tituloSs.str(std::string());
		tituloSs.clear();

	}

	Utilizador * U = new Utilizador(nome, mail, idade, localidade, B);

	for (const auto & c : cartoes) {
		U->adicionaCartaoCredito(c);
	}

	this->jogadores.push_back(U);
}

void Sistema::readUtilizadores() {

	unsigned int i = 1;

	while (true) {
		std::ifstream file;
		file.open("Utilizador" + std::to_string(i) + ".txt");
		if (!file.fail()) {
			readFileUtilizadores(file);
			file.close();
			i++;
		} else
			break;
	}

}

void Sistema::saveUtilizadores() const{

	for (unsigned int i = 0; i < jogadores.size(); i++) {
		std::ofstream file("Utilizador" + std::to_string(i + 1) + ".txt");
		std::string nome = jogadores.at(i)->getNome();
		std::string mail = jogadores.at(i)->getEmail();
		unsigned int idade = jogadores.at(i)->getIdade();
		std::string localidade = jogadores.at(i)->getMorada();
		std::vector<CartaoCredito> cartoes = jogadores.at(i)->getCc();

		file << nome << std::endl << mail << std::endl << idade << std::endl
				<< localidade;
		std::vector<Titulo*> titulos =
				jogadores.at(i)->getBiblioteca().getTitulos();

		if (cartoes.size() != 0) {
			file << std::endl;
			for (const auto & cartao : cartoes) {
				file << cartao.getSaldo() << " " << cartao.getDataDeValidade()
						<< " " << cartao.getId() << std::endl;
			}
		}

		file << std::endl;

		for (size_t i = 0; i < titulos.size(); i++) {
			Online* online = dynamic_cast<Online*>(titulos.at(i));
			if (online != NULL) {
				std::string tipoDeJogo = "Online";
				std::string nomeDoJogo = online->getNome();
				unsigned int idadeMinima = online->getIdadeMinima();
				std::string plataforma = online->getPlataforma();
				std::vector<float> preco = online->getHistorialPreco();
				std::vector<std::string> genero = online->getGeneros();
				std::string empresa = online->getEmpresa();
				Data data = online->getDataLancamento();
				std::string subscricao;
				if (online->getSubscricao())
					subscricao = "fixa";
				else
					subscricao = "variavel";
				float precoSubs = online->getPrecoSubscricao();
				std::vector<Data> datasJogo = online->getDatasJogo();
				std::vector<unsigned int> minutosJogados =
						online->getMinutosJogo();
				file << tipoDeJogo << " " << nomeDoJogo << " " << idadeMinima
						<< " " << plataforma << " ";

				file << empresa << " " << data << " " << subscricao << " "
						<< precoSubs << std::endl;
				for (unsigned int i = 0; i < preco.size(); i++) {
					if (i == preco.size() - 1)
						file << preco[i] << std::endl;
					else
						file << preco[i] << " ";
				}

				for (unsigned int i = 0; i < genero.size(); i++) {
					if (i == genero.size() - 1)
						file << genero[i] << std::endl;
					else
						file << genero[i] << " ";
				}

				file << online->getAnuncios() << std::endl;
				file << online->getCliques() << std::endl;

				for (unsigned int i = 0; i < datasJogo.size(); i++) {
					if (i == datasJogo.size() - 1)
						file << datasJogo[i] << " " << minutosJogados[i];
					else
						file << datasJogo[i] << " " << minutosJogados[i] << " ";
				}

				if (i != titulos.size() - 1)
					file << std::endl;
			} else {
				Home* home = dynamic_cast<Home*>(titulos.at(i));
				std::string tipoDeJogo = "Home";
				std::string nomeDoJogo = home->getNome();
				unsigned int idadeMinima = home->getIdadeMinima();
				std::string plataforma = home->getPlataforma();
				std::vector<float> preco = home->getHistorialPreco();
				std::vector<std::string> genero = home->getGeneros();
				std::string empresa = home->getEmpresa();
				Data data = home->getDataLancamento();
				std::vector<Data> datasAtualizacao = home->getDatas();
				file << tipoDeJogo << " " << nomeDoJogo << " " << idadeMinima
						<< " " << plataforma << " " << empresa << " " << data
						<< std::endl;
				for (unsigned int i = 0; i < preco.size(); i++) {
					if (i == preco.size() - 1)
						file << preco[i] << std::endl;
					else
						file << preco[i] << " ";
				}

				for (unsigned int i = 0; i < genero.size(); i++) {
					if (i == genero.size() - 1)
						file << genero[i] << std::endl;
					else
						file << genero[i] << " ";
				}

				file << home->getAnuncios() << std::endl;
				file << home->getCliques() << std::endl;

				for (unsigned int i = 0; i < datasAtualizacao.size(); i++) {
					if (i == datasAtualizacao.size() - 1)
						file << datasAtualizacao[i];
					else
						file << datasAtualizacao[i] << " ";
				}

				if (i != titulos.size() - 1)
					file << std::endl;

			}
		}
		file.close();
	}
}


void Sistema::readFileEmpresas(std::ifstream & f) {
	std::string nome, mail,numeroTelemovel,nif,titulo;
	std::stringstream tituloSs;
	std::string numeroAnunciosStr;
	std::string numeroCliquesStr;
	unsigned int numeroAnuncios;
	unsigned int numeroCliques;

	getline(f, nome);
	getline(f, mail);
	getline(f, numeroTelemovel);
	getline(f, nif);

	Empresa *e= new Empresa(nome,mail,numeroTelemovel,nif);

	while (!f.eof()) {
		std::string tipoDeJogo;
		std::string nomeDoJogo;
		float idadeMinima;
		std::string plataforma;
		float preco;
		std::string genero = ".";
		std::string empresa;
		std::string dataStr;
		std::vector<std::string> generos;
		std::vector<float> price_history;
		std::string subscricao;
		std::string precoSubsStr;

		getline(f, titulo);
		if (titulo == "")
			break;

		tituloSs << titulo;

		tituloSs >> tipoDeJogo;

		if (tipoDeJogo == "Online") {
			Online *ptr;
			std::vector<Data> datasJogo;
			std::vector<unsigned int> minutosJogados;
			tituloSs >> nomeDoJogo >> idadeMinima >> plataforma >> empresa
					>> dataStr >> subscricao >> precoSubsStr;

			Data d(dataStr);

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco) {
				price_history.push_back(preco);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;

			while (tituloSs >> genero) {
				generos.push_back(genero);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, numeroAnunciosStr);
			numeroAnuncios = std::stoul(numeroAnunciosStr, nullptr, 0);

			getline(f, numeroCliquesStr);
			numeroCliques = std::stoul(numeroCliquesStr, nullptr, 0);

			unsigned int precoSubs = std::stof(precoSubsStr);
			if (subscricao == "fixa")
				ptr = new Online(nomeDoJogo, idadeMinima, plataforma, 0,
						generos, empresa, d, numeroAnuncios, numeroCliques, true, precoSubs);
			else
				ptr = new Online(nomeDoJogo, idadeMinima, plataforma, 0,
						generos, empresa, d, numeroAnuncios, numeroCliques, false, precoSubs);

			bool fim = false;
			std::string data;
			unsigned int minutos;
			while (true) {
				if (fim)
					break;

				else {
					getline(f, titulo);
					tituloSs << titulo;
					while (tituloSs >> data >> minutos) {
						datasJogo.push_back(Data(data));
						minutosJogados.push_back(minutos);
					}
					fim = true;
				}
			}
			ptr->setHistoricoPreco(price_history);
			ptr->setDatasJogo(datasJogo);
			ptr->setMinutosJogo(minutosJogados);
			e->criarTitulo(ptr);
			this->titulos.push_back(ptr);
		} else {
			Home *ptr;
			tituloSs >> nomeDoJogo >> idadeMinima >> plataforma >> empresa
					>> dataStr;

			Data d(dataStr);

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;
			while (tituloSs >> preco) {
				price_history.push_back(preco);
			}
			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, titulo);
			tituloSs << titulo;

			while (tituloSs >> genero) {
				generos.push_back(genero);
			}

			tituloSs.str(std::string());
			tituloSs.clear();

			getline(f, numeroAnunciosStr);
			numeroAnuncios = std::stoul(numeroAnunciosStr, nullptr, 0);

			getline(f, numeroCliquesStr);
			numeroCliques = std::stoul(numeroCliquesStr, nullptr, 0);

			ptr = new Home(nomeDoJogo, idadeMinima, plataforma, preco, generos,
					empresa, d, numeroAnuncios, numeroCliques);
			std::string data;
			getline(f, titulo);
			tituloSs << titulo;

			while (tituloSs >> data) {
				ptr->adicionaAtualizacao(Data(data));
			}
			ptr->setHistoricoPreco(price_history);
			e->criarTitulo(ptr);
			this->titulos.push_back(ptr);
		}
		tituloSs.str(std::string());
		tituloSs.clear();
	}

	this->empresas.insert(e);
}

void Sistema::readEmpresas() {

	unsigned int i = 1;

	while (true) {
		std::ifstream file;
		file.open("Empresa" + std::to_string(i) + ".txt");
		if (!file.fail()) {
			readFileEmpresas(file);
			file.close();
			i++;
		} else
			break;
	}
}


void Sistema::saveEmpresas(){
	unsigned i=1;
	for(auto empresa:this->empresas){
		std::ofstream file("Empresa" + std::to_string(i) + ".txt");
		i++;
		std::string nome=empresa->getNomeEmpresa();
		std::string mail=empresa->getContactos().email;
		std::string numero=empresa->getContactos().numeroTelemovel;
		std::string nif=empresa->getNif();
		file << nome << std::endl << mail << std::endl << numero<<std::endl<<nif<<std::endl;

		std::vector<Titulo*> titulos = empresa->getTitulos();

		for (size_t i = 0; i < titulos.size(); i++) {
			Online* online = dynamic_cast<Online*>(titulos.at(i));
			if (online != NULL) {
				std::string tipoDeJogo = "Online";
				std::string nomeDoJogo = online->getNome();
				unsigned int idadeMinima = online->getIdadeMinima();
				std::string plataforma = online->getPlataforma();
				std::vector<float> preco = online->getHistorialPreco();
				std::vector<std::string> genero = online->getGeneros();
				std::string empresa = online->getEmpresa();
				Data data = online->getDataLancamento();
				std::string subscricao;
				if (online->getSubscricao())
					subscricao = "fixa";
				else
					subscricao = "variavel";
				float precoSubs = online->getPrecoSubscricao();
				std::vector<Data> datasJogo = online->getDatasJogo();
				std::vector<unsigned int> minutosJogados =
						online->getMinutosJogo();
				file << tipoDeJogo << " " << nomeDoJogo << " " << idadeMinima
						<< " " << plataforma << " ";

				file << empresa << " " << data << " " << subscricao << " "
						<< precoSubs << std::endl;
				for (unsigned int i = 0; i < preco.size(); i++) {
					if (i == preco.size() - 1)
						file << preco[i] << std::endl;
					else
						file << preco[i] << " ";
				}

				for (unsigned int i = 0; i < genero.size(); i++) {
					if (i == genero.size() - 1)
						file << genero[i] << std::endl;
					else
						file << genero[i] << " ";
				}

				file << online->getAnuncios() << std::endl;
				file << online->getCliques() << std::endl;

				if (i != titulos.size() - 1)
					file << std::endl;
			} else {
				Home* home = dynamic_cast<Home*>(titulos.at(i));
				std::string tipoDeJogo = "Home";
				std::string nomeDoJogo = home->getNome();
				unsigned int idadeMinima = home->getIdadeMinima();
				std::string plataforma = home->getPlataforma();
				std::vector<float> preco = home->getHistorialPreco();
				std::vector<std::string> genero = home->getGeneros();
				std::string empresa = home->getEmpresa();
				Data data = home->getDataLancamento();
				std::vector<Data> datasAtualizacao = home->getDatas();
				file << tipoDeJogo << " " << nomeDoJogo << " " << idadeMinima
						<< " " << plataforma << " " << empresa << " " << data
						<< std::endl;
				for (unsigned int i = 0; i < preco.size(); i++) {
					if (i == preco.size() - 1)
						file << preco[i] << std::endl;
					else
						file << preco[i] << " ";
				}

				for (unsigned int i = 0; i < genero.size(); i++) {
					if (i == genero.size() - 1)
						file << genero[i] << std::endl;
					else
						file << genero[i] << " ";
				}

				file << home->getAnuncios() << std::endl;
				file << home->getCliques() << std::endl;

				for (unsigned int i = 0; i < datasAtualizacao.size(); i++) {
					if (i == datasAtualizacao.size() - 1)
						file << datasAtualizacao[i];
					else
						file << datasAtualizacao[i] << " ";
				}

				if (i != titulos.size() - 1)
					file << std::endl;

			}
		}
		file.close();
	}
}

unsigned int Sistema::nrMedioTitulos() const{

	unsigned int nrTotalTitulos = 0;

	for (const auto & utilizador : this->jogadores) {
		nrTotalTitulos += utilizador->getBiblioteca().getTitulos().size();
	}

	double media = static_cast<double>(nrTotalTitulos) / this->jogadores.size();

	nrTotalTitulos = media + 0.5;

	return nrTotalTitulos;
}

float Sistema::custoMedioBiblioteca() const{

	float custoTotal = 0;

	for (const auto & utilizador : this->jogadores) {
		custoTotal += utilizador->getGastos();
	}

	custoTotal /= this->jogadores.size(); /*cada utilizador tem uma biblioteca*/
	return custoTotal;
}


bool Sistema::validEmail(const std::string email) const{
        for (const auto & utilizador : this->jogadores) {
            if (utilizador->getEmail() == email)
                return false;
        }

        return true;

 }

void Sistema::isValidEmail(std::string & email,bool checkafter) const{
    const int x = 60; //random size enough to hold contents of array plus one for null terminator
    char input[x]; //array to hold input
    int sizeOf; //holds length of input array
    char* ptr = nullptr; //pointer
    char* ptr2 = nullptr; //pointer

    std::cout << "Escreve o teu endereco de email \n";
    std::cin.getline(input, x);
    email = input;
    sizeOf = strlen(input);

    for (int i = 0; i < sizeOf; i++) {
        ptr = strstr(input, "@"); //searches input array for "@" string
        if (ptr != nullptr) {
            break;
        }
    }

    for (int i = 0; i < sizeOf; i++) {
        ptr2 = strstr(input, "."); //searches input array for "." string
        if (ptr2 != nullptr && &ptr2 > &ptr) {
            break;
        }
    }

    if (ptr != nullptr) //validates input of "@" sign
            {
        if (ptr2 != 0 && &ptr2 < &ptr) {
        	if(!checkafter) {
            if (validEmail(email)) {
                return;
            } else {
                throw(ErroEmail("Email ja existente.\n"));
            }

            }

        }

        else {
            throw(ErroEmail("Falta o . depois de @\n"));

        }
    }

    else {
        throw(ErroEmail("Falta o simbolo @.\n"));
    }

}

void Sistema::saldoUtilizador(const Utilizador * u) const{
	float saldo = 0;
		for (const auto & cartao : u->getCc())
			saldo += cartao.getSaldo();
	std::cout << "Saldo: " << saldo << " euros" << std::endl;
}

void Sistema::tempoJogado(const Utilizador * u) const{
	unsigned int horas=0;
	for (const auto & titulo : u->getBiblioteca().getTitulos())
	{
		Online* online = dynamic_cast<Online*>(titulo);

		if (online != NULL)
		{
			horas += online->getHorasTotais();
		}
	}
	std::cout << "Horas jogadas: " << horas << std::endl;
}

void Sistema::adicionaUtilizador(Utilizador *u) {
    this->jogadores.push_back(u);
}

void Sistema::utilizadorJogar(Utilizador * u, Titulo * t, unsigned int minutos) {
	for(const auto titulo : u->getBiblioteca().getTitulos()) {
		if (titulo->getNome() == t->getNome() && titulo->getPlataforma() == t->getPlataforma())
		{
			Online * o = dynamic_cast<Online *>(titulo);
			o->adicionaEstatisticas(banco.getDataAtual(), minutos);
		}

	}
}

void Sistema::addTitulo(Titulo *titulo,std::string empresa){
	std::string nome=titulo->getNome();
	std::string plataforma=titulo->getPlataforma();
	for(auto const&i:titulos){
		if(i->getNome()==nome && i->getEmpresa()==empresa && i->getPlataforma()==plataforma)
			throw TituloJaAdicionado("Titulo ja adicionado");
	}
	titulos.push_back(titulo);
	for(auto e:this->empresas){
		if(e->getNomeEmpresa()==empresa)
			e->criarTitulo(titulo);
	}
}

void Sistema::adicionaEmpresa(Empresa *empresa){
	for(auto e: this->empresas){
		if(e->getNomeEmpresa()==empresa->getNomeEmpresa() && e->getNif()==empresa->getNif())
			throw EmpresaJaAdicionada("Empresa ja adicionada");
	}
	this->empresas.insert(empresa);
}

void Sistema::adicionaAtualizacao(std::string nome,std::string plataforma,const Data data){

	for(const auto utilizador: jogadores){
		std::vector<Titulo*> titulos=utilizador->getBiblioteca().getTitulos();
		for(auto titulo: titulos){
			if(titulo->getNome()==nome && titulo->getPlataforma()==plataforma){
				Home* h=dynamic_cast<Home*>(titulo);
				h->adicionaAtualizacao(data);
			}
		}
	}
}

void Sistema::ordenaUtilizadores(std::string tipo, bool ascend) {
	if (tipo == "idade") {
		if (ascend)
			std::sort(jogadores.begin(), jogadores.end(), userAgeAscend);
		else
			std::sort(jogadores.begin(), jogadores.end(), userAgeDescend);
	}

	else if (tipo == "nome") {
		if (ascend)
			std::sort(jogadores.begin(), jogadores.end(), userNameAscend);
		else
			std::sort(jogadores.begin(), jogadores.end(), userNameDescend);
	}
	else if (tipo == "jogos") {
		if (ascend)
			std::sort(jogadores.begin(), jogadores.end(),
					userNumberGamesAscend);
		else
			std::sort(jogadores.begin(), jogadores.end(),
					userNumberGamesDescend);
	}
	displayUtilizadores();
}


void Sistema::ordenaTitulos(std::string tipo, bool ascend){
	if (tipo == "id") {
			if (ascend)
				std::sort(titulos.begin(), titulos.end(), gameIdAscend);
			else
				std::sort(titulos.begin(), titulos.end(), gameIdDescend);
		}

	else if (tipo == "data") {
		if (ascend)
			std::sort(titulos.begin(), titulos.end(), gameReleaseAscend);
		else
			std::sort(titulos.begin(), titulos.end(), gameReleaseDescend);
	}

	else if (tipo == "idade") {
		if (ascend)
			std::sort(titulos.begin(), titulos.end(), gameAgeAscend);
		else
			std::sort(titulos.begin(), titulos.end(), gameAgeDescend);
	}
	else if (tipo == "empresa") {
		if (ascend)
			std::sort(titulos.begin(), titulos.end(),
					gameDeveloperAscend);
		else
			std::sort(titulos.begin(), titulos.end(),
					gameDeveloperDescend);
	}

	displayTitulos();
}

Utilizador* Sistema::pesquisaUtilizador(std::string nome, std::string email) {
	for(size_t i=0;i<jogadores.size();i++) {
		if (jogadores[i]->getEmail()==email && jogadores[i]->getNome()==nome){
			return jogadores[i];
		}
	}
	throw(UtilizadorInexistente("O utilizador de nome "+ nome+ " e email "+email+" nao existe"));
}

Titulo* Sistema::pesquisaJogo(std::string nome,std::string plataforma) const{
	for(auto titulo : this->titulos) {
		if (titulo->getNome() == nome && titulo->getPlataforma() == plataforma){
			std::cout << titulo->getNome() << ", " << titulo->getEmpresa() << ", " << titulo->getPlataforma() << ", " << titulo->getPreco() << " euros, (desconto: " << titulo->getDesconto() << "% ), " << titulo->getDataLancamento().getAno() << ", idade minima: " << titulo->getIdadeMinima() << std::endl;
			return titulo;
		}
	}
	throw(TituloInexistente("O titulo de nome " + nome + " na plataforma " + plataforma + " nao existe"));
}

Empresa* Sistema::pesquisaEmpresa(std::string nome,std::string nif) const{
	for (auto empresa: this->empresas){
		if(empresa->getNomeEmpresa()==nome && empresa->getNif()==nif){
			return empresa;
		}
	}
	throw(EmpresaInexistente("A empresa de nome "+nome+" com nif "+nif+" nao existe"));
}

std::vector<Titulo*> Sistema::ordenaTitulosUtilizador(const Utilizador *u, std::string criterio,bool ascend) const{
	std::vector<Titulo*> titulos = u->getBiblioteca().getTitulos();

	if (criterio == "id")
	{
		if (ascend)
			sort(titulos.begin(), titulos.end(), gameIdAscend);
		else
			sort(titulos.begin(), titulos.end(), gameIdDescend);
	}
	else if (criterio == "data")
	{
		if (ascend)
			sort(titulos.begin(), titulos.end(), gameReleaseAscend);
		else
			sort(titulos.begin(), titulos.end(), gameReleaseDescend);
	}
	else if (criterio == "idade")
	{
		if (ascend)
			sort(titulos.begin(), titulos.end(), gameAgeAscend);
		else
			sort(titulos.begin(), titulos.end(), gameAgeDescend);
	}
	else if (criterio == "empresa")
	{
		if (ascend)
			sort(titulos.begin(), titulos.end(), gameDeveloperAscend);
		else
			sort(titulos.begin(), titulos.end(), gameDeveloperDescend);
	}

	return titulos;
}

void displayRank(std::vector<std::string> a) {

	std::vector<std::string> aux=a;
	sort(aux.begin(), aux.end());
	aux.erase(std::unique(aux.begin(), aux.end()), aux.end());

	std::vector<int> co;
	for (size_t i = 0; i < aux.size(); i++) {
		co.push_back(count(a.begin(), a.end(), aux[i]));
	}
	for (size_t i = 0; i < aux.size(); i++) {
		int maxElementIndex = std::max_element(co.begin(),co.end()) - co.begin();
		std::cout<<(i+1)<<": "<<aux[maxElementIndex]<<" Ocorrencias: "<< co[maxElementIndex]<<std::endl;
		co[maxElementIndex]=0;
	}
	std::cout<<std::endl<<std::endl;
}

void Sistema::rankingDeGeneros() const{
	std::vector<std::string> generos;

	for (auto const & utilizador : this->jogadores) {
		std::vector<Titulo*> titulos = utilizador->getBiblioteca().getTitulos();

		for (auto const & titulo : titulos) {
			std::vector<std::string> generosVector = titulo->getGeneros();

			for (auto const & genero : generosVector) {
				generos.push_back(genero);
			}
		}
	}

	displayRank(generos);
}

void Sistema::rankingDePlataformas() const{
	std::vector<std::string> plataformas;

	for (auto const & utilizador : this->jogadores) {
		std::vector<Titulo*> titulos = utilizador->getBiblioteca().getTitulos();

		for (auto const & titulo : titulos) {
			plataformas.push_back(titulo->getPlataforma());
		}
	}

	displayRank(plataformas);
}

void Sistema::rankingDeIdades() const{

	std::vector<std::string> faixasEtarias;

	for (auto const & utilizador : this->jogadores) {
		unsigned int idade = utilizador->getIdade();

		if (idade <= 10)
			faixasEtarias.push_back("0-10");
		else if (idade <= 20)
			faixasEtarias.push_back("11-20");
		else if (idade <= 30)
			faixasEtarias.push_back("21-30");
		else if (idade <= 40)
			faixasEtarias.push_back("31-40");
		else
			faixasEtarias.push_back("40+");
	}

	displayRank(faixasEtarias);
}

int findPair(const std::vector<std::pair<std::string, float>> & rentabilidade,
		std::string nome){
	unsigned int comprimento = rentabilidade.size();
	for (unsigned int par = 0; par < comprimento; par++) {
		if (rentabilidade[par].first == nome) {
			return par;
		}
	}
	return -1;
}

void Sistema::rankingDeRentabilidades() const{

	std::vector<std::pair<std::string, float>> rentabilidade;
	int pos;

	for (auto const & utilizador : this->jogadores) {
		std::vector<Titulo*> titulos = utilizador->getBiblioteca().getTitulos();

		for (auto const & titulo : titulos) {
			pos = findPair(rentabilidade, titulo->getNome());
			if (pos == -1) {
				rentabilidade.push_back(
						std::make_pair(titulo->getNome(), titulo->getGastos()));
			} else {
				rentabilidade[pos].second += titulo->getGastos();
			}
		}
	}

	sort(rentabilidade.begin(), rentabilidade.end(), cmpParJogoRentabilidade);

	for (auto const & titulo : rentabilidade) {
		std::cout << titulo.first << ": " << titulo.second << std::endl;
	}
}

std::vector<Utilizador*> Sistema::getJogadores() const{
	return this->jogadores;
}

void Sistema::displayUtilizadores() const{
	for (const auto & utilizador : this->jogadores)
		std::cout << utilizador->getNome() << ", " << utilizador->getIdade() << ", numero de jogo: " << utilizador->getBiblioteca().getTitulos().size() << std::endl;
	std::cout<<std::endl<<std::endl;
}

std::vector<Titulo *> Sistema::getTitulos() const{
	return this->titulos;
}

void Sistema::displayTitulos() const{
	for (const auto & titulo : this->titulos)
		std::cout << titulo->getNome() << ", " << titulo->getEmpresa() << ", " << titulo->getPlataforma() << ", " << titulo->getPreco() << " euros, (desconto: " << titulo->getDesconto() << "% ), " << titulo->getDataLancamento().getAno() << ", idade minima: " << titulo->getIdadeMinima() << std::endl;
	std::cout << std::endl<<std::endl;
}

std::vector<std::string> Sistema::getPlataformas() const{
	return this->plataformas;
}

Banco Sistema::getBanco() const{
	return this->banco;
}

void Sistema::dataValida(CartaoCredito & D) const{
	if (!this->banco.isDataValida(D))
	{
		std::cout << "O cartao de "+D.getId()+ " tem a data invalida"<<std::endl;
		std::cout << "A atualizar automaticamente a validade do cartao, extendendo para 3 anos"<<std::endl;
		D.atualizaDataDeValidade();
		}

}

void Sistema::displayEmpresas(std::string s) const{
	if(s=="plataforma"){
		std::cout<< "Insira a plataforma" << std::endl;
		getline(std::cin,s);
		for(auto it : this->empresas){
			std::vector <Titulo*> t = it->getTitulos();
			for(auto titulo : t){
				if(titulo->getPlataforma() == s) {
					std::cout << it->getNomeEmpresa() << "  "<<it->getNif()<<std::endl;
					break;
				}
			}
		}
	}

	else if(s=="numero"){
		std::cout<<"Insira o numero de titulos"<<std::endl;
		int opt;
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
		for(auto it : this->empresas){
			std::cout << it->getNumeroTitulos() << std::endl;
			if(it->getNumeroTitulos() == (unsigned)opt)
				std::cout << it->getNomeEmpresa() << "  "<<it->getNif()<<std::endl;
		}
	}

	else {
		for(auto it : this->empresas){
			std::cout << "Empresa: " << it->getNomeEmpresa() << "; NIF: "<<it->getNif()  << "; N.º de jogos: " << it->getNumeroTitulos() <<std::endl;
		}
	}
}
