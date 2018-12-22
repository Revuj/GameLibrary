#include "empresa.h"

Empresa::Empresa(std::string nome,std::string email,std::string numeroTelemovel, std::string nif)
 	 :nome(nome),Nif(nif) {

	this->numeroTitulos=0;
	this->contacto.email=email;
	this->contacto.numeroTelemovel=numeroTelemovel;

}

unsigned int Empresa::getNumeroTitulos()const {
	return this->numeroTitulos;
}

std::string Empresa::getNomeEmpresa()const {
	return this->nome;
}

std::string Empresa::getNif()const {
	return this->Nif;
}

void Empresa::addNumero() {
	this->numeroTitulos++;
}

bool Empresa::operator <(const Empresa & empresa) {

	if(this->numeroTitulos==empresa.getNumeroTitulos())
		return this->nome < empresa.getNomeEmpresa();
	 else
		 return this->numeroTitulos< empresa.getNumeroTitulos();
}

bool Empresa::operator == (const Empresa & empresa) {
	return this->Nif==empresa.getNif();
}

void Empresa::criarTitulo(Titulo * t) {

	for(const auto & titles : this->Titulos) {
		if(titles==t)
			return;//throw(EmpresaJaComTitulo(t))
	}
	this->Titulos.push_back(t);
}






