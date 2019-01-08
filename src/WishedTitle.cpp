#include "WishedTitle.h"
#include "Titulo.h"

WishedTitle::WishedTitle(unsigned interesse, float probabilidade, Titulo* title){
	if(interesse>10){
		this->interesse=10;
	}
	else this->interesse=interesse;

	if(probabilidade>1){
		this->probabilidadeCompra=1;
	}
	else this->probabilidadeCompra=probabilidade;
	this->titulo=title;
}

void WishedTitle::setProbabilidadeCompra(float probabilidade){
	if(probabilidade>1){
		this->probabilidadeCompra=1;
	}
	else this->probabilidadeCompra=probabilidade;
}

bool WishedTitle::operator<(const WishedTitle &title) const {
	if (interesse == title.getInteresse())
		return probabilidadeCompra < title.getProbabilidadeCompra();
	return interesse < title.getInteresse();
}

void WishedTitle::atualizaProbabilidade(float saldo){
	unsigned anuncios = this->titulo->getAnuncios(),cliques = this->titulo->getCliques();
	this->probabilidadeCompra=(2*this->interesse+30*anuncios/(anuncios +10) + 30 * cliques /(cliques +5) + saldo/(5*(saldo+this->titulo->getPreco())))/100.0;
}


