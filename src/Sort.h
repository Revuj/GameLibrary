#ifndef SORT_H_
#define SORT_H_

#include "Titulo.h"

bool userNameAscend(Utilizador& user1,Utilizador& user2);
bool userNameDescend(Utilizador& user1,Utilizador& user2);
bool userAgeAscend(Utilizador& user1,Utilizador& user2);
bool userAgeDescend(Utilizador& user1,Utilizador& user2);
bool userNumberGamesAscend(Utilizador& user1,Utilizador& user2);
bool userNumberGamesDescend(Utilizador& user1,Utilizador& user2);
 
bool gameIdAscend(Titulo* titulo1,Titulo* titulo2);
bool gameIdDescend(Titulo* titulo1,Titulo* titulo2);
bool gameReleaseAscend(Titulo* titulo1,Titulo* titulo2);
bool gameReleaseDescend(Titulo* titulo1,Titulo* titulo2);
bool gameAgeAscend(Titulo* titulo1,Titulo* titulo2);
bool gameAgeDescend(Titulo* titulo1,Titulo* titulo2);
bool gameDeveloperAscend(Titulo* titulo1,Titulo* titulo2);
bool gameDeveloperDescend(Titulo* titulo1,Titulo* titulo2);

bool cmpParJogoRentabilidade(const std::pair<std::string,float> & p1,const std::pair<std::string,float> & p2);

#endif /* SORT_H_ */
