#include "Data.h"
#include <time.h>
#include <ctime>


// construtor
Data::Data(int dia, int mes, int ano) {

	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

Data & Data::setDia(const unsigned int dia) {
	this->dia = dia;
	return *this;
}

Data & Data::setMes(const unsigned int mes) {
	this->mes = mes;
	return *this;
}

Data & Data::setAno(const unsigned int ano) {
	this->ano = ano;
	return *this;
}

unsigned int Data::getDia() const {
	return dia;
}

unsigned int Data::getMes() const {
	return mes;
}

unsigned int Data::getAno() const {
	return ano;
}

unsigned int Data::diferencaEntreDatas(const Data & data) {
    struct std::tm a = {0,0,0,this->dia, this->mes - 1,this->ano - 1900}; /* June 24, 2004 */
    struct std::tm b = {0,0,0,data.getDia(), data.getMes() - 1 , data.getAno() - 1900}; /* July 5, 2004 */
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);

    unsigned int difference = std::difftime(y, x) / (60 * 60 * 24);
    return difference;
}

bool Data::operator<=(const Data& D1) const {

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

bool Data::operator ==(const Data & D2) const {
	return (this->ano == D2.ano) && (this->mes == D2.mes)
			&& (this->dia == D2.dia);
}



std::ostream & operator <<(std::ostream & os, const Data & data) {
	os << data.getDia() << "/" << data.getMes() << "/" << data.getAno();
	return os;
}
