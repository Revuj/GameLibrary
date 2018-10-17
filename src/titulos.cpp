#include "titulos.h"


// construtor

Titulo::Titulo(string n,float pa,int ii,int ifi,string p,string g,string e) {

	nome=n;
	preco_aquisicao= pa;
	idade_minima=ii;
	idade_maxima=ifi;
	plataforma=p;
	genero=g;
	empresa=e;
	historial_preco.push_back(pa);
}

void Titulo::set_preco(float preco) {
	this->preco_aquisicao=preco;
	historial_preco.push_back(preco);
}


 size_t Online:: horas_totais=0;





