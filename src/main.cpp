#include <iostream>

#include "Titulo.h"
#include "Banco.h"
#include "Erro.h"


#include <algorithm>
using namespace std;

int main() {

	cout<<">>>>>>>>>>GAME LYBRARY MENU<<<<<<<<<<"<<endl<<endl;
	bool exit=false;
	while(!exit){
		int option;
		cout<<"1 - Create User"<<endl;
		cout<<"2 - Create Game"<<endl;
		cout<<"3 - Add game to User"<<endl;
		cout<<"4 - List games of User"<<endl;
		cout<<"100 - Exit"<<endl;
		cin>>option;
		switch(option){
		case 1:
			//createUser();
			break;
		case 2:
			//creatGame();
			break;
		case 3:
			//adicionaJogo();
			break;
		case 4:
			//listGames();
			break;
		case 100:
			exit=true;
			break;
		}
	}

    return 0;
}
