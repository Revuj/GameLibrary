/*
 * Sistema.cpp
 *
 *  Created on: 21/11/2018
 *      Author: revuj
 */

#include "Sistema.h"

	bool Sistema::validName(const std::string nome)
	{
		for(auto const & utilizador : this->jogadores) {
			if (utilizador.getNome() == nome)
				return false;
		}

		return true;

	}

	bool Sistema::validEmail(const std::string email)
		{
			for(auto const & utilizador : this->jogadores) {
				if (utilizador.getEmail() == email)
					return false;
			}

			return true;

		}

	void Sistema::addUtilizador() /*a incluir throws*/
	{
		std::string nome;
		std::string email;
		std::string EMAILCHAR = "@";
		std::string idade;
		std::string morada;
		std::cout << "Creating a user...  \n";
		std::cout <<"Enter a user name: ";
		getline(std::cin,nome);

		std::cout <<"Checking if is a valid name... \n";
		if(validName(nome))
			std::cout << "Valid name";
		else
			std::cout << "Invalid Name, try again";

		std::cout <<"Enter your email \n";
		getline(std::cin,email);
		if(email.find(EMAILCHAR) == std::string::npos)
			std::cout <<"Invalid email it must contain '@' \n";
		if(validEmail(email))
			std::cout <<"Email Valid \n";
		else
			std::cout << "Already exists email\n";

		std::cout << "Enter your age ";
		getline(std::cin,idade);
		std::cout <<"Enter your address: "; getline(std::cin,morada);

		jogadores.push_back(Utilizador(nome,email,stoi(idade),morada));
		//std::sort(jogadores.begin(),jogadores.end(),userNameAscend);













		std::cout << "Do you want to play online or do you prefer to play home? (home/online)?"<<std::endl;

	}






