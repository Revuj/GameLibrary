/*
 * Sistema.h
 *
 *  Created on: 21/11/2018
 *      Author: revuj
 */

#ifndef SRC_SISTEMA_H_
#define SRC_SISTEMA_H_
#include "Utilizador.h"
#include "sort.h"
#include <algorithm>
#include<string>


class Sistema {
	std::vector <Utilizador> jogadores;
	std::vector <Titulo> titulos;
	std::vector <std::string> plataformas;



	public:
	Sistema() {};
	~Sistema() {};
	//readUtilizadoresSistema();
	bool validName(const std::string nome);
	bool validEmail(const std::string email);
	void addUtilizador();
	unsigned int nrMedioTitulos();
	float custoMedioBiblioteca();
	void rankingDeGeneros();
	void rankingDePlataformas();
	void rankingDeIdades();
	void rankingDeRentabilidades();







};



#endif /* SRC_SISTEMA_H_ */
