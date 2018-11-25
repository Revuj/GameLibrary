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
#include <iomanip>


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
	void saveUtilizadores() const;
	void readFileTitulos(std:: ifstream & file);
	void readTitulos();
	void saveTitulos() const;
	bool validEmail(const std::string email) const;
	void isValidEmail(std::string & email,bool checkafter=false) const;
	void utilizadorJogar(Utilizador & u, Titulo * t, unsigned int minutos);
	void saldoUtilizador(const Utilizador & u) const;
	void tempoJogado(const Utilizador & u) const;
	void adicionaUtilizador(const Utilizador & u);
	void addTitulo(Titulo *titulo);
	void adicionaAtualizacao(std::string nome,std::string plataforma,Data& data);
	void ordenaUtilizadores(std::string tipo,bool ascend);
	void ordenaTitulos(std::string tipo, bool ascend);
	Utilizador * pesquisaUtilizador(std::string nome, std::string email) ;
	Titulo * pesquisaJogo(std::string nome,std::string plataforma) const;
	std::vector<Titulo*> ordenaTitulosUtilizador(const Utilizador & u, std::string criterio,bool ascend) const;
	unsigned int nrMedioTitulos() const;
	float custoMedioBiblioteca() const;
	void rankingDeGeneros() const;
	void rankingDePlataformas() const;
	void rankingDeIdades() const;
	void rankingDeRentabilidades() const;
	std::vector <Utilizador> getJogadores() const;
	void displayUtilizadores() const;
	std::vector <Titulo *> getTitulos() const;
	void displayTitulos() const;
	std::vector <std::string> getPlataformas() const;
	Banco getBanco() const;
	void dataValida( CartaoCredito & D) const;
};




#endif /* SRC_SISTEMA_H_ */
