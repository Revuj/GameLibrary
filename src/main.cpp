#include <iostream>

#include "Titulo.h"
#include "Banco.h"
#include "Erro.h"


#include <algorithm>
using namespace std;

//estas funções serão eventualmente postas numa outra classe (tipo sistema.h)

unsigned int nrMedioTitulos(const vector <Utilizador>& U) {

    unsigned int nrTotalTitulos = 0;

    for (const auto & utilizador : U)
    {
        nrTotalTitulos+= utilizador.getBiblioteca().getTitulos().size();
    }

    double media = static_cast<double>(nrTotalTitulos)/U.size();

    nrTotalTitulos = media + 0.5;

    return nrTotalTitulos;
}

float custoMedioBiblioteca(const vector < Utilizador>& U) {

    float custoTotal=0;

    for(auto const & utilizadores : U)
    {
        custoTotal += utilizadores.getGastos();
    }

    custoTotal /= U.size(); /*cada utilizador tem uma biblioteca*/
    return custoTotal;
}

template <class T>
int getPos(const vector<T> & v,const T e)
{
    unsigned int pos = 0;
     for (const auto & elemento : v )
     {
         if (elemento == e)
             return pos;
         else
             pos++;
     }

     return -1; /*caso nao encontre o elemento que estamos à procura*/
}

/*void adicionaGenero(const string  & genero, map<string,unsigned int> & m)
{
    map<string,unsigned int>::iterator it =m.lower_bound(genero);

    if (it->first == genero){
        it->second++;
    }
    else
        m[genero]=1;
}*/

bool comparaValor(const pair <string, unsigned int> &i1,const pair<string, unsigned int>& i2)
{
    return i1.second < i2.second;
}

void displayRank(vector<string> a)
{
	//Não testei
	sort(a.begin(),a.end());
	vector<string> aux=a;
	unique (aux.begin(), aux.end());
	vector<int> co;
    for(size_t i=0;i<aux.size();i++)
    {
        co.push_back(count(a.begin(), a.end(), aux[i]));
    }

    for(size_t i=0;i<aux.size();i++){
		cout << i + 1 << ": " << aux.at(distance(co.begin(), max_element(co.begin(), co.end()))-1) <<  endl;
		co.erase(max_element(co.begin(), co.end()));
    }
}


void rankingDeGeneros(vector<Utilizador> utilizadores)
{
	vector<string> generos;

	for (auto const & utilizador : utilizadores)
	{
		vector<Titulo*> titulos = utilizador.getBiblioteca().getTitulos();

		for (auto const & titulo : titulos)
		{
			vector<string> generosVector = titulo->getGeneros();

			for (auto const & genero : generosVector)
			{
				generos.push_back(genero);
			}
		}
	}

	displayRank(generos);
}

void rankingDePlataformas(vector<Utilizador> utilizadores)
{
	vector<string> plataformas;

	for (auto const & utilizador : utilizadores)
	{
		plataformas.push_back(utilizador.PlataformaPreferida());
	}

	displayRank(plataformas);
}

/*void rankingDeIdades(vector<Utilizador> utilizadores)
{
	map <string, unsigned int> faixasEtarias = {{"0 - 10", 0}, {"11 - 20", 0}, {"21 - 30", 0}, {"31 - 40", 0}, {"40+", 0}}; //existem 5 faixas etárias: 10 ou menos, 11 - 20, 21 - 30, 31- 40, 40 ou mais

	for (auto const & utilizador : utilizadores)
	{
		unsigned int idade = utilizador.getIdade();

		if (idade<= 10)
			faixasEtarias["0-10"]++;
		else if (idade <= 20)
			faixasEtarias["11-20"]++;
		else if (idade <= 30)
			faixasEtarias["21-30"]++;
		else if (idade <= 40)
			faixasEtarias["31-40"]++;
		else
			faixasEtarias["40+"]++;
	}

	displayMap(faixasEtarias);
}*/

/*void rankingDeRentabilidades(vector<Utilizador> utilizadores)
{
	map <string, unsigned int> rentabilidade;

	for (auto const & utilizador : utilizadores)
	{
		map<Titulo*,vector<string>> titulos = utilizador.getBiblioteca().getBiblioteca();

		for (auto const & titulo : titulos)
		{
			rentabilidade[titulo.first->getNome()] += titulo.first->getGastos();
		}
	}
	displayMap(rentabilidade);
}*/

