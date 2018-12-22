#ifndef SRC_EMPRESA_H_
#define SRC_EMPRESA_H_
#include "Titulo.h"

typedef struct {
	std::string email;
	std::string numeroTelemovel;
} contactos;

class Empresa {
private:
	std::string nome;
	unsigned int numeroTitulos;
	contactos contacto;
	std::string Nif;
	std::vector<Titulo*> Titulos;


public:
	Empresa(std::string nome,std::string email,std::string numeroTelemovel, std::string nif);
	std::string getNomeEmpresa() const;
	unsigned int getNumeroTitulos() const;
	void addNumero();
	bool operator <(const Empresa & empresa);
	void criarTitulo(Titulo * t);


};





#endif /* SRC_EMPRESA_H_ */


