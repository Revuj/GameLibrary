#include "data.h"

// construtor
Data::Data(int dia,int mes,int ano) {

    this->dia=dia;
    this->mes=mes;
    this->ano=ano;
}

bool Data::operator<=(const Data& D1) {

    if(ano > D1.ano)
        return false;
    else if (ano == D1.ano) {

        if(mes> D1.mes)
            return false;
        if(dia > D1.mes)
            return false;

        return true;
    }
    else
        return true;
}
