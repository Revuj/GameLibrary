#ifndef SORT_H_
#define SORT_H_

#include "Titulo.h"

bool userNameAscend(const Utilizador& user1,const Utilizador& user2);
bool userNameDescend(const Utilizador& user1,const Utilizador& user2);
bool userAgeAscend(const Utilizador& user1,const Utilizador& user2);
bool userAgeDescend(const Utilizador& user1,const Utilizador& user2);
bool userNumberGamesAscend(const Utilizador& user1,const Utilizador& user2);
bool userNumberGamesDescend(const Utilizador& user1,const Utilizador& user2);
 
bool gameIdAscend(const Titulo* titulo1,const Titulo* titulo2);
bool gameIdDescend(const Titulo* titulo1,const Titulo* titulo2);
bool gameReleaseAscend(const Titulo* titulo1,const Titulo* titulo2);
bool gameReleaseDescend(const Titulo* titulo1,const Titulo* titulo2);
bool gameAgeAscend(const Titulo* titulo1,const Titulo* titulo2);
bool gameAgeDescend(const Titulo* titulo1,const Titulo* titulo2);
bool gameDeveloperAscend(const Titulo* titulo1,const Titulo* titulo2);
bool gameDeveloperDescend(const Titulo* titulo1,const Titulo* titulo2);

bool cmpParJogoRentabilidade(const std::pair<std::string,float> & p1,const std::pair<std::string,float> & p2);

#endif /* SORT_H_ */
