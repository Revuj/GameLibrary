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
	/**
	 * @brief Construtor por default da classe empresa
	 */
	Empresa() {this->numeroTitulos=0;}
	/**
	 * @brief Construtor da classe empresa
	 * @param nome - nome da empresa
	 * @param email - email da empresa
	 * @param numeroTelemovel - numero de telemovel da empresa
	 * @param nif - nif da empresa
	 */
	Empresa(std::string nome,std::string email,std::string numeroTelemovel, std::string nif);

	/**
	 * @brief Adiciona um titulo novo a empresa
	 */
	void criarTitulo(Titulo * t);

	/**
	 * @brief Devolve o nome da empresa
	 * @return Retorna o nome da empresa
	 */
	std::string getNomeEmpresa() const;

	/**
	 * @brief Devolve o numero de titulos da empresa
	 * @return Retorna o numero de titulos da empresa
	 */
	unsigned int getNumeroTitulos() const;

	/**
	 * @brief Devolve o NIF da empresa
	 * @return retorna o NIF da empresa
	 */
	std::string getNif()const;

	/**
	 * @brief Devolve os contactos da empresa
	 * @return Retorna a struct contactos, da empresa
	 */
	contactos getContactos() const;

	/**
	 * @brief Devolve os titulos da empresa
	 * @return Retorna o vector com os titulos da empresa
	 */
	std::vector<Titulo*> getTitulos() const;

	/**
	 * @brief Mostra os titulos da empresa no ecra
	 */
	void displayTitulos();

	/**
	 * @brief Incrementa o numero de titulos da empresa
	 */
	void addNumero();

	/**
	 * @brief Overload do operador menor para objetos da classe Empresa
	 */
	bool operator <(const Empresa & empresa);

	/**
	 * @brief Overload do operador igual para objetos da classe Empresa
	 */
	bool operator == (const Empresa & empresa);
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


