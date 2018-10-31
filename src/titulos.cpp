#include "titulos.h"
#include <algorithm>

/*inicializacao de variaveis static*/
unsigned int Titulo:: IdUnico = 1;
float Online:: horas_totais=0;

/*
 * construtor titulo
 */

Titulo::Titulo(std::string n,float pa,int ii,int ifi,std::string p,std::string g,std::string e) {

	this->IdU=IdUnico++;
	nome=n;
	precoAquisicao= pa;
	idadeMinima=ii;
	idadeMaxima=ifi;
	plataforma=p;
	genero=g;
	empresa=e;
	historial_preco.push_back(pa);
}

bool Titulo::addPrice(const float preco)
{
	if(preco <= 0)
		return false;
	else
	{
		this->historial_preco.push_back(preco);
		return true;
	}
}


float Titulo::getPrecoAtual()
{
	return this->historial_preco.at(0);
}


/*se o identificador unico for igual entao tratase do mesmo titulo*/
	bool Titulo::operator== (const Titulo & T)
	{
		return (this->IdU== T.IdU);
	}


/*
 * classe Home, derivada da Titulo
 */

Home::Home(std::string n,float pa,int ii,int ifi,std::string p,std::string g,std::string e)
	:Titulo(n,pa,ii,ifi,p,g,e)
{

}



bool Home::adicionaAtualizacao(const Data & D)
{

	if( find(this->data_de_atualizacao.begin(),this->data_de_atualizacao.end(), D)!= this->data_de_atualizacao.end() )
		return false;
	else
	{
		this->data_de_atualizacao.push_back(D);
		return true;
	}

}


Online::Online(std::string n,float pa,int ii,int ifi,std::string p,std::string g,std::string e, bool subs, size_t pSubscricao)
:Titulo(n,pa,ii,ifi,p,g,e)
{
	this->subscricaoFixa=subs;
	this->precoSubscricao=pSubscricao;
}

bool Online::adicionaUtilizador(const Utilizador &U)
{
	if( find(this->utilizadores.begin(),this->utilizadores.end(), U)!= this->utilizadores.end() )
		return false;
	else
	{
		this->utilizadores.push_back(U);
		return true;
	}
}


void Online::atualizaEstAux(const Data & D1,const size_t minutos, const std::string plataforma)
{
	this->Data_em_que_jogou.push_back(D1);
	this->minutos_jogados_por_data.push_back(minutos);
	this->plataformas.push_back(plataforma);
}

void Online::adicionaEstaticas(const Data & D1,const size_t minutos, const std::string plataforma)
{

	unsigned int indiceData=0;

	for(auto data : this->Data_em_que_jogou)
	{
		if(data == D1 && plataformas[indiceData]==plataforma)
		{
			this->minutos_jogados_por_data[indiceData]+=minutos; /*atualiza os minutos numa data*/
			horas_totais+= minutos/60;
			return;
		}

		indiceData++;
	}

		/*se plataforma e/ou data forem diferentes adiciona uma nova estatistica*/
		atualizaEstAux(D1,minutos,plataforma);
		horas_totais+= minutos/60;

		return;
}







