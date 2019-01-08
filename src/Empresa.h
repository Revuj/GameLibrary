#ifndef SRC_EMPRESA_H_
#define SRC_EMPRESA_H_

#include <string>
#include <vector>
class Titulo;
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
	Empresa() {this->numeroTitulos=0;}
	Empresa(std::string nome,std::string email,std::string numeroTelemovel, std::string nif);
	std::string getNomeEmpresa() const;
	unsigned int getNumeroTitulos() const;
	std::string getNif()const;
	contactos getContactos() const;
	std::vector<Titulo*> getTitulos() const;
	void displayTitulos();
	void addNumero();
	bool operator <(const Empresa & empresa);
	bool operator == (const Empresa & empresa);
	void criarTitulo(Titulo * t);
};

struct EmpresasComp
{
	bool operator()(Empresa *empresa1,  Empresa *empresa2) const
	{
		if (empresa1->getNumeroTitulos() == empresa2->getNumeroTitulos())
			return empresa1->getNomeEmpresa() < empresa2->getNomeEmpresa();
		return empresa1->getNumeroTitulos() < empresa2->getNumeroTitulos();
	}
};



#endif /* SRC_EMPRESA_H_ */


