

#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_
#include "titulos.h"

class Biblioteca {

	vector<Titulo*> titulos;
public:
	void adiciona_titulo(Titulo *T);
};



#endif /* SRC_BIBLIOTECA_H_ */
