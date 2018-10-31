#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

//#include "titulos.h"

#include <vector>

class Titulo;

class Biblioteca {

	std::vector<Titulo*> titulos;
public:
	void adiciona_titulo(Titulo *T);
	/*
	 * compara duas bibliotecas
	 * @param B biblioteca com que se compara o objeto atual
	 * return true se a mesma senao falso
	 */
	bool operator==(const Biblioteca B);
};



#endif /* SRC_BIBLIOTECA_H_ */
