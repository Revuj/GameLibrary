#include "Data.h"

// construtor
Data::Data(int dia, int mes, int ano) {

	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

bool Data::operator<=(const Data& D1) {

	if (ano > D1.ano)
		return false;
	else if (ano == D1.ano) {

		if (mes > D1.mes)
			return false;
		if (dia > D1.mes)
			return false;

		return true;
	} else
		return true;
}

bool Data::operator ==(const Data & D2) {
	return (this->ano == D2.ano) && (this->mes == D2.mes)
			&& (this->dia == D2.dia);
}

std::ostream & operator <<(std::ostream & os, const Data & data) {
	os << data.getDia() << "/" << data.getMes() << "/" << data.getAno();
	return os;
}
