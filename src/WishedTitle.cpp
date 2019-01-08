#include "WishedTitle.h"

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




