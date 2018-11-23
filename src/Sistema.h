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
#include <fstream>



class Sistema {
private:
	std::vector <Utilizador> jogadores;
	std::vector <Titulo *> titulos;
	std::vector <std::string> plataformas;



public:
	Sistema() {};
	~Sistema() {};
	void readFile(std::ifstream & file);
	void readUtilizadores();
	bool validName(const std::string nome);
	bool validEmail(const std::string email);
	bool addUtilizador();
	bool ordenarUtilizadores(std::string tipo,bool ascend);
	Utilizador pesquisaUtilizador(std::string nome);
	unsigned int nrMedioTitulos();
	float custoMedioBiblioteca();
	void rankingDeGeneros();
	void rankingDePlataformas();
	void rankingDeIdades();
	void rankingDeRentabilidades();
	std::vector <Utilizador> getJogadores();
	std::vector <Titulo *> getTitulos();
	std::vector <std::string> getPlataformas();







};




#endif /* SRC_SISTEMA_H_ */