int main() {

	cout<<">>>>>>>>>>GAME LYBRARY MENU<<<<<<<<<<"<<endl<<endl;
	bool exit=false;
	while(!exit){
		int option;
		cout<<"1 - Create User"<<endl;
		cout<<"2 - Create Game"<<endl;
		cout<<"3 - Add game to User"<<endl;
		cout<<"4 - List games of User"<<endl;
		cout<<"100 - Exit"<<endl;
		cin>>option;
		switch(option){
		case 1:
			//createUser();
			break;
		case 2:
			//creatGame();
			break;
		case 3:
			//adicionaJogo();
			break;
		case 4:
			//listGames();
			break;
		case 100:
			exit=true;
			break;
		}
	}


	Data d1(31, 10, 2018);

	    Data d2(1,11,2018);

	    Data d3(20, 10, 2024);

	    /*generos por ordem alfabetica*/

	    /*map<string,unsigned int> generOcorrencias;

	    generOcorrencias["Action"]=1;
	    generOcorrencias["Action-Adventure"]=1;
	    generOcorrencias["Role_playing"]=1;
	    generOcorrencias["Simulation"]=1;
	    generOcorrencias["Strategy"]=1;
	    generOcorrencias["Sports"]=1;
	    generOcorrencias["Others"]=1;

	    adicionaGenero("Action",generOcorrencias);
	    adicionaGenero("Action",generOcorrencias);
	    adicionaGenero("RPG",generOcorrencias);
	    adicionaGenero("RPG",generOcorrencias);
	    adicionaGenero("Simulation",generOcorrencias);

	    cout << "ocorrencias:";
	    cout << generOcorrencias["RPG"]<<endl;

	    cout << "_______________________________\n";
	    cout << "generos:\n";
	    for(map<string,unsigned int>::const_iterator it =generOcorrencias.begin(); it != generOcorrencias.end(); ++it)
	    {
	        std::cout << it->first << " " << it->second<< "\n";
	    }

	    cout << "_______________________________\n";

	    cout << "test function"<<endl;
	    //rankingDePlataformas(generOcorrencias);


	    vector<string> generos1 = { "Luta", "Acao", "RPG" };

	    vector<string> generos2 = { "Luta", "MMO" };

	    std::map<std::string, std::vector<float>> precosPlataforma1;

	    vector<float> precosNintendo = { 60, 50, 40 }; //preco mais antigo tem de ser o mais caro, preco de lancamento
	    precosPlataforma1["Nintendo"] = precosNintendo;

	    vector<float> precosPlayStation = {60 ,40, 50 };
	    precosPlataforma1["PlayStation"] = precosPlayStation;


	    Online t1("testeGame", 5, precosPlataforma1, generos1, "Square Enix", d1,true,1);
	    cout << t1.getDesconto("Nintendo") << "%"<<endl; //preco mais caro esta em ultimo, preco de lancamento
	    cout << t1 << endl;

	    //////////
	    //JOGO 2//
	    //////////
	    Home t2 ("testeGame2", 10, precosPlataforma1, generos2, "Capcom", d1);
	    t2.adicionaAtualizacao(d1);
	    t2.adicionaAtualizacao(d1); //nao e adicionada


	    vector<string> plataformas={"Nintendo","PlayStation"};
	    cout << t2 << endl;



	    //////////
	    //JOGO 3//
	    //////////

	    Online t3 ("testeGame3", 5, precosPlataforma1, generos1, "Square Enix", d1,true,10);
	    t3.adicionaEstaticas(d1,70,"Nintendo");
	    t3.adicionaEstaticas(d1,30,"PlayStation");
	    t3.adicionaEstaticas(d1,21,"Nintendo"); //arredonda para tres horas
	    cout<<"horas totais: "<<t3.getHorasTotais()<<endl;
	    cout << t3 << endl;



	    cout << endl << endl << endl;

	    Biblioteca b1;
	    Biblioteca b2;

	    b1.adicionaTitulo(&t1,plataformas);
	//   b1.adicionaTitulo(&t2,plataformas);

	    b2.adicionaTitulo(&t1,plataformas);
	    b2.adicionaTitulo(&t2,plataformas);
	    b2.adicionaTitulo(&t3,plataformas);



	    CartaoCredito c1(100, d3, "1234");

	    Utilizador u1("Rafa", "oioi@yolo.com", 19, "Rua do Salgueiral, 293", b1);

	    u1.adicionaCartaoCredito(c1);

	    cout << "gastos:";
	    cout << u1.getGastos()<<"€"<<endl;
	    t2.adicionaAtualizacao(d2);
	    cout << "gastos:";
	    cout << u1.getGastos()<<"€"<<endl;
	    cout << "datas de atualizacao"<<endl;
	    cout << t2 << endl;

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



	    Utilizador u2("daniel", "oi@yolo.com", 198, "Rua do Sal, 63", b2);
	    vector <Utilizador> jogadores = {u1,u2};

	    cout << u1 << endl;
	    cout << u2 << endl;

	    cout << "nr medio de titulos:";
	    cout << nrMedioTitulos(jogadores)<<endl;

	    cout << "custo medio biblioteca:";
	    cout << custoMedioBiblioteca(jogadores)<<endl;

	    rankingDeGeneros(jogadores);
	    cout << endl;
	    rankingDePlataformas(jogadores);
	    cout << endl;
	    rankingDeIdades(jogadores);
	    cout << endl;
	    rankingDeRentabilidades(jogadores);
	    cout << endl;


*/

    return 0;
}
