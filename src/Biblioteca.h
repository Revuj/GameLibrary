#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include <vector>
#include <map>
#include <string>

class Titulo;

class Biblioteca {

	std::map<Titulo *,std::vector<std::string>> titulos;
public:
	/*
	 * adicona um titulo ao map titulos caso já exista adiciona as plataformas novas
	 */
	void adicionaTitulo(Titulo * T,const std::vector<std::string>& plataforma);

	/*
	 * retorna o conjunto de titulos
	 */
	std::vector<Titulo*> getTitulos() const;

	/*
	 * retorna o conjunto de plataformas
	 */
	std::vector<std::string> getPlataformas() const;
	/*
	 * compara duas bibliotecas
	 * @param B biblioteca com que se compara o objeto atual
	 * return true se a mesma senao falso
	 */
	bool operator==(const Biblioteca B);

	float getGastos() const;

};
