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

	struct tm data1 = {0};

    data1.tm_year = ano - 1900;
    data1.tm_mon = mes - 1;
    data1.tm_mday = dia;

    struct tm data2 = {0};

    data2.tm_year = data.getAno() - 1900;
    data2.tm_mon = data.getMes() - 1;
    data2.tm_mday = data.getDia();

    std::time_t time1 = std::mktime(&data1);
    std::time_t time2 = std::mktime(&data2);

    const int seconds_per_day = 60*60*24;
    unsigned int difference = abs(time1 - time2) / seconds_per_day;

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
