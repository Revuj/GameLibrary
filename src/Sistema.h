/*
 * Sistema.h
 *
 *  Created on: 21/11/2018
 *      Author: revuj
 */

#ifndef SRC_SISTEMA_H_
#define SRC_SISTEMA_H_

#include "Utilizador.h"
#include "Banco.h"
#include <string>
#include <fstream>


class Sistema {
private:
	std::vector <Utilizador> jogadores;
	std::vector <Titulo *> titulos;
	std::vector <std::string> plataformas;
	Banco banco;
public:
	Sistema() {};
	~Sistema();
	void readFileUtilizadores(std::ifstream & file);
	void readUtilizadores();
	void saveUtilizadores();
	void readFileTitulos(std:: ifstream & file);
	void readTitulos();
	void saveTitulos();
	bool validEmail(const std::string email);
	void isValidEmail(std::string & email,bool checkafter=false);
	void utilizadorJogar(Utilizador & u, Titulo * t, unsigned int minutos);
	void saldoUtilizador(const Utilizador & u);
	void tempoJogado(const Utilizador & u);
	void adicionaUtilizador(const Utilizador & u);
	void addTitulo(Titulo *titulo);
	void ordenaUtilizadores(std::string tipo,bool ascend);
	void ordenaTitulos(std::string tipo, bool ascend);
	Utilizador pesquisaUtilizador(std::string nome, std::string email);
	Titulo * pesquisaJogo(std::string nome,std::string plataforma);
	std::vector<Titulo*> ordenaTitulosUtilizador(const Utilizador & u, std::string criterio,bool ascend);
	unsigned int nrMedioTitulos();
	float custoMedioBiblioteca();
	void rankingDeGeneros();
	void rankingDePlataformas();
	void rankingDeIdades();
	void rankingDeRentabilidades();
	std::vector <Utilizador> getJogadores();
	void displayUtilizadores();
	std::vector <Titulo *> getTitulos();
	void displayTitulos();
	std::vector <std::string> getPlataformas();
	Banco getBanco();
	void dataValida( CartaoCredito & D);
};




#endif /* SRC_SISTEMA_H_ */
