#include "Sort.h"

bool userNameAscend(Utilizador* user1,Utilizador* user2){
	return user1->getNome() < user2->getNome();
}

bool userNameDescend(Utilizador* user1,Utilizador* user2){
	return user1->getNome() > user2->getNome();
}

bool userAgeAscend(Utilizador* user1,Utilizador* user2){
	return user1->getIdade() < user2->getIdade();
}

bool userAgeDescend(Utilizador* user1,Utilizador* user2){
	return user1->getIdade() > user2->getIdade();
}




bool gameIdAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdU() < titulo2->getIdU();
}

bool gameIdDescend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdU() > titulo2->getIdU();
}

bool gameReleaseAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getDataLancamento() < titulo2->getDataLancamento();
}

bool gameReleaseDescend(Titulo* titulo1,Titulo* titulo2){
	return !(titulo1->getDataLancamento() <= titulo2->getDataLancamento());
}

bool gameAgeAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdadeMinima() < titulo2->getIdadeMinima();
}

bool gameAgeDescend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getIdadeMinima() > titulo2->getIdadeMinima();
}

bool gameDeveloperAscend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getEmpresa() < titulo2->getEmpresa();
}

bool gameDeveloperDescend(Titulo* titulo1,Titulo* titulo2){
	return titulo1->getEmpresa() > titulo2->getEmpresa();
}

bool cmpParJogoRentabilidade(const std::pair<std::string,float> & p1,const std::pair<std::string,float> & p2){
	return p1.second > p2.second;
}




